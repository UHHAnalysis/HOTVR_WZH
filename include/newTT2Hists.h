#ifndef newTT2Hists_H
#define newTT2Hists_H

// ROOT include(s):
#include <TObject.h>
#include <TString.h>
#include "TH2.h"

// Local include(s):
#include "SFrameTools/include/BaseHists.h"
#include "include/TMVA_tagger.h"
#include "include/Showerdeconstruction.h"
#include "include/ShowerdeconstructionV2.h"
#include "include/SoftDrop.h"
#include "include/Jetswithoutjets.h"
#include "include/VariableR.h"


class newTT2Hists : public BaseHists {

public:
   /// Named constructor
   newTT2Hists(const char* name);

   /// Default destructor
   ~newTT2Hists();

   void Init();

   void Fill();

   void Finish();
   
   void SetIdVersion(TString s);

private:
 TString idVersion;
 TMVA_tagger* tmva_tagger;
  Showerdeconstruction* Showerdeconstruction_tagger;
  ShowerdeconstructionV2* Showerdeconstruction_taggerV2;
  SoftDrop* Softdrop;
  Jetswithoutjets* jwj;
  VariableR* varR;

}; // class RocHists


#endif // RocHists_H
