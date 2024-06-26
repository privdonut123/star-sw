*
* $Id: ggperp.F,v 1.1.1.2 2009/02/01 17:10:24 fisyak Exp $
*
* $Log: ggperp.F,v $
* Revision 1.1.1.2  2009/02/01 17:10:24  fisyak
* Merge with .DEV2
*
* Revision 1.1.1.1  2008/12/10 20:47:44  fisyak
* Merge with macos version
*
* Revision 1.1.1.1  2005/05/25 22:37:35  fisyak
* Alice version of geant3 (-minicern)
*
* Revision 1.2  2003/11/28 11:23:56  brun
* New version of geant321 with all geant3 routines renamed from G to G3
*
* Revision 1.1.1.1  2002/07/24 15:56:25  rdm
* initial import into CVS
*
* Revision 1.1.1.1  2002/06/16 15:18:38  hristov
* Separate distribution  of Geant3
*
* Revision 1.2  2001/03/20 06:36:27  alibrary
* 100 parameters now allowed for geant shapes
*
* Revision 1.1.1.1  1999/05/18 15:55:17  fca
* AliRoot sources
*
* Revision 1.1.1.1  1995/10/24 10:20:50  cernlib
* Geant
*
*
#include "geant321/pilot.h"
*FCA :          05/01/99  09:58:02 by  Federico Carminati
*               Effectively print the message when a shape is
*               not implemented
*CMZ :  3.21/02 29/03/94  15.41.28  by  S.Giani
*-- Author :
      SUBROUTINE G3GPERP (X,U,IERR)
C.
C.    ****************************************************************
C.    *                                                              *
C.    *  This routine solves the general problem of calculating the  *
C.    *  unit vector normal to the surface of the current volume at  *
C.    *  the point X. The result is returned in the array U.  X is   *
C.    *  assumed to be on or near a boundary of the current volume.  *
C.    *  The current volume is indicated by the common /GCVOLU/.     *
C.    *  U points from inside to outside in that neighbourhood.      *
C.    *  If X is equidistant to more than one boundary (in a corner) *
C.    *  an arbitrary choice is made based upon the order of         *
C.    *  precedence implied by the IF statements below.  If the      *
C.    *  routine fails to find the unit normal, it returns with      *
C.    *  IERR=1, otherwise IERR=0.                                   *
C.    *                                                              *
C.    *   Called by : GSURFP, GDSTEP                                 *
C.    *   Authors   : F.Carminati, R.Jones, F.Ohlsson-Malek          *
C.    *                                                              *
C.    ****************************************************************
#include "geant321/gcvolu.inc"
#include "geant321/gconsp.inc"
#include "geant321/gcbank.inc"
#include "geant321/gcshno.inc"
#include "geant321/gctmed.inc"
#include "geant321/gcunit.inc"
      DIMENSION X(3),U(3),XL(3),UL(3),DXL(3),PAR(100),SPAR(100),ATT(20)
      DIMENSION PERP(10)
#if !defined(CERNLIB_SINGLE)
      DOUBLE PRECISION PERP,PMIN0
      DOUBLE PRECISION PAR,DXL,RHO,R,RINV,PHI,THE
      DOUBLE PRECISION PHI1,PHI2,THE1,THE2,XWID
      DOUBLE PRECISION GUARD,DPHI,PHI0,SPHI0,CPHI0
      DOUBLE PRECISION FACT,CALPH,SALPH,TALPH
      DOUBLE PRECISION RAT,RATL,RATH,H,BL,TL,DX,DY,DZ,DU
      DOUBLE PRECISION UU0,VV0,UU,W1,W2,W3,W4
      DOUBLE PRECISION SEW1,SEW2,SEW3,SEW4
      DOUBLE PRECISION TAN1,TAN2,TAN3,TAN4
      DOUBLE PRECISION SEC1,SEC2,SEC3,SEC4
      DOUBLE PRECISION U0,V0,U1,U1L,U2,U2L
      DOUBLE PRECISION ONE,TWO
      DOUBLE PRECISION DSECT,ZERO,FULL,FULL10,DBY2
#endif
      LOGICAL LNTFOU
      PARAMETER (ONE=1,TWO=2)
      PARAMETER (ZERO=0.,DBY2=0.5,FULL=360.,FULL10=3600.)
C.
C.    ------------------------------------------------------------------
C.
      LNTFOU = .FALSE.
*
* *** Transform current point into local reference system
      CALL G3MTOD(X,XL,1)
      DXL(1) = XL(1)
      DXL(2) = XL(2)
      DXL(3) = XL(3)
