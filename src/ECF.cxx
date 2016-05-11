#include "include/ECF.h"
#include "NtupleWriter/include/JetProps.h"
#include "NtupleWriter/interface/GenJetProps.h"
#include <fastjet/JetDefinition.hh>
#include <fastjet/PseudoJet.hh>
#include <fastjet/ClusterSequence.hh>
#include <fastjet/ClusterSequenceArea.hh>
#include <fastjet/GhostedAreaSpec.hh>
#include "fastjet/contrib/SoftDrop.hh"
#include "fastjet/contrib/EnergyCorrelator.hh"
#include "SFrameTools/include/EventCalc.h"

#include "include/TopTagfunctions.h"
#include "include/topquark.h"

using namespace std;
using namespace fastjet;
using namespace fastjet::contrib;
ECF* ECF::m_instance = NULL;

ECF* ECF::Instance()
{
  // Get a pointer to the object handler.
  // This is the only way to access this class, 
  // since it's a singleton. This method is accessible
  // from everywhere.

  if (m_instance == NULL){
    m_instance = new ECF();
  }
  return m_instance; 
   
}


ECF::ECF() : m_logger("ECF")
{
  // constructor: initialise all variables

  
  m_logger << DEBUG << "Constructor called." << SLogger::endmsg;
  
     //Reset();

  
}



ECF::~ECF()
{
  // default destructor
  
}


double ECF::Get_C(TopJet topjet,std::vector<PFParticle>* allparts , int N, double beta){
  fastjet::ClusterSequence* JetFinder;
  fastjet::JetDefinition* JetDef ;

  JetProps jp(&topjet, allparts);
  std::vector<fastjet::PseudoJet> jetpart = jp.GetJetConstituents();
  double conesize=3;
  JetDef = new fastjet::JetDefinition(fastjet::antikt_algorithm,conesize); 

  JetFinder = new fastjet::ClusterSequence(jetpart, *JetDef);

  std::vector<fastjet::PseudoJet> jets = JetFinder->inclusive_jets(10.);
   if (jets.size() == 0){
    delete JetFinder;
    delete JetDef;
    return false;
  }
   std::vector<fastjet::PseudoJet> SortedJets = sorted_by_pt(jets);
  EnergyCorrelatorDoubleRatio C(N,beta,EnergyCorrelator::pt_R);
  
  
  return C(SortedJets[0]);
}



double  ECF::Get_D3(TopJet topjet,std::vector<PFParticle>* allparts , double alpha, double beta, double gamma){
   fastjet::ClusterSequence* JetFinder;
  fastjet::JetDefinition* JetDef ;

  JetProps jp(&topjet, allparts);
  std::vector<fastjet::PseudoJet> jetpart = jp.GetJetConstituents();
  double conesize=3;
  JetDef = new fastjet::JetDefinition(fastjet::cambridge_algorithm,conesize); 

  JetFinder = new fastjet::ClusterSequence(jetpart, *JetDef);

  std::vector<fastjet::PseudoJet> jets = JetFinder->inclusive_jets(10.);
   if (jets.size() == 0){
    delete JetFinder;
    delete JetDef;
    return false;
  }
   std::vector<fastjet::PseudoJet> SortedJets = sorted_by_pt(jets);
   
     EnergyCorrelator ecf2(2,alpha,EnergyCorrelator::pt_R);
   EnergyCorrelator ecf3(3,beta,EnergyCorrelator::pt_R);
   EnergyCorrelator ecf4(4,gamma,EnergyCorrelator::pt_R);
   std::cout<<SortedJets[0].pt()<<std::endl;
   double ECF2=ecf2(SortedJets[0]);
     double ECF3=ecf3(SortedJets[0]);
   double ECF4=ecf4(SortedJets[0]);

   double m_top=172;
   double pT_cut=500;
   double kappa_1=1.;
   double kappa_2=1.;
   double x=kappa_1*pow(pow(pT_cut,2)/pow(m_top,2),alpha*gamma/beta-alpha/2);
   double y=kappa_2*pow(pow(pT_cut,2)/pow(m_top,2),5*gamma/2-2*beta);
   

   /*  double D3= pow(ECF4,gamma)*pow(pow(ECF2,alpha),3*gamma/alpha)/pow(pow(ECF3,beta),3*gamma/beta)+x*pow(ECF4,gamma)*pow(pow(ECF2,alpha),2*gamma/beta-1)/pow(pow(ECF3,beta),2*gamma/beta)+y*pow(ECF4,gamma)*pow(pow(ECF2,alpha),2*beta/alpha-gamma/alpha)/pow(pow(ECF3,beta),2);*/
    double D3= ECF4*pow(ECF2,3*gamma/alpha)/pow(ECF3,3*gamma/beta)+x*ECF4*pow(ECF2,2*gamma/beta-1)/pow(ECF3,2*gamma/beta)+y*ECF4*pow(ECF2,2*beta/alpha-gamma/alpha)/pow(ECF3,2);
   std::cout<<"d3 "<<D3<<std::endl;

  return D3;
}
