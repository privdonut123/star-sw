*
* $Id: cadig.F,v 1.1.1.1 2004/01/15 00:12:19 potekhin Exp $
*
* $Log: cadig.F,v $
* Revision 1.1.1.1  2004/01/15 00:12:19  potekhin
*
* Revision 1.1.1.1  1997/11/03 15:30:56  atlascvs
* Importing CERNLIB version 08.21.
*
* Revision 1.1.1.1  1995/10/24 10:21:55  cernlib
* Geant
*
*
#include "geant321/pilot.h"
*CMZ :  3.21/04 23/02/95  14.46.01  by  S.Giani
*-- Author :
      FUNCTION CADIG(E)
C       THIS FUNCTION ADDS A TOLERANCE TO THE ARGUMENT
      ARG=ALOG10(E)
      ITR=5-IFIX(ARG)
      EPS=10.**ITR
      CADIG=1./EPS
      RETURN
      END