*
* *** Fetch the parameters of the current volume
      JVO = LQ(JVOLUM-LVOLUM(NLEVEL))
      IN = LINDEX(NLEVEL)
      IF (NLEVEL.GT.1) THEN
        JVOM = LQ(JVOLUM-LVOLUM(NLEVEL-1))
        JIN = LQ(JVOM-IN)
      ENDIF
      ISH = Q(JVO+2)
      NIN = Q(JVO+3)
      IF (NLEVEL.LT.NLDEV(NLEVEL)) THEN
        JPAR = 0
      ELSE
*     (case with structure JVOLUM locally developed)
        JPAR = LQ(LQ(JVOLUM-LVOLUM(NLDEV(NLEVEL))))
        IF (NLEVEL.EQ.NLDEV(NLEVEL)) GO TO 20
        DO 10  ILEV = NLDEV(NLEVEL), NLEVEL-1
          IF (IQ(JPAR+1).EQ.0) THEN
            JPAR = LQ(JPAR-LINDEX(ILEV+1))
            IF (JPAR.EQ.0) GO TO 20
          ELSE IF (IQ(JPAR-3).GT.1) THEN
            JPAR = LQ(JPAR-LINDEX(ILEV+1))
          ELSE
            JPAR = LQ(JPAR-1)
          ENDIF
          IF (ILEV.EQ.NLEVEL-1) THEN
            JPAR = JPAR + 5
            NPAR = IQ(JPAR)
            CALL UCOPY (Q(JPAR+1), SPAR, NPAR)
            DO 100 I=1,NPAR
                PAR(I)=SPAR(I)
  100       CONTINUE
          ENDIF
   10   CONTINUE
        GO TO 30
      ENDIF
*     (normal case)
   20 CONTINUE
      CALL GFIPAR(JVO,JIN,IN,NPAR,NATT,SPAR,ATT)
      DO 101 I=1,NPAR
           PAR(I)=SPAR(I)
  101 CONTINUE
   30 CONTINUE
*
* *** Case of the BOX:
      IF (ISH.EQ.NSBOX) THEN
        PERP(1) = ABS(ABS(DXL(1))-PAR(1))
        PERP(2) = ABS(ABS(DXL(2))-PAR(2))
        PERP(3) = ABS(ABS(DXL(3))-PAR(3))
        PMIN0 = MIN(PERP(1),PERP(2),PERP(3))
        IF (PERP(1).EQ.PMIN0) THEN
          UL(1) = SIGN(ONE,DXL(1))
          UL(2) = 0.
          UL(3) = 0.
        ELSE IF (PERP(2).EQ.PMIN0) THEN
          UL(1) = 0.
          UL(2) = SIGN(ONE,DXL(2))
          UL(3) = 0.
        ELSE IF (PERP(3).EQ.PMIN0) THEN
          UL(1) = 0.
          UL(2) = 0.
          UL(3) = SIGN(ONE,DXL(3))
        ELSE
          LNTFOU=.TRUE.
        ENDIF
*
* *** Case of the TUBE, TUBeSection:
      ELSE IF (ISH.EQ.NSTUBE.OR.ISH.EQ.NSTUBS) THEN
        RHO = SQRT(DXL(1)**2 + DXL(2)**2)
        PERP(1) = ABS(RHO-PAR(1))
        PERP(2) = ABS(RHO-PAR(2))
        PERP(3) = ABS(ABS(DXL(3))-PAR(3))
        IF (ISH.EQ.NSTUBE) THEN
          PMIN0 = MIN(PERP(1),PERP(2),PERP(3))
        ELSE
          PHI = ATAN2(DXL(2),DXL(1))
          IF (PHI.LT.0.) PHI = PHI+TWOPI
          PHI1 = MOD(PAR(4)+FULL10,FULL)*DEGRAD
          PERP(4) = ABS(PHI-PHI1)
          IF (PERP(4).GT.PI) PERP(4) = TWOPI-PERP(4)
          PHI2 = MOD(PAR(5)+FULL10,FULL)*DEGRAD
          PERP(5) = ABS(PHI-PHI2)
          IF (PERP(5).GT.PI) PERP(5) = TWOPI-PERP(5)
          PERP(4) = PERP(4)*RHO
          PERP(5) = PERP(5)*RHO
          PMIN0 = MIN(PERP(1),PERP(2),PERP(3),PERP(4),PERP(5))
        ENDIF
        IF (PERP(1).EQ.PMIN0) THEN
          UL(1) = -DXL(1)/RHO
          UL(2) = -DXL(2)/RHO
          UL(3) = 0.
        ELSE IF (PERP(2).EQ.PMIN0) THEN
          UL(1) = DXL(1)/RHO
          UL(2) = DXL(2)/RHO
          UL(3) = 0.
        ELSE IF (PERP(3).EQ.PMIN0) THEN
          UL(1) = 0.
          UL(2) = 0.
          UL(3) = SIGN(ONE,DXL(3))
        ELSE IF (PERP(4).EQ.PMIN0) THEN
          UL(1) = SIN(PHI1)
          UL(2) = -COS(PHI1)
          UL(3) = 0.
        ELSE IF (PERP(5).EQ.PMIN0) THEN
          UL(1) = -SIN(PHI2)
          UL(2) = COS(PHI2)
          UL(3) = 0.
        ELSE
          LNTFOU=.TRUE.
        ENDIF
