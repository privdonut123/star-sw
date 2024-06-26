*
* $Id: cgsize.F,v 1.1.1.2 2009/02/01 17:10:07 fisyak Exp $
*
* $Log: cgsize.F,v $
* Revision 1.1.1.2  2009/02/01 17:10:07  fisyak
* Merge with .DEV2
*
* Revision 1.1.1.1  2008/12/10 20:46:03  fisyak
* Merge with macos version
*
* Revision 1.1.1.1  2005/05/25 22:36:40  fisyak
* Alice version of geant3 (-minicern)
*
* Revision 1.1.1.1  2002/07/24 15:56:27  rdm
* initial import into CVS
*
* Revision 1.1.1.1  2002/06/16 15:17:54  hristov
* Separate distribution  of Geant3
*
* Revision 1.1.1.1  1999/05/18 15:55:04  fca
* AliRoot sources
*
* Revision 1.1.1.1  1995/10/24 10:19:44  cernlib
* Geant
*
*
#include "geant321/pilot.h"
*CMZ :  3.21/02 29/03/94  15.41.32  by  S.Giani
*-- Author :
      FUNCTION CGSIZE(N,NFATYP,NFAC,NEDG)
************************************************************************
*                                                                      *
*     Name: CGSIZE                                                     *
*     Author: E. Chernyaev                       Date:    20.03.88     *
*                                                Revised:              *
*                                                                      *
*     Function: Compute size of CG-object                              *
*                                                                      *
*     References: none                                                 *
*                                                                      *
*     Input:  N       - max size of CG-object                          *
*             NFATYP  - number of different face type                  *
*             NFAC(*) - number of faces of given type                  *
*             NEDG(*) - number of edges in face of given type          *
*                                                                      *
*     Output: CGSIZE - CG-object size (= 0, if error in parameters)    *
*                                                                      *
*     Errors: none                                                     *
*                                                                      *
************************************************************************
#include "geant321/cggpar.inc"
      INTEGER   NFAC(*),NEDG(*)
*-
      CGSIZE = 0.
      IF (N .LE. 1)             GOTO 999
      IF (NFATYP .LE. 0)        GOTO 999
      NEED  = LCGHEA
      DO 100 I=1,NFATYP
        IF (NFAC(I).LT.0 .OR. NEDG(I).LT.3)     GOTO 999
        NEED   = NEED + NFAC(I)*(LCGFAC + NEDG(I)*LCGEDG)
  100   CONTINUE
      IF (NEED .EQ. LCGHEA)     GOTO 999
      IF (N-NEED .LT. 0)        CGSIZE = N - NEED
      IF (N-NEED .GE. 0)        CGSIZE = NEED
  999 RETURN
      END
