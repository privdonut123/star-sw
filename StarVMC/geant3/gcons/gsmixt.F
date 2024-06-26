*
* $Id: gsmixt.F,v 1.1.1.2 2009/02/01 17:10:19 fisyak Exp $
*
* $Log: gsmixt.F,v $
* Revision 1.1.1.2  2009/02/01 17:10:19  fisyak
* Merge with .DEV2
*
* Revision 1.1.1.1  2008/12/10 20:47:05  fisyak
* Merge with macos version
*
* Revision 1.1.1.1  2005/05/25 22:37:26  fisyak
* Alice version of geant3 (-minicern)
*
* Revision 1.3  2003/11/28 11:23:55  brun
* New version of geant321 with all geant3 routines renamed from G to G3
*
* Revision 1.2  2002/12/02 16:37:44  brun
* Changes from Federico Carminati and Peter Hristov who ported the system
* on the Ithanium processors.It is tested on HP, Sun, and Alpha, everything
* seems to work. The optimisation is switched off in case of gcc2.xx.yyy
*
* Revision 1.1.1.1  2002/07/24 15:56:24  rdm
* initial import into CVS
*
* Revision 1.1.1.1  2002/06/16 15:18:37  hristov
* Separate distribution  of Geant3
*
* Revision 1.1.1.1  1999/05/18 15:55:16  fca
* AliRoot sources
*
* Revision 1.1.1.1  1995/10/24 10:20:17  cernlib
* Geant
*
*
#include "geant321/pilot.h"
*CMZ :  3.21/02 29/03/94  15.41.19  by  S.Giani
*-- Author :
      SUBROUTINE G3SMIXT(IMAT,NAMATE,A,Z,DENS,NLMAT,WMAT)
C.
C.    ******************************************************************
C.    *                                                                *
C.    *       Defines mixture OR COMPOUND IMAT as composed by          *
C.    *       THE BASIC NLMAT materials defined by arrays A,Z and WMAT *
C.    *                                                                *
C.    *       If NLMAT.GT.0 then WMAT contains the PROPORTION BY       *
C.    *       WEIGTHS OF EACH BASIC MATERIAL IN THE MIXTURE.           *
C.    *                                                                *
C.    *       If NLMAT.LT.0 then WMAT contains the number of atoms     *
C.    *       of a given kind into the molecule of the COMPOUND        *
C.    *       In this case, WMAT in output is changed to relative      *
C.    *       weigths.                                                 *
C.    *                                                                *
C.    *       nb : the radiation length is computed according          *
C.    *            the EGS manual slac-210 uc-32 June-78               *
C.    *                           formula  2-6-8 (37)                  *
C.    *                                                                *
C.    *    ==>Called by : <USER>, UGEOM                                *
C.    *       Authors    R.Brun, M.Maire  *********                    *
C.    *                                                                *
C.    ******************************************************************
C.
#include "geant321/gcbank.inc"
#include "geant321/gcnum.inc"
#include "geant321/gcunit.inc"
#include "geant321/gcmzfo.inc"
      COMMON / FIXIT / JMA, JMIXT, JMI1
      DIMENSION WMAT(1),A(1),Z(1)
      CHARACTER*(*) NAMATE
      CHARACTER*20 NAME
      DATA ALR2AV , AL183 / 1.39621E-03  ,  5.20948 /
C.
C.    ------------------------------------------------------------------
C.
      IF (IMAT.LE.0)GO TO 99
      IF(JMATE.LE.0)THEN
         CALL MZBOOK(IXCONS,JMATE,JMATE,1,'MATE',NMATE,NMATE,0,3,0)
         IQ(JMATE-5)=0
      ENDIF
      IF(IMAT.GT.NMATE)THEN
         CALL MZPUSH(IXCONS,JMATE,IMAT-NMATE,0,'I')
         NMATE=IMAT
         JMA1=0
      ELSE
         JMA1=LQ(JMATE-IMAT)
         IF(JMA1.GT.0) THEN
            WRITE(CHMAIL,10000)
            CALL GMAIL(1,0)
            CALL G3PMATE(IMAT)
            CALL MZDROP(IXCONS,LQ(JMATE-IMAT),' ')
         ENDIF
      ENDIF
      CALL MZBOOK(IXCONS,JMA,JMATE,-IMAT,'MATE',20,20,11,IOMATE,0)
