#include "include/ZPrimeDecay.h"

using namespace std;

ZPrimeDecay::ZPrimeDecay(  BaseCycleContainer* bcc )
{
   m_pdgId1 = 0;
   m_pdgId2 = 0;

   
   for(/*unsigned*/ int i = 0; i < bcc->genparticles->size(); i++)
      {
         GenParticle genp = bcc->genparticles->at(i);
         if(genp.pdgId() == 32)
            {
	      m_ZPrime = genp;
	      if(genp.daughter(bcc->genparticles,1) && genp.daughter(bcc->genparticles,2)) //Gibt es zwei Toechter?
		 {                  
		   if(genp.daughter(bcc->genparticles,1)->pdgId() == 24) //Ist erste Tochter ein W?
		     {
		       GenParticle genp2 = bcc->genparticles->at(genp.daughter(bcc->genparticles,1)->index()); //genp2 ist TOchter des ZPrime: Immer ein W
		       bool end = false;
		       while(!end)
			 {
			   if(genp2.daughter(bcc->genparticles,1)) if(genp2.daughter(bcc->genparticles,1)->pdgId() == 24)  genp2 = bcc->genparticles->at(genp2.daughter(bcc->genparticles,1)->index());	//genp2 = index() ?????
			     else end=true;
			   else end=true;
			 }       //While-Schleife geht so lange, bis W nicht mehr ein W ist, sondern zerfaellt!!
		       
		       m_indexW = genp.daughter(bcc->genparticles,1)->index();
		       m_WZPrime = bcc->genparticles->at(m_indexW);
		       if(genp2.daughter(bcc->genparticles,1) && genp2.daughter(bcc->genparticles,2))
			 {
			   if(/*genp2.status() >= 21 &&  genp2.status() <= 29*/true)
			     {
			       m_index1 = genp2.daughter(bcc->genparticles,1)->index();
			       m_Wdecay1 = bcc->genparticles->at(genp2.daughter(bcc->genparticles,1)->index());
			       m_pdgId1= genp2.daughter(bcc->genparticles,1)->pdgId();                        /// Was genau wird hier zugeordnet?
			       m_index2 = genp2.daughter(bcc->genparticles,2)->index();
			       m_Wdecay2 = bcc->genparticles->at(m_index2);
			     }
			 }
                           
		       m_indexb = genp.daughter(bcc->genparticles,2)->index();        //Falsch, da statt einem b-Quark ein zweites W vorhanden ist!
		       m_bZPrime = bcc->genparticles->at(m_indexb);
		     }

		   if(genp.daughter(bcc->genparticles,2)->pdgId() == 24) //Ist zweite Tochter ein W?
		     {
		       GenParticle genp2=bcc->genparticles->at(genp.daughter(bcc->genparticles,2)->index());
		       bool end=false;
		       while(!end){
			 
			 if(genp2.daughter(bcc->genparticles,1)) if(genp2.daughter(bcc->genparticles,1)->pdgId() == 24 /*&& genp.status() >= 21 &&  genp.status() <= 29*/)  genp2=bcc->genparticles->at(genp2.daughter(bcc->genparticles,1)->index());	
			   else end=true;
			 else end=true;
		       }
                       
		       m_indexW = genp.daughter(bcc->genparticles,2)->index();
		       m_WZPrime = bcc->genparticles->at(m_indexW);
		       if(genp2.daughter(bcc->genparticles,1) && genp2.daughter(bcc->genparticles,2))
			 {
			   if(/*genp2.status() >= 21 &&  genp2.status() <= 29*/true)
			     {
			       m_index1 = genp2.daughter(bcc->genparticles,1)->index();
			       m_Wdecay1 = bcc->genparticles->at(m_index1);
			       m_pdgId1= genp2.daughter(bcc->genparticles,1)->pdgId();
			       m_index2 = genp2.daughter(bcc->genparticles,2)->index();
			       m_Wdecay2 = bcc->genparticles->at(m_index2);
			     }
			 }
		       
		       m_indexb = genp.daughter(bcc->genparticles,1)->index();
		       m_bZPrime = bcc->genparticles->at(m_indexb);
		     }
		 }
            }

         if ( genp.pdgId() == -32)
	   {
	     m_AntiZPrime = genp;
	     if (genp.daughter(bcc->genparticles,1) && (genp.daughter(bcc->genparticles,2)))
	       {
                     
		 if (genp.daughter(bcc->genparticles,1)->pdgId() == -24 /*&&  genp.status() >= 21 &&  genp.status() <= 29*/) 
		   {
		     GenParticle genp2=bcc->genparticles->at(genp.daughter(bcc->genparticles,1)->index());
		     bool end=false;
		     while(!end){
		       if(genp2.daughter(bcc->genparticles,1)) if(genp2.daughter(bcc->genparticles,1)->pdgId() == -24/*&& genp.status() >= 21 &&  genp.status() <= 29*/)  genp2=bcc->genparticles->at(genp2.daughter(bcc->genparticles,1)->index());	
			 else end=true;
		       else end=true;
		     }
		     m_indexW = genp.daughter(bcc->genparticles,1)->index();
		     m_WAntiZPrime = bcc->genparticles->at(m_indexW);
		     if(genp2.daughter(bcc->genparticles,1) && genp2.daughter(bcc->genparticles,2)){
		       if(/*genp2.status() >= 21 &&  genp2.status() <= 29*/true)
			 {
			   m_index1 = genp2.daughter(bcc->genparticles,1)->index();
			   m_WMinusdecay1 = bcc->genparticles->at(m_index1);
			   m_pdgId2= genp2.daughter(bcc->genparticles,1)->pdgId();
			   m_index2 = genp2.daughter(bcc->genparticles,2)->index();
			   m_WMinusdecay2 = bcc->genparticles->at(m_index2);
			 }
		     }
		     m_indexb = genp.daughter(bcc->genparticles,2)->index();
		     m_bAntiZPrime = bcc->genparticles->at(m_indexb);
		   }
		 if (genp.daughter(bcc->genparticles,2)->pdgId() == -24 /*&& genp.status() >= 21 &&  genp.status() <= 29*/)
		   {
		     GenParticle genp2=bcc->genparticles->at(genp.daughter(bcc->genparticles,2)->index());
		     bool end=false;
		     while(!end){
		       if(genp2.daughter(bcc->genparticles,1)) if(genp2.daughter(bcc->genparticles,1)->pdgId() == -24 /*&& genp.status() >= 21 &&  genp.status() <= 29*/)  genp2=bcc->genparticles->at(genp2.daughter(bcc->genparticles,1)->index());	
			 else end=true;
		       else end=true;
		     }
		     m_indexW = genp.daughter(bcc->genparticles,2)->index();
		     m_WAntiZPrime = bcc->genparticles->at(m_indexW);
                           
		     if(genp2.daughter(bcc->genparticles,1) && genp2.daughter(bcc->genparticles,2)){
		       if(/*genp2.status() >= 21 &&  genp2.status() <= 29*/true)
			 {
			   m_index1 = genp2.daughter(bcc->genparticles,1)->index();
			   m_WMinusdecay1 = bcc->genparticles->at(genp2.daughter(bcc->genparticles,1)->index());
			   m_pdgId2= genp2.daughter(bcc->genparticles,1)->pdgId();
			   m_index2 = genp2.daughter(bcc->genparticles,2)->index();
			   m_WMinusdecay2 = bcc->genparticles->at(genp2.daughter(bcc->genparticles,2)->index());
			 }
		     }
                           
		     m_indexb = genp.daughter(bcc->genparticles,1)->index();
		     m_bAntiZPrime = bcc->genparticles->at(m_indexb);
		   }
	       }
	   }
         
      }
   
   
}   
 

