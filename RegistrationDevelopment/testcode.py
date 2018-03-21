import vtk
import mdsc.loadimg as li
import mdsc.renderimg as ri
import vmtk
from vmtk import pypes


def writePolyDataOut(reader, OutFname):
    writer = vtk.vtkXMLPolyDataWriter()
    writer.SetFileName(OutFname)
    writer.SetInputData(reader.GetOutput())
    writer.Write()


# args_dict = {'directory': "/home/richard/MyProjects/Registration/RegistrationProject/RegistrationDevelopment/",
#              'filename': "registered.stl"}
# ins = li.getImageData(**args_dict)
# reader = ins.reader
# writePolyDataOut(reader, "registered.vtp")
# outfile = "centerLineSurface.vtp"
# infile = "centerLineSurface.vtp"
fnamelist = ['aaa1.vtp', 'registered.vtp', 'centerLineSurface.vtp']
readerlist = []
for f in fnamelist:
    args_dict = {'directory': "/home/richard/MyProjects/Tutorials/AAAregistrationV1_build/",
                 'filename': f}
    #
    reader = vtk.vtkXMLPolyDataReader()
    reader.SetFileName(f)
    reader.Update()
    readerlist.append(reader)

proplist = [{'opacity': .2, 'r': 0.1, 'g': 0.1, 'b': 0.9},
            {'opacity': .2, 'r': 0.1, 'g': 0.9, 'b': 0.1},
            {'opacity': 1, 'r': 0.9, 'g': 0.1, 'b': 0.1}]

actors = ri.actorimg3d().getActors(readerlist, propdict=proplist)

ri.actorimg3d().simpleDisplay(actors)
# args_string1 = "vmtkcenterlines -seedselector openprofiles -ifile {} -ofile foo_centerlines.vtp".format(
#     outfile)
# # args_string2 = """vmtksurfacereader -ifile aaa1.vtp --pipe vmtkcenterlines --pipe
# #                 vmtkrenderer --pipe vmtksurfaceviewer -opacity 0.25 --pipe
# #                 vmtksurfaceviewer -i @vmtkcenterlines.o -array MaximumInscribedSphereRadius"""
# mypype = pypes.PypeRun(args_string1)
# mySurface = mypype.GetScriptObject('vmtkcenterlines', '0').Centerlines
# print(mySurface)
# writePolyDataOut(mySurface, outfile)