*
* *** Case of the CONE, CONeSection:
      ELSE IF (ISH.EQ.NSCONE.OR.ISH.EQ.NSCONS) THEN
        RHO  = SQRT(DXL(1)**2 + DXL(2)**2)
        TAN1 = (PAR(4)-PAR(2))/(TWO*PAR(1))
        SEC1 = SQRT(ONE+TAN1**2)
        U1   = RHO-DXL(3)*TAN1
        U1L  = PAR(4)-PAR(1)*TAN1
        TAN2 = (PAR(5)-PAR(3))/(TWO*PAR(1))
        SEC2 = SQRT(ONE+TAN2**2)
        U2   = RHO-DXL(3)*TAN2
        U2L  = PAR(5)-PAR(1)*TAN2
        PERP(1) = ABS(ABS(DXL(3))-PAR(1))
        PERP(2) = ABS(U1-U1L)/SEC1
        PERP(3) = ABS(U2-U2L)/SEC2
        IF (ISH.EQ.NSCONE) THEN
          PMIN0 = MIN(PERP(1),PERP(2),PERP(3))
        ELSE
          PHI = ATAN2(DXL(2),DXL(1))
          IF (PHI.LT.0.) PHI = PHI+TWOPI
          PHI1 = MOD(PAR(6)+FULL10,FULL)*DEGRAD
          PERP(4) = ABS(PHI-PHI1)
          IF (PERP(4).GT.PI) PERP(4) = TWOPI-PERP(4)
          PHI2 = MOD(PAR(7)+FULL10,FULL)*DEGRAD
          PERP(5) = ABS(PHI-PHI2)
          IF (PERP(5).GT.PI) PERP(5) = TWOPI-PERP(5)
          PERP(4) = PERP(4)*RHO
          PERP(5) = PERP(5)*RHO
          PMIN0 = MIN(PERP(1),PERP(2),PERP(3),PERP(4),PERP(5))
        ENDIF
        IF (PERP(1).EQ.PMIN0) THEN
          UL(1) = 0.
          UL(2) = 0.
          UL(3) = SIGN(ONE,DXL(3))
        ELSE IF (PERP(2).EQ.PMIN0) THEN
          RHO = RHO*SEC1
          UL(1) = -DXL(1)/RHO
          UL(2) = -DXL(2)/RHO
          UL(3) = TAN1/SEC1
        ELSE IF (PERP(3).EQ.PMIN0) THEN
          RHO = RHO*SEC2
          UL(1) = DXL(1)/RHO
          UL(2) = DXL(2)/RHO
          UL(3) = -TAN2/SEC2
        ELSE IF (PERP(4).EQ.PMIN0) THEN
          UL(1) = SIN(PHI1)
          UL(2) = -COS(PHI1)
          UL(3) = 0.
        ELSE IF (PERP(5).EQ.PMIN0) THEN
          UL(1) = -SIN(PHI2)
          UL(2) = COS(PHI2)
          UL(3) = 0.
        ELSE
          LNTFOU=.TRUE.
        ENDIF
