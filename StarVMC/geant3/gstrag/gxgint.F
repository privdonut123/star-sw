*
* $Id: gxgint.F,v 1.1.1.2 2009/02/01 17:10:33 fisyak Exp $
*
* $Log: gxgint.F,v $
* Revision 1.1.1.2  2009/02/01 17:10:33  fisyak
* Merge with .DEV2
*
* Revision 1.1.1.1  2008/12/10 20:48:50  fisyak
* Merge with macos version
*
* Revision 1.1.1.1  2005/05/25 22:37:56  fisyak
* Alice version of geant3 (-minicern)
*
* Revision 1.2  2003/11/28 11:23:56  brun
* New version of geant321 with all geant3 routines renamed from G to G3
*
* Revision 1.1.1.1  2002/07/24 15:56:27  rdm
* initial import into CVS
*
* Revision 1.1.1.1  2002/06/16 15:18:41  hristov
* Separate distribution  of Geant3
*
* Revision 1.1.1.1  1999/05/18 15:55:21  fca
* AliRoot sources
*
* Revision 1.1.1.1  1995/10/24 10:21:39  cernlib
* Geant
*
*
#include "geant321/pilot.h"
*CMZ :  3.21/02 29/03/94  15.41.25  by  S.Giani
*-- Author :
      FUNCTION G3XGINT(EXT,A,B,EPS)
*
*    Gauss integration routine
*
#include "geant321/gcunit.inc"
#if !defined(CERNLIB_SINGLE)
      DOUBLE PRECISION OTB,U1,U2,W1,W2,Y
#endif
      EXTERNAL EXT
      PARAMETER (U1=.3399810,U2=.8611363,W1=.6521452,W2=.3478548)
*
*-----------------------------------------------------------------------
*
      N      = 5
      OTB    = 0
      DHALF  = (B-A)/N
   10 CONTINUE
*
*   Convergence loop
*
      Y = OTB
      OTB = 0
      D = DHALF
      DHALF = 0.5*D
      CENTX = A-DHALF
      D1 = U1*DHALF
      D2 = U2*DHALF
*
*   Piecewise integration loop
*
      DO 20 I=1,N
         CENTX=CENTX+D
         OTB = OTB +W2*(EXT(CENTX-D2)+EXT(CENTX+D2)) +W1*(EXT(CENTX-D1)
     +   +EXT(CENTX+D1))
   20 CONTINUE
      OTB=OTB*DHALF
*
      IF(EPS.GT.0.AND.ABS(OTB-Y).GT.ABS(EPS*OTB)) THEN
         N = 2*N
         IF (N.GT.100 000) THEN
*
*   Check N>100 000
*
            WRITE(CHMAIL,10000) EPS, ABS((OTB-Y)/OTB)
            CALL GMAIL(1,0)
            GO TO 30
         END IF
         GOTO 10
      ENDIF
*
   30 CONTINUE
      G3XGINT=OTB
10000 FORMAT('*** G3XGINT : required precision ',G10.3,
     +      ' obtained precision ',G10.3)
      END
