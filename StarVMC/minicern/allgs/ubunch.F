*
* $Id: ubunch.F,v 1.1.1.1 2005/05/25 20:36:46 fisyak Exp $
*
* $Log: ubunch.F,v $
* Revision 1.1.1.1  2005/05/25 20:36:46  fisyak
*
* Revision 1.1.1.1  2002/07/24 15:56:28  rdm
* initial import into CVS
*
* Revision 1.1.1.1  1999/05/18 15:55:32  fca
* AliRoot sources
*
* Revision 1.1.1.1  1996/02/15 17:50:23  mclareni
* Kernlib
*
*
      SUBROUTINE UBUNCH (MS,MT,NCHP)
C
C CERN PROGLIB# M409    UBUNCH          .VERSION KERNVMI  1.01  891208
C ORIG. 03/02/89 K.M.STORR
C

      DIMENSION    MS(99), MT(99), NCHP(9)
      DATA IBLAN1  /z'20202020'/
      DATA MASK1   /z'000000ff'/

      NCH = NCHP(1)
      IF   (NCH)             91,39,11
   11 NWT    = ishft (NCH,-2)
      NTRAIL = IAND (NCH,3)
      JS     = 0
      IF (NWT.EQ.0)          GO TO 31

C--                Pack the initial complete words

      DO 24  JT=1,NWT
      MT(JT) = IOR (IOR (IOR (
     +                  IAND(MS(JS+1),MASK1),
     +           ishft (IAND(MS(JS+2),MASK1), 8)),
     +           ishft (IAND(MS(JS+3),MASK1),16)),
     +           ishft      (MS(JS+4),       24) )
   24 JS = JS + 4

      IF (NTRAIL.EQ.0)       RETURN

C--                Pack the trailing word

   31 MWD = IBLAN1
      JS  = NCH

      DO 34 JT=1,NTRAIL
      MWD = IOR (ishft(MWD,8), IAND(MS(JS),MASK1))
   34 JS  = JS - 1
      MT(NWT+1) = MWD
   39 RETURN

   91 CALL ABEND
      END
