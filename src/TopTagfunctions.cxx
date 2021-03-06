#include "include/TopTagfunctions.h"
#include "NtupleWriter/include/JetProps.h"
#include "include/MCDataScaleFactors.h"

#include <fastjet/JetDefinition.hh>
#include <fastjet/PseudoJet.hh>
#include <fastjet/ClusterSequence.hh>
#include <fastjet/ClusterSequenceArea.hh>
#include <fastjet/GhostedAreaSpec.hh>
namespace external {
#include "include/HEPTopTagger.h"
}
#include "SFrameTools/include/EventCalc.h"
using namespace std;
using namespace fastjet;
using namespace contrib;


vector<fastjet::PseudoJet> Get_varRJet(fastjet::ClusterSequence &clusterSq){
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
  //  delete JetDef;
  return SortedJets;

}

double IntegratedSubJetShape(fastjet::PseudoJet subjet, double rmax, double rmin){
 
  double R = 0;
  /* if (type == e_CA8) R=0.8;
  else if (type == e_CA15) R=1.5;
  else if (type == e_AK5) R=0.5;
  else {
  m_logger << ERROR << "EventCalc::IntegratedJetShape: can not determine radius for this type of jet, return Psi=-1" << SLogger::endmsg;
  return -1;
  }
  */
  R=0.8;
  //std::vector<PFParticle> pfps = GetJetPFParticles(jet); 
  std::vector<fastjet::PseudoJet> pfps= subjet.pieces();
  double pt_tot=0;
  double pt_frac=0;
 
  for(unsigned int i=0; i< pfps.size(); i++){
  
  if( pfps[i].delta_R(subjet) >= rmin && pfps[i].delta_R(subjet) <= rmax) pt_frac += pfps[i].pt();
  if( pfps[i].delta_R(subjet) >= rmin && pfps[i].delta_R(subjet) <= R) pt_tot += pfps[i].pt();
  }
 
  double psi=0;
  if(pt_tot>0) psi=pt_frac/pt_tot;
  return psi;
 }




bool jet_matches_top(TopJet topjet, float cone){
  
  EventCalc* calc = EventCalc::Instance();
  for(unsigned int k=0;k<calc->GetGenParticles()->size();++k){
	GenParticle top=calc->GetGenParticles()->at(k);
	if((abs(calc->GetGenParticles()->at(k).pdgId())==6) &&  (sqrt(pow(topjet.phi()-top.phi(),2)+pow(topjet.eta()-top.eta(),2))<cone)) return true;
	
	
  }
  return false;
}
bool jet_decays_hadronic(TopJet topjet, float cone) {

  EventCalc* calc = EventCalc::Instance();
  TTbarGen* Decay = calc->GetTTbarGen();
  GenParticle top;
   GenParticle atop;
   bool btop=false;
   bool btop2=false;
   if (Decay->IsTopHadronicDecay()) {
     top=Decay->Top();
     // if(topjet.pt()>700) std::cout<<"1"<<std::endl;
     btop=true;
}
   if (Decay->IsAntiTopHadronicDecay()) {
     atop=Decay->Antitop();
     // if(topjet.pt()>700) std::cout<<"2"<<std::endl;
     btop2=true;
}
 
   // if(topjet.pt()>700) std::cout<<topjet.pt()<<std::endl;
     if (topjet.deltaR(top)<cone ||topjet.deltaR(atop)<cone ) return true;
   // if (sqrt(pow(topjet.phi()-atop.phi(),2)+pow(topjet.eta()-atop.eta(),2))<cone) return true;
   else {
       if((btop || btop2) && topjet.pt()>700) {
	 std::cout<<topjet.deltaR(top)<<std::endl;
	 std::cout<<topjet.deltaR(atop)<<std::endl;
	 std::cout<<topjet.pt()<<" "<<topjet.phi()<<" "<<topjet.eta()<<" "<<topjet.v4().M()<<std::endl;
      for(unsigned int k=0;k<calc->GetGenParticles()->size();k++){
	 GenParticle particle=calc->GetGenParticles()->at(k);
	 	 particle.Print(calc->GetGenParticles());
      }}
     //  std::cout<<topjet.pt()<<std::endl;
     // if(topjet.pt()>700) std::cout<<topjet.deltaR(top)<<std::endl;
     // if(topjet.pt()>700) std::cout<<topjet.deltaR(atop)<<std::endl;
 return false;
   }
}