ZPrimeDecay::~ZPrimeDecay()
{
  // default destructor, does nothing
}

GenParticle ZPrimeDecay::ZPrime()
{
  return m_ZPrime;
}

GenParticle ZPrimeDecay::AntiZPrime()
{
  return m_AntiZPrime;
} 

GenParticle ZPrimeDecay::WZPrime()
{
  return m_WZPrime;
}

GenParticle ZPrimeDecay::WAntiZPrime()
{
  return m_WAntiZPrime;
}

GenParticle ZPrimeDecay::bZPrime()
{
  return m_bZPrime;
}

GenParticle ZPrimeDecay::bAntiZPrime()
{
  return m_bAntiZPrime;
} 

GenParticle ZPrimeDecay::Wdecay1()
{
  return m_Wdecay1;
} 

GenParticle ZPrimeDecay::Wdecay2()
{
  return m_Wdecay2;
} 

GenParticle ZPrimeDecay::WMinusdecay1()
{
  return m_WMinusdecay1;
} 

GenParticle ZPrimeDecay::WMinusdecay2()
{
  return m_WMinusdecay2;
} 

ZPrimeDecay::E_DecayChannel ZPrimeDecay::DecayChannel()
{  
  m_type = e_notfound;
 
  if ((abs(m_pdgId1)==11 || abs(m_pdgId1)==12) && (abs(m_pdgId2)==11 || abs(m_pdgId2)==12)) m_type = e_ee;
  if ((abs(m_pdgId1)==13 || abs(m_pdgId1)==14) && (abs(m_pdgId2)==13 || abs(m_pdgId2)==14)) m_type = e_mumu;
  if ((abs(m_pdgId1)==15 || abs(m_pdgId1)==16) && (abs(m_pdgId2)==15 || abs(m_pdgId2)==16)) m_type = e_tautau;
  if ((abs(m_pdgId1)<=5) && (abs(m_pdgId2)<=5))                                             m_type = e_had;
  if ((abs(m_pdgId1)==11 || abs(m_pdgId1)==12) && (abs(m_pdgId2)<=5))                       m_type = e_ehad;
  if ((abs(m_pdgId2)==11 || abs(m_pdgId2)==12) && (abs(m_pdgId1)<=5))                       m_type = e_ehad;
  if ((abs(m_pdgId1)==13 || abs(m_pdgId1)==14) && (abs(m_pdgId2)<=5))                       m_type = e_muhad;
  if ((abs(m_pdgId2)==13 || abs(m_pdgId2)==14) && (abs(m_pdgId1)<=5))                       m_type = e_muhad;
  if ((abs(m_pdgId1)==15 || abs(m_pdgId1)==16) && (abs(m_pdgId2)<=5))                       m_type = e_tauhad;
  if ((abs(m_pdgId2)==15 || abs(m_pdgId2)==16) && (abs(m_pdgId1)<=5))                       m_type = e_tauhad;
  if ((abs(m_pdgId1)==11 || abs(m_pdgId1)==12) && (abs(m_pdgId2)==13 || abs(m_pdgId2)==14)) m_type = e_emu;
  if ((abs(m_pdgId2)==11 || abs(m_pdgId2)==12) && (abs(m_pdgId1)==13 || abs(m_pdgId1)==14)) m_type = e_emu;
  if ((abs(m_pdgId1)==11 || abs(m_pdgId1)==12) && (abs(m_pdgId2)==15 || abs(m_pdgId2)==16)) m_type = e_etau;
  if ((abs(m_pdgId2)==11 || abs(m_pdgId2)==12) && (abs(m_pdgId1)==15 || abs(m_pdgId1)==16)) m_type = e_etau;
  if ((abs(m_pdgId1)==13 || abs(m_pdgId1)==14) && (abs(m_pdgId2)==15 || abs(m_pdgId2)==16)) m_type = e_mutau;
  if ((abs(m_pdgId2)==13 || abs(m_pdgId2)==14) && (abs(m_pdgId1)==15 || abs(m_pdgId1)==16)) m_type = e_mutau;
  if(m_pdgId1==0 || m_pdgId2==0) m_type = e_notfound;
  return m_type;
}

