from preprocessimg import processImageData

'''
~~~~~~~~~~~~~~~ Some Generic functions to use ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
'''
def getNP(self, reader,*args):

    imageData = reader.GetOutput()

    #Get image as a numpy array
    extent = reader.GetDataExtent()
    dimensions = [extent[1]-extent[0]+1, extent[3]-extent[2]+1,extent[5]-extent[4]+1]
    pointData = imageData.GetPointData()

    arrayData = pointData.GetArray(0)
    npArray = numpy_support.vtk_to_numpy(arrayData)
    npArray = npArray.reshape(dimensions, order='F')

    return npArray

# def binaryLookupTable(self, r=0.0,g=1.0,b=0.0,op=1.0):
#
#     #Takes binary representation and
#     #Set color for look out SetTable
#     #input : r,g,b,op => red, green, blue, opacity
#
#     t = vtk.vtkLookupTable()
#     t.SetNumberOfTableValues(2)
#     t.SetRange(0,1)
#     t.SetTableValue(0, 0.0, 0.0, 0.0, 0.0) # 0 = black
#     t.SetTableValue(1, r, g, b, op) # 1 = (r,g,b) as input of function
#     t.Build()
#
#     return t
