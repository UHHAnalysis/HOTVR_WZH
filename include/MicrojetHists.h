#ifndef MicrojetHists_H
#define MicrojetHists_H
#include "SFrameTools/include/BaseHists.h"
#include "SFrameTools/include/Objects.h"
#include "SFrameTools/include/fwd.h"
#include "SFrameTools/include/boost_includes.h"
#include "include/BaseHists.h"
#include "include/BaseCycleContainer.h"
#include "HypothesisDiscriminator.h"
#include "TH2.h"
#include "Utils.h"
#include "EventCalc.h"
#include "include/Showerdeconstruction.h"
//#include "include/TopFitCalc.h"
/**
 *   Class for booking and filling TopJet histograms
 *
 *   
 *   @version $Revision: 1.1 $
 */

class MicrojetHists : public BaseHists {

public:
   /// Named constructor
   MicrojetHists(const char* name);

   /// Default destructor
   ~MicrojetHists();

   void Init();
   void Fill();
   void Fill2(TopJet topjet, double mva_value);
 private:
 Showerdeconstruction* Showerdeconstruction_tagger;
 // class TopTagHists
};
#endif // TopTagcontrol_H


