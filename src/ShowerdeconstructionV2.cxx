#include "include/ShowerdeconstructionV2.h"
#include "NtupleWriter/include/JetProps.h"

#include <fastjet/JetDefinition.hh>
#include <fastjet/PseudoJet.hh>
#include <fastjet/ClusterSequence.hh>
#include <fastjet/ClusterSequenceArea.hh>
#include <fastjet/GhostedAreaSpec.hh>
#include "SFrameTools/include/EventCalc.h"

#include "include/TopTagfunctions.h"
#include "AnalysisParameters.h"
#include "Exception.h"

#include "Message.h"
#include "Exception.h"
#include "AnalysisParameters.h"
#include "TopGluonModel.h"
#include "BackgroundModel.h"
#include "ISRModel.h"
#include "Deconstruct.h"
#include "ParseUtils.h"

using namespace std;
using namespace Deconstruction;

ShowerdeconstructionV2* ShowerdeconstructionV2::m_instance = NULL;

ShowerdeconstructionV2* ShowerdeconstructionV2::Instance()
{
  // Get a pointer to the object handler.
  // This is the only way to access this class, 
  // since it's a singleton. This method is accessible
  // from everywhere.

  if (m_instance == NULL){
    m_instance = new ShowerdeconstructionV2();
  }
  return m_instance; 
   
}


ShowerdeconstructionV2::ShowerdeconstructionV2() : m_logger("ShowerdeconstructionV2")
{
  // constructor: initialise all variables

  
  //   m_logger << DEBUG << "Constructor called." << SLogger::endmsg;
  
     //Reset();

  
}



ShowerdeconstructionV2::~ShowerdeconstructionV2()
{
  // default destructor
  
}

double ShowerdeconstructionV2::ChiMicro_MultiR(TopJet topjet, int &nmicrojets, double &Mmicrojet, double microjet_cone,  std::vector<fastjet::PseudoJet> &microjets){
   std::string inputcard = "/afs/desy.de/user/t/tlapsien/Analysis/Sframex/LapsienAnalysis/src/input_card.dat";
   AnalysisParameters param(inputcard);
   TopGluonModel *signal = 0;
  BackgroundModel *background = 0;
  ISRModel *isr = 0;
  Deconstruct *deconstruct = 0;
  signal = new TopGluonModel(param);
  background = new BackgroundModel(param);
  isr = new ISRModel(param);
  deconstruct = new Deconstruct(param, *signal, *background, *isr);
  EventCalc* calc = EventCalc::Instance();
  BaseCycleContainer* bcc = calc->GetBaseCycleContainer();
  fastjet::PseudoJet sumpseudojet;
  fastjet::PseudoJet multiRjet=Get_new_jet(topjet, calc->GetPFParticles(),0.2);
  



  double Psignal = 0.0;
  double Pbackground = 0.0;
 
   std::vector<PFParticle> jetconst =  calc->GetJetPFParticles(&topjet);
  std::vector<PFParticle>* jetconst2 = &jetconst;
  JetProps jp(&topjet,calc->GetPFParticles());
  if(calc->GetJetPFParticles()==NULL) std::cout<<"hallo"<<std::endl;
  std::vector<fastjet::PseudoJet> pseudojets = jp.GetFastJet(microjet_cone,fastjet::kt_algorithm);

  for(int i=0;i<pseudojets.size();i++){
    fastjet::PseudoJet MicroJet=pseudojets[i];
    if(sqrt(pow(MicroJet.phi()-multiRjet.phi(),2)+pow(MicroJet.eta()-multiRjet.eta(),2))>0.2) pseudojets.erase(pseudojets.begin()+i);

  }



  if(pseudojets.size()>9) pseudojets.erase(pseudojets.begin()+9,pseudojets.end());
  microjets=pseudojets;
  nmicrojets=pseudojets.size();
 
   if(nmicrojets>9) nmicrojets=9;
  int nmicrojetstrue=0;
  bool test=false;
   
      for(unsigned int j=0;j<nmicrojets;++j){
     fastjet::PseudoJet pseudojet=pseudojets[j];

     nmicrojetstrue++;
    
      
     sumpseudojet+=pseudojet;
   

     
     }
     
Mmicrojet=sumpseudojet.m();
 double chi;
 try {
  chi = deconstruct->deconstruct(pseudojets, Psignal, Pbackground);
 
    } catch(Deconstruction::Exception &e) {
   std::cout << "Exception while running SD: " << e.what() << std::endl;
   }

 return chi;
}




