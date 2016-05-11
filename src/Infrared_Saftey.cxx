#include "include/Infrared_Saftey.h"
#include "NtupleWriter/include/JetProps.h"
#include "NtupleWriter/interface/GenJetProps.h"
#include <fastjet/JetDefinition.hh>
#include <fastjet/PseudoJet.hh>
#include <fastjet/ClusterSequence.hh>
#include <fastjet/ClusterSequenceArea.hh>
#include <fastjet/GhostedAreaSpec.hh>
#include "fastjet/contrib/SoftDrop.hh"
#include "SFrameTools/include/EventCalc.h"
#include "TRandom3.h"
#include "include/TopTagfunctions.h"
#include "include/topquark.h"

using namespace std;

Infrared_Saftey* Infrared_Saftey::m_instance = NULL;

Infrared_Saftey* Infrared_Saftey::Instance()
{
  // Get a pointer to the object handler.
  // This is the only way to access this class, 
  // since it's a singleton. This method is accessible
  // from everywhere.

  if (m_instance == NULL){
    m_instance = new  Infrared_Saftey();
  }
  return m_instance; 
   
}


Infrared_Saftey::Infrared_Saftey() : m_logger("Infrared_Saftey")
{
  // constructor: initialise all variables

  
  m_logger << DEBUG << "Constructor called." << SLogger::endmsg;
  
     //Reset();

  
}



Infrared_Saftey::~Infrared_Saftey()
{
  // default destructor
  
}

double Infrared_Saftey::create_random(double low, double high){
  /* std::uniform_real_distribution<double> unif(low,high);
   std::default_random_engine re;
   double a_random_double = unif(re);
   return a_random_double;*/
  TRandom3 rnd = TRandom3();
   rnd.SetSeed(0);
   double r = ((high-low)*rnd.Uniform() + low);
  return r;
}


void Infrared_Saftey::add_soft_particles(std::vector<fastjet::PseudoJet> &jetpart){
  int nparticles=jetpart.size();
    TRandom3 rnd = TRandom3();
    rnd.SetSeed(0);
    int softparticles=rnd.Integer(nparticles)+1;//add n new soft particles
    // std::cout<<"---------"<<nparticles<<" "<<softparticles<<std::endl;
  for(int i=0;i<softparticles;i++){
    TLorentzVector particle;
    double pT = create_random(0,pow(10,-10));
    double phi = create_random(0,2*PI);
    double eta = create_random(0,10)-5.;
    double E = create_random(pT,pow(10,-8));
    //std::cout<<"pT "<<pT<<" phi "<<phi<<" eta "<<eta<<" E "<<E<<std::endl;
    particle.SetPtEtaPhiE(pT,eta,phi,E);
    fastjet::PseudoJet soft_particle(particle.Px(),particle.Py(),particle.Pz(),particle.E());
    if(soft_particle.m()<0)std::cout<<"ERROR"<<std::endl;
    if(soft_particle.m()>0)jetpart.push_back(soft_particle);
    //  std::cout<<"---------"<<soft_particle.perp()<<std::endl;
    // std::cout<<"Particle pT "<<particle.Px()<<" phi "<<particle.Py()<<" eta "<<particle.Pz()<<" E "<<particle.E()<<std::endl;
  }
}

void  Infrared_Saftey::add_collinear_splitting(std::vector<fastjet::PseudoJet> &jetpart){
  int nparticles=jetpart.size();
  for(int i=0;i<nparticles;i++){
    if(create_random(0,1)>0.5) {//now collinear splitting
      fastjet::PseudoJet split_particle=jetpart.at(i);
      double lambda=create_random(0,1);
      double lambda2=create_random(0,1);
      fastjet::PseudoJet jet1(lambda*split_particle.px(),lambda*split_particle.py(),lambda*split_particle.pz(),lambda*split_particle.E());
      fastjet::PseudoJet jet2=split_particle;
      jet2.operator-=(jet1);
      if(jet1.m()>0) {
      jetpart.push_back(jet1);
      jetpart.push_back(jet2);
      
      jetpart.erase(jetpart.begin()+i);
      }     
    }
  }
}


