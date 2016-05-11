#include "include/Showerdeconstruction.h"
#include "NtupleWriter/include/JetProps.h"
#include "NtupleWriter/interface/GenJetProps.h"
#include <fastjet/JetDefinition.hh>
#include <fastjet/PseudoJet.hh>
#include <fastjet/ClusterSequence.hh>
#include <fastjet/ClusterSequenceArea.hh>
#include <fastjet/GhostedAreaSpec.hh>
#include "SFrameTools/include/EventCalc.h"

#include "include/TopTagfunctions.h"
#include "include/topquark.h"

using namespace std;

Showerdeconstruction* Showerdeconstruction::m_instance = NULL;

Showerdeconstruction* Showerdeconstruction::Instance()
{
  // Get a pointer to the object handler.
  // This is the only way to access this class, 
  // since it's a singleton. This method is accessible
  // from everywhere.

  if (m_instance == NULL){
    m_instance = new Showerdeconstruction();
  }
  return m_instance; 
   
}


Showerdeconstruction::Showerdeconstruction() : m_logger("TMVA_tagger")
{
  // constructor: initialise all variables

  
  m_logger << DEBUG << "Constructor called." << SLogger::endmsg;
  
     //Reset();

  
}



Showerdeconstruction::~Showerdeconstruction()
{
  // default destructor
  
}

double Showerdeconstruction::Chi(TopJet topjet){
  double Psignal = 0.0;
  double Pbackground = 0.0;
  DES::fourvector pTop;
  std::vector<Particle> subjets = topjet.subjets();
  sort(subjets.begin(),subjets.end(),HigherPt());
  int nsubjets = subjets.size();
  DES::microjet mJ[DES::maxsize];
  for(unsigned int j=0;j<nsubjets;++j){
    Particle subjet = subjets[j];
    LorentzVector microjet = subjet.v4();
    DES::microjet mjet(microjet.E(),microjet.px(),microjet.py(),microjet.pz());
    /* std::cout<<"E: "<<microjet.E()<<std::endl;
    std::cout<<"px: "<<microjet.Px()<<std::endl;
    std::cout<<"py: "<<microjet.Py()<<std::endl;
    std::cout<<"pz: "<<microjet.Pz()<<std::endl;*/
    mJ[j] = mjet; 
  }
  double chi = DES::Chi(mJ,nsubjets,Psignal,Pbackground, pTop);
  // if(chi!=0) std::cout<<"ca subjets "<<Psignal<<" "<<Pbackground<<"Chi "<<chi<<" "<<nsubjets<<std::endl;
  return chi;
}/*

double Showerdeconstruction::ChiMicro(TopJet topjet){
   EventCalc* calc = EventCalc::Instance();
  JetProps jp(&topjet, calc->GetPFParticles() );
  std::cout<<"test1"<<std::endl;
  std::vector<Particle> microjets = jp.GetMicroSubjet(0.2);
  //same as in Chi
  double Psignal = 0.0;
  double Pbackground = 0.0;
  DES::fourvector pTop;
   std::cout<<"test2"<<std::endl;
  int nsubjets = microjets.size();
  if(nsubjets>9) nsubjets=9;
  DES::microjet mJ[DES::maxsize];
   std::cout<<"test3"<<std::endl;
  for(unsigned int j=0;j<nsubjets;++j){
    Particle subjet = microjets[j];
    LorentzVector microjet = subjet.v4();
    DES::microjet mjet(microjet.E(),microjet.px(),microjet.py(),microjet.pz());
    mJ[j] = mjet; 
     std::cout<<"test4"<<std::endl;
  }
  double chi = DES::Chi(mJ,nsubjets,Psignal,Pbackground, pTop);
  return chi;
  return 0;
  }*/


