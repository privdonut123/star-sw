
/***************************************************************************
 *
 * $Id: StTrsZeroSuppressedReader.hh,v 1.3 2003/12/24 13:44:52 fisyak Exp $
 *
 * Authors: bl, mcbs
 ***************************************************************************
 *
 * Description: Access to the digital information via the abstract
 *              interface
 *
 *
 * int getPadList(int PadRow, u_char **padList);
 *
 *        Fills (*padList[]) with the list of pad numbers containing hits
 *        returns number of pads in (*padList)[]
 *        or negative if call fails
 *
 * int getSequences(int PadRow, int Pad, int *nSeq, StSequence **SeqData)
 *
 *        Fills (*SeqData)[] along with the ADC
 *        buffers pointed to by (*SeqData)[]
 *        Set nSeq to the # of elements in the (*SeqData)[] array
 *        returns 0 if OK...or negative if call fails
 *
 * struct Sequence
 * {
 *  u_short startTimeBin;
 *  u_short Length;
 *  u_char *FirstAdc;
 * };
 ***************************************************************************
 *
 * $Log: StTrsZeroSuppressedReader.hh,v $
 * Revision 1.3  2003/12/24 13:44:52  fisyak
 * Add (GEANT) track Id information in Trs; propagate it via St_tpcdaq_Maker; account interface change in StTrsZeroSuppressedReaded in StMixerMaker
 *
 * Revision 1.2  2000/03/15 18:08:43  calderon
 * ZSR is no longer a singleton.  Two will be needed for mixer chain.
 *
 * Revision 1.1  1999/11/05 22:17:05  calderon
 * Made private copy constructor and operator= in StTrsDigitalSector.
 * Renamed DigitalSignalGenerators: Fast -> Old, Parameterized -> Fast
 * and use new "Fast" as default.
 * Added StTrsZeroSuppressedReader and StTrsZeroSuppressedReader for DAQ type
 * data access.
 *
 ***************************************************************************/
#ifndef ST_TRS_ZERO_SUPPRESSED_READER_HH
#define ST_TRS_ZERO_SUPPRESSED_READER_HH

#include "StSequence.hh"
#include "StDaqLib/GENERIC/EventReader.hh"
// struct StTrsSequence : public Sequence {
//   StTrsSequence() : Sequence(), FirstId(0) {}
//   int*           FirstId;           // ptr to the first simulated track id in the sequence           
// };

class StTpcRawDataEvent;
class StTrsRawDataEvent;
class StTrsDigitalSector;

class StTrsZeroSuppressedReader {//: public ZeroSuppressedReader {
public:
    StTrsZeroSuppressedReader();
    StTrsZeroSuppressedReader(StTpcRawDataEvent*);
    ~StTrsZeroSuppressedReader();

    //StTrsZeroSuppressedReader(StTrsZeroSuppressedReader&);

    int getPadList(int padRow, unsigned char **padList);
  //    int getSequences(int padRow, int Pad, int *nSeq, StTrsSequence*& SeqData);
    int getSequences(int padRow, int Pad, int *nSeq, StSequence** SeqData, int ***Id);
    int getSequences(int padRow, int Pad, int *nSeq, StSequence** SeqData);
    int getSequences(int padRow, int Pad, int *nSeq, Sequence** SeqData, int ***Id);
    int getSequences(int padRow, int Pad, int *nSeq, Sequence** SeqData);
#if 0
    int getSpacePts(int, int*, SpacePt**);
    int MemUsed();
#endif
    int setSector(int);
    void clear();

private:
    StTrsZeroSuppressedReader(int);    

    int checkTheData(unsigned int);

    int                 mSector;
    StTrsDigitalSector* mTheSector;
    unsigned char*      mPadList;
    StSequence*         mSequence;
    StTrsRawDataEvent*  mTrsEvent;

};
#endif
