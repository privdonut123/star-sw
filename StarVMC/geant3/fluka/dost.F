*
* $Id: dost.F,v 1.1.1.2 2009/02/01 17:10:17 fisyak Exp $
*
* $Log: dost.F,v $
* Revision 1.1.1.2  2009/02/01 17:10:17  fisyak
* Merge with .DEV2
*
* Revision 1.1.1.1  2008/12/10 20:46:46  fisyak
* Merge with macos version
*
* Revision 1.1.1.1  2005/05/25 22:37:23  fisyak
* Alice version of geant3 (-minicern)
*
* Revision 1.1.1.1  2002/07/24 15:56:24  rdm
* initial import into CVS
*
* Revision 1.1.1.1  2002/06/16 15:18:36  hristov
* Separate distribution  of Geant3
*
* Revision 1.1.1.1  1999/05/18 15:55:15  fca
* AliRoot sources
*
* Revision 1.1.1.1  1995/10/24 10:19:54  cernlib
* Geant
*
*
#include "geant321/pilot.h"
*CMZ :  3.21/02 29/03/94  15.41.42  by  S.Giani
*-- Author :
*$ CREATE DOST.FOR
*COPY DOST
*                                                                      *
*=== dost==============================================================*
*                                                                      *
      FUNCTION DOST(I,Z)
 
#include "geant321/dblprc.inc"
#include "geant321/dimpar.inc"
#include "geant321/iounit.inc"
C--------------------------------------------------------------------
C SUBNAME = DOST
C--------------------------------------------------------------------
#include "geant321/eva0.inc"
C--------------------------------------------------------------------
      IF(Z-70.D0)1,2,2
    2 DOST=T(I,7)
    3 RETURN
    1 IF(Z-10.D0)5,5,6
    5 DOST=T(I,1)
      GOTO3
    6 N=.1D0*Z+1.D0
      X=10*N
      X=(X-Z)*.1D0
      DOST=X*T(I,N-1)+(1.D0-X)*T(I,N)
      GOTO3
      END