*
* *** Case of the PolyCONe:
      ELSE IF (ISH.EQ.NSPCON) THEN
        PERP(1) = ABS(DXL(3)-PAR(4))
        DO 400 I=7,NPAR,3
          PERP(2) = ABS(DXL(3)-PAR(I))
          IF (PERP(2).GT.PERP(1)) GOTO 401
          PERP(1) = PERP(2)
  400   CONTINUE
  401   I = I-3
        IF (I.GT.4) THEN
          PERP(1) = 100.
          RHO  = SQRT(DXL(1)**2 + DXL(2)**2)
          DZ   = PAR(I)-PAR(I-3)+1.e-10
          TAN1 = (PAR(I+1)-PAR(I-2))/DZ
          SEC1 = SQRT(ONE+TAN1**2)
          U1   = RHO-DXL(3)*TAN1
          U1L  = PAR(I+1)-PAR(I)*TAN1
          TAN2 = (PAR(I+2)-PAR(I-1))/DZ
          SEC2 = SQRT(ONE+TAN2**2)
          U2   = RHO-DXL(3)*TAN2
          U2L  = PAR(I+2)-PAR(I)*TAN2
          GUARD = MAX(DXL(3)-PAR(I),ZERO)
          PERP(3) = ABS(U1-U1L)/SEC1 + GUARD*SEC1
          PERP(4) = ABS(U2-U2L)/SEC2 + GUARD*SEC2
        ELSE
          PERP(3) = 100.
          PERP(4) = 100.
        ENDIF
        IF (I.LT.NPAR-2) THEN
          PERP(2) = 100.
          RHO = SQRT(DXL(1)**2 + DXL(2)**2)
          DZ  = PAR(I+3)-PAR(I)+1.e-10
          TAN3 = (PAR(I+4)-PAR(I+1))/DZ
          SEC3 = SQRT(ONE+TAN3**2)
          U1   = RHO-DXL(3)*TAN3
          U1L  = PAR(I+1)-PAR(I)*TAN3
          TAN4 = (PAR(I+5)-PAR(I+2))/DZ
          SEC4 = SQRT(ONE+TAN4**2)
          U2   = RHO-DXL(3)*TAN4
          U2L  = PAR(I+2)-PAR(I)*TAN4
          GUARD = MAX(PAR(I)-DXL(3),ZERO)
          PERP(5) = ABS(U1-U1L)/SEC3 + GUARD*SEC3
          PERP(6) = ABS(U2-U2L)/SEC4 + GUARD*SEC4
        ELSE
          PERP(5) = 100.
          PERP(6) = 100.
        ENDIF
        PHI = ATAN2(DXL(2),DXL(1))
        IF (PHI.LT.0.) PHI = PHI+TWOPI
        PHI1 = MOD(PAR(1)+FULL10,FULL)*DEGRAD
        PERP(7) = ABS(PHI-PHI1)
        IF (PERP(7).GT.PI) PERP(7) = TWOPI-PERP(7)
        PHI2 = MOD(PAR(1)+PAR(2)+FULL10,FULL)*DEGRAD
        PERP(8) = ABS(PHI-PHI2)
        IF (PERP(8).GT.PI) PERP(8) = TWOPI-PERP(8)
        PERP(7) = PERP(7)*RHO
        PERP(8) = PERP(8)*RHO
        PMIN0 = MIN(PERP(1),PERP(2),PERP(3),PERP(4),
     +             PERP(5),PERP(6),PERP(7),PERP(8))
        IF (PERP(1).EQ.PMIN0) THEN
          UL(1) = 0.
          UL(2) = 0.
          UL(3) = -1.
        ELSE IF (PERP(2).EQ.PMIN0) THEN
          UL(1) = 0.
          UL(2) = 0.
          UL(3) = 1.
        ELSE IF (PERP(3).EQ.PMIN0) THEN
          RHO = RHO*SEC1
          UL(1) = -DXL(1)/RHO
          UL(2) = -DXL(2)/RHO
          UL(3) = TAN1/SEC1
        ELSE IF (PERP(4).EQ.PMIN0) THEN
          RHO = RHO*SEC2
          UL(1) = DXL(1)/RHO
          UL(2) = DXL(2)/RHO
          UL(3) = -TAN2/SEC2
        ELSE IF (PERP(5).EQ.PMIN0) THEN
          RHO = RHO*SEC3
          UL(1) = -DXL(1)/RHO
          UL(2) = -DXL(2)/RHO
          UL(3) = TAN3/SEC3
        ELSE IF (PERP(6).EQ.PMIN0) THEN
          RHO = RHO*SEC4
          UL(1) = DXL(1)/RHO
          UL(2) = DXL(2)/RHO
          UL(3) = -TAN4/SEC4
        ELSE IF (PERP(7).EQ.PMIN0) THEN
          UL(1) = SIN(PHI1)
          UL(2) = -COS(PHI1)
          UL(3) = 0.
        ELSE IF (PERP(8).EQ.PMIN0) THEN
          UL(1) = -SIN(PHI2)
          UL(2) = COS(PHI2)
          UL(3) = 0.
        ELSE
          LNTFOU=.TRUE.
        ENDIF
