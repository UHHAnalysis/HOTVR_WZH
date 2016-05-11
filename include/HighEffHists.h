#ifndef HighEffHists_H
#define HighEffHists_H

// ROOT include(s):
#include <TObject.h>
#include <TString.h>
#include "TH2.h"

// Local include(s):
#include "SFrameTools/include/BaseHists.h"
#include "include/TMVA_tagger.h"
#include "include/Showerdeconstruction.h"
#include "include/ShowerdeconstructionV2.h"

/**
 *   SemileptonicPreselection class for booking and filling histograms
 *
 *   This class books and fills a collection of histograms.
 *   It should have a unique name, such that the histograms
 *   of multiple instances of this class are ordered in the
 *   output file. 
 *   Always sort your histograms and used methods topically.
 *   This example collection can be used for data and reconstructed
 *   MC events.
 *   
 *   @version $Revision: 1.2 $
 */

class HighEffHists : public BaseHists {

public:
   /// Named constructor
   HighEffHists(const char* name);

   /// Default destructor
   ~HighEffHists();

   void Init();

   void Fill();

   void Finish();
   
   void SetIdVersion(TString s);

private:
 TString idVersion;
 TMVA_tagger* tmva_tagger;
  Showerdeconstruction* Showerdeconstruction_tagger;
  ShowerdeconstructionV2* Showerdeconstruction_taggerV2;
}; // class RocHists


#endif // RocHists_H
