*
* $Id: gsipar.F,v 1.1.1.2 2009/02/01 17:10:26 fisyak Exp $
*
* $Log: gsipar.F,v $
* Revision 1.1.1.2  2009/02/01 17:10:26  fisyak
* Merge with .DEV2
*
* Revision 1.1.1.1  2008/12/10 20:47:57  fisyak
* Merge with macos version
*
* Revision 1.1.1.1  2005/05/25 22:37:36  fisyak
* Alice version of geant3 (-minicern)
*
* Revision 1.1.1.1  2002/07/24 15:56:25  rdm
* initial import into CVS
*
* Revision 1.1.1.1  2002/06/16 15:18:39  hristov
* Separate distribution  of Geant3
*
* Revision 1.2  2001/03/20 06:36:27  alibrary
* 100 parameters now allowed for geant shapes
*
* Revision 1.1.1.1  1999/05/18 15:55:17  fca
* AliRoot sources
*
* Revision 1.1.1.1  1995/10/24 10:20:56  cernlib
* Geant
*
*
#include "geant321/pilot.h"
*CMZ :  3.21/02 29/03/94  15.41.30  by  S.Giani
*-- Author :
      SUBROUTINE GSIPAR(JVO,JIN,NPAR,NATT,PAR,ATT)
C.
C.    ******************************************************************
C.    *                                                                *
C.    *    ROUTINE TO SET INTERNAL PARAMETERS AND ATTRIBUTES.          *
C.    *                                                                *
C.    *    ==>Called by : GSDVN,GSDVN2,GSDVT,GSDVT2,GSVOLU             *
C.    *         Author  A.McPherson  *********                         *
C.    *                                                                *
C.    ******************************************************************
C.
#include "geant321/gcbank.inc"
#include "geant321/gcunit.inc"
      DIMENSION PAR(100),ATT(20)
C.
C.              --------------------------------------------
C.
      IF(NPAR.LT.0.OR.NPAR.GT.100) GO TO 900
      IF(NATT.LE.0.OR.NATT.GT.20) GO TO 900
C
      IF(JVO.LE.0) GO TO 910
      IF(JIN.GT.0) GO TO 10
C
      Q(JVO+5)=NPAR
      Q(JVO+6)=NATT
      JPAR=JVO+7
      JATT=JVO+7+NPAR
C
      GO TO 20
   10 CONTINUE
C
      JPAR=JIN+9
      Q(JPAR)=NPAR
      Q(JVO+5)=0
      Q(JVO+6)=NATT
      JPAR=JPAR+1
      JATT=JVO+7
C
   20 CONTINUE
C
      CALL UCOPY(PAR,Q(JPAR),NPAR)
      CALL UCOPY(ATT,Q(JATT),NATT)
C
      GO TO 999
  900 CONTINUE
C
      WRITE(CHMAIL,1000) NPAR,NATT
      CALL GMAIL(0,0)
 1000 FORMAT(' **** ERROR IN GSIPAR - NPAR =',I12,' OR NATT =',I12,
     +' OUT OF RANGE ****')
C
      GO TO 999
  910 CONTINUE
C
      WRITE(CHMAIL,1010) JVO
      CALL GMAIL(0,0)
 1010 FORMAT(' **** ERROR IN GSIPAR - JVO =',I12,
     +' LE 0. ****')
C
  999 END