*
* *** Case of the PolyGON:
      ELSE IF (ISH.EQ.NSPGON) THEN
        RHO = SQRT(DXL(1)**2+DXL(2)**2)
        PHI = ATAN2(DXL(2),DXL(1))
        IF (PHI.LT.0.) PHI = PHI+TWOPI
        DPHI = MOD(PHI*RADDEG-PAR(1)+FULL10,FULL)
        PDIV = PAR(2)/PAR(3)
        DSECT = INT(DPHI/PDIV + ONE)
        IF (DSECT.GT.PAR(3)) THEN
          IF (DPHI.GT.(180.+PAR(2)*DBY2)) THEN
            DSECT = ONE
          ELSE
            DSECT = PAR(3)
          ENDIF
        ENDIF
        PHI0 = MOD(PAR(1)+(DSECT-DBY2)*PDIV+FULL10,FULL)*DEGRAD
        SPHI0 = SIN(PHI0)
        CPHI0 = COS(PHI0)
        U0 = DXL(1)*CPHI0 + DXL(2)*SPHI0
        V0 = DXL(2)*CPHI0 - DXL(1)*SPHI0
        PERP(1) = ABS(DXL(3)-PAR(5))
        DO 500 I=8,NPAR,3
          PERP(2) = ABS(DXL(3)-PAR(I))
          IF (PERP(2).GT.PERP(1)) GOTO 501
          PERP(1) = PERP(2)
  500   CONTINUE
  501   I = I-3
        IF (I.GT.5) THEN
          PERP(1) = 100.
          DZ   = PAR(I)-PAR(I-3)+1.e-10
          TAN1 = (PAR(I+1)-PAR(I-2))/DZ
          SEC1 = SQRT(ONE+TAN1**2)
          U1   = U0-DXL(3)*TAN1
          U1L  = PAR(I+1)-PAR(I)*TAN1
          TAN2 = (PAR(I+2)-PAR(I-1))/DZ
          SEC2 = SQRT(ONE+TAN2**2)
          U2   = U0-DXL(3)*TAN2
          U2L  = PAR(I+2)-PAR(I)*TAN2
          GUARD = MAX(DXL(3)-PAR(I),ZERO)
          PERP(3) = ABS(U1-U1L)/SEC1 + GUARD*SEC1
          PERP(4) = ABS(U2-U2L)/SEC2 + GUARD*SEC2
        ELSE
          PERP(3) = 100.
          PERP(4) = 100.
        ENDIF
        IF (I.LT.NPAR-2) THEN
          PERP(2) = 100.
          DZ   = PAR(I+3)-PAR(I)+1.e-10
          TAN3 = (PAR(I+4)-PAR(I+1))/DZ
          SEC3 = SQRT(ONE+TAN3**2)
          U1   = U0-DXL(3)*TAN3
          U1L  = PAR(I+1)-PAR(I)*TAN3
          TAN4 = (PAR(I+5)-PAR(I+2))/DZ
          SEC4 = SQRT(ONE+TAN4**2)
          U2   = U0-DXL(3)*TAN4
          U2L  = PAR(I+2)-PAR(I)*TAN4
          GUARD = MAX(PAR(I)-DXL(3),ZERO)
          PERP(5) = ABS(U1-U1L)/SEC3 + GUARD*SEC3
          PERP(6) = ABS(U2-U2L)/SEC4 + GUARD*SEC4
        ELSE
          PERP(5) = 100.
          PERP(6) = 100.
        ENDIF
        PHI1 = MOD(PAR(1)+FULL10,FULL)*DEGRAD
        PERP(7) = ABS(PHI-PHI1)
        IF (PERP(7).GT.PI) PERP(7) = TWOPI-PERP(7)
        PHI2 = MOD(PAR(1)+PAR(2)+FULL10,FULL)*DEGRAD
        PERP(8) = ABS(PHI-PHI2)
        IF (PERP(8).GT.PI) PERP(8) = TWOPI-PERP(8)
        PERP(7) = PERP(7)*RHO
        PERP(8) = PERP(8)*RHO
        PMIN0 = MIN(PERP(1),PERP(2),PERP(3),PERP(4),
     +             PERP(5),PERP(6),PERP(7),PERP(8))
        IF (PERP(1).EQ.PMIN0) THEN
          UL(1) = 0.
          UL(2) = 0.
          UL(3) = -1.
        ELSE IF (PERP(2).EQ.PMIN0) THEN
          UL(1) = 0.
          UL(2) = 0.
          UL(3) = 1.
        ELSE IF (PERP(3).EQ.PMIN0) THEN
          FACT = ONE/SEC1
          UL(1) = -CPHI0*FACT
          UL(2) = -SPHI0*FACT
          UL(3) = TAN1*FACT
        ELSE IF (PERP(4).EQ.PMIN0) THEN
          FACT = ONE/SEC2
          UL(1) = CPHI0*FACT
          UL(2) = SPHI0*FACT
          UL(3) = -TAN2*FACT
        ELSE IF (PERP(5).EQ.PMIN0) THEN
          FACT = ONE/SEC3
          UL(1) = -CPHI0*FACT
          UL(2) = -SPHI0*FACT
          UL(3) = TAN3*FACT
        ELSE IF (PERP(6).EQ.PMIN0) THEN
          FACT = ONE/SEC4
          UL(1) = CPHI0*FACT
          UL(2) = SPHI0*FACT
          UL(3) = -TAN4*FACT
        ELSE IF (PERP(7).EQ.PMIN0) THEN
          UL(1) = SIN(PHI1)
          UL(2) = -COS(PHI1)
          UL(3) = 0.
        ELSE IF (PERP(8).EQ.PMIN0) THEN
          UL(1) = -SIN(PHI2)
          UL(2) = COS(PHI2)
          UL(3) = 0.
        ELSE
          LNTFOU=.TRUE.
        ENDIF
