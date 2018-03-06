import argparse
import os

class commandargs(object):

    def __init__(self,**kwargs):

        cwd = os.getcwd()
        parser = argparse.ArgumentParser()
        parser.add_argument('directory', help='Manditory to enter a folder name')
        parser.add_argument('-w','--window', nargs='?', default=1000, type=int, help='This changes the grey scale value (default is 1000)')
        parser.add_argument('-l','--level', nargs='?', default=0, type=int, help='This changes the window level value (default is 0)')
        parser.add_argument('-z','--zslice', nargs='?', default=0, type=int, help='This changes the initial slice value (default is 0)')
        parser.add_argument('-wd','--width', nargs='?', default=512, type=int, help='This changes the width of display (default is 512)')
        parser.add_argument('-ht','--height', nargs='?', default=512, type=int, help='This changes the height of display (default is 512)')
        parser.add_argument('-sj','--slicejump', nargs='?', default=1, type=int, help='This changes the number of slices to scroll (default is 1)')
        parser.add_argument('-f','--filename', help='Add a filename to directory incase of multiple .nii files')
        parser.add_argument('-fi','--filter', help='Add the type of filter to apply to the image, options are ("Gauss","Median")')

        args = parser.parse_args()
        self.args_dict = vars(args)
