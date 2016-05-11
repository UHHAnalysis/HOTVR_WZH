#include "include/TTbarGen2.h"
#include "include/ZPrimeEugen.h"


using namespace std;

ZPrimeEugen::ZPrimeEugen(  BaseCycleContainer* bcc )
{
  m_pdgId1 = 0;
  m_pdgId2 = 0;

  // m_WPlusDecay1 = 0;
  // m_WPlusDecayIndex1 = 0;
  // m_WPlusDecay2 = 0;
  // m_WPlusDecayIndex2 = 0;

  // m_WMinusDecay1 = 0;
  // m_WMinusDecayIndex1 = 0;
  // m_WMinusdecay2 = 0;
  // m_WMinusDecayIndex2 = 0;





  // for(int i = 0; i < bcc->genparticles->size(); ++i)
    //  {
      // bcc->genparticles->at(i).Print(bcc->genparticles);
      // 		  cout<<endl;
      // 		  cout<<endl;




      /*
      GenParticle genp = bcc->genparticles->at(i);
      if(abs(genp.pdgId() == 32))
	{			     
	  m_ZPrime = genp;
	  if(genp.daughter(bcc->genparticles,1) && genp.daughter(bcc->genparticles,2)) // Hat das ZPrime zwei Toechter?
	    {           
	      //--------------------------------------    W+   -----------------------------------------------------//
	      if(genp.daughter(bcc->genparticles,1)->pdgId() == 24) // Ist das W+ die erste Tochter?
		{
		  GenParticle genp2 = bcc->genparticles->at(genp.daughter(bcc->genparticles,1)->index()); //genp2 ist W+


		  bool end = false;
		  while(!end)
		    {
		      if(genp2.daughter(bcc->genparticles,1)) if(genp2.daughter(bcc->genparticles,1)->pdgId() == 24)  genp2 = bcc->genparticles->at(genp2.daughter(bcc->genparticles,1)->index());	
			else end=true;
		      else end=true;
		    }
		     
		     
		  if(genp2.daughter(bcc->genparticles,1) && genp2.daughter(bcc->genparticles,2)) // Hat das W+ zwei Toechter?
		    {	
		      if(abs(genp2.daughter(bcc->genparticles,1)->pdgId()) <= 6  && abs(genp2.daughter(bcc->genparticles,2)->pdgId()) <= 6) // Sind beide Toechter des W+ in Quark-Antiquark zerfallen?
			{
	      cout<<"genp2.daughter(bcc->genparticles,1)->pdgId() = "<< genp2.daughter(bcc->genparticles,1)->pdgId() << " & genp2.daughter(bcc->genparticles,1)->index() = "<<genp2.daughter(bcc->genparticles,1)->index() <<endl;
	      cout<<endl;
	      cout<<"genp2.daughter(bcc->genparticles,2)->pdgId() = "<< genp2.daughter(bcc->genparticles,2)->pdgId() << " & genp2.daughter(bcc->genparticles,2)->index() = "<<genp2.daughter(bcc->genparticles,2)->index() <<endl;
	      cout<<endl;


	      m_WPlusDecayIndex1 = genp2.daughter(bcc->genparticles,1)->index();
	      m_WPlusDecay1      = bcc->genparticles->at(m_WPlusDecayIndex1 - 1);  //Funktioniert mit -1, aber wieso???


	      cout<<"m_WPlusDecayIndex1 = "<< m_WPlusDecayIndex1<<" & m_WPlusDecay1.pdgId() = "<<m_WPlusDecay1.pdgId()<<endl;

			  m_WPlusDecayIndex2 = genp2.daughter(bcc->genparticles,2)->index();
			  m_WPlusDecay2 = bcc->genparticles->at(m_WPlusDecayIndex2 -1);
			  cout<<"genp2.daughter(bcc->genparticles,2)->index() = "<<genp2.daughter(bcc->genparticles,2)->index() <<endl;
			  cout<<"m_WPlusDecayIndex2 = "<< m_WPlusDecayIndex2<<endl;



			  cout<<"Erstes  Zerfallsprodukt des W+ = "<< m_WPlusDecay1.pdgId() <<" mit einem Index von = "<< m_WPlusDecay1.index() <<endl; 
			  cout<<"Zweites Zerfallsprodukt des W+ = "<< m_WPlusDecay2.pdgId() <<" mit einem Index von = "<< m_WPlusDecay2.index() <<endl;
			  m_WPlus = genp2;
			  
			}
		    }
		}

	      if(genp.daughter(bcc->genparticles,2)->pdgId() == 24)  // Ist das W+ die zweite Tochter?
		{                       			       		   		
		  GenParticle genp2 = bcc->genparticles->at(genp.daughter(bcc->genparticles,2)->index()); //genp2 ist W+
		  bool end=false;
		  while(!end)
		    {   
		      if(genp2.daughter(bcc->genparticles,1)) if(genp2.daughter(bcc->genparticles,1)->pdgId() == 24)  genp2=bcc->genparticles->at(genp2.daughter(bcc->genparticles,1)->index());	
			else end=true;
		      else end=true;
		    }
                           
		  // m_IndexW = genp.daughter(bcc->genparticles,2)->index();
		  // m_WZPrime = bcc->genparticles->at(m_IndexW);

		  if(genp2.daughter(bcc->genparticles,1) && genp2.daughter(bcc->genparticles,2)) // Hat das W+ zwei Toechter?
			 {
			   if(abs(genp2.daughter(bcc->genparticles,1)->pdgId()) <= 6  && abs(genp2.daughter(bcc->genparticles,2)->pdgId()) <= 6) // Sind beide Toechter des W+ in Quark-Antiquark zerfallen?
			     {
			       m_WPlusDecayIndex1 = genp2.daughter(bcc->genparticles,1)->index();
			       m_WPlusDecay1 = bcc->genparticles->at(genp2.daughter(bcc->genparticles,1)->index());
			       
			       m_WPlusDecayIndex2 = genp2.daughter(bcc->genparticles,2)->index();
			       m_WPlusDecay2 = bcc->genparticles->at(genp2.daughter(bcc->genparticles,2)->index());
			       
			       cout<<"W ist zweite Tochter "<<endl; 
			       cout<<"Erstes Zerfallsprodukt des W+ = "<<  m_WPlusDecay1.pdgId()<<endl; 
			       cout<<"Zweites Zerfallsprodukt des W+ = "<<  m_WPlusDecay2.pdgId()<<endl;
			       m_WPlus = genp2;
			     }
			 }
		}
		 */
	      /*  //--------------------------------------    W-   -----------------------------------------------------//
		  if (genp.daughter(bcc->genparticles,1)->pdgId() == -24) // Ist das W- die erste Tochter?
		  {
		  cout<<"TEST4.2 "<<endl;			   		

		  GenParticle genp2 = bcc->genparticles->at(genp.daughter(bcc->genparticles,1)->index()); //genp2 ist W-
		  bool end = false;
		  while(!end)
		  {
		  if(genp2.daughter(bcc->genparticles,1)) if(genp2.daughter(bcc->genparticles,1)->pdgId() == -24)  genp2 = bcc->genparticles->at(genp2.daughter(bcc->genparticles,1)->index());	
		  else end=true;
		  else end=true;
		  }
                       
		  m_indexAntiW = genp.daughter(bcc->genparticles,1)->index();
		  m_AntiWZPrime = bcc->genparticles->at(m_indexAntiW); 

		  if(genp2.daughter(bcc->genparticles,1) && genp2.daughter(bcc->genparticles,2)) // Hat das W- zwei Toechter?
		  {	
		  if(abs(genp2.daughter(bcc->genparticles,1)->pdgId()) <= 6  && abs(genp2.daughter(bcc->genparticles,2)->pdgId()) <= 6) // Sind beide Toechter des W- in Quark-Antiquark zerfallen?
		  {
		  m_index1 = genp2.daughter(bcc->genparticles,1)->index();
		  m_AntiWDecay1 = bcc->genparticles->at(genp2.daughter(bcc->genparticles,1)->index());
		  m_pdgId1= genp2.daughter(bcc->genparticles,1)->pdgId();
		  m_index2 = genp2.daughter(bcc->genparticles,2)->index();
		  m_AntiWDecay2 = bcc->genparticles->at(m_index2);
		  cout<<"In der Schleife: m_pdgIdW-,Tochter1 = "<<  m_pdgId1<<endl;			   		    //////////HIER WEITER MACHEN!!!!
		  //m_W = 
		  // ZPRIME??
		  }
		  }

		  // m_indexb = genp.daughter(bcc->genparticles,2)->index();
		  // m_bTop = bcc->genparticles->at(m_indexb);
		  }

		  if(genp.daughter(bcc->genparticles,2)->pdgId() == -24)  // Ist das W- die zweite Tochter?
		  {                       			       cout<<"TEST4.222 "<<endl;			   		

		  GenParticle genp2 = bcc->genparticles->at(genp.daughter(bcc->genparticles,2)->index()); //genp2 ist W-
		  bool end=false;
		  while(!end)
		  {   
		  if(genp2.daughter(bcc->genparticles,1)) if(genp2.daughter(bcc->genparticles,1)->pdgId() == -24)  genp2=bcc->genparticles->at(genp2.daughter(bcc->genparticles,1)->index());	
		  else end=true;
		  else end=true;
		  }
                           
		  m_indexAntiW = genp.daughter(bcc->genparticles,2)->index();
		  m_AntiWZPrime = bcc->genparticles->at(m_indexAntiW);

		  if(genp2.daughter(bcc->genparticles,1) && genp2.daughter(bcc->genparticles,2)) // Hat das W- zwei Toechter?
		  {
		  if(abs(genp2.daughter(bcc->genparticles,1)->pdgId()) <= 6  && abs(genp2.daughter(bcc->genparticles,2)->pdgId()) <= 6) // Sind beide Toechter des W- in Quark-Antiquark zerfallen?
		  { cout<<"TEST43333.222 "<<endl;
		  m_index1 = genp2.daughter(bcc->genparticles,1)->index();
		  m_AntiWDecay1 = bcc->genparticles->at(m_index1);
		  m_pdgId1= genp2.daughter(bcc->genparticles,1)->pdgId();
		  m_index2 = genp2.daughter(bcc->genparticles,2)->index();
		  m_AntiWDecay2 = bcc->genparticles->at(m_index2);
		  cout<<"In der Schleife: m_pdgIdW-,Tochter2 = "<<  m_pdgId1<<endl;			   		    
		  }
                           
		  //  m_indexb = genp.daughter(bcc->genparticles,1)->index();
		  //   m_bTop = bcc->genparticles->at(m_indexb);
		  }
		  }
	      
	    }
	}
	      */
  //}
	      
}

