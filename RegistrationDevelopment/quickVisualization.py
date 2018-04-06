import vtk
import mdsc.loadimg as li
import mdsc.renderimg as ri
import mdsc.preprocessimg as pi

args_dict = {'directory': "/home/richard/",
             'filename': "testOutput.vtk"}
ins = li.getImageData(**args_dict)
reader = ins.reader

#gauss = pi.processImageData().applyGauss(reader, std=1, radius=3)
cubes = pi.processImageData().applyDiscreteMarchingCubes(reader)
smooth = pi.processImageData().applySmoothPolyFilter(cubes, 40, 0.1)

proplist = [{'opacity': 1, 'r': 0, 'g': 1, 'b': 0}]

actors = ri.actorimg3d().getActors([smooth], propdict=proplist)

ri.actorimg3d().simpleDisplay(actors)

writer = vtk.vtkXMLPolyDataWriter()
writer.SetFileName("AortaMap.vtp")
writer.SetInputData(smooth.GetOutput())
writer.Write()
