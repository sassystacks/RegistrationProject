import vtk
import os


class getImageData:

    def __init__(self, **kwargs):

        # Takes in an argument of a directory and optional filename to load image
        # directory to look in for the data set
        try:
            self.directory = os.path.join(kwargs['directory'])
            chkFtype = kwargs['filename']
        except:
            self.directory = os.path.join(kwargs['directory'])
            # Read first file in the directory and Determine if it is a DICOM type or NIFTI type folder
            chkFtype = os.listdir(self.directory)[0]

        # if it is a DICOM folder set the filetype and define an actor
        if chkFtype.endswith(".dcm"):
            self.ftype = 'DCM'
            self.reader = self.readDICOM()

        # if it is a DICOM folder set the filetype and define an actor
        elif chkFtype.endswith(".nii"):
            self.ftype = 'NII'
            self.reader = self.readNIFTI(chkFtype)

        # if it is a DICOM folder set the filetype and define an actor
        elif chkFtype.endswith(".obj"):
            self.ftype = 'OBJ'
            self.reader = self.readOBJECT(chkFtype)

        elif chkFtype.endswith(".stl"):
            self.ftype = 'STL'
            self.reader = self.readSTL(chkFtype)

        else:
            print(chkFtype)
            print("The folder specified won't work with this application")

    def readSTL(self, *args):

        reader = vtk.vtkSTLReader()
        reader.SetFileName(os.path.join(self.directory, args[0]))
        reader.Update()

        return reader

    def readDICOM(self, *args):

        # create reader
        reader = vtk.vtkDICOMImageReader()
        reader.SetDirectoryName(self.directory)
        reader.Update()

        return reader

    def readNIFTI(self, *args):

        # create reader
        reader = vtk.vtkNIFTIImageReader()
        reader.SetFileName(os.path.join(self.directory, args[0]))
        reader.Update()

        return reader

    def readOBJECT(self, *args):

        # create reader
        reader = vtk.vtkOBJReader()
        reader.SetFileName(os.path.join(self.directory, args[0]))
        reader.Update()

        return reader

    def get2DActor(self, *args):

        # Instance actor and set its mapper
        actor = vtk.vtkActor2D()
        actor.SetMapper(self.mapper)

        return actor