/*
bool ZPrimeEugen::IsWPlusHadronicDecay()
{
  if(abs(m_pdgId1)<=6 && m_pdgId1 != 0) return true;
  else return false;
}

bool ZPrimeEugen::IsWMinusHadronicDecay()
{
  if (abs(m_pdgId2)<=6 && m_pdgId2 != 0) return true;
  else return false;
}



GenParticle ZPrimeEugen::WPlus()    //Liefert W+ zurueck
{
  if(m_WPlus.pt() != 0)
    return m_WPlus;
}

GenParticle ZPrimeEugen::WMinus()    //Liefert W+ zurueck
{
  if(m_WMinus.pt() != 0)
    return m_WMinus;
}


GenParticle ZPrimeEugen::WMinusDecay1()   //Liefert 1tes Zerfallsprodukt des W- zurueck 
{
  return m_WMinusDecay1;
}

GenParticle ZPrimeEugen::WMinusDecay2()   //Liefert 2tes Zerfallsprodukt des W- zurueck 
{
  return m_WMinusDecay2;
}

GenParticle ZPrimeEugen::WPlusDecay1()    //Liefert 1tes Zerfallsprodukt W+ zurueck
{
  return m_WPlusDecay1;
}

GenParticle ZPrimeEugen::WPlusDecay2()    //Liefert 2tes Zerfallsprodukt W+ zurueck
{
  return m_WPlusDecay2;
}

*/


	 /*
         if ( genp.pdgId() == -32)   
            {
               m_Antitop = genp;
               if (genp.daughter(bcc->genparticles,1) && (genp.daughter(bcc->genparticles,2)))
                  {
                     
		    if (genp.daughter(bcc->genparticles,1)->pdgId() == -24) 
                        {
                           GenParticle genp2=bcc->genparticles->at(genp.daughter(bcc->genparticles,1)->index());
                           bool end=false;
                           while(!end){
			     if(genp2.daughter(bcc->genparticles,1)) if(genp2.daughter(bcc->genparticles,1)->pdgId() == -24)  genp2=bcc->genparticles->at(genp2.daughter(bcc->genparticles,1)->index());	
                                 else end=true;
                              else end=true;
                           }
                           m_indexW = genp.daughter(bcc->genparticles,1)->index();
                           m_WAntitop = bcc->genparticles->at(m_indexW);
                           if(genp2.daughter(bcc->genparticles,1) && genp2.daughter(bcc->genparticles,2)){
			     if(true)
                                 {
                                    m_index1 = genp2.daughter(bcc->genparticles,1)->index();
                                    m_WMinusdecay1 = bcc->genparticles->at(m_index1);
                                    m_pdgId2= genp2.daughter(bcc->genparticles,1)->pdgId();
                                    m_index2 = genp2.daughter(bcc->genparticles,2)->index();
                                    m_WMinusdecay2 = bcc->genparticles->at(m_index2);
				    cout<<"In der Schleife: m_pdgId21 = "<<  m_pdgId2<<endl;

                                 }
                           }
                           m_indexb = genp.daughter(bcc->genparticles,2)->index();
                           m_bAntitop = bcc->genparticles->at(m_indexb);
                        }
		    if (genp.daughter(bcc->genparticles,2)->pdgId() == -24 )
                        {
                           GenParticle genp2=bcc->genparticles->at(genp.daughter(bcc->genparticles,2)->index());
                           bool end=false;
                           while(!end){
			     if(genp2.daughter(bcc->genparticles,1)) if(genp2.daughter(bcc->genparticles,1)->pdgId() == -24 )  genp2=bcc->genparticles->at(genp2.daughter(bcc->genparticles,1)->index());	
                                 else end=true;
                              else end=true;
                           }
                           m_indexW = genp.daughter(bcc->genparticles,2)->index();
                           m_WAntitop = bcc->genparticles->at(m_indexW);
                           
                           if(genp2.daughter(bcc->genparticles,1) && genp2.daughter(bcc->genparticles,2)){
			     if(true)
                                 {
                                    m_index1 = genp2.daughter(bcc->genparticles,1)->index();
                                    m_WMinusdecay1 = bcc->genparticles->at(genp2.daughter(bcc->genparticles,1)->index());
                                    m_pdgId2= genp2.daughter(bcc->genparticles,1)->pdgId();
                                    m_index2 = genp2.daughter(bcc->genparticles,2)->index();
                                    m_WMinusdecay2 = bcc->genparticles->at(genp2.daughter(bcc->genparticles,2)->index());
				    cout<<"In der Schleife: m_pdgId22 = "<<  m_pdgId2<<endl;

                                 }
                           }
                           
                           m_indexb = genp.daughter(bcc->genparticles,1)->index();
                           m_bAntitop = bcc->genparticles->at(m_indexb);
                        }
                  }
            }
         
      }
   
}   
 */