double ShowerdeconstructionV2::ChiMicro(TopJet topjet, int &nmicrojets, double &Mmicrojet, double microjet_cone,  std::vector<fastjet::PseudoJet> &microjets){
   std::string inputcard = "/afs/desy.de/user/t/tlapsien/Analysis/Sframex/LapsienAnalysis/src/input_card.dat";
   AnalysisParameters param(inputcard);
   TopGluonModel *signal = 0;
  BackgroundModel *background = 0;
  ISRModel *isr = 0;
  Deconstruct *deconstruct = 0;
  // std::cout<<inputcard<<std::endl;
  signal = new TopGluonModel(param);
  background = new BackgroundModel(param);
  isr = new ISRModel(param);
  deconstruct = new Deconstruct(param, *signal, *background, *isr);
  EventCalc* calc = EventCalc::Instance();
  BaseCycleContainer* bcc = calc->GetBaseCycleContainer();
  fastjet::PseudoJet sumpseudojet;
  // std::vector<JetCorrectorParameters> pars;
  // pars.push_back(JetCorrectorParameters("/nfs/dust/cms/user/peiffer/CMSSW_5_3_10/src/START53_V27_L1FastJet_AK5PFchs.txt"));
   //  FactorizedJetCorrector* corrector = new FactorizedJetCorrector(pars);
   //corrector = new FactorizedJetCorrector(subpars);



  double Psignal = 0.0;
  double Pbackground = 0.0;
 
   std::vector<PFParticle> jetconst =  calc->GetJetPFParticles(&topjet);
  std::vector<PFParticle>* jetconst2 = &jetconst;
  JetProps jp(&topjet,calc->GetPFParticles());
  if(calc->GetJetPFParticles()==NULL) std::cout<<"hallo"<<std::endl;
  std::vector<fastjet::PseudoJet> pseudojets = jp.GetFastJet(microjet_cone,fastjet::kt_algorithm);
  if(pseudojets.size()>9) pseudojets.erase(pseudojets.begin()+9,pseudojets.end());
  microjets=pseudojets;
  nmicrojets=pseudojets.size();
  /* for(unsigned int j=0;j<pseudojets.size();++j) {
    fastjet::PseudoJet pseudojet2=pseudojets[j];
    if(pseudojet2.pt()<20) nmicrojets=nmicrojets-1;
    }*/
   if(nmicrojets>9) nmicrojets=9;
  int nmicrojetstrue=0;
  bool test=false;
   
      for(unsigned int j=0;j<nmicrojets;++j){
     fastjet::PseudoJet pseudojet=pseudojets[j];

     nmicrojetstrue++;
    
       //else nmicrojets=nmicrojets-1;
       //     std::cout<<"E: "<<pseudojet.E()<<"px: "<<pseudojet.px()<<"py: "<<pseudojet.py()<<"pz: "<<pseudojet.pz()<<"pt: "<<pseudojet.pt()<<std::endl;
       //	  std::cout<<"FUCK"<<sqrt(pow(topjet.phi()-pseudojet.phi(),2)+pow(topjet.eta()-pseudojet.eta(),2))<<std::endl;
     sumpseudojet+=pseudojet;
   

     
     }
      //std::cout<<"alle jets"<<std::endl;
Mmicrojet=sumpseudojet.m();
 double chi;
 try {
  chi = deconstruct->deconstruct(pseudojets, Psignal, Pbackground);
  // signalWeight = deconstruct->signalWeight();
    } catch(Deconstruction::Exception &e) {
   std::cout << "Exception while running SD: " << e.what() << std::endl;
   }
// double chi=1;
 // fastjet::PseudoJet top(pTop(1),pTop(2),pTop(3),pTop(0)); 
 // Mmicrojet=top.m();
// if(chi!=0) std::cout<<chi<<"M: "<<sumpseudojet.pt()<<std::endl;
//if(chi!=0) std::cout<<Psignal<<" "<<Pbackground<<"Chi "<<chi<<" "<<nsubjets<<std::endl;
 return chi;
}