bool ZPrimeDecay::IsZPrimeHadronicDecay()
{
  //std::cout<<"done2"<<std::endl;
  if (abs(m_pdgId1)<=5) return true;
  else return false;
}

bool ZPrimeDecay::IsAntiZPrimeHadronicDecay()
{
  if (abs(m_pdgId2)<=5) return true;
  else return false;
}

GenParticle ZPrimeDecay::ChargedLepton(){
  GenParticle lepton;  
  if (m_type != e_ehad &&  m_type != e_muhad  && m_type!= e_tauhad){
    std::cerr << "This is no l+jets ttbar event, no charged lepton found" <<std::endl;
    return lepton;
  }

  int nlepton=0;
  if(abs(Wdecay1().pdgId())==11 || abs(Wdecay1().pdgId())==13 || abs(Wdecay1().pdgId())==15){
    lepton = Wdecay1();
    nlepton++;
  }
  if(abs(Wdecay2().pdgId())==11 || abs(Wdecay2().pdgId())==13 || abs(Wdecay2().pdgId())==15){
    lepton = Wdecay2();
    nlepton++;
  }
  if(abs(WMinusdecay1().pdgId())==11 || abs(WMinusdecay1().pdgId())==13 || abs(WMinusdecay1().pdgId())==15){
    lepton = WMinusdecay1();
    nlepton++;
  }
  if(abs(WMinusdecay2().pdgId())==11 || abs(WMinusdecay2().pdgId())==13 || abs(WMinusdecay2().pdgId())==15){
    lepton = WMinusdecay2();
    nlepton++;
  }
  if(nlepton!=1) std::cerr << "Not exactly one lepton found " << nlepton<< std::endl;

  return lepton;

}

