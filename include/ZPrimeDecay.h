#ifndef ZPrimeDecay_H
#define ZPrimeDecay_H

#include "TLorentzVector.h"
#include "SFrameTools/include/Objects.h"
#include "SFrameTools/include/BaseCycleContainer.h"

/**
 *   Class for WW generator truth information
 */

class ZPrimeDecay
{
  
 public:
  /// Default constructor, loops over generator particle list and fills the relevant particles
  ZPrimeDecay(BaseCycleContainer* bcc);
  
  /// Default destructor
  ~ZPrimeDecay();

  enum E_DecayChannel{
    e_had, 
    e_ehad, 
    e_muhad,
    e_tauhad,
    e_ee,  
    e_mumu,
    e_tautau,
    e_emu,
    e_etau,
    e_mutau,
    e_notfound
  };

  GenParticle ZPrime(); 
  GenParticle AntiZPrime();
  GenParticle WZPrime(); 
  GenParticle WAntiZPrime(); 
  GenParticle bZPrime(); 
  GenParticle bAntiZPrime(); 
  GenParticle Wdecay1(); 
  GenParticle Wdecay2(); 
  GenParticle WMinusdecay1(); 
  GenParticle WMinusdecay2();
  E_DecayChannel DecayChannel();

  bool IsZPrimeHadronicDecay();
  bool IsAntiZPrimeHadronicDecay();

  //only for l+jets decays
  GenParticle ZPrimeLep(); 
  GenParticle ZPrimeHad();
  GenParticle BLep();
  GenParticle BHad(); 
  GenParticle WLep();
  GenParticle WHad(); 
  GenParticle ChargedLepton();
  GenParticle Neutrino();
  GenParticle Q1();
  GenParticle Q2(); 

  
 private:

  GenParticle m_ZPrime; 
  GenParticle m_AntiZPrime;
  GenParticle m_WZPrime; 
  GenParticle m_WAntiZPrime;
  GenParticle m_bZPrime; 
  GenParticle m_bAntiZPrime;
  GenParticle m_Wdecay1; 
  GenParticle m_Wdecay2; 
  GenParticle m_WMinusdecay1; 
  GenParticle m_WMinusdecay2; 
  int m_pdgId1;
  int m_pdgId2;
  int m_indexW;
  int m_indexb;
  int m_index1;
  int m_index2;

  E_DecayChannel m_type;


}; // class ZPrimeDecay


#endif // ZPrimeDecay_H