double ShowerdeconstructionV2::ChiMicro_pseudo(fastjet::PseudoJet topjet, int &nmicrojets, double &Mmicrojet, double microjet_cone,  std::vector<fastjet::PseudoJet> &microjets){
   std::string inputcard = "/afs/desy.de/user/t/tlapsien/Analysis/Sframex/LapsienAnalysis/src/input_card.dat";
   AnalysisParameters param(inputcard);
   TopGluonModel *signal = 0;
  BackgroundModel *background = 0;
  ISRModel *isr = 0;
  Deconstruct *deconstruct = 0;
  // std::cout<<inputcard<<std::endl;
  signal = new TopGluonModel(param);
  background = new BackgroundModel(param);
  isr = new ISRModel(param);
  deconstruct = new Deconstruct(param, *signal, *background, *isr);
  EventCalc* calc = EventCalc::Instance();
  BaseCycleContainer* bcc = calc->GetBaseCycleContainer();
  fastjet::PseudoJet sumpseudojet;
  // std::vector<JetCorrectorParameters> pars;
  // pars.push_back(JetCorrectorParameters("/nfs/dust/cms/user/peiffer/CMSSW_5_3_10/src/START53_V27_L1FastJet_AK5PFchs.txt"));
   //  FactorizedJetCorrector* corrector = new FactorizedJetCorrector(pars);
   //corrector = new FactorizedJetCorrector(subpars);



  double Psignal = 0.0;
  double Pbackground = 0.0;
 
  fastjet::ClusterSequence* JetFinder;
  fastjet::JetDefinition* JetDef ;
  JetDef = new fastjet::JetDefinition(fastjet::kt_algorithm,microjet_cone);
  std::vector<fastjet::PseudoJet> jetconst=topjet.constituents();
  JetFinder = new fastjet::ClusterSequence(jetconst, *JetDef);
  std::vector<fastjet::PseudoJet> pseudojets = JetFinder->inclusive_jets(10.);
  

  
 
 
  
  if(pseudojets.size()>9) pseudojets.erase(pseudojets.begin()+9,pseudojets.end());
  microjets=pseudojets;
  nmicrojets=pseudojets.size();
  /* for(unsigned int j=0;j<pseudojets.size();++j) {
    fastjet::PseudoJet pseudojet2=pseudojets[j];
    if(pseudojet2.pt()<20) nmicrojets=nmicrojets-1;
    }*/
   if(nmicrojets>9) nmicrojets=9;
  int nmicrojetstrue=0;
  bool test=false;
   
      for(unsigned int j=0;j<nmicrojets;++j){
     fastjet::PseudoJet pseudojet=pseudojets[j];

     nmicrojetstrue++;
    
       //else nmicrojets=nmicrojets-1;
       //     std::cout<<"E: "<<pseudojet.E()<<"px: "<<pseudojet.px()<<"py: "<<pseudojet.py()<<"pz: "<<pseudojet.pz()<<"pt: "<<pseudojet.pt()<<std::endl;
       //	  std::cout<<"FUCK"<<sqrt(pow(topjet.phi()-pseudojet.phi(),2)+pow(topjet.eta()-pseudojet.eta(),2))<<std::endl;
     sumpseudojet+=pseudojet;
   

     
     }
      //std::cout<<"alle jets"<<std::endl;
Mmicrojet=sumpseudojet.m();
 double chi;
 try {
  chi = deconstruct->deconstruct(pseudojets, Psignal, Pbackground);
  // signalWeight = deconstruct->signalWeight();
    } catch(Deconstruction::Exception &e) {
   std::cout << "Exception while running SD: " << e.what() << std::endl;
   }
// double chi=1;
 // fastjet::PseudoJet top(pTop(1),pTop(2),pTop(3),pTop(0)); 
 // Mmicrojet=top.m();
// if(chi!=0) std::cout<<chi<<"M: "<<sumpseudojet.pt()<<std::endl;
//if(chi!=0) std::cout<<Psignal<<" "<<Pbackground<<"Chi "<<chi<<" "<<nsubjets<<std::endl;
 return chi;
}






