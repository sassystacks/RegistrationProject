#!/usr/bin/env python

'''
class to render 3d images. Based on Assignment 4 in MDSC 689.03
To check this class grab if name = __main__ from assignment 4


'''


import vtk
import numpy as np
import sys

from vtk.util import numpy_support

from vtk.util.vtkConstants import *


class actorimg3d:

    # def __init__(self,reader,rendertype = 'surface',threshlist=[400,5000],*args,**kwargs):
    def __init__(self):
        # Set Threshold limits based on whether it is CT or MR
        # Determine if it is a surface or volume render
        # Run function specified. Defaults to surface
        pass
        # self.reader = reader
        # #Deterimine  the type of rendering and run that type
        # if rendertype == 'surface':
        #     self.surfaceActor(self.reader,threshlist,op)
        # elif rendertype == 'volume':
        #     self.volumeActor(self.reader,threshlist,op)
        # else:
        #     print "{} is not a valid option for visualization".format(rendertype)

    '''
    ~~~~~~~~~~~~~~~~~~~~~~~~   Surface Rendering    ~~~~~~~~~~~~~~~~~~~~~~~~
    '''

    def getActors(self, dataList, propList=[{'opacity': 1, 'r': 0.1, 'g': 0.1, 'b': 0.6},
                                            {'opacity': 1, 'r': 1, 'g': 0.2, 'b': 1}]):

        actorList = []
        # loop through all the data sets passed to function
        for i, t in enumerate(dataList):
            mapper = ri.mapperFuncs().getPolyDataMap(t)  # call method from precious assignment

            # initialize actor and set properties
            actor = vtk.vtkActor()
            actor.GetProperty().SetOpacity(propList[i]['opacity'])
            actor.GetProperty().SetColor(propList[i]['r'],
                                         propList[i]['g'],
                                         propList[i]['b'])
            actor.SetMapper(mapper)  # create new actor

            actorList.append(actor)
        return actorList  # return list of actors

    '''
    ~~~~~~~~~~~~~~~~~~~~~~~~    Volume Rendering   ~~~~~~~~~~~~~~~~~~~~~~~~
    '''

    def volumeActor(self, reader, segementedimg,
                    colourList=[[0, 0, 0, 0, 0], [1, 1, 0.894, 0.769, 1]]):
        # Takes inputs and renders a volume based on the thresholds provided and the opacity
        # inputs:
        # reader (vtk object),
        # threshold list : list [upper,lower],
        # opacity : float 0.0 - 1.0
        # colourList: list of lists [[val,r,g,b,opacity],.....[]] default= [[nothing for zeros],[bisque for 1's]]

        filterimgData = reader.GetOutput()  # get the output from filterimg
        tf = [l for l in colourList]
        actor = self.volumeRender(segementedimg, tf=tf, spacing=filterimgData.GetSpacing())

        return actor

    def volumeRender(self, imgData, tf, spacing=[1.0, 1.0, 1.0]):
        # Returns a list of actors to be visualized based on a numpy array and image input
        # input:

        # img : vtk object
        # tf : transfer function values to generate colouring from list of lists [val,r,g,v,op]
        # spacing: imaging spacing

        # Initialize transfer functions
        opTF = vtk.vtkPiecewiseFunction()
        colourTF = vtk.vtkColorTransferFunction()

        for p in tf:  # look through all of the transfer functions

            colourTF.AddRGBPoint(p[0], p[1], p[2], p[3])
            opTF.AddPoint(p[0], p[4])

        # Use ray cast method to render volume
        volMapper = vtk.vtkVolumeRayCastMapper()
        compFunc = vtk.vtkVolumeRayCastCompositeFunction()
        compFunc.SetCompositeMethodToInterpolateFirst()
        volMapper.SetVolumeRayCastFunction(compFunc)
        volMapper.SetInputConnection(imgData.GetOutputPort())

        # set the volume properties from the transfer function
        volProp = vtk.vtkVolumeProperty()
        volProp.SetColor(colourTF)
        volProp.SetScalarOpacity(opTF)
        volProp.ShadeOn()
        volProp.SetInterpolationTypeToLinear()

        actor = vtk.vtkVolume()
        actor.SetMapper(volMapper)
        actor.SetProperty(volProp)

        return actor

    def simpleDisplay(self, actors):
        # displays a volume type actor
        # input : actors list of actors

        # create a rendering window and renderer
        ren = vtk.vtkRenderer()
        renWin = vtk.vtkRenderWindow()
        renWin.AddRenderer(ren)
        renWin.SetSize(512, 512)

        # create a renderwindowinteractor
        iren = vtk.vtkRenderWindowInteractor()
        iren.SetRenderWindow(renWin)

        for actor in actors:
            ren.AddActor(actor)

        camera = ren.MakeCamera()
        camera.SetFocalPoint(1, 0, 1)
        camera.SetPosition(1, 1, 1)
        camera.SetViewUp(0, -1, 1)
        camera.OrthogonalizeViewUp()
        ren.SetActiveCamera(camera)
        ren.ResetCamera()

        # render
        renWin.Render()

        # enable user interface interactor
        iren.Initialize()
        iren.Start()

    def imageView(self, imgData, **kwargs):
        view = vtk.vtkImageViewer2()
        interactor = vtk.vtkRenderWindowInteractor()

        view.SetInputData(imgData)
        view.SetupInteractor(interactor)
        view.SetSliceOrientationToYZ()

        if 'zslice' in kwargs:
            view.SetSlice(kwargs['zslice'])
        if 'window' in kwargs:
            view.SetColorWindow(kwargs['window'])
        if 'level' in kwargs:
            view.SetColorLevel(kwargs['level'])

        view.Render()
        interactor.Start()


class mapperFuncs:

    def __init__(self):
        pass

    def getPolyDataMap(self, Data):
        mapper = vtk.vtkPolyDataMapper()
        try:
            mapper.SetInputData(Data)  # if it's vtkPolyData
        except TypeError:
            mapper.SetInputConnection(Data.GetOutputPort())  # if it's other vtkObject

        return mapper

    def get2DMapper(self, data, **kwargs):

        # Set up mapper according to input arguments
        mapper = vtk.vtkImageMapper()
        mapper.SetInputData(data.GetOutput())

        if 'zslice' in kwargs:
            mapper.SetZSlice(kwargs['zslice'])
        if 'window' in kwargs:
            mapper.SetColorWindow(kwargs['window'])
        if 'level' in kwargs:
            mapper.SetColorLevel(kwargs['level'])

        return mapper