*
* *** Case of the SPHEre:
      ELSE IF (ISH.EQ.NSSPHE) THEN
        R = SQRT(DXL(1)**2+DXL(2)**2+DXL(3)**2)
        RHO = SQRT(DXL(1)**2+DXL(2)**2)
        THE = ATAN2(RHO,DXL(3))
        PHI = ATAN2(DXL(2),DXL(1))
        IF (PHI.LT.0.) PHI = PHI+TWOPI
        THE1 = MOD(PAR(3)+FULL10,FULL)*DEGRAD
        THE2 = MOD(PAR(4)+FULL10,FULL)*DEGRAD
        PHI1 = MOD(PAR(5)+FULL10,FULL)*DEGRAD
        PHI2 = MOD(PAR(6)+FULL10,FULL)*DEGRAD
        PERP(1) = ABS(R-PAR(1))
        PERP(2) = ABS(R-PAR(2))
        PERP(3) = ABS(THE-THE1)*R
        PERP(4) = ABS(THE-THE2)*R
        PERP(5) = ABS(PHI-PHI1)
        IF (PERP(5).GT.PI) PERP(5) = TWOPI-PERP(5)
        PERP(5) = PERP(5)*RHO
        PERP(6) = ABS(PHI-PHI2)
        IF (PERP(6).GT.PI) PERP(6) = TWOPI-PERP(6)
        PERP(6) = PERP(6)*RHO
        PMIN0 = MIN(PERP(1),PERP(2),PERP(3),PERP(4),PERP(5),PERP(6))
        IF (PERP(1).EQ.PMIN0) THEN
          RINV = ONE/R
          UL(1) = -DXL(1)*RINV
          UL(2) = -DXL(2)*RINV
          UL(3) = -DXL(3)*RINV
        ELSE IF (PERP(2).EQ.PMIN0) THEN
          RINV = ONE/R
          UL(1) = DXL(1)*RINV
          UL(2) = DXL(2)*RINV
          UL(3) = DXL(3)*RINV
        ELSE IF (PERP(3).EQ.PMIN0) THEN
          UL(1) = -COS(THE1)*COS(PHI)
          UL(2) = -COS(THE1)*SIN(PHI)
          UL(3) = +SIN(THE1)
        ELSE IF (PERP(4).EQ.PMIN0) THEN
          UL(1) = +COS(THE2)*COS(PHI)
          UL(2) = +COS(THE2)*SIN(PHI)
          UL(3) = -SIN(THE2)
        ELSE IF (PERP(5).EQ.PMIN0) THEN
          UL(1) = +SIN(PHI1)
          UL(2) = -COS(PHI1)
          UL(3) = 0
        ELSE IF (PERP(6).EQ.PMIN0) THEN
          UL(1) = -SIN(PHI2)
          UL(2) = +COS(PHI2)
          UL(3) = 0
        ELSE
          LNTFOU=.TRUE.
        ENDIF
