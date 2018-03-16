import vtk


class applyRegistration(object):

    def __init__(self, **kwargs):
        pass

    def applyTransform(self, icp, Data):
        # Return the tranformed source
        tObj = vtk.vtkTransformPolyDataFilter()
        tObj.SetInputData(Data)
        tObj.SetTransform(icp)
        tObj.Update()

        return tObj.GetOutput()  # vtkPolyData

    def applyICP(self, pList, iterNum):
        # Iterative closest point applied for number of iterations

        polyTarget = pList[0]
        polySource = pList[1]

        icp = vtk.vtkIterativeClosestPointTransform()
        icp.SetSource(polySource)
        icp.SetTarget(polyTarget)
        icp.GetLandmarkTransform().SetModeToRigidBody()
        icp.SetMaximumNumberOfIterations(iterNum)
        icp.Update()
        print"icp tranform is : ", icp

        return icp

    def applyDecimation(self, polyData, reductionNum):
        # Decimate the image to lower comp cost
        decimate = vtk.vtkDecimatePro()
        decimate.SetInputData(polyData.GetOutput())
        decimate.SetTargetReduction(reductionNum)
        decimate.PreserveTopologyOn()
        decimate.Update()

        return decimate  # vtkPolyData

    def applyReslice(self, icp, reader):
        # reslice the image to display tranformation
        rslice = vtk.vtkImageReslice()
        rslice.SetInputData(reader.GetOutput())
        rslice.SetInterpolationModeToLinear()
        rslice.SetResliceAxes(icp.GetMatrix())
        rslice.Update()

        return rslice  # Data
