#ifndef TopTagfunctions_H
#define TopTagfunctions_H

#include "SFrameTools/include/Objects.h"
#include "SFrameTools/include/fwd.h"
#include "SFrameTools/include/boost_includes.h" // for shared_array
#include <fastjet/PseudoJet.hh>
#include "TVector3.h"
#include <limits>
#include <algorithm>
#include <memory>
#include <TF1.h>
#include "fastjet/contrib/VariableRPlugin.hh"






std::vector<fastjet::PseudoJet> Get_varRJet(fastjet::ClusterSequence &clusterSq);
double IntegratedSubJetShape(fastjet::PseudoJet subjet, double rmax, double rmin );
bool jet_matches_top(TopJet topjet, float cone);
bool jet_decays_hadronic(TopJet topjet, float cone);
bool jet_decays_leptonic(TopJet topjet, float cone);
bool vec_matches_leptonic_decay(LorentzVector vec, float cone);
bool decay_products_in_jet_had(TopJet topjet, float cone);
double distance_quark(TopJet topjet, int nquarks, float cone);

#endif
