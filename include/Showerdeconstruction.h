#ifndef Showerdeconstruction_H
#define Showerdeconstruction_H

#include "SFrameTools/include/Objects.h"
#include <fastjet/PseudoJet.hh>
#include "SFrameTools/include/fwd.h"
#include "SFrameTools/include/boost_includes.h" // for shared_array
#include <TMVA/Reader.h>
#include "TVector3.h"
#include <limits>
#include <algorithm>
#include <memory>
#include <TF1.h>
#include "Utils.h"
#include "EventCalc.h"
#include "include/Cleaner.h"
#include "FactorizedJetCorrector.h"
#include "JetCorrectorParameters.h"


//typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> > LorentzVectorXYZE;
class Showerdeconstruction{
 private:
  static Showerdeconstruction* m_instance;
  mutable SLogger m_logger;
 TMVA::Reader *reader=NULL;


 public:
Showerdeconstruction();
  ~Showerdeconstruction();
  double  Chi(TopJet topjet);
  double ChiMicro(TopJet topjet, int& nmicrojets, double& Mmicrojet, double microjet_cone, std::vector<fastjet::PseudoJet>& microjets);
   double ChiMicroGen(GenJetWithParts topjet, int& nmicrojets, double& Mmicrojet, double microjet_cone, std::vector<fastjet::PseudoJet>& microjets);
   double ChiPF(TopJet topjet, int& nmicrojets, double& Mmicrojet);
  int GetNmicrojets(TopJet topjet);
static Showerdeconstruction* Instance();


};

#endif
