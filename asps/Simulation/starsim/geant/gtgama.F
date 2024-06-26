#include "geant321/pilot.h"
*CMZ :  3.21/02 29/03/94  15.41.24  by  S.Giani
*-- Author :
      SUBROUTINE GTGAMA
C.
C.    ******************************************************************
C.    *                                                                *
C.    *   Photon track. Computes step size and propagates particle     *
C.    *    through step.                                               *
C.    *                                                                *
C.    *   ==>Called by : GTRACK                                        *
C.    *      Authors    R.Brun, F.Bruyant L.Urban ********             *
C.    * Modifications:                                                 *
C.    * cernlib, 95-97: aban logic corrected                           *
C.    * PN,1999: save correct process when phot is stop due to photoabs*
C.    ******************************************************************
C.
#include "geant321/gcbank.inc"
#include "geant321/gccuts.inc"
#include "geant321/gcjloc.inc"
#include "geant321/gconsp.inc"
#include "geant321/gcphys.inc"
#include "geant321/gcstak.inc"
#include "geant321/gctmed.inc"
#include "geant321/gcmulo.inc"
#include "geant321/gctrak.inc"
#if defined(CERNLIB_DEBUG)
#include "geant321/gcunit.inc"
#endif
#if !defined(CERNLIB_SINGLE)
      PARAMETER (EPSMAC=1.E-6)
      DOUBLE PRECISION ONE,XCOEF1,XCOEF2,XCOEF3,ZERO
#endif
#if defined(CERNLIB_SINGLE)
      PARAMETER (EPSMAC=1.E-11)
#endif
      PARAMETER (ONE=1,ZERO=0)
      PARAMETER (EPCUT=1.022E-3)
*
      IABAN = NINT(DPHYS1)
*
C.
C.    ------------------------------------------------------------------
*
* *** Particle below energy threshold ?  Short circuit
*
*
      STEP=0.0001
      IF (GEKIN.LE.CUTGAM) GOTO 998
*
* *** Update local pointers if medium has changed
*
      IF(IUPD.EQ.0)THEN
         IUPD  = 1
         JPHOT = LQ(JMA-6)
         JCOMP = LQ(JMA-8)
         JPAIR = LQ(JMA-10)
         JPFIS = LQ(JMA-12)
         JRAYL = LQ(JMA-13)
      ENDIF
*
* *** Compute current step size
*
      IPROC  = 103
      STEP   = STEMAX
      GEKRT1 = 1 .-GEKRAT
*
*  **   Step limitation due to pair production ?
*
      IF (GETOT.GT.EPCUT) THEN
         IF (IPAIR.GT.0) THEN
            STEPPA = GEKRT1*Q(JPAIR+IEKBIN) +GEKRAT*Q(JPAIR+IEKBIN+1)
            SPAIR  = STEPPA*ZINTPA
            IF (SPAIR.LT.STEP) THEN
               STEP  = SPAIR
               IPROC = 6
            ENDIF
         ENDIF
      ENDIF
*
*  **   Step limitation due to Compton scattering ?
*
      IF (ICOMP.GT.0) THEN
         STEPCO = GEKRT1*Q(JCOMP+IEKBIN) +GEKRAT*Q(JCOMP+IEKBIN+1)
         SCOMP  = STEPCO*ZINTCO
         IF (SCOMP.LT.STEP) THEN
            STEP  = SCOMP
            IPROC = 7
         ENDIF
      ENDIF
*
*  **   Step limitation due to photo-electric effect ?
*
      IF (GEKIN.LT.0.4) THEN
         IF (IPHOT.GT.0) THEN
            STEPPH = GEKRT1*Q(JPHOT+IEKBIN) +GEKRAT*Q(JPHOT+IEKBIN+1)
            SPHOT  = STEPPH*ZINTPH
            IF (SPHOT.LT.STEP) THEN
               STEP  = SPHOT
               IPROC = 8
            ENDIF
         ENDIF
      ENDIF
*
*  **   Step limitation due to photo-fission ?
*
      IF (JPFIS.GT.0) THEN
         STEPPF = GEKRT1*Q(JPFIS+IEKBIN) +GEKRAT*Q(JPFIS+IEKBIN+1)
         SPFIS  = STEPPF*ZINTPF
         IF (SPFIS.LT.STEP) THEN
            STEP  = SPFIS
            IPROC = 23
         ENDIF
      ENDIF
*
*  **   Step limitation due to Rayleigh scattering ?
*
      IF (IRAYL.GT.0) THEN
         IF (GEKIN.LT.0.01) THEN
            STEPRA = GEKRT1*Q(JRAYL+IEKBIN) +GEKRAT*Q(JRAYL+IEKBIN+1)
            SRAYL  = STEPRA*ZINTRA
            IF (SRAYL.LT.STEP) THEN
               STEP  = SRAYL
               IPROC = 25
            ENDIF
         ENDIF
      ENDIF
*
      IF (STEP.LT.0.) STEP = 0.
*
*  **   Step limitation due to geometry ?
*
      IF (STEP.GE.SAFETY) THEN
         CALL GTNEXT
         IF (IGNEXT.NE.0) THEN
            STEP   = SNEXT + PREC
            INWVOL= 2
            IPROC = 0
            NMEC =  1
            LMEC(1)=1
         ENDIF
