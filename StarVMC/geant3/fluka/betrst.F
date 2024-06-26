*
* $Id: betrst.F,v 1.1.1.2 2009/02/01 17:10:16 fisyak Exp $
*
* $Log: betrst.F,v $
* Revision 1.1.1.2  2009/02/01 17:10:16  fisyak
* Merge with .DEV2
*
* Revision 1.1.1.1  2008/12/10 20:46:41  fisyak
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
*CMZ :  3.21/02 29/03/94  15.41.41  by  S.Giani
*-- Author :
*$ CREATE BETRST.FOR
*COPY BETRST
*
*=== betrst ===========================================================*
*
      FUNCTION BETRST ( GAM, ETA, X0, X1 )
 
#include "geant321/dblprc.inc"
#include "geant321/dimpar.inc"
#include "geant321/iounit.inc"
*
*----------------------------------------------------------------------*
*                                                                      *
*     New version:                                                     *
*     Created on 20 february 1991  by    Alfredo Ferrari & Paola Sala  *
*                                                   Infn - Milan       *
*                                                                      *
*     Last change on 20-feb-91     by    Alfredo Ferrari               *
*                                                                      *
*     Sampling from beta distribution in [X0,X1) :                     *
*                                                                      *
*     P(X) = X**(GAM-1.D0)*(1.D0-X)**(ETA-1)*GAMM(ETA+GAM)             *
*          / (GAMM(GAM*GAMM(ETA))                                      *
*                                                                      *
*----------------------------------------------------------------------*
*
      REAL RNDM(2)
*
*  +-------------------------------------------------------------------*
*  |
      IF ( X1 .LT. X0 ) THEN
         WRITE (LUNOUT,*)' Betrst: x1<x0, gam, eta', X1, X0, GAM, ETA
         WRITE (LUNERR,*)' Betrst: x1<x0, gam, eta', X1, X0, GAM, ETA
         X0 = MIN ( X0, ONEONE-0.05 )
         X1 = MIN ( ONEONE, X0/TWOTHI )
      END IF
*  |
*  +-------------------------------------------------------------------*
      GAMI  = 1.D+00 / GAM
      X0GAM = X0**GAM
      X1GAM = X1**GAM
      X0TO1 = 1.D+00 - X0
      CNORM = X1GAM - X0GAM
      ETAM1 = ETA - 1.D+00
      NTAM1 = NINT (ETA - 1.D+00)
*  +-------------------------------------------------------------------*
*  |
      IF ( ETAM1 - NTAM1 .NE. 0.D+00 ) THEN
*  |  +----------------------------------------------------------------*
*  |  |  First sample from X**(gam-1) and then reject according to
*  |  |  (1-X)**(eta-1)
  100    CONTINUE
            CALL GRNDM(RNDM,2)
            BETRST = ( RNDM (1) * CNORM + X0GAM )**GAMI
            REJE   = ( ( 1.D+00 - BETRST ) / X0TO1 )**ETAM1
         IF ( RNDM (2) .GE. REJE ) GO TO 100
*  |  |
*  |  +----------------------------------------------------------------*
*  |
*  +-------------------------------------------------------------------*
*  |
      ELSE
*  |  +----------------------------------------------------------------*
*  |  |  First sample from X**(gam-1) and then reject according to
*  |  |  (1-X)**(eta-1)
  200    CONTINUE
            CALL GRNDM(RNDM,2)
            BETRST = ( RNDM (1) * CNORM + X0GAM )**GAMI
            REJE   = ( ( 1.D+00 - BETRST ) / X0TO1 )**NTAM1
         IF ( RNDM (2) .GE. REJE ) GO TO 200
*  |  |
*  |  +----------------------------------------------------------------*
      END IF
*  |
*  +-------------------------------------------------------------------*
      RETURN
*=== End of function betrst ===========================================*
      END
