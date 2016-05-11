#ifndef Mistagcontrol_HHTT_H
#define Mistagcontrol_HHTT_H
#include <TMVA/Reader.h>
#include "include/TMVA_tagger.h"
#include "SFrameTools/include/BaseHists.h"
#include "include/BaseHists.h"
#include "include/BaseCycleContainer.h"
#include "HypothesisDiscriminator.h"
#include "TH2.h"
#include "include/Showerdeconstruction.h"
#include "include/SoftDrop.h"
//#include "include/TopFitCalc.h"
/**
 *   Class for booking and filling TopJet histograms
 *
 *   
 *   @version $Revision: 1.1 $
 */

class Mistagcontrol_HHTT : public BaseHists {

public:
   /// Named constructor
   Mistagcontrol_HHTT(const char* name);

   /// Default destructor
   ~Mistagcontrol_HHTT();

   void Init();

   void Fill();
 // class TopTagHists
private:
Chi2Discriminator* tagchi2discr;
TMVA_tagger* tmva_tagger;
  Showerdeconstruction* Showerdeconstruction_tagger;
  SoftDrop* softdrop;
//TMVA::Reader* reader;
};
#endif // TopTagcontrol_H


