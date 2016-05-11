#ifndef ECF_H
#define ECF_H

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
class ECF{
 private:
  static ECF* m_instance;
  mutable SLogger m_logger;


 public:
ECF();
  ~ECF();
 static ECF* Instance();


 double Get_C(TopJet topjet,std::vector<PFParticle>* allparts, int N, double beta);
 double Get_D3(TopJet topjet,std::vector<PFParticle>* allparts, double alpha, double beta, double gamma);

};

#endif
