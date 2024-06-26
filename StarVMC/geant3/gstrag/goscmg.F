*
* $Id: goscmg.F,v 1.1.1.2 2009/02/01 17:10:33 fisyak Exp $
*
* $Log: goscmg.F,v $
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
* Revision 1.2  2002/05/13 12:40:58  hristov
* Dummy subroutines to avoid files with no code in
*
* Revision 1.1.1.1  1999/05/18 15:55:21  fca
* AliRoot sources
*
* Revision 1.1.1.1  1995/10/24 10:21:38  cernlib
* Geant
*
*
#include "geant321/pilot.h"
#if defined(CERNLIB_ASHO)
*CMZ :  3.21/02 29/03/94  15.41.25  by  S.Giani
*-- Author :
C
      SUBROUTINE G3OSCMG
 
#include "geant321/gcmate.inc"
#include "geant321/gcasho.inc"
C-----------------------------------------------------------------------
C      This program calculates the parameters of the oscillators.
C      The input data are in the GCASHO. The lowest poten-
C      tials are convoluted to escape unreasonably high accuracy.
C-----------------------------------------------------------------------
C      Update history: 10-8-93
C
C-----------------------------------------------------------------------
      REAL KSI0
      PARAMETER (ENERR=0.02,TWOELM=2*511)
C-----------------------------------------------------------------------
C      Convolution of the first shells
C-----------------------------------------------------------------------
      C1 = 153.6*STEP*DENS/(BE2*AMED)
      C2 = 2.*LOG(PLIN)-BE2
      KSI0 = C1*ZMED
      X = 2.*LOG(E0MED/PLASM) + 1.
      CALL G3STCOR(X,E0MED,PLOG,DENS,D)
      A0 = LOG(TWOELM*TRNSMA/E0MED**2)+C2-D
      EMEAN = KSI0*A0
      DO 10 I = 1,NSMED
         IF (ESMED(I).GT.EMEAN*ENERR/ALFA) GOTO 20
   10 CONTINUE
   20 J = MAX(I - 1,1)
      S1 = 0.
      Z1 = 0.
      DO 30 I = 1,J
         S1 = S1 + LOG(ESMED(I))*ZSMED(I)
         Z1 = Z1 + ZSMED(I)
   30 CONTINUE
      S1  = EXP(S1/Z1)
      NOSC = NSMED - J + 1
      DO 40 I = 2,NOSC
         X = ESMED(I + J - 1)/S1
         IOSC(I) = X + 0.5
         EOSC(I) = S1*IOSC(I)*ALFA
         ZOSC(I) = ZSMED(I + J - 1)
   40 CONTINUE
      EOSC(1) = S1*ALFA
      IOSC(1) = 1
      ZOSC(1) = Z1
C-----------------------------------------------------------------------
C      Calculation of the oscillator parameters
C-----------------------------------------------------------------------
      C3 = C2 + 0.423
      DO 50 I = 1,NOSC
         X = C1*ZOSC(I)
         BOSC(I) = X/EOSC(I)
         X = 2.*LOG(EOSC(I)/PLASM)+1.
         CALL G3STCOR(X,EOSC(I),PLOG,DENS,D)
         AOSC(I) = LOG(TWOELM/EOSC(I)) +C3 -D
   50 CONTINUE
      END
#else
      SUBROUTINE GOSCMG_DUMMY
      END
#endif
