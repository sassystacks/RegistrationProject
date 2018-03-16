import vtk
import itk
import mdsc.loadimg as li
import mdsc.preprocessimg as pi
import mdsc.registerimg as re
import mdsc.renderimg as ri


class applyRegistration:

    def __init__(self, *args, **kwargs):
        pass

    def __repr__(self):
        pass


if __name__ == '__main__':
    import os
    import argparse

    topdir = '/home/richard//MyProjects/Registration/ImageData/NoFilter'
    stlList = os.listdir(topdir)
    stlList = [stlList[3], stlList[2]]
    print(stlList)
    #testFname = os.path.join(topdir, stlList[0])
    surfList = []
    readerList = []
    for f in stlList:
        args_dict = {'directory': topdir, 'filename': f}

        # Create instance of a reader and filetype
        instance = li.getImageData(**args_dict)
        try:
            reader = instance.reader
            ftype = instance.ftype
            readerList.append(reader)
        except:
            continue
        # Reads image, filter and decimate
        surf = re.applyRegistration().applyDecimation(reader, 0.1).GetOutput()

        surfList.append(surf)  # append surface to list

        # Call function to apply the ICP transformation
    icpOut = re.applyRegistration().applyICP(surfList, 200)

    # Apply transformation to data to obtain registration
    transformobj = re.applyRegistration().applyTransform(icpOut, surfList[1])
    #transformimg = applyRegistration().applyReslice(icpOut,reader).GetOutput()

    transformList = [transformobj, surfList[0]]

    pList = [{'opacity': 0.7, 'r': 0.1, 'g': 0.1, 'b': 0.6},
             {'opacity': 0.2, 'r': 0.9, 'g': 0.3, 'b': 0.2}]  # set properties rgb for actors

    # a = {'opacity': 0.5, 'r': 0.1, 'g': 0.1, 'b': 0.6}  # set properties rgb for actors
    # pList = [a for i in xrange(0, len(readerList))]  # loop through properties for each reader

    actorList = ri.actorimg3d().getActors(transformList, propList=pList)  # Get a list of actors
    ri.actorimg3d().simpleDisplay(actorList)

    #
    # k = len(actorList)
    # viewportlist = [[float(n)/k, 0, (n+1)/float(k), 1]
    #                 for n in xrange(0, k)]
    # ri.actorimg3d().viewportDisplay(actorList, viewportlist=viewportlist)