*
* *** Case of the PARAllelpiped:
***************************************************************
*  Warning:  the parameters for this shape are NOT stored in  *
*  the data structure as the user supplies them.  Rather, the *
*  user supplies PAR(4)=alph, PAR(5)=the, PAR(6)=phi, and the *
*  data structure contains PAR(4)=Tan(alph), PAR(5)=Tan(the)* *
*  Cos(phi), PAR(6)=Tan(the)*Sin(phi).                        *
***************************************************************
      ELSE IF (ISH.EQ.NSPARA) THEN
        DX = PAR(5)
        DY = PAR(6)
        U0 = DXL(1)-DX*DXL(3)
        V0 = DXL(2)-DY*DXL(3)
        CALPH = ONE/SQRT(ONE+PAR(4)**2)
        SALPH = -CALPH*PAR(4)
        U1 = U0*CALPH+V0*SALPH
        U1L = PAR(1)*CALPH
        PERP(1) = ABS(ABS(U1)-U1L)
        PERP(2) = ABS(ABS(V0)-PAR(2))
        PERP(3) = ABS(ABS(DXL(3))-PAR(3))
        PMIN0 = MIN(PERP(1),PERP(2),PERP(3))
        IF (PERP(1).EQ.PMIN0) THEN
          DU = DX*CALPH+DY*SALPH
          FACT = SIGN(ONE/SQRT(ONE+DU**2),U1)
          UL(1) = CALPH*FACT
          UL(2) = SALPH*FACT
          UL(3) = -DU*FACT
        ELSE IF (PERP(2).EQ.PMIN0) THEN
          FACT = SIGN(ONE/SQRT(ONE+DY**2),V0)
          UL(1) = 0.
          UL(2) = FACT
          UL(3) = -DY*FACT
        ELSE IF (PERP(3).EQ.PMIN0) THEN
          UL(1) = 0.
          UL(2) = 0.
          UL(3) = SIGN(ONE,DXL(3))
        ELSE
          LNTFOU=.TRUE.
        ENDIF
*
* *** Case of the trapezoid TRD1
      ELSE IF (ISH.EQ.NSTRD1) THEN
        DZ   = TWO*PAR(4)+1.e-10
        TAN1 = (PAR(2)-PAR(1))/DZ
        SEC1 = SQRT(ONE+TAN1**2)
        U1   = ABS(DXL(1))-DXL(3)*TAN1
        U1L  = PAR(2)-PAR(4)*TAN1
        PERP(1) = ABS(U1-U1L)/SEC1
        PERP(2) = ABS(ABS(DXL(2))-PAR(3))
        PERP(3) = ABS(ABS(DXL(3))-PAR(4))
        PMIN0 = MIN(PERP(1),PERP(2),PERP(3))
        IF (PERP(1).EQ.PMIN0) THEN
          FACT = ONE/SEC1
          UL(1) = SIGN(FACT,DXL(1))
          UL(2) = 0.
          UL(3) = -TAN1*FACT
        ELSE IF (PERP(2).EQ.PMIN0) THEN
          UL(1) = 0.
          UL(2) = SIGN(ONE,DXL(2))
          UL(3) = 0.
        ELSE IF (PERP(3).EQ.PMIN0) THEN
          UL(1) = 0.
          UL(2) = 0.
          UL(3) = SIGN(ONE,DXL(3))
        ELSE
          LNTFOU=.TRUE.
        ENDIF
*
* *** Case of the trapezoid TRD2
      ELSE IF (ISH.EQ.NSTRD2) THEN
        DZ   = TWO*PAR(5)+1.e-10
        TAN1 = (PAR(2)-PAR(1))/DZ
        SEC1 = SQRT(ONE+TAN1**2)
        U1   = ABS(DXL(1))-DXL(3)*TAN1
        U1L  = PAR(2)-PAR(5)*TAN1
        TAN2 = (PAR(4)-PAR(3))/DZ
        SEC2 = SQRT(ONE+TAN2**2)
        U2   = ABS(DXL(2))-DXL(3)*TAN2
        U2L  = PAR(4)-PAR(5)*TAN2
        PERP(1) = ABS(U1-U1L)/SEC1
        PERP(2) = ABS(U2-U2L)/SEC2
        PERP(3) = ABS(ABS(DXL(3))-PAR(5))
        PMIN0 = MIN(PERP(1),PERP(2),PERP(3))
        IF (PERP(1).EQ.PMIN0) THEN
          FACT = ONE/SEC1
          UL(1) = SIGN(FACT,DXL(1))
          UL(2) = 0.
          UL(3) = -TAN1*FACT
        ELSE IF (PERP(2).EQ.PMIN0) THEN
          FACT = ONE/SEC2
          UL(1) = 0.
          UL(2) = SIGN(FACT,DXL(2))
          UL(3) = -TAN2*FACT
        ELSE IF (PERP(3).EQ.PMIN0) THEN
          UL(1) = 0.
          UL(2) = 0.
          UL(3) = SIGN(ONE,DXL(3))
        ELSE
          LNTFOU=.TRUE.
        ENDIF