double Showerdeconstruction::ChiMicro(TopJet topjet, int &nmicrojets, double &Mmicrojet, double microjet_cone,  std::vector<fastjet::PseudoJet> &microjets){
  EventCalc* calc = EventCalc::Instance();
  BaseCycleContainer* bcc = calc->GetBaseCycleContainer();
  fastjet::PseudoJet sumpseudojet;
  // std::vector<JetCorrectorParameters> pars;
  // pars.push_back(JetCorrectorParameters("/nfs/dust/cms/user/peiffer/CMSSW_5_3_10/src/START53_V27_L1FastJet_AK5PFchs.txt"));
   //  FactorizedJetCorrector* corrector = new FactorizedJetCorrector(pars);
   //corrector = new FactorizedJetCorrector(subpars);



  double Psignal = 0.0;
  double Pbackground = 0.0;
  DES::fourvector pTop;
  //std::vector<PFParticle> jetconst =  calc->GetJetPFParticles(&topjet);
   // std::vector<PFParticle>* jetconst2 = &jetconst;
  JetProps jp(&topjet,calc->GetPFParticles());
  if(calc->GetJetPFParticles()==NULL) std::cout<<"hallo"<<std::endl;
  std::vector<fastjet::PseudoJet> pseudojets = jp.GetFastJet(microjet_cone,fastjet::kt_algorithm);
  microjets=pseudojets;
  nmicrojets=pseudojets.size();
  /* for(unsigned int j=0;j<pseudojets.size();++j) {
    fastjet::PseudoJet pseudojet2=pseudojets[j];
    if(pseudojet2.pt()<20) nmicrojets=nmicrojets-1;
    }*/
   if(nmicrojets>9) nmicrojets=9;
  int nmicrojetstrue=0;
  bool test=false;
    DES::microjet mJ[DES::maxsize];
      for(unsigned int j=0;j<nmicrojets;++j){
     fastjet::PseudoJet pseudojet=pseudojets[j];
     nmicrojetstrue++;
     DES::microjet mjet(pseudojet.E(),pseudojet.px(),pseudojet.py(),pseudojet.pz());
       //else nmicrojets=nmicrojets-1;
       //     std::cout<<"E: "<<pseudojet.E()<<"px: "<<pseudojet.px()<<"py: "<<pseudojet.py()<<"pz: "<<pseudojet.pz()<<"pt: "<<pseudojet.pt()<<std::endl;
       //	  std::cout<<"FUCK"<<sqrt(pow(topjet.phi()-pseudojet.phi(),2)+pow(topjet.eta()-pseudojet.eta(),2))<<std::endl;
     sumpseudojet+=pseudojet;
   
      mJ[j] = mjet;
     
     }
      //std::cout<<"alle jets"<<std::endl;
Mmicrojet=sumpseudojet.m();
double chi = DES::Chi(mJ,nmicrojets,Psignal,Pbackground, pTop);
// double chi=1;
 // fastjet::PseudoJet top(pTop(1),pTop(2),pTop(3),pTop(0)); 
 // Mmicrojet=top.m();
// if(chi!=0) std::cout<<chi<<"M: "<<sumpseudojet.pt()<<std::endl;
//if(chi!=0) std::cout<<Psignal<<" "<<Pbackground<<"Chi "<<chi<<" "<<nsubjets<<std::endl;
 return chi;
}



