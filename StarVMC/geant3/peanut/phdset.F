*
* $Id: phdset.F,v 1.1.1.2 2009/02/01 17:10:35 fisyak Exp $
*
* $Log: phdset.F,v $
* Revision 1.1.1.2  2009/02/01 17:10:35  fisyak
* Merge with .DEV2
*
* Revision 1.1.1.1  2008/12/10 20:49:08  fisyak
* Merge with macos version
*
* Revision 1.1.1.1  2005/05/25 22:37:58  fisyak
* Alice version of geant3 (-minicern)
*
* Revision 1.1.1.1  2002/07/24 15:56:28  rdm
* initial import into CVS
*
* Revision 1.1.1.1  2002/06/16 15:18:43  hristov
* Separate distribution  of Geant3
*
* Revision 1.1.1.1  1999/05/18 15:55:22  fca
* AliRoot sources
*
* Revision 1.1.1.1  1995/10/24 10:22:02  cernlib
* Geant
*
*
#include "geant321/pilot.h"
*CMZ :  3.21/02 29/03/94  15.41.46  by  S.Giani
*-- Author :
*$ CREATE PHDSET.FOR
*COPY PHDSET
*
*=== phdset ===========================================================*
*
      SUBROUTINE PHDSET ( IKPMX )
 
#include "geant321/dblprc.inc"
#include "geant321/dimpar.inc"
#include "geant321/iounit.inc"
*
*----------------------------------------------------------------------*
*----------------------------------------------------------------------*
*
#include "geant321/nucgeo.inc"
#include "geant321/parnuc.inc"
#include "geant321/part.inc"
*
 1000 CONTINUE
      PDIFF = PNUCL (IKPMX) - PNUCCO
      IF ( PDIFF .LT. - ANGLGB ) THEN
         PNUCL0 = PNUCL (IKPMX)
         PNUCL (IKPMX) = PNUCCO
         PDTCMP = - ( PXNUCL (IKPMX) * CXIMPC + PYNUCL (IKPMX)
     &          * CYIMPC + PZNUCL (IKPMX) * CZIMPC )
         DELTAE = PDTCMP**2 - PNUCL0**2 + PNUCL (IKPMX)**2
         DELTAP = - PDTCMP + SQRT ( DELTAE )
         PXNUCL (IKPMX) = PXNUCL (IKPMX) + DELTAP * CXIMPC
         PYNUCL (IKPMX) = PYNUCL (IKPMX) + DELTAP * CYIMPC
         PZNUCL (IKPMX) = PZNUCL (IKPMX) + DELTAP * CZIMPC
      ELSE IF ( PDIFF .GT. ANGLGB ) THEN
         PNUCL0 = PNUCL (IKPMX)
         PNUCL (IKPMX) = PNUCCO
         PDTCMP = PXNUCL (IKPMX) * CXIMPC + PYNUCL (IKPMX)
     &          * CYIMPC + PZNUCL (IKPMX) * CZIMPC
         IF ( PDTCMP .GE. 0.D+00 ) THEN
            PNUCL0 = PNUCL (IKPMX) / PNUCL0
            PXNUCL (IKPMX) = PXNUCL (IKPMX) * PNUCL0
            PYNUCL (IKPMX) = PYNUCL (IKPMX) * PNUCL0
            PZNUCL (IKPMX) = PZNUCL (IKPMX) * PNUCL0
         ELSE
            DELTAE = PDTCMP**2 - PNUCL0**2 + PNUCL (IKPMX)**2
            IF ( DELTAE .LT. 0.D+00 ) THEN
               DELTAP = - PDTCMP
               PXNUCL (IKPMX) = PXNUCL (IKPMX) + DELTAP * CXIMPC
               PYNUCL (IKPMX) = PYNUCL (IKPMX) + DELTAP * CYIMPC
               PZNUCL (IKPMX) = PZNUCL (IKPMX) + DELTAP * CZIMPC
               PNUCL0 = SQRT ( PXNUCL (IKPMX)**2
     &                + PYNUCL (IKPMX)**2 + PZNUCL (IKPMX)**2 )
               PNUCL0 = PNUCL (IKPMX) / PNUCL0
               PXNUCL (IKPMX) = PXNUCL (IKPMX) * PNUCL0
               PYNUCL (IKPMX) = PYNUCL (IKPMX) * PNUCL0
               PZNUCL (IKPMX) = PZNUCL (IKPMX) * PNUCL0
            ELSE
               DELTAP = - PDTCMP - SQRT ( DELTAE )
               PXNUCL (IKPMX) = PXNUCL (IKPMX) + DELTAP * CXIMPC
               PYNUCL (IKPMX) = PYNUCL (IKPMX) + DELTAP * CYIMPC
               PZNUCL (IKPMX) = PZNUCL (IKPMX) + DELTAP * CZIMPC
            END IF
         END IF
      END IF
      RETURN
*=== End of subroutine phdset =========================================*
      END
