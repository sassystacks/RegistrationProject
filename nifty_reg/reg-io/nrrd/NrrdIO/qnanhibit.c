/*
  NrrdIO: stand-alone code for basic nrrd functionality
  Copyright (C) 2005  Gordon Kindlmann
  Copyright (C) 2004, 2003, 2002, 2001, 2000, 1999, 1998  University of Utah
 
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any
  damages arising from the use of this software.
 
  Permission is granted to anyone to use this software for any
  purpose, including commercial applications, and to alter it and
  redistribute it freely, subject to the following restrictions:
 
  1. The origin of this software must not be misrepresented; you must
     not claim that you wrote the original software. If you use this
     software in a product, an acknowledgment in the product
     documentation would be appreciated but is not required.
 
  2. Altered source versions must be plainly marked as such, and must
     not be misrepresented as being the original software.
 
  3. This notice may not be removed or altered from any source distribution.
*/

#include <stdio.h>
#include <float.h>

int
main(int argc, char *argv[])
{
  char *me;
  float pinf, qnan;
  int i;
  
  me = argv[0];
  if (sizeof(float) != sizeof(int))
    {
    fprintf(stderr, "%s: MADNESS:  sizeof(float)=%d != sizeof(int)=%d\n",
            me, (int)sizeof(float), (int)sizeof(int)); 
    return -1;
    }
  pinf = FLT_MAX;
  pinf = pinf*pinf;
  qnan = pinf/pinf;
  i = *(int*)(&qnan);
  printf("-DTEEM_QNANHIBIT=%d\n", (i >> 22) & 1);
  return (int)((i >> 22) & 1);
}
