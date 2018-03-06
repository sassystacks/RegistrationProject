import vtk
from mdsc import loadimg as li
from mdsc import preprocessimg as pi
from mdsc import renderimg as ri


class applyRegistration:

    def __init__(self, *args, **kwargs):
        pass

    def __repr__(self):
        pass


if '__name__' == 'main':
    import os
    import argparse

    # Create instance of a reader and filetype
    instance = li.getImageData(**args_dict)
    reader = instance.reader
    ftype = instance.ftype

    actorList = applyNoiseStats().getActors([surfacePolyData])

    ri.actorimg3d().simpleDisplay(actorList)
