#include "include/VariableR.h"
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
using namespace contrib;
VariableR* VariableR::m_instance = NULL;

VariableR* VariableR::Instance()
{
  // Get a pointer to the object handler.
  // This is the only way to access this class, 
  // since it's a singleton. This method is accessible
  // from everywhere.

  if (m_instance == NULL){
    m_instance = new VariableR();
  }
  return m_instance; 
   
}


VariableR::VariableR() : m_logger("VariableR")
{
  // constructor: initialise all variables

  
  m_logger << DEBUG << "Constructor called." << SLogger::endmsg;
  
     //Reset();

  
}



VariableR::~VariableR()
{
  // default destructor
  
}


fastjet::PseudoJet VariableR::Get_varRSubJet(TopJet topjet,std::vector<PFParticle>* allparts , double pTcut, double conesize, fastjet::ClusterSequence &clusterSq, double &subjetmass, double &mmin, double &rho){
  fastjet::JetDefinition* JetDef ;
  std::vector<fastjet::PseudoJet> SortedJets;
  JetProps jp(&topjet, allparts);
  std::vector<fastjet::PseudoJet> jetpart = jp.GetJetConstituents();
  double nsubjets=0;
  int count=0;
  rho=172.;
  double min_r(0.0), max_r(1.0),ptmin(10.);
  while(nsubjets<3 && rho>0){
    
    rho=rho-2;
  VariableRPlugin lvjet_pluginCA(rho, min_r, max_r, VariableRPlugin::CALIKE);
  fastjet::JetDefinition jet_defCA(&lvjet_pluginCA);
  fastjet::ClusterSequence clust_seqCA(jetpart, jet_defCA);
  clusterSq=clust_seqCA;
  vector<fastjet::PseudoJet> inclusive_jetsCA = clust_seqCA.inclusive_jets(ptmin);
  SortedJets = sorted_by_pt(inclusive_jetsCA);
  delete JetDef;
  
  //std::cout<<"pt varR "<<topjet.pt()<<" "<<SortedJets[0].perp()<<std::endl;
  //  std::cout<<"Subjets "<<SortedJets.size()<<"rho" <<rho<<std::endl;
  nsubjets=SortedJets.size();
  }
  std::cout<<"next jet"<<std::endl;
  // std::cout << "Ran " << jet_defCA.description() << std::endl;
  if(!SortedJets.size()>0) return false;
  fastjet::PseudoJet sumsubjets;
  std::vector<Particle> cms_sub=topjet.subjets();
  for(int i=0;i<SortedJets.size();i++){
    std::cout<<"subjet"<<i<<" pt "<<SortedJets[i].perp()<<" "<<SortedJets[i].eta()<<"cms "<<cms_sub[i].pt()<<" "<<cms_sub[i].eta()<<std::endl;
    sumsubjets+=SortedJets[i];
  }
  //std::cout<<topjet.v4().M()<<" "<<sumsubjets.m()<<std::endl;
  subjetmass=sumsubjets.m();


  nsubjets=SortedJets.size();
  if(nsubjets<3){
    return false;
  }
  double m01 = 0;
  m01=(SortedJets[0]+SortedJets[1]).m();
  double m02 = 0;
  m02=(SortedJets[0]+SortedJets[2]).m();
 double m12 = 0; 
 m12 = (SortedJets[1]+SortedJets[2]).m();
   mmin = std::min(m01,std::min(m02,m12));



  return SortedJets[0];
 

  }


vector<fastjet::PseudoJet> VariableR::Get_varRJet(fastjet::ClusterSequence &clusterSq){
  EventCalc* calc = EventCalc::Instance();
  fastjet::JetDefinition *JetDef ;
  std::vector<fastjet::PseudoJet> SortedJets;
  TopJet topjet;
  JetProps jp(&topjet,calc->GetPFParticles());
  std::vector<fastjet::PseudoJet> jetpart = jp.Get_all_pfparticles();
  double min_r(0.1), max_r(2.0),ptmin(10.),rho(100.);
  VariableRPlugin lvjet_pluginCA(rho, min_r, max_r, VariableRPlugin::CALIKE);
  fastjet::JetDefinition jet_defCA(&lvjet_pluginCA);
  fastjet::ClusterSequence clust_seqCA(jetpart, jet_defCA);
  vector<fastjet::PseudoJet> inclusive_jetsCA = clust_seqCA.inclusive_jets(ptmin);
  SortedJets = sorted_by_pt(inclusive_jetsCA);
  //  std::cout<<"bla2"<<std::endl;
  for(int i=0;i<SortedJets.size();i++){
   
     std::vector<fastjet::PseudoJet> pfcands = SortedJets[i].exclusive_subjets_up_to(1000);
     double oldR=0;
     
     for(int j=0;j<pfcands.size();j++){
       double R=SortedJets[i].delta_R(pfcands[j]);
       // std::cout<<"pf distance "<<R<<std::endl;
	 if(R>oldR){
	  
	   oldR=R;
	 }
       }
     // std::cout<<"maxR "<<oldR<<std::endl;
     SortedJets[i].set_user_index(int(oldR*10));
     //  std::cout<<"maxR "<< SortedJets[i].user_index()<<std::endl;
     //  std::cout<<"pt "<< SortedJets[i].perp()<<std::endl;
     }
  // std::vector<fastjet::PseudoJet> pfcands = SortedJets[0].pieces();
  //std::cout<<"test2"<<std::endl;
  delete JetDef;
  return SortedJets;

}

double VariableR::Get_Jetsize(fastjet::PseudoJet pseudojet,fastjet::ClusterSequence clusterSq){
  std::cout<<"test"<<std::endl;
  std::vector<fastjet::PseudoJet> pfcands = pseudojet.pieces();
  std::cout<<"Pieces "<<pfcands.size()<<std::endl;
  double distance;
  for(int i=0; i<pfcands.size(); i++){
    distance=pseudojet.plain_distance(pfcands[i]);
    std::cout<<"distance "<<distance<<std::endl;
  }

}





/*double VariableR::Get_subjetPSI(fastjet::PseudoJet subjet, double rmin, double rmax, double R){
  }*/


