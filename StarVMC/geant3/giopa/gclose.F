*
* $Id: gclose.F,v 1.1.1.2 2009/02/01 17:10:29 fisyak Exp $
*
* $Log: gclose.F,v $
* Revision 1.1.1.2  2009/02/01 17:10:29  fisyak
* Merge with .DEV2
*
* Revision 1.1.1.1  2008/12/10 20:48:26  fisyak
* Merge with macos version
*
* Revision 1.1.1.1  2005/05/25 22:37:38  fisyak
* Alice version of geant3 (-minicern)
*
* Revision 1.1.1.1  2002/07/24 15:56:25  rdm
* initial import into CVS
*
* Revision 1.1.1.1  2002/06/16 15:18:40  hristov
* Separate distribution  of Geant3
*
* Revision 1.1.1.1  1999/05/18 15:55:20  fca
* AliRoot sources
*
* Revision 1.1.1.1  1995/10/24 10:21:16  cernlib
* Geant
*
*
#include "geant321/pilot.h"
*CMZ :  3.21/02 29/03/94  15.41.20  by  S.Giani
*-- Author :
      SUBROUTINE GCLOSE (LUN,IER)
C.
C.    ******************************************************************
C.    *                                                                *
C.    *       Routine to close I/O units                               *
C.    *                                                                *
C.    *       LUN      Logical unit number                             *
C.    *       IER      error flag                                      *
C.    *                                                                *
C.    *    ==>Called by : <USER>, UGLAST                               *
C.    *       Authors    R.Brun, F.Carena  *********                   *
C.    *                                                                *
C.    ******************************************************************
C.
#include "geant321/gcunit.inc"
C.
C.    ------------------------------------------------------------------
C.
      IER=0
      IF(LUN.EQ.0)THEN
         CALL FZENDO(LUN,'T')
         CALL FZENDI(LUN,'T')
      ELSE
         DO 10 I=1,NUNITS
            IF(LUN.EQ.ABS(LUNITS(I)))THEN
               IF(LUNITS(I).LT.0)THEN
                  CALL FZENDI(LUN,'T')
               ELSE
                  CALL FZENDO(LUN,'T')
               ENDIF
               LUNITS(I)=0
               GOTO 999
            ENDIF
   10    CONTINUE
         IER=1
      ENDIF
  999 END