/*
ZPrimeEugen::~ZPrimeEugen()
{
  // default destructor, does nothing
}

GenParticle ZPrimeEugen::Top()
{
  return m_Top;      //m_Top wurde oben mit m_ZPrime ersetzt
}

GenParticle ZPrimeEugen::Antitop()
{
  return m_Antitop;
} 

GenParticle ZPrimeEugen::WTop()
{
  return m_WTop;    //m_WTop wurde oben mit m_WZPrime ersetzt
}

GenParticle ZPrimeEugen::WAntitop()
{
  return m_WAntitop;
}

GenParticle ZPrimeEugen::bTop()
{
  return m_bTop;
}

GenParticle ZPrimeEugen::bAntitop()
{
  return m_bAntitop;
} 

GenParticle ZPrimeEugen::Wdecay1()
{
  return m_Wdecay1;
} 

GenParticle ZPrimeEugen::Wdecay2()
{
  return m_Wdecay2;
} 

GenParticle ZPrimeEugen::WMinusdecay1()
{
  return m_WMinusdecay1;
} 

GenParticle ZPrimeEugen::WMinusdecay2()
{
  return m_WMinusdecay2;
} 

ZPrimeEugen::E_DecayChannel ZPrimeEugen::DecayChannel()
{  
  m_type = e_notfound;
 
  if ((abs(m_pdgId1)==11 || abs(m_pdgId1)==12) && (abs(m_pdgId2)==11 || abs(m_pdgId2)==12)) m_type = e_ee;
  if ((abs(m_pdgId1)==13 || abs(m_pdgId1)==14) && (abs(m_pdgId2)==13 || abs(m_pdgId2)==14)) m_type = e_mumu;
  if ((abs(m_pdgId1)==15 || abs(m_pdgId1)==16) && (abs(m_pdgId2)==15 || abs(m_pdgId2)==16)) m_type = e_tautau;
  if ((abs(m_pdgId1)<=5) && (abs(m_pdgId2)<=5)) m_type = e_had;
  if ((abs(m_pdgId1)==11 || abs(m_pdgId1)==12) && (abs(m_pdgId2)<=5)) m_type = e_ehad;
  if ((abs(m_pdgId2)==11 || abs(m_pdgId2)==12) && (abs(m_pdgId1)<=5)) m_type = e_ehad;
  if ((abs(m_pdgId1)==13 || abs(m_pdgId1)==14) && (abs(m_pdgId2)<=5)) m_type = e_muhad;
  if ((abs(m_pdgId2)==13 || abs(m_pdgId2)==14) && (abs(m_pdgId1)<=5)) m_type = e_muhad;
  if ((abs(m_pdgId1)==15 || abs(m_pdgId1)==16) && (abs(m_pdgId2)<=5)) m_type = e_tauhad;
  if ((abs(m_pdgId2)==15 || abs(m_pdgId2)==16) && (abs(m_pdgId1)<=5)) m_type = e_tauhad;
  if ((abs(m_pdgId1)==11 || abs(m_pdgId1)==12) && (abs(m_pdgId2)==13 || abs(m_pdgId2)==14)) m_type = e_emu;
  if ((abs(m_pdgId2)==11 || abs(m_pdgId2)==12) && (abs(m_pdgId1)==13 || abs(m_pdgId1)==14)) m_type = e_emu;
  if ((abs(m_pdgId1)==11 || abs(m_pdgId1)==12) && (abs(m_pdgId2)==15 || abs(m_pdgId2)==16)) m_type = e_etau;
  if ((abs(m_pdgId2)==11 || abs(m_pdgId2)==12) && (abs(m_pdgId1)==15 || abs(m_pdgId1)==16)) m_type = e_etau;
  if ((abs(m_pdgId1)==13 || abs(m_pdgId1)==14) && (abs(m_pdgId2)==15 || abs(m_pdgId2)==16)) m_type = e_mutau;
  if ((abs(m_pdgId2)==13 || abs(m_pdgId2)==14) && (abs(m_pdgId1)==15 || abs(m_pdgId1)==16)) m_type = e_mutau;
  if(m_pdgId1==0 || m_pdgId2==0) m_type = e_notfound;
  return m_type;
}

bool ZPrimeEugen::IsTopHadronicDecay()
{
  //std::cout<<"done2"<<std::endl;
  if (abs(m_pdgId1)<=6 && m_pdgId1 != 0) return true; // War nicht gegen 0 gesichert -.-
  else return false;
}

bool ZPrimeEugen::IsAntiTopHadronicDecay()
{
  if (abs(m_pdgId2)<=6 && m_pdgId2 != 0) return true; // War nicht gegen 0 gesichert
  else return false;
}

GenParticle ZPrimeEugen::ChargedLepton(){
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

GenParticle ZPrimeEugen::Neutrino(){
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

GenParticle ZPrimeEugen::TopLep(){
 
  if(ChargedLepton().charge()>0) return Top();
  else return Antitop();

}

GenParticle ZPrimeEugen::TopHad(){

  if(ChargedLepton().charge()<0) return Top();
  else return Antitop();

}


GenParticle ZPrimeEugen::BLep(){
 
  if(ChargedLepton().charge()>0) return bTop();
  else return bAntitop();

}

GenParticle ZPrimeEugen::BHad(){
 
  if(ChargedLepton().charge()<0) return bTop();
  else return bAntitop();

}

GenParticle ZPrimeEugen::WLep(){
 
  if(ChargedLepton().charge()>0) return WTop();
  else return WAntitop();

}

GenParticle ZPrimeEugen::WHad(){
 
  if(ChargedLepton().charge()<0) return WTop();
  else return WAntitop();

}

GenParticle ZPrimeEugen::Q1(){
 
  if(ChargedLepton().charge()>0) return WMinusdecay1();
  else return Wdecay1();

}

GenParticle ZPrimeEugen::Q2(){
 
  if(ChargedLepton().charge()>0) return WMinusdecay2();
  else return Wdecay2();

}


*/
