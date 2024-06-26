*
* $Id: xsecn5.F,v 1.1.1.2 2009/02/01 17:10:35 fisyak Exp $
*
* $Log: xsecn5.F,v $
* Revision 1.1.1.2  2009/02/01 17:10:35  fisyak
* Merge with .DEV2
*
* Revision 1.1.1.1  2008/12/10 20:49:06  fisyak
* Merge with macos version
*
* Revision 1.1.1.1  2005/05/25 22:37:58  fisyak
* Alice version of geant3 (-minicern)
*
* Revision 1.1.1.1  2002/07/24 15:56:27  rdm
* initial import into CVS
*
* Revision 1.1.1.1  2002/06/16 15:18:43  hristov
* Separate distribution  of Geant3
*
* Revision 1.1.1.1  1999/05/18 15:55:21  fca
* AliRoot sources
*
* Revision 1.1.1.1  1995/10/24 10:22:00  cernlib
* Geant
*
*
#include "geant321/pilot.h"
*CMZ :  3.21/02 29/03/94  15.41.48  by  S.Giani
*-- Author :
      SUBROUTINE XSECN5(NTX,IGCBS,LGCB,IGCBS2,LGCB2,BUF,IBUF,D,LD,
     +LIM,LAST)
C       THIS ROUTINE READS THE PHOTON PARTIAL DISTRIBUTIONS FOR EACH
C       REACTION LISTED IN THE GCB ARRAYS AND SUMS THEM UP TO
C       CREATE A TOTAL MULTIPLICITY * CROSS SECTION ARRAY FOR
C       EACH REACTION AND STORES THIS CROSS SECTION DATA IN CORE
#include "geant321/minput.inc"
#include "geant321/mconst.inc"
#include "geant321/mmicab.inc"
      DIMENSION NTX(NNUC),IGCBS(NGR,NNUC),LGCB(NGR,NNUC),
     +IGCBS2(NGR,NNUC),LGCB2(NGR,NNUC),BUF(*),IBUF(*),D(*),LD(*)
C       ASSIGN THE DEFAULT VALUES
      LEN=0
C       INITIALIZE THE COUNTERS FOR THE LOOP
C       LAST EQUALS THE LAST CORE POSITION USED IN THE CALLING
CROUTINE (INPUT1)
C       LST EQUALS THE LAST POSITION USED IN THE BUF ARRAY
C   (I.E. (BUF(LST) = D(LAST)))
      LST=0
      DO 70 I=1,NNUC
         NNTX=NTX(I)
         L=2*NNTX
         IF(L.EQ.0)GO TO 70
         DO 60 I2=1,NNTX
            LZ=LGCB(2*I2,I)
            IF(LZ.EQ.0)GO TO 60
            LEN=LIM-LAST
            IF(LEN.LT.LZ)GO TO 80
C       EQUATE THE MT NUMBERS IN THE GCB AND GCB2 DICTIONARIES
            IGCBS2(2*I2-1,I)=IGCBS(2*I2-1,I)
            LGCB2(2*I2-1,I)=LGCB(2*I2-1,I)
C       SET THE STARTING LOCATION FOR THE PHOTON TOTAL CROSS SECTION
            IGCBS2(2*I2,I)=LAST+1-LMOX4
C       OBTAIN THE STARTING LOCATION OF THE PARTIAL DISTRIBUTIONS
            IST=IGCBS(2*I2,I)+LMOX2
            NK=LD(IST)
            NP=LD(IST+1)
            NP2=2*NP
            LGCB2(2*I2,I)=NP2
C       ZERO OUT THE CORE AREA TO STORE THE TOTAL PHOTON
C       MULTIPLICITY * CROSS SECTION ARRAYS
            DO 10 IP=1,NP2
               BUF(LST+IP)=0.0
   10       CONTINUE
C       SET UP THE ENERGY BOUNDARIES FOR THE (E,XS) TABLE
            DO 20 J=1,NP
               BUF(LST+2*J-1)=D(IST+J+2-1)
   20       CONTINUE
            II=NP+2
            AWRI=D(IST+II+3-1)
C       SUM THE PARTIAL DISTRIBUTIONS TO OBTAIN THE TOTAL
C       MULTIPLICITY * CROSS SECTION ARRAY AND STORE IN THE
C       ENERGY,CROSS SECTION TABLE
            DO 40 J=1,NK
               II=II+4
               DO 30 K=1,NP
                  BUF(LST+2*K)=BUF(LST+2*K)+D(IST+II+K-1)
   30          CONTINUE
               II=II+NP
   40       CONTINUE
   50       CONTINUE
C       UPDATE CORE LOCATION POINTERS
            LAST=LAST+NP2
            LST=LST+NP2
   60    CONTINUE
   70 CONTINUE
      RETURN
   80 WRITE(IOUT,10000)LZ,LEN
10000 FORMAT(' MICAP: NOT ENOUGH SPACE TO READ IN RECORD',/,5X,
     +'LENGTH OF RECORD=',I10,/,5X,'SPACE AVAILABLE=',I10)
      PRINT '('' CALOR: ERROR in XSECN5 ====> STOP '')'
      STOP
      END
