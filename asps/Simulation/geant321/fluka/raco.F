*
* $Id: raco.F,v 1.1.1.1 2004/01/15 00:12:02 potekhin Exp $
*
* $Log: raco.F,v $
* Revision 1.1.1.1  2004/01/15 00:12:02  potekhin
*
* Revision 1.1.1.1  1997/11/03 15:29:23  atlascvs
* Importing CERNLIB version 08.21.
*
* Revision 1.1.1.1  1995/10/24 10:20:03  cernlib
* Geant
*
*
#include "geant321/pilot.h"
*CMZ :  3.21/02 29/03/94  15.41.44  by  S.Giani
*-- Author :
*$ CREATE RACO.FOR
*COPY RACO
*
*=== raco =============================================================*
*
      SUBROUTINE RACO(WX,WY,WZ)
#include "geant321/dblprc.inc"
#include "geant321/dimpar.inc"
#include "geant321/iounit.inc"
      REAL RNDM(2)
C********************************************************************
C     VERSION JUNE 81 BY             PERTTI AARNIO
C     LAST CHANGE 22. JUNE 81 BY     PERTTI AARNIO
C                                    HELSINKI UNIVERSITY OF
C                                    TECHNOLOGY, FINLAND
C
C
C     SUBROUTINE OF FLUKA TO GIVE THE DIRECTION COSINES OF RANDOM
C     UNIFORM (ISOTROPIC) DIRECTION IN THREE DIMENSIONAL SPACE.
C********************************************************************
C
 10   CALL GRNDM(RNDM,2)
      X=2.D0*RNDM(1)-1.D0
      Y=RNDM(2)
      X2=X*X
      Y2=Y*Y
      IF (X2+Y2.GT.1.D0) GO TO 10
      CFE=(X2-Y2)/(X2+Y2)
      SFE=2.D0*X*Y/(X2+Y2)
      CALL GRNDM(RNDM,1)
      Z=RNDM(1)
      Z2=Z*Z
      WZ=SQRT(Z-Z2)
      WX=2.D0*WZ*CFE
      WY=2.D0*WZ*SFE
      WZ=2.D0*Z-1.D0
      RETURN
      END
