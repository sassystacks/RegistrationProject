import numpy as np
import vtk
from vtk.util import numpy_support


class processImageData:

    def __init__(self, *args, **kwargs):

        rgb_vals = kwargs.get('rgb', {'r': 1, 'g': 1, 'b': 1, })

    '''
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Useful methods ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    '''

    def getHistogram(self, imageArray):
        import matplotlib.pyplot as plt
        # function takes the numpy arrary representation of the image
        # and returns a histogram

        flatImg = imageArray.flatten()
        imgRange = np.ptp(flatImg)
        imgMin = np.amin(flatImg)
        imgMax = np.amax(flatImg)
        print(imgMin)
        print(imgMax)
        print(imgRange)
        plt.hist(flatImg, bins=imgRange, range=[imgMin, imgMax])
        # plt.xlim(imgMin,imgMax)
        plt.ylim(0, 100000)
        plt.show()

    def getPolyfromImg(self, reader):
        polyData = vtk.vtkImageDataGeometryFilter()
        polyData.SetInputData(reader.GetOutput())

        return polyData

    def binaryLookupTable(self, r=0.0, g=1.0, b=0.0, op=1.0):

        # Takes binary representation and
        # Set color for look out SetTable
        # input : r,g,b,op => red, green, blue, opacity

        t = vtk.vtkLookupTable()
        t.SetNumberOfTableValues(2)
        t.SetRange(0, 1)
        t.SetTableValue(0, 0.0, 0.0, 0.0, 0.0)  # 0 = black
        t.SetTableValue(1, r, g, b, op)  # 1 = (r,g,b) as input of function
        t.Build()

        return t

    def getNPfromPoly(self, reader):

        polydata = reader.GetOutput()
        points = polydata.GetPoints()
        array = points.GetData()
        npArray = numpy_support.vtk_to_numpy(polydata)

        return npArray  # Numpy Array

    def getNPfromFilter(self, data):

        imgData = data.GetOutput()
        imgArray = imgData.GetPointData().GetAbstractArray(0)
        npArray = numpy_support.vtk_to_numpy(imgArray)

        return npArray

    def getNPfromImageData(self, reader):

        imageData = reader.GetOutput()

        # imageData = reader
        # Get image as a numpy array
        extent = reader.GetDataExtent()
        dimensions = [extent[1]-extent[0]+1, extent[3]-extent[2]+1, extent[5]-extent[4]+1]
        pointData = imageData.GetPointData()

        arrayData = pointData.GetArray(0)
        npArray = numpy_support.vtk_to_numpy(arrayData)
        npArray = npArray.reshape(dimensions, order='F')

        return npArray  # Numpy Array

    def getNP(self, reader, ftype):

        if ftype is 'DCM' or ftype is 'NII':
            npArray = self.getNPfromImageData(reader)  # use for imageData
        elif ftype is 'OBJ':
            npArray = self.getNPfromPoly(reader)  # use for vtkPolyData
        # elif ftype is 'imagedata':
        #     print "imagedata"
        #     npArray = self.getNPfromPoly(reader)  # use for vtkPolyData
        return npArray

    def getVTKfromNumpy(self, img, spacing=[1.0, 1.0, 1.0]):
        # This method of returning a numpy array was found on github
        # it works well so used it for the volume Rendering
        # img :

        importer = vtk.vtkImageImport()

        img_data = img.astype('uint8')
        img_string = img_data.tostring()
        dim = img.shape

        importer.CopyImportVoidPointer(img_string, len(img_string))
        importer.SetDataScalarType(VTK_UNSIGNED_CHAR)
        importer.SetNumberOfScalarComponents(1)

        extent = importer.GetDataExtent()
        importer.SetDataExtent(extent[0], extent[0] + dim[2] - 1,
                               extent[2], extent[2] + dim[1] - 1,
                               extent[4], extent[4] + dim[0] - 1)
        importer.SetWholeExtent(extent[0], extent[0] + dim[2] - 1,
                                extent[2], extent[2] + dim[1] - 1,
                                extent[4], extent[4] + dim[0] - 1)

        importer.SetDataSpacing(spacing[0], spacing[1], spacing[2])
        importer.SetDataOrigin(0, 0, 0)

        return importer  # vtk object

    '''
    ~~~~~~~~~~~~~~~~~~~ Functions Below Manipulate numpy Arrays ~~~~~~~~~~~~~~~~~~~~~
    '''

    def applyGlobalThreshold(self, npArray, lower, upper):
        # Applies a logical opperator to an image and
        # returns new image as numpy array

        binarray = np.zeros(npArray.shape)
        binarray[np.logical_and(npArray > lower, npArray < upper)] = 1

        return binarray  # returns numpyArray

    def applyMedianFilterNP(self, npArray):
        # apply median filter to numpy Array
        from scipy import ndimage
        filterImg = ndimage.median_filter(npArray, size=5)
        return filterImg

    '''
    ~~~~~~~~~~~~~~~~~~~ Functions Below Manipulate vtk objects ~~~~~~~~~~~~~~~~~~~~~
    '''

    def applyMedianFilterVTK(self, imgData, kern=[3, 3, 3]):

        med = vtk.vtkImageMedian3D()
        med.SetInputData(imgData.GetOutput())
        med.SetKernelSize(kern[0], kern[1], kern[2])
        med.Update()

        return med

    def applyGauss(self, imgData, std=1, radius=3):

        # Use bult in functions in vtk to smooth data
        filterImg = vtk.vtkImageGaussianSmooth()
        # set input connection from the reader
        filterImg.SetInputData(imgData.GetOutput())
        filterImg.SetStandardDeviation(std, std, std)
        filterImg.SetRadiusFactors(radius, radius, radius)
        filterImg.SetDimensionality(3)
        filterImg.Update()

        return filterImg  # return vtk object type

    def applyVTKthreshold(self, reader, lower, upper):

        # use builtin functions for threshold to avoid storing in memory
        threshold = vtk.vtkImageThreshold()
        threshold.SetInputData(reader.GetOutput())
        threshold.ThresholdBetween(lower, upper)  # Set threshold upper and lower limits
        threshold.ReplaceInOn()
        threshold.SetInValue(1)  # set values inside threshold to 0
        threshold.ReplaceOutOn()
        threshold.SetOutValue(0)  # set values outside threshold to 0
        threshold.Update()

        return threshold  # returns vtkImageData

    def applyDilateErode(self, imgData, dVal, eVal, kernel=[3, 3, 3]):

        deImg = vtk.vtkImageDilateErode3D()
        deImg.SetInputData(imgData.GetOutput())
        deImg.SetDilateValue(dVal)
        deImg.SetErodeValue(eVal)
        deImg.SetKernelSize(kernel[0], kernel[1], kernel[2])
        deImg.Update()

        return deImg

    def applyOpenClose(self, imgData, oVal, cVal, kernel=[3, 3, 3]):

        ocImg = vtk.vtkImageOpenClose3D()
        ocImg.SetInputData(imgData.GetOutput())
        ocImg.SetOpenValue(oVal)
        ocImg.SetCloseValue(cVal)
        ocImg.SetKernelSize(kernel[0], kernel[1], kernel[2])
        ocImg.Update()

        return ocImg

    def applyMarchingCubes(self, imgData):

        mc = vtk.vtkMarchingCubes()
        mc.SetInputData(imgData.GetOutput())
        mc.Update()

        return mc  # vtkobject

    def applyDiscreteMarchingCubes(self, imgData):
        # Apply marching cubes to render surface
        # Distcrete MarchingCubes speeds up computation
        dmc = vtk.vtkDiscreteMarchingCubes()
        dmc.SetInputData(imgData.GetOutput())
        dmc.GenerateValues(1, 1, 1)
        dmc.Update()

        return dmc.GetOutput()  # vtkPolyData