double Showerdeconstruction::ChiMicroGen(GenJetWithParts topjet, int &nmicrojets, double &Mmicrojet, double microjet_cone,  std::vector<fastjet::PseudoJet> &microjets){
  EventCalc* calc = EventCalc::Instance();
  BaseCycleContainer* bcc = calc->GetBaseCycleContainer();
  fastjet::PseudoJet sumpseudojet;
  // std::vector<JetCorrectorParameters> pars;
  // pars.push_back(JetCorrectorParameters("/nfs/dust/cms/user/peiffer/CMSSW_5_3_10/src/START53_V27_L1FastJet_AK5PFchs.txt"));
   //  FactorizedJetCorrector* corrector = new FactorizedJetCorrector(pars);
   //corrector = new FactorizedJetCorrector(subpars);



  double Psignal = 0.0;
  double Pbackground = 0.0;
  DES::fourvector pTop;
  
  GenJetProps jp(&topjet,calc->GetGenParticles());
  //if(calc->GetJetPFParticles()==NULL) std::cout<<"hallo"<<std::endl;
  std::vector<fastjet::PseudoJet> pseudojets = jp.GetFastJet(microjet_cone,fastjet::kt_algorithm);
  microjets=pseudojets;
  nmicrojets=pseudojets.size();
  /* for(unsigned int j=0;j<pseudojets.size();++j) {
    fastjet::PseudoJet pseudojet2=pseudojets[j];
    if(pseudojet2.pt()<20) nmicrojets=nmicrojets-1;
    }*/
   if(nmicrojets>9) nmicrojets=9;
  int nmicrojetstrue=0;
  bool test=false;
    DES::microjet mJ[DES::maxsize];
      for(unsigned int j=0;j<nmicrojets;++j){
     fastjet::PseudoJet pseudojet=pseudojets[j];
     nmicrojetstrue++;
     DES::microjet mjet(pseudojet.E(),pseudojet.px(),pseudojet.py(),pseudojet.pz());
       //else nmicrojets=nmicrojets-1;
       //     std::cout<<"E: "<<pseudojet.E()<<"px: "<<pseudojet.px()<<"py: "<<pseudojet.py()<<"pz: "<<pseudojet.pz()<<"pt: "<<pseudojet.pt()<<std::endl;
       //	  std::cout<<"FUCK"<<sqrt(pow(topjet.phi()-pseudojet.phi(),2)+pow(topjet.eta()-pseudojet.eta(),2))<<std::endl;
     sumpseudojet+=pseudojet;
   
      mJ[j] = mjet;
     
     }
      //std::cout<<"alle jets"<<std::endl;
Mmicrojet=sumpseudojet.m();
double chi = DES::Chi(mJ,nmicrojets,Psignal,Pbackground, pTop);
// double chi=1;
 // fastjet::PseudoJet top(pTop(1),pTop(2),pTop(3),pTop(0)); 
 // Mmicrojet=top.m();
// if(chi!=0) std::cout<<chi<<"M: "<<sumpseudojet.pt()<<std::endl;
//if(chi!=0) std::cout<<Psignal<<" "<<Pbackground<<"Chi "<<chi<<" "<<nsubjets<<std::endl;
 return chi;
}


double Showerdeconstruction::ChiPF(TopJet topjet, int &nmicrojets, double &Mmicrojet){
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
	//	 std::cout<<"E: "<<pfparticlev4.E()<<"px: "<<pfparticlev4.px()<<"py: "<<pfparticlev4.py()<<"pz: "<<pfparticlev4.pz()<<"pt: "<<pfparticlev4.pt()<<std::endl;
	//	 std::cout<<"FUCK"<<sqrt(pow(topjet.phi()-pfparticlev4.phi(),2)+pow(topjet.eta()-pfparticlev4.eta(),2))<<std::endl;
	sumpfparticle+=pfparticlev4;
   
     mJ[j] = mjet;
     }
Mmicrojet=sumpfparticle.M();
double chi = DES::Chi(mJ,nmicrojets,Psignal,Pbackground, pTop);
// if(chi!=0) std::cout<<chi<<"signal: "<<Psignal<<"Background "<<Pbackground<<"pt: "<<sumpfparticle.pt()<<std::endl;
//if(chi!=0) std::cout<<Psignal<<" "<<Pbackground<<"Chi "<<chi<<" "<<nsubjets<<std::endl;
 return chi;
}



int Showerdeconstruction::GetNmicrojets(TopJet topjet){
  EventCalc* calc = EventCalc::Instance();
  JetProps jp(&topjet, calc->GetPFParticles() );
  std::vector<fastjet::PseudoJet> pseudojets = jp.GetFastJet(0.2);
  int nmicrojets=pseudojets.size();
  return nmicrojets;

}