double ShowerdeconstructionV2::ChiMicro_btag(TopJet topjet, int &nmicrojets, double &Mmicrojet, double microjet_cone,  std::vector<fastjet::PseudoJet> &microjets){
   std::string inputcard = "/afs/desy.de/user/t/tlapsien/Analysis/Sframex/LapsienAnalysis/src/input_card.dat";
   AnalysisParameters param(inputcard);
   TopGluonModel *signal = 0;
  BackgroundModel *background = 0;
  ISRModel *isr = 0;
  Deconstruct *deconstruct = 0;
  //std::cout<<inputcard<<std::endl;
  signal = new TopGluonModel(param);
  background = new BackgroundModel(param);
  isr = new ISRModel(param);
  deconstruct = new Deconstruct(param, *signal, *background, *isr);
  EventCalc* calc = EventCalc::Instance();
  BaseCycleContainer* bcc = calc->GetBaseCycleContainer();
  fastjet::PseudoJet sumpseudojet;
  // std::vector<JetCorrectorParameters> pars;
  // pars.push_back(JetCorrectorParameters("/nfs/dust/cms/user/peiffer/CMSSW_5_3_10/src/START53_V27_L1FastJet_AK5PFchs.txt"));
   //  FactorizedJetCorrector* corrector = new FactorizedJetCorrector(pars);
   //corrector = new FactorizedJetCorrector(subpars);



  double Psignal = 0.0;
  double Pbackground = 0.0;
 
   std::vector<PFParticle> jetconst =  calc->GetJetPFParticles(&topjet);
  std::vector<PFParticle>* jetconst2 = &jetconst;
  JetProps jp(&topjet,calc->GetPFParticles());
  //if(calc->GetJetPFParticles()==NULL) std::cout<<"hallo"<<std::endl;
  std::vector<fastjet::PseudoJet> pseudojets = jp.GetFastJet(microjet_cone,fastjet::kt_algorithm);
  if(pseudojets.size()>9) pseudojets.erase(pseudojets.begin()+9,pseudojets.end());
  microjets=pseudojets;
  nmicrojets=pseudojets.size();
  /* for(unsigned int j=0;j<pseudojets.size();++j) {
    fastjet::PseudoJet pseudojet2=pseudojets[j];
    if(pseudojet2.pt()<20) nmicrojets=nmicrojets-1;
    }*/
   if(nmicrojets>9) nmicrojets=9;
  int nmicrojetstrue=0;
  bool test=false;
  bool is_b=false; 
      for(unsigned int j=0;j<nmicrojets;++j){
     fastjet::PseudoJet pseudojet=pseudojets[j];
     pseudojets[j].set_user_index(0);
     std::vector<Particle> subjets=topjet.subjets();
     for(int k=0;k<subjets.size();k++){
       Particle subjet=subjets[k];
       if(sqrt(pow(subjet.phi()-pseudojet.phi(),2)+pow(subjet.eta()-pseudojet.eta(),2))<0.3){
	 if(topjet.subCSV().at(k)>0.679){
	   pseudojets[j].set_user_index(1);
	   is_b=true;
	 }
	 else if(!is_b)  pseudojets[j].set_user_index(-1);

	 }
     
     }
      
     //std::Cout<<"BTAG "<<
     //pseudojets[j].set_user_index(1);
     nmicrojetstrue++;
    
       //else nmicrojets=nmicrojets-1;
       //     std::cout<<"E: "<<pseudojet.E()<<"px: "<<pseudojet.px()<<"py: "<<pseudojet.py()<<"pz: "<<pseudojet.pz()<<"pt: "<<pseudojet.pt()<<std::endl;
       //	  std::cout<<"FUCK"<<sqrt(pow(topjet.phi()-pseudojet.phi(),2)+pow(topjet.eta()-pseudojet.eta(),2))<<std::endl;
     sumpseudojet+=pseudojet;
   

     
      }
      //std::cout<<"alle jets"<<std::endl;
      for(int i=0;i<pseudojets.size();i++){
	//	std::cout<<"fastjet "<<i<<"ui "<<pseudojets[i].user_index()<<std::endl;
      }

Mmicrojet=sumpseudojet.m();
 double chi;
 try {
  chi = deconstruct->deconstruct(pseudojets, Psignal, Pbackground);
  // signalWeight = deconstruct->signalWeight();
    } catch(Deconstruction::Exception &e) {
   std::cout << "Exception while running SD: " << e.what() << std::endl;
   }
 std::cout<<"CHI: "<<chi<<std::endl;
// double chi=1;
 // fastjet::PseudoJet top(pTop(1),pTop(2),pTop(3),pTop(0)); 
 // Mmicrojet=top.m();
// if(chi!=0) std::cout<<chi<<"M: "<<sumpseudojet.pt()<<std::endl;
//if(chi!=0) std::cout<<Psignal<<" "<<Pbackground<<"Chi "<<chi<<" "<<nsubjets<<std::endl;
 return chi;
}















