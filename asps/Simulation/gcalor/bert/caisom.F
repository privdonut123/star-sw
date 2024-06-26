* $Id: caisom.F,v 1.1.1.1 2004/01/15 00:08:45 potekhin Exp $
* $Name:  $
#include <commons/config.h>
      SUBROUTINE CAISOM
#include "gcalor/cbert.inc"
      REAL * 8 FERMN
      SAVE
C
      CALL CAPOL1(POLC,POLS)
      CALL CAAZIO(SOPC,SOPS)
      M = SNGL(CLSM) + .05
      IF(STRKP+2.0)20,20,10
   10 FERMN=FMPN(M)
C     STRUCK PROTON
      GOTO30
   20 FERMN=FMPN(M+3)
C     STRUCK NEUTRON
   30 CALL FRMICC(P2)
      P2=FERMN*P2
C     FRMIC SELECTS LARGEST OF 3 RANDOM NUMBERS
C     P2=MOMENTUM OF PARTICLE SELECTED FROM PROPER
C     FERMI DISTRIBUTION
      A=P2*POLS
C     P2 SIN THETA
      PXYZ(2)=A*SOPC
C     P2 SIN THETA COS PHI
      PXYZ(6)=A*SOPS
C     P2 SIN PHI
      PXYZ(10)=P2*POLC
C     P2 COS THETA
      E(2)=DSQRT(P2*P2+SQNM)
C     SQ. RT. MOMENTUM STRUCK PART. SQD. +NUCLEON MASS SQD.
      RLKE=(((E(1)*E(2)-PXYZ(1)*PXYZ(2)-PXYZ(5)*PXYZ(6)-PXYZ(9)*
     1PXYZ(10))/DNCMS   )-PM(1))/RCPMV
C     RELATIVE K.E.(MEV)--CONSTANT=NUCLEON MASS         /CM,
C     SECOND=MEV/CM.
      RETURN
      END