*
* *** Case of the TRAPezoid
***************************************************************
*  Warning:  the parameters for this shape are NOT stored in  *
*  the data structure as the user supplies them.  Rather, the *
*  user supplies PAR(2)=thet, PAR(3)=phi, PAR(7)=alp1, and    *
*  PAR(11)=alp2, while the data structure contains PAR(2)=    *
*  Tan(thet)*Cos(phi), PAR(3)=Tan(thet)*Sin(phi), PAR(7)=     *
*  Tan(alp1), and PAR(11)=Tan(alp2).                          *
***************************************************************
      ELSE IF (ISH.EQ.NSTRAP) THEN
        PERP(1) = ABS(ABS(DXL(3))-PAR(1))
        DX = PAR(2)
        DY = PAR(3)
        U0 = DX*DXL(3)
        V0 = DY*DXL(3)
        UU0 = DX*PAR(1)
        VV0 = DY*PAR(1)
        RAT = DXL(3)/PAR(1)
        RATL = (ONE-RAT)/TWO
        RATH = (ONE+RAT)/TWO
        H = PAR(4)*RATL+PAR(8)*RATH
        BL = PAR(5)*RATL+PAR(9)*RATH
        TL = PAR(6)*RATL+PAR(10)*RATH
        TALPH = PAR(7)*RATL+PAR(11)*RATH
        XWID = (TL+BL)/TWO
        TAN1 = TALPH+(TL-BL)/(TWO*H)
        SEC1 = SQRT(ONE+TAN1**2)
        U1 = DXL(1)-DXL(2)*TAN1
        U1L = U0+XWID-V0*TAN1
        TAN2 = TAN1-TWO*TALPH
        SEC2 = SQRT(ONE+TAN2**2)
        U2 = DXL(1)+DXL(2)*TAN2
        U2L = U0-XWID+V0*TAN2
        IF (DXL(3).LT.0) THEN
          DZ = PAR(1)-DXL(3)+1.e-10
          UU = UU0+(PAR(9)+PAR(10))/TWO
          W1 = (UU-VV0*TAN1-U1L)/DZ
          UU = TWO*UU0-UU
          W2 = (UU+VV0*TAN2-U2L)/DZ
        ELSE
          DZ = -PAR(1)-DXL(3)+1.e-10
          UU = -UU0+(PAR(5)+PAR(6))/TWO
          W1 = (UU+VV0*TAN1-U1L)/DZ
          UU = -TWO*UU0-UU
          W2 = (UU-VV0*TAN2-U2L)/DZ
        ENDIF
        W3 = DY+(PAR(8)-PAR(4))/(TWO*PAR(1))
        W4 = TWO*DY-W3
        SEW1 = SQRT(ONE+W1**2)
        SEW2 = SQRT(ONE+W2**2)
        SEW3 = SQRT(ONE+W3**2)
        SEW4 = SQRT(ONE+W4**2)
        PERP(2) = ABS(U1-U1L)/(SEC1*SEW1)
        PERP(3) = ABS(U2-U2L)/(SEC2*SEW2)
        PERP(4) = ABS(DXL(2)-V0-H)/SEW3
        PERP(5) = ABS(DXL(2)-V0+H)/SEW4
        PMIN0 = MIN(PERP(1),PERP(2),PERP(3),PERP(4),PERP(5))
        IF (PERP(1).EQ.PMIN0) THEN
          UL(1) = 0.
          UL(2) = 0.
          UL(3) = SIGN(ONE,DXL(3))
        ELSE IF (PERP(2).EQ.PMIN0) THEN
          FACT = ONE/(SEC1*SEW1)
          UL(1) = FACT
          UL(2) = -TAN1*FACT
          UL(3) = -W1/SEW1
        ELSE IF (PERP(3).EQ.PMIN0) THEN
          FACT = ONE/(SEC2*SEW2)
          UL(1) = -FACT
          UL(2) = -TAN2*FACT
          UL(3) = W2/SEW2
        ELSE IF (PERP(4).EQ.PMIN0) THEN
          FACT = ONE/SEW3
          UL(1) = 0.
          UL(2) = FACT
          UL(3) = -W3*FACT
        ELSE IF (PERP(5).EQ.PMIN0) THEN
          FACT = ONE/SEW4
          UL(1) = 0.
          UL(2) = -FACT
          UL(3) = W4*FACT
        ELSE
          LNTFOU=.TRUE.
        ENDIF
*
* *** everything else (currently NOT IMPLEMENTED)
      ELSE
        WRITE(CHMAIL,10100) ISH
        CALL GMAIL(0,0)
        IERR = 1
        GOTO 999
      ENDIF
 
      IF(LNTFOU) THEN
        WRITE(CHMAIL,10000) ISH
        CALL GMAIL(0,0)
        IERR = 1
      ELSE
*
* *** Transform back into the MCS
        CALL G3DTOM(UL,U,2)
        IERR = 0
      ENDIF
 
10000 FORMAT(' GGPERP - geometry check error for shape #',I2,'!')
10100 FORMAT(' GGPERP - non implemented for shape #',I2)
  999 END