double ShowerdeconstructionV2::ChiMicro_btag_gen(TopJet topjet, int &nmicrojets, double &Mmicrojet, double microjet_cone,  std::vector<fastjet::PseudoJet> &microjets){
   std::string inputcard = "/afs/desy.de/user/t/tlapsien/Analysis/Sframex/LapsienAnalysis/src/input_card.dat";
   AnalysisParameters param(inputcard);
   TopGluonModel *signal = 0;
  BackgroundModel *background = 0;
  ISRModel *isr = 0;
  Deconstruct *deconstruct = 0;
  // std::cout<<inputcard<<std::endl;
  signal = new TopGluonModel(param);
  background = new BackgroundModel(param);
  isr = new ISRModel(param);
  deconstruct = new Deconstruct(param, *signal, *background, *isr);
  EventCalc* calc = EventCalc::Instance();
  BaseCycleContainer* bcc = calc->GetBaseCycleContainer();
  fastjet::PseudoJet sumpseudojet;
  // std::vector<JetCorrectorParameters> pars;
  // pars.push_back(JetCorrectorParameters("/nfs/dust/cms/user/peiffer/CMSSW_5_3_10/src/START53_V27_L1FastJet_AK5PFchs.txt"));
   //  FactorizedJetCorrector* corrector = new FactorizedJetCorrector(pars);
   //corrector = new FactorizedJetCorrector(subpars);



  double Psignal = 0.0;
  double Pbackground = 0.0;
 
   std::vector<PFParticle> jetconst =  calc->GetJetPFParticles(&topjet);
  std::vector<PFParticle>* jetconst2 = &jetconst;
  JetProps jp(&topjet,calc->GetPFParticles());
  //if(calc->GetJetPFParticles()==NULL) std::cout<<"hallo"<<std::endl;
  std::vector<fastjet::PseudoJet> pseudojets = jp.GetFastJet(microjet_cone,fastjet::kt_algorithm);
  if(pseudojets.size()>9) pseudojets.erase(pseudojets.begin()+9,pseudojets.end());
  microjets=pseudojets;
  nmicrojets=pseudojets.size();
  /* for(unsigned int j=0;j<pseudojets.size();++j) {
    fastjet::PseudoJet pseudojet2=pseudojets[j];
    if(pseudojet2.pt()<20) nmicrojets=nmicrojets-1;
    }*/
   if(nmicrojets>9) nmicrojets=9;
  int nmicrojetstrue=0;
  bool test=false;
  bool no_b=true;
  const GenParticle *bquark;
 for(unsigned int k=0;k<calc->GetGenParticles()->size();++k){
	GenParticle top=calc->GetGenParticles()->at(k);

	if((abs(calc->GetGenParticles()->at(k).pdgId())==6) &&  (sqrt(pow(topjet.phi()-top.phi(),2)+pow(topjet.eta()-top.eta(),2))<0.8)) {
	  if((abs(top.daughter(calc->GetGenParticles(),2)->pdgId())==5)) bquark=top.daughter(calc->GetGenParticles(),2);
	  else if((abs(top.daughter(calc->GetGenParticles(),1)->pdgId())==5)) bquark=top.daughter(calc->GetGenParticles(),1);
	  no_b=false;
	}
	//else no_b=true;
	
	
  }


      for(unsigned int j=0;j<nmicrojets;++j){
     fastjet::PseudoJet pseudojet=pseudojets[j];
     pseudojets[j].set_user_index(0);
     if(no_b) pseudojets[j].set_user_index(-1);
      if(sqrt(pow(bquark->phi()-pseudojet.phi(),2)+pow(bquark->eta()-pseudojet.eta(),2))<0.5 && !no_b)  pseudojets[j].set_user_index(1);
      else  pseudojets[j].set_user_index(-1);

	 
     
      

     //std::Cout<<"BTAG "<<
     //pseudojets[j].set_user_index(1);
     nmicrojetstrue++;
    
       //else nmicrojets=nmicrojets-1;
       //     std::cout<<"E: "<<pseudojet.E()<<"px: "<<pseudojet.px()<<"py: "<<pseudojet.py()<<"pz: "<<pseudojet.pz()<<"pt: "<<pseudojet.pt()<<std::endl;
       //	  std::cout<<"FUCK"<<sqrt(pow(topjet.phi()-pseudojet.phi(),2)+pow(topjet.eta()-pseudojet.eta(),2))<<std::endl;
     sumpseudojet+=pseudojet;
   

     
     }
      //std::cout<<"alle jets"<<std::endl;
      for(int i=0;i<pseudojets.size();i++){
	std::cout<<"fastjet "<<i<<"ui "<<pseudojets[i].user_index()<<std::endl;
      }

Mmicrojet=sumpseudojet.m();
 double chi;
 try {
  chi = deconstruct->deconstruct(pseudojets, Psignal, Pbackground);
  // signalWeight = deconstruct->signalWeight();
    } catch(Deconstruction::Exception &e) {
   std::cout << "Exception while running SD: " << e.what() << std::endl;
   }
 std::cout<<"CHI: "<<chi<<std::endl;
// double chi=1;
 // fastjet::PseudoJet top(pTop(1),pTop(2),pTop(3),pTop(0)); 
 // Mmicrojet=top.m();
// if(chi!=0) std::cout<<chi<<"M: "<<sumpseudojet.pt()<<std::endl;
//if(chi!=0) std::cout<<Psignal<<" "<<Pbackground<<"Chi "<<chi<<" "<<nsubjets<<std::endl;
 return chi;
}






