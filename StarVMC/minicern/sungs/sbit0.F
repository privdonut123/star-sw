*
* $Id: sbit0.F,v 1.1.1.1 2005/05/25 20:36:55 fisyak Exp $
*
* $Log: sbit0.F,v $
* Revision 1.1.1.1  2005/05/25 20:36:55  fisyak
*
* Revision 1.1.1.1  2002/07/24 15:56:28  rdm
* initial import into CVS
*
* Revision 1.1.1.1  1999/05/18 15:55:32  fca
* AliRoot sources
*
* Revision 1.1.1.1  1996/02/15 17:50:21  mclareni
* Kernlib
*
*
      SUBROUTINE SBIT0 (IZW,IZP)
C
C CERN PROGLIB# M421    SBIT0           .VERSION KERNSUN  1.00  880922
C ORIG. 22/09/88, JZ
C
      IZW = AND (IZW, NOT(LSHIFT(1,IZP-1)))
      RETURN
      END