/*bool jet_decays_hadronic(TopJet topjet, float cone) {

  EventCalc* calc = EventCalc::Instance();
   for(unsigned int k=0;k<calc->GetGenParticles()->size();k++){
     GenParticle top=calc->GetGenParticles()->at(k);
     if(abs(calc->GetGenParticles()->at(k).pdgId())==6) std::cout<<topjet.deltaR(top)<<std::endl;
     if((abs(calc->GetGenParticles()->at(k).pdgId())==6) &&  topjet.deltaR(top)<cone){
      if(abs(top.daughter(calc->GetGenParticles(),1)->pdgId())==24) {
       if((abs(top.daughter(calc->GetGenParticles(),1)->daughter(calc->GetGenParticles(),1)->pdgId())<7)) return true;
       }
       else if((abs(top.daughter(calc->GetGenParticles(),2)->daughter(calc->GetGenParticles(),1)->pdgId())<7)) return true;
    
       return true;}
   }
   return false;
   }
*/


   bool jet_decays_leptonic(TopJet topjet, float cone) {

  EventCalc* calc = EventCalc::Instance();
   for(unsigned int k=0;k<calc->GetGenParticles()->size();k++){
     GenParticle top=calc->GetGenParticles()->at(k);
     if((abs(calc->GetGenParticles()->at(k).pdgId())==6) &&  (sqrt(pow(topjet.phi()-top.phi(),2)+pow(topjet.eta()-top.eta(),2))<cone))
       if(abs(top.daughter(calc->GetGenParticles(),1)->pdgId())==24) {
       if((abs(top.daughter(calc->GetGenParticles(),1)->daughter(calc->GetGenParticles(),1)->pdgId())>7)) return true;
       }
       else if((abs(top.daughter(calc->GetGenParticles(),2)->daughter(calc->GetGenParticles(),1)->pdgId())>7)) return true;
	
   }
   return false;
   }


 bool vec_matches_leptonic_decay(LorentzVector vec, float cone) {

  EventCalc* calc = EventCalc::Instance();
   for(unsigned int k=0;k<calc->GetGenParticles()->size();++k){
     GenParticle top=calc->GetGenParticles()->at(k);
     if((abs(calc->GetGenParticles()->at(k).pdgId())==6) &&  (sqrt(pow(vec.Phi()-top.phi(),2)+pow(vec.Eta()-top.eta(),2))<cone))
       if(abs(top.daughter(calc->GetGenParticles(),1)->pdgId())==24) {
       if((abs(top.daughter(calc->GetGenParticles(),1)->daughter(calc->GetGenParticles(),1)->pdgId())>7)) return true;
       }
       else if((abs(top.daughter(calc->GetGenParticles(),2)->daughter(calc->GetGenParticles(),1)->pdgId())>7)) return true;
	
   }
   return false;
   }

