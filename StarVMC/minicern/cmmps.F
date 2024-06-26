*
* $Id: cmmps.F,v 1.1 2005/06/09 00:05:10 fisyak Exp $
*
* $Log: cmmps.F,v $
* Revision 1.1  2005/06/09 00:05:10  fisyak
* Add stuff for reconstruction
*
* Revision 1.1  2005/05/26 22:28:00  fisyak
* Add stuff necessary for reconstruction packages
*
* Revision 1.1.1.1  1996/02/15 17:48:57  mclareni
* Kernlib
*
*
#include "kernnum/pilot.h"
          SUBROUTINE          CMMPS(M,N,X,X12,X21,Y,Y2,Z,Z2)
          COMPLEX             X(*),X12(*),X21(*),Y(*),Y2(*),Z(*),Z2(*)
          COMPLEX             A, B, SIGNF
#if !defined(CERNLIB_NUMCDBLE)
          COMPLEX             SUM, F
          F(A,B,SUM)  =  A*B + SUM
#endif
#if defined(CERNLIB_NUMCDBLE)
          COMPLEX*16          SUM, DC, F
          DC(A)       =  DCMPLX(DBLE(REAL(A)),DBLE(AIMAG(A)))
          F(A,B,SUM)  =  DC(A)*DC(B) + SUM
#endif
          SIGNF(A)    =  -A
          IF(M .LE. 0  .OR.  N .LE. 0)  RETURN
#include "cxij.inc"
#include "cyj.inc"
#include "czi.inc"
#include "mmpa.inc"
