*
* $Id: rdmin.F,v 1.1.1.1 2005/05/25 20:36:52 fisyak Exp $
*
* $Log: rdmin.F,v $
* Revision 1.1.1.1  2005/05/25 20:36:52  fisyak
*
* Revision 1.1.1.1  2002/07/24 15:56:28  rdm
* initial import into CVS
*
* Revision 1.1.1.1  2002/06/16 15:18:47  hristov
* Separate distribution  of Geant3
*
* Revision 1.1.1.1  1999/05/18 15:55:33  fca
* AliRoot sources
*
* Revision 1.1.1.1  1996/02/15 17:50:07  mclareni
* Kernlib
*
*
#include "kerngen/pilot.h"
        SUBROUTINE RDMIN(ISEED)
        COMMON /MCGN/ MCGN

C--       Set the seed
      MCGN = ISEED
      RETURN

C--       Get the seed
      ENTRY RDMOUT (ISEED)
      ISEED = MCGN
      END