*
*        Update SAFETY in stack companions, if any
         IF (IQ(JSTAK+3).NE.0) THEN
            DO 10 IST = IQ(JSTAK+3),IQ(JSTAK+1)
               JST = JSTAK +3 +(IST-1)*NWSTAK
               Q(JST+11) = SAFETY
   10       CONTINUE
            IQ(JSTAK+3) = 0
         ENDIF
*
      ELSE
         IQ(JSTAK+3) = 0
      ENDIF
*
* *** Linear transport
*
      IF (INWVOL.EQ.2) THEN
         DO 20 I = 1,3
            VECTMP  = VECT(I) +STEP*VECT(I+3)
            IF(VECTMP.EQ.VECT(I)) THEN
*
* *** Correct for machine precision
*
               IF(VECT(I+3).NE.0.) THEN
                  VECTMP=VECT(I)+ABS(VECT(I))*SIGN(EPSMAC,VECT(I+3))
                  IF(NMEC.EQ.0 .or. LMEC(NMEC).NE.104) then
                     NMEC=NMEC+1
                     LMEC(NMEC)=104
                  ENDIF

#if defined(CERNLIB_DEBUG)
                  WRITE(CHMAIL, 10000)
                  CALL GMAIL(0,0)
                  WRITE(CHMAIL, 10100) GEKIN, NUMED, STEP, SNEXT
                  CALL GMAIL(0,0)
10000 FORMAT(' Boundary correction in GTGAMA: ',
     +       '    GEKIN      NUMED       STEP      SNEXT')
10100 FORMAT(31X,E10.3,1X,I10,1X,E10.3,1X,E10.3,1X)
#endif
               ENDIF
            ENDIF
            VECT(I) = VECTMP
   20    CONTINUE
      ELSE
         DO 30 I = 1,3
            VECT(I)  = VECT(I) +STEP*VECT(I+3)
   30    CONTINUE
      ENDIF
*
      SLENG = SLENG +STEP
*
* *** Update time of flight
*
      TOFG = TOFG +STEP/CLIGHT
*
* *** Update interaction probabilities
*
      IF (GETOT.GT.EPCUT) THEN
         IF (IPAIR.GT.0) ZINTPA = ZINTPA -STEP/STEPPA
      ENDIF
      IF (ICOMP.GT.0)    ZINTCO = ZINTCO -STEP/STEPCO
      IF (GEKIN.LT.0.4) THEN
         IF (IPHOT.GT.0) ZINTPH = ZINTPH -STEP/STEPPH
      ENDIF
      IF (JPFIS.GT.0)    ZINTPF = ZINTPF -STEP/STEPPF
      IF (IRAYL.GT.0) THEN
         IF (GEKIN.LT.0.01) ZINTRA = ZINTRA -STEP/STEPRA
      ENDIF
*
      IF (IPROC.EQ.0) GO TO 999
      NMEC = 1
      LMEC(1) = IPROC
*
*  ** Pair production ?
*
      IF (IPROC.EQ.6) THEN
         CALL GPAIRG
*
*  ** Compton scattering ?
*
      ELSE IF (IPROC.EQ.7) THEN
         CALL GCOMP
*
*  ** Photo-electric effect ?
*
      ELSE IF (IPROC.EQ.8) THEN
*
*        IABAN > 0  can stop particles above the CUTE
*
       IF(IABAN.GT.0) THEN
*
*        STOP gamma IF estimated_range(photoelectron) < safety
*
*       Calculate range of the photoelectron ( with kin. energy Ephot)
*
        IF(GEKIN.LE.0.001)  THEN
          JCOEF = LQ(JMA-17)
          IF(GEKRAT.LT.0.7) THEN
            I1 = MAX(IEKBIN-1,1)
          ELSE
            I1 = MIN(IEKBIN,NEKBIN-1)
          ENDIF
          I1 = 3*(I1-1)+1
          XCOEF1 = Q(JCOEF+I1)
          XCOEF2 = Q(JCOEF+I1+1)
          XCOEF3 = Q(JCOEF+I1+2)
          IF(XCOEF1.NE.0.) THEN
            STOPMX = -XCOEF2+SIGN(SQRT(XCOEF2**2-(XCOEF3-GEKIN/XCOEF1))
     >                              ,XCOEF1)
          ELSE
            STOPMX = - (XCOEF3-GEKIN)/XCOEF2
          ENDIF
*
*        DO NOT call GPHOT if this (overestimated) range is smaller than SAFETY
*        PN: but still save the right process id

          IF (STOPMX.LE.SAFETY) then
            DESTEP = GEKIN
            GEKIN  = 0.
            GETOT  = 0.
            VECT(7)= 0.
            ISTOP  = 2
            go to  999
          endif
*
         ENDIF
*
        ENDIF
        CALL GPHOT
*
*  ** Rayleigh effect ?
*
      ELSE IF (IPROC.EQ.25) THEN
         CALL GRAYL
*
*  ** Photo-fission ?
*
      ELSE IF (IPROC.EQ.23) THEN
         CALL GPFIS
*
      ENDIF
*
      GOTO 999

  998    NMEC   = 1
         LMEC(1)= 30
  990    DESTEP = GEKIN
         GEKIN  = 0.
         GETOT  = 0.
         VECT(7)= 0.
         ISTOP  = 2
  999 END
