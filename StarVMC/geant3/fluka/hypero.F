*
* $Id: hypero.F,v 1.1.1.2 2009/02/01 17:10:18 fisyak Exp $
*
* $Log: hypero.F,v $
* Revision 1.1.1.2  2009/02/01 17:10:18  fisyak
* Merge with .DEV2
*
* Revision 1.1.1.1  2008/12/10 20:46:51  fisyak
* Merge with macos version
*
* Revision 1.1.1.1  2005/05/25 22:37:24  fisyak
* Alice version of geant3 (-minicern)
*
* Revision 1.1.1.1  2002/07/24 15:56:24  rdm
* initial import into CVS
*
* Revision 1.1.1.1  2002/06/16 15:18:36  hristov
* Separate distribution  of Geant3
*
* Revision 1.1.1.1  1999/05/18 15:55:16  fca
* AliRoot sources
*
* Revision 1.1.1.1  1995/10/24 10:20:00  cernlib
* Geant
*
*
#include "geant321/pilot.h"
*CMZ :  3.21/02 29/03/94  15.41.44  by  S.Giani
*-- Author :
*$ CREATE HYPERO.FOR
*COPY HYPERO
*
*=== hypero ===========================================================*
*
      SUBROUTINE HYPERO(IT,ITNUCR,SICO,PLABCO)
 
#include "geant321/dblprc.inc"
#include "geant321/dimpar.inc"
#include "geant321/iounit.inc"
      COMMON /FKABLT/ AM(330),ICH(110),IBAR(110),K(220)
*     DIMENSION SICOR(30)
      DIMENSION IHATRS(30),INUTRS(30)
      DATA IHATRS/16*30,25,24,30,16,15,25,8*30/
C
C--------------------------------------------------
C*** ATTENSION, IN CASE OF IT=SIG+=21 NO STRANGENES-CONS.,DIFFER.1UNIT
C--------------------------------------------------
      DATA INUTRS/16*30,8,2,30,8,1,8,8*30/
      ITNUCR=INUTRS(IT)
      ITHACR=IHATRS(IT)
      PLABCO=1.D0
      ITHATR=ITHACR
      IF (ITNUCR.GE.30) ITHATR=IT
      IF (ITNUCR.GE.30) ITNUCR=IT
      SICO=1.D0
      IF (ITHATR.LT.30) SICO=42.D0/39.D0
      IF (IT.EQ.21) SICO=42.D0/40.D0
      IF (ITHATR.LT.30) PLABCO=AM(IT)/(AM(ITNUCR)+1.D-10)
      IT=ITHATR
      RETURN
      END
