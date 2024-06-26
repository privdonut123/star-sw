*
* $Id: geta.F,v 1.1.1.2 2009/02/01 17:10:17 fisyak Exp $
*
* $Log: geta.F,v $
* Revision 1.1.1.2  2009/02/01 17:10:17  fisyak
* Merge with .DEV2
*
* Revision 1.1.1.1  2008/12/10 20:46:50  fisyak
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
* Revision 1.1.1.1  1999/05/18 15:55:15  fca
* AliRoot sources
*
* Revision 1.1.1.1  1995/10/24 10:19:56  cernlib
* Geant
*
*
#include "geant321/pilot.h"
*CMZ :  3.21/02 29/03/94  15.41.42  by  S.Giani
*-- Author :
*$ CREATE GETA.FOR
*COPY GETA
*
*=== geta =============================================================*
*
      FUNCTION GETA ( U, JZ, JN, MODE, IS, AOGMAX,
     &                                 AOGMIN )
 
#include "geant321/dblprc.inc"
#include "geant321/dimpar.inc"
#include "geant321/iounit.inc"
*
*----------------------------------------------------------------------*
*                                                                      *
*     Created on 18 january 1993   by    Alfredo Ferrari & Paola Sala  *
*                                                   Infn - Milan       *
*                                                                      *
*     Last change on 28-jan-93     by    Alfredo Ferrari               *
*                                                                      *
*----------------------------------------------------------------------*
*
#include "geant321/eva0.inc"
#if !defined(CERNLIB_SINGLE)
      PARAMETER ( ASMTOG = 6.0D0 / PIPIPI**2 )
#endif
#if defined(CERNLIB_SINGLE)
      PARAMETER ( ASMTOG = 6.0e0 / PIPIPI**2 )
#endif
      LOGICAL LASMLL
*
      LASMLL = .TRUE.
      IF ( JZ .LE. 0 .OR. JN .LE. 0 ) THEN
         GETA = ( JZ + JN) / B0
         AOGMAX = GETA
         AOGMIN = GETA
         RETURN
      END IF
      GO TO 5
      ENTRY GETG ( U, JZ, JN, MODE, IS, AOGMAX, AOGMIN )
      LASMLL = .FALSE.
    5 CONTINUE
      JA = JN + JZ
      AA = JA
      ZZ = JZ
      GO TO (10,20,30), MODE
*  +-------------------------------------------------------------------*
*  |  Standard EVAP parametrization for the level density
   10 CONTINUE
         TEMP = AA * ( ONEONE + Y0 * ( ( AA - TWOTWO*ZZ ) / AA )**2) /B0
         AOGMAX = TEMP
         AOGMIN = TEMP
      GO TO 40
*  |
*  +-------------------------------------------------------------------*
*  |  Gilbert & Cameron level density (with Z and A dependent correction
*  |  smoothly going into the Ignatyuk high energy limit, according
*  |  to the Ignatyuk interpolation formula
   20 CONTINUE
         STOP 'GETA:20'
***      GO TO 40
*  |
*  +-------------------------------------------------------------------*
*  |  Julich zero energy A-dependent level density:
   30 CONTINUE
         STOP 'GETA:30'
   40 CONTINUE
*  |
*  +-------------------------------------------------------------------*
*  +-------------------------------------------------------------------*
*  |  geta = a (U) (aogmax = a_max)
      IF ( LASMLL ) THEN
         GETA   = TEMP
*  |
*  +-------------------------------------------------------------------*
*  |  getg = g (U) (aogmax = g_max)
      ELSE
         GETG   = ASMTOG * TEMP
         AOGMAX = ASMTOG * AOGMAX
         AOGMIN = ASMTOG * AOGMIN
      END IF
*  |
*  +-------------------------------------------------------------------*
*=== End of Function geta =============================================*
      RETURN
      END
