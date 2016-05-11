#ifndef VariableR_H
#define VariableR_H

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
#include "fastjet/contrib/VariableRPlugin.hh"


//typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> > LorentzVectorXYZE;
class VariableR{
 private:
  static VariableR* m_instance;
  mutable SLogger m_logger;


 public:
VariableR();
  ~VariableR();
 static VariableR* Instance();


 fastjet::PseudoJet Get_varRSubJet(TopJet topjet,std::vector<PFParticle>* allparts, double pTcut, double conesize, fastjet::ClusterSequence &clusterSq, double &subjetmass, double &mmin, double &rho);
 vector<fastjet::PseudoJet> Get_varRJet(fastjet::ClusterSequence &clusterSq);
 double Get_Jetsize(fastjet::PseudoJet pseudoje,fastjet::ClusterSequence clustersq);


};

#endif
