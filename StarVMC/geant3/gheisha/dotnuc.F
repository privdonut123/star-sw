*
* $Id: dotnuc.F,v 1.1.1.2 2009/02/01 17:10:27 fisyak Exp $
*
* $Log: dotnuc.F,v $
* Revision 1.1.1.2  2009/02/01 17:10:27  fisyak
* Merge with .DEV2
*
* Revision 1.1.1.1  2008/12/10 20:48:06  fisyak
* Merge with macos version
*
* Revision 1.1.1.1  2005/05/25 22:37:37  fisyak
* Alice version of geant3 (-minicern)
*
* Revision 1.1.1.1  2002/07/24 15:56:27  rdm
* initial import into CVS
*
* Revision 1.1.1.1  2002/06/16 15:18:39  hristov
* Separate distribution  of Geant3
*
* Revision 1.1.1.1  1999/05/18 15:55:18  fca
* AliRoot sources
*
* Revision 1.1.1.1  1995/10/24 10:21:06  cernlib
* Geant
*
*
#include "geant321/pilot.h"
*CMZ :  3.21/02 29/03/94  15.41.40  by  S.Giani
*-- Author :
      SUBROUTINE DOTNUC(C,S,C2,S2,PR,I)
C
#if !defined(CERNLIB_SINGLE)
      IMPLICIT DOUBLE PRECISION (A-H,O-Z)
#endif
      DIMENSION PR(50)
      K1 = 5*I - 4
      K2 = K1 + 1
      SA = PR(K1)
      SB = PR(K2)
      A      = SA*C - SB*S
      PR(K2) = SA*S + SB*C
      K2 = K2 + 1
      B = PR(K2)
      PR(K1) = A*C2 - B*S2
      PR(K2) = A*S2 + B*C2
      RETURN
      END
