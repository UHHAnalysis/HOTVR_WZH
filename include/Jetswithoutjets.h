#ifndef Jetswithoutjets_H
#define Jetswithoutjets_H

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
class Jetswithoutjets{
 private:
  static Jetswithoutjets* m_instance;
  mutable SLogger m_logger;


 public:
Jetswithoutjets();
  ~Jetswithoutjets();
 static Jetswithoutjets* Instance();


 double SubjetMultiplicity(TopJet topjet,std::vector<PFParticle>* allparts, double pTcut, double conesize);
 std::vector<fastjet::PseudoJet> Get_subjets(TopJet topjet, std::vector<PFParticle>* allparts,double pTcut, double conesize);

};

#endif
