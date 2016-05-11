#include "include/Jetswithoutjets.h"
#include "NtupleWriter/include/JetProps.h"
#include "NtupleWriter/interface/GenJetProps.h"
#include <fastjet/JetDefinition.hh>
#include <fastjet/PseudoJet.hh>
#include <fastjet/ClusterSequence.hh>
#include <fastjet/ClusterSequenceArea.hh>
#include <fastjet/GhostedAreaSpec.hh>
#include "fastjet/contrib/JetsWithoutJets.hh"
#include "SFrameTools/include/EventCalc.h"

#include "include/TopTagfunctions.h"
#include "include/topquark.h"

using namespace std;
using namespace fastjet;
using namespace fastjet::jwj;
Jetswithoutjets* Jetswithoutjets::m_instance = NULL;

Jetswithoutjets* Jetswithoutjets::Instance()
{
  // Get a pointer to the object handler.
  // This is the only way to access this class, 
  // since it's a singleton. This method is accessible
  // from everywhere.

  if (m_instance == NULL){
    m_instance = new Jetswithoutjets();
  }
  return m_instance; 
   
}


Jetswithoutjets::Jetswithoutjets() : m_logger("JetsWithoutJets")
{
  // constructor: initialise all variables

  
  m_logger << DEBUG << "Constructor called." << SLogger::endmsg;
  
     //Reset();

  
}



Jetswithoutjets::~Jetswithoutjets()
{
  // default destructor
  
}


double Jetswithoutjets::SubjetMultiplicity(TopJet topjet,std::vector<PFParticle>* allparts , double pTcut, double conesize){
  fastjet::ClusterSequence* JetFinder;
  fastjet::JetDefinition* JetDef ;

  JetProps jp(&topjet, allparts);
  std::vector<fastjet::PseudoJet> jetpart = jp.GetJetConstituents();

  ShapeJetMultiplicity_MultipleRValues Nj_allR(pTcut*topjet.pt());
  Nj_allR.set_input(jetpart);
  // std::cout << "N_jet from full R function=" <<  Nj_allR.eventShapeFor(0.1) << std::endl;
  return Nj_allR.eventShapeFor(conesize);
 

  }


std::vector<fastjet::PseudoJet> Jetswithoutjets::Get_subjets(TopJet topjet, std::vector<PFParticle>* allparts,double pTcut, double conesize){
  //std::cout<<"start"<<std::endl;
  fastjet::ClusterSequence* JetFinder;
  fastjet::JetDefinition* JetDef ;

  JetProps jp(&topjet, allparts);
  std::vector<fastjet::PseudoJet> jetpart = jp.GetJetConstituents();
  EventShapeDensity_JetAxes axes_eventShape(conesize,pTcut*topjet.pt()); //Default local recombination metric is antikt with winner-take-all scheme
   axes_eventShape.set_input(jetpart);  //Loads particles and finds axes and weights
   
   //Get jet axes (by default sorted by pt). Pt of each axis corresponds to its pt weight. 	
   vector<PseudoJet> axes = axes_eventShape.axes();
   //Get N_jet weights
   vector<double> Njw = axes_eventShape.Njet_weights();
   
   //If you want turn on global consistency and recalculate axes and weights
   axes_eventShape.setGlobalConsistencyCheck(true);
   axes_eventShape.find_axes_and_weights(); // uses stored information to save time; don't need to set_input again
   vector<PseudoJet> axes_gc = axes_eventShape.axes();
   vector<double> Njw_gc = axes_eventShape.Njet_weights();
   
   
   //If you want to use a different metric for local recombination, Cambridge-Aachen for example
   EventShapeDensity_JetAxes axes_eventShape_CA(conesize,pTcut*topjet.pt(),cambridge_algorithm);
   axes_eventShape_CA.set_input(jetpart);
   
   //Get jet axes and Njet weights	
   vector<PseudoJet> axes_CA = axes_eventShape_CA.axes();
   vector<double> Njw_CA = axes_eventShape_CA.Njet_weights();
   return axes_CA;
}