/*
double ShowerdeconstructionV2::ChiPF(TopJet topjet, int &nmicrojets, double &Mmicrojet){
  LorentzVector sumpfparticle;
  double Psignal = 0.0;
  double Pbackground = 0.0;
  DES::fourvector pTop;
  EventCalc* calc = EventCalc::Instance();
  std::vector<PFParticle> jetconst =  calc->GetJetPFParticles(&topjet);
  // std::vector<PFParticle>* jetconst =  calc->GetPFParticles();
  nmicrojets=jetconst.size();
  if(nmicrojets>9) nmicrojets=9;
  bool test=false;
   DES::microjet mJ[DES::maxsize];
      for(unsigned int j=0;j<nmicrojets;++j){
	PFParticle pfparticle=jetconst[j];
	LorentzVector pfparticlev4=pfparticle.v4();
	DES::microjet mjet(pfparticlev4.E(),pfparticlev4.px(),pfparticlev4.py(),pfparticlev4.pz());
	 std::cout<<"E: "<<pfparticlev4.E()<<"px: "<<pfparticlev4.px()<<"py: "<<pfparticlev4.py()<<"pz: "<<pfparticlev4.pz()<<"pt: "<<pfparticlev4.pt()<<std::endl;
	 std::cout<<"FUCK"<<sqrt(pow(topjet.phi()-pfparticlev4.phi(),2)+pow(topjet.eta()-pfparticlev4.eta(),2))<<std::endl;
	sumpfparticle+=pfparticlev4;
   
     mJ[j] = mjet;
     }
Mmicrojet=sumpfparticle.M();
double chi = DES::Chi(mJ,nmicrojets,Psignal,Pbackground, pTop);
 if(chi!=0) std::cout<<chi<<"signal: "<<Psignal<<"Background "<<Pbackground<<"pt: "<<sumpfparticle.pt()<<std::endl;
//if(chi!=0) std::cout<<Psignal<<" "<<Pbackground<<"Chi "<<chi<<" "<<nsubjets<<std::endl;
 return chi;
}

*/

int ShowerdeconstructionV2::GetNmicrojets(TopJet topjet){
  EventCalc* calc = EventCalc::Instance();
  JetProps jp(&topjet, calc->GetPFParticles() );
  std::vector<fastjet::PseudoJet> pseudojets = jp.GetFastJet(0.2);
  int nmicrojets=pseudojets.size();
  return nmicrojets;

}