GenParticle ZPrimeDecay::Neutrino(){
  GenParticle neutrino;
  
  if (m_type != e_ehad &&  m_type != e_muhad  && m_type!= e_tauhad){
    std::cerr << "This is no l+jets ttbar event, no neutrino found" <<std::endl;
    return neutrino;
  }

  int nneutrino=0;
  if(abs(Wdecay1().pdgId())==12 || abs(Wdecay1().pdgId())==14 || abs(Wdecay1().pdgId())==16){
    neutrino = Wdecay1();
    nneutrino++;
  }
  if(abs(Wdecay2().pdgId())==12 || abs(Wdecay2().pdgId())==14 || abs(Wdecay2().pdgId())==16){
    neutrino = Wdecay2();
    nneutrino++;
  }
  if(abs(WMinusdecay1().pdgId())==12 || abs(WMinusdecay1().pdgId())==14 || abs(WMinusdecay1().pdgId())==16){
    neutrino = WMinusdecay1();
    nneutrino++;
  }
  if(abs(WMinusdecay2().pdgId())==12 || abs(WMinusdecay2().pdgId())==14 || abs(WMinusdecay2().pdgId())==16){
    neutrino = WMinusdecay2();
    nneutrino++;
  }
  if(nneutrino!=1) std::cerr << "Not exactly one neutrino found " << nneutrino<< std::endl;

  return neutrino;

}

GenParticle ZPrimeDecay::ZPrimeLep(){
 
  if(ChargedLepton().charge()>0) return ZPrime();
  else return AntiZPrime();

}

GenParticle ZPrimeDecay::ZPrimeHad(){

  if(ChargedLepton().charge()<0) return ZPrime();
  else return AntiZPrime();

}


GenParticle ZPrimeDecay::BLep(){
 
  if(ChargedLepton().charge()>0) return bZPrime();
  else return bAntiZPrime();

}

GenParticle ZPrimeDecay::BHad(){
 
  if(ChargedLepton().charge()<0) return bZPrime();
  else return bAntiZPrime();

}

GenParticle ZPrimeDecay::WLep(){
 
  if(ChargedLepton().charge()>0) return WZPrime();
  else return WAntiZPrime();

}

GenParticle ZPrimeDecay::WHad(){
 
  if(ChargedLepton().charge()<0) return WZPrime();
  else return WAntiZPrime();

}

GenParticle ZPrimeDecay::Q1(){
 
  if(ChargedLepton().charge()>0) return WMinusdecay1();
  else return Wdecay1();

}

GenParticle ZPrimeDecay::Q2(){
 
  if(ChargedLepton().charge()>0) return WMinusdecay2();
  else return Wdecay2();

}

