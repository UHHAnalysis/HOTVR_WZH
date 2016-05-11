#ifndef Eugen_H
#define Eugen_H

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
#include "include/ECF.h"
#include "include/VariableR.h"
#include "include/Infrared_Saftey.h"

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

class Eugen : public BaseHists {

public:
   /// Named constructor
  /* Eugen(const char* name, int _rho, double _theta, int _mu); */
  Eugen(const char* name);

   /// Default destructor
   ~Eugen();

   void Init();

   void Fill();

   void Finish();
   
   void SetIdVersion(TString s);

private:
 TString idVersion;
 TMVA_tagger* tmva_tagger;
 TMVA_tagger* tmva_tagger2;
 TMVA_tagger* tmva_tagger300;
 TMVA_tagger* tmva_tagger500;
 TMVA_tagger* tmva_tagger700;
 TMVA_tagger* tmva_taggerInf;
  Showerdeconstruction* Showerdeconstruction_tagger;
  ShowerdeconstructionV2* Showerdeconstruction_taggerV2;
  SoftDrop* Softdrop;
  Jetswithoutjets* jwj;
  ECF* ecf;
  VariableR* varR;
  Infrared_Saftey* IR_Saftey;

  int rho;
  double theta;
  int mu;


}; // class RocHists


#endif // RocHists_H