C
      NAME=NAMATE
      NCH=LNBLNK(NAME)
      IF(NCH.GT.0)THEN
         IF(NAME(NCH:NCH).EQ.'$')NAME(NCH:NCH)=' '
      ENDIF
      CALL UCTOH(NAME,IQ(JMA+1),4,20)
C
C             Store mixture parameters
C             and parameter for Pair/Brems and
C             Photoelectric routines
C
      NLM    = IABS(NLMAT)
      IF (NLM.LE.0)GO TO 90
      CALL MZBOOK(IXCONS,JMIXT,JMA,-5,'MAMI',2,2,4*NLM,3,0)
      CALL MZBOOK(IXCONS,JMI1,JMIXT,-1,'MAM1',0,0,10,3,0)
      JMA = LQ(JMATE- IMAT)
      IQ(JMIXT-5)=IMAT
      IQ(JMI1-5)=IMAT
C
C             Compute proportion by weigths in the compound
C
      IF(NLMAT.LT.0) THEN
         AMOL   = 0.
         ZMOL   = 0.
         DO 10 I= 1,NLM
         AMOL   = AMOL + WMAT(I)*A(I)
         ZMOL   = ZMOL + WMAT(I)*Z(I)
   10    CONTINUE
         DO 20 I= 1,NLM
         WMAT(I)= WMAT(I)*A(I) / AMOL
   20    CONTINUE
      ENDIF
C
C             Compute effective mixture parameters
C
      AEFF   = 0.
      ZEFF   = 0.
      RADINV = 0.
      DO 40 I = 1,NLM
         AEFF   = AEFF + WMAT(I)*A(I)
         ZEFF   = ZEFF + WMAT(I)*Z(I)
         ZC     = Z(I)
         ALZ    = LOG(ZC)/3.
         XINV   = ZC*(ZC+G3XSI(ZC))*(AL183-ALZ-G3FCOUL(ZC))/A(I)
         RADINV = RADINV + WMAT(I)*XINV
         Q(JMIXT+3*NLM+I)=XINV
         Q(JMIXT + 2* NLM + I) = WMAT(I)
         Q(JMIXT + NLM + I) = Z(I)
         Q(JMIXT + I) = A(I)
   40 CONTINUE
      RADINV = ALR2AV * DENS * RADINV
      RADEFF = 1. / RADINV
      CALL G3HMIX(A,WMAT,NLM,AHEFF)
      ABSEFF=10000.*AHEFF/(6.022*DENS*G3HSIGM(5.,8,AHEFF))
C
      Q(JMA + 6) = AEFF
      Q(JMA + 7) = ZEFF
      Q(JMA + 8) = DENS
      Q(JMA + 9) = RADEFF
      Q(JMA + 10) = ABSEFF
      Q(JMA + 11) = NLM
      Q(JMI1 + 1) = AHEFF
      IF(NLMAT.GT.0)THEN
         Q(JMI1 + 2) = AEFF
         Q(JMI1 + 3) = ZEFF
      ELSE
         Q(JMI1 + 2) = AMOL
         Q(JMI1 + 3) = ZMOL
      ENDIF
C
      IF(JMA1.GT.0) THEN
         CALL G3PMATE(-IMAT)
      ENDIF
C
      GO TO 99
C
  90  CHMAIL=' ***** GSMIXT ERROR. MIXTURE WITH NO COMPONENTS'
      CALL GMAIL(0,0)
C
  99  RETURN
10000 FORMAT(' *** GSMIXT ***: Warning, material redefinition:')
      END