bool decay_products_in_jet_had(TopJet topjet, float cone){
      EventCalc* calc = EventCalc::Instance();
      for(unsigned int k=0;k<calc->GetGenParticles()->size();++k){
     GenParticle top=calc->GetGenParticles()->at(k);
     if(sqrt(pow(topjet.phi()-top.phi(),2)+pow(topjet.eta()-top.eta(),2))<0.8){
     if((abs(calc->GetGenParticles()->at(k).pdgId())==6)){
     const GenParticle *quark1;
     const GenParticle *quark2;
     const GenParticle *quark3;
     if(abs(top.daughter(calc->GetGenParticles(),1)->pdgId())==24){
       const GenParticle *quark1=top.daughter(calc->GetGenParticles(),2);
     const GenParticle *wboson=top.daughter(calc->GetGenParticles(),1);
     const GenParticle *quark2=top.daughter(calc->GetGenParticles(),1)->daughter(calc->GetGenParticles(),1);
     const GenParticle *quark3=top.daughter(calc->GetGenParticles(),1)->daughter(calc->GetGenParticles(),2);
    }
      else
       if(abs(top.daughter(calc->GetGenParticles(),2)->pdgId())==24){
	 const GenParticle *quark1=top.daughter(calc->GetGenParticles(),1);
     const GenParticle *wboson=top.daughter(calc->GetGenParticles(),2);
     const GenParticle *quark2=top.daughter(calc->GetGenParticles(),2)->daughter(calc->GetGenParticles(),1);
     const GenParticle *quark3=top.daughter(calc->GetGenParticles(),2)->daughter(calc->GetGenParticles(),2);
       }
     /* const GenParticle *quark2=top.daughter(calc->GetGenParticles(),2)->daughter(calc->GetGenParticles(),1);
	const GenParticle *quark3=wboson.daughter(calc->GetGenParticles(),2);*/
      if(sqrt(pow(topjet.phi()-quark1->phi(),2)+pow(topjet.eta()-quark1->eta(),2))<cone && sqrt(pow(topjet.phi()-quark2->phi(),2)+pow(topjet.eta()-quark2->eta(),2))<cone && sqrt(pow(topjet.phi()-quark3->phi(),2)+pow(topjet.eta()-quark3->eta(),2))<cone) return true;
     }}
	
      }

   
   return false;
}

double distance_quark(TopJet topjet, int nquark, float cone){
  EventCalc* calc = EventCalc::Instance();
      for(unsigned int k=0;k<calc->GetGenParticles()->size();++k){
     GenParticle top=calc->GetGenParticles()->at(k);
     if((abs(calc->GetGenParticles()->at(k).pdgId())==6)){
       if(sqrt(pow(topjet.phi()-top.phi(),2)+pow(topjet.eta()-top.eta(),2))<0.8){
     const GenParticle *quark1;
     const GenParticle *quark2;
     const GenParticle *quark3;
     const GenParticle *wboson;
     if(abs(top.daughter(calc->GetGenParticles(),1)->pdgId())==24){
     quark1=top.daughter(calc->GetGenParticles(),2);
     wboson=top.daughter(calc->GetGenParticles(),1);
     quark2=top.daughter(calc->GetGenParticles(),1)->daughter(calc->GetGenParticles(),1);
     quark3=top.daughter(calc->GetGenParticles(),1)->daughter(calc->GetGenParticles(),2);
    }
      else
       if(abs(top.daughter(calc->GetGenParticles(),2)->pdgId())==24){
     quark1=top.daughter(calc->GetGenParticles(),1);
     wboson=top.daughter(calc->GetGenParticles(),2);
     quark2=top.daughter(calc->GetGenParticles(),2)->daughter(calc->GetGenParticles(),1);
     quark3=top.daughter(calc->GetGenParticles(),2)->daughter(calc->GetGenParticles(),2);
       }
      if(nquark==1) return sqrt(pow(topjet.phi()-quark1->phi(),2)+pow(topjet.eta()-quark1->eta(),2));
     if(nquark==2) return sqrt(pow(topjet.phi()-quark2->phi(),2)+pow(topjet.eta()-quark2->eta(),2));
     if(nquark==3) return sqrt(pow(topjet.phi()-quark3->phi(),2)+pow(topjet.eta()-quark3->eta(),2));
     /*if(nquark==1) return quark1->eta();
     if(nquark==2) return quark2->eta();
     if(nquark==3) return quark3->eta();*/
       }}
      }
}

