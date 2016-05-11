#include "include/TMVA_tagger.h"
#include "NtupleWriter/include/JetProps.h"

#include <fastjet/JetDefinition.hh>
#include <fastjet/PseudoJet.hh>
#include <fastjet/ClusterSequence.hh>
#include <fastjet/ClusterSequenceArea.hh>
#include <fastjet/GhostedAreaSpec.hh>
#include "SFrameTools/include/EventCalc.h"
#include "include/TopTagfunctions.h"

using namespace std;

TMVA_tagger* TMVA_tagger::m_instance = NULL;

TMVA_tagger* TMVA_tagger::Instance()
{
  // Get a pointer to the object handler.
  // This is the only way to access this class, 
  // since it's a singleton. This method is accessible
  // from everywhere.

  if (m_instance == NULL){
    m_instance = new TMVA_tagger();
  }
  return m_instance; 
   
}


TMVA_tagger::TMVA_tagger() : m_logger("TMVA_tagger")
{
  // constructor: initialise all variables

  
  m_logger << DEBUG << "Constructor called." << SLogger::endmsg;
  
     //Reset();

  
}



TMVA_tagger::~TMVA_tagger()
{
  // default destructor
  
}

bool TMVA_tagger::IsTobiasTagged(TopJet topjet){
  TMVA_tagger::push_variables(topjet);
  //cuts
  // if(Nsubjets>1 && Nsubjets<4)
    //if(subjet1pt<300)
  // if(tau1>0.36 && tau1<0.64)
  //	if(t3t2>0 && t3t2<0.72)
	//  if(tau1pruned>0.32 && tau1pruned<0.64)
	 if(Subjet12mass>80 && Subjet12mass<110)
	{
	    TMVA_tagger::reset_variables();
	    return true;
	  }
      //   else return false;
      // else return false;
      //	else return false;
      //  else return false;
  //else return false;
  else return false;
  
}


/*void TMVA_tagger::calc_vars(TopJet topjet) {
  TMVA_tagger::push_variables(topjet);
  }*/

bool TMVA_tagger::IsTagged(TString taggername, TopJet topjet, double cutvalue, double &mva_value){
  // double mva_value;
   if(reader==NULL) TMVA_tagger::Set_Reader(taggername);
  TMVA_tagger::push_variables(topjet);
  if(!taggername.Contains("simple_cuts")) mva_value=TMVA_tagger::GetMVA_value(true);
  else mva_value=TMVA_tagger::GetMVA_value(false);
  TMVA_tagger::reset_variables();
  return mva_value>cutvalue;
}

void TMVA_tagger::reset_variables(){
 Nsubjets=0; //done
 Topjetmass=0; //done
 Subjet12mass=0; //done
 Subjet13mass=0; //done
 Subjet23mass=0; //done
 t3t2=0; //done
 t2t1=0; //done
 Q_valatility=0; //done
 npv=0; 
 Subjet12mass_pruned=0; //done
 Subjet13mass_pruned=0; //done
 Subjet23mass_pruned=0; //done
 t3t2p=0;
 t2t1p=0;
 subjet1pt=0; //sjpt1 done
 subjet2pt=0;//done	 
 subjet3pt=0; //done
 tau1=0; //done
 tau2=0; //done
 tau3=0; //done
 tau4=0;
 Topjetmass_pruned=0; //done
 tau1pruned=0; //done t1p
 tau2pruned=0; //done t2p
 tau3pruned=0; //done t3p
 HelAng12=0; //done HA12
 HelAng13=0; //done HA13
 HelAng23=0; //done HA23
 P02=0;
 P04=0;
 P06=0;
 P08=0;
 P10=0;
 w=0;
 st1=0;
 st2=0;
 st3=0;

}


void TMVA_tagger::Set_Reader(TString option) {
  reader=new TMVA::Reader();



  if(option=="pf_bdt"){
   reader->AddVariable("pf_pt1",&m_pf_pt[0]);
   reader->AddVariable("pf_pt2",&m_pf_pt[1]);
   reader->AddVariable("pf_pt3",&m_pf_pt[2]);
   reader->AddVariable("pf_pt4",&m_pf_pt[3]);
   reader->AddVariable("pf_pt5",&m_pf_pt[4]);
   reader->AddVariable("pf_pt6",&m_pf_pt[5]);
   reader->AddVariable("pf_pt7",&m_pf_pt[6]);
   reader->AddVariable("pf_pt8",&m_pf_pt[7]);
   reader->AddVariable("pf_pt9",&m_pf_pt[8]);
   reader->AddVariable("pf_pt10",&m_pf_pt[9]);

   /*  reader->AddVariable("pf_pt11",&m_pf_pt[10]);
   reader->AddVariable("pf_pt12",&m_pf_pt[11]);
   reader->AddVariable("pf_pt13",&m_pf_pt[12]);
   reader->AddVariable("pf_pt14",&m_pf_pt[13]);
   reader->AddVariable("pf_pt15",&m_pf_pt[14]);
   reader->AddVariable("pf_pt16",&m_pf_pt[15]);
   reader->AddVariable("pf_pt17",&m_pf_pt[16]);
   reader->AddVariable("pf_pt18",&m_pf_pt[17]);
   reader->AddVariable("pf_pt19",&m_pf_pt[18]);
   reader->AddVariable("pf_pt20",&m_pf_pt[19]);*/

    reader->AddVariable("pf_pt21",&m_pf_pt[20]);
   reader->AddVariable("pf_pt22",&m_pf_pt[21]);
   reader->AddVariable("pf_pt23",&m_pf_pt[22]);
   reader->AddVariable("pf_pt24",&m_pf_pt[23]);
   reader->AddVariable("pf_pt25",&m_pf_pt[24]);
   reader->AddVariable("pf_pt26",&m_pf_pt[25]);
   reader->AddVariable("pf_pt27",&m_pf_pt[26]);
   reader->AddVariable("pf_pt28",&m_pf_pt[27]);
   reader->AddVariable("pf_pt29",&m_pf_pt[28]);
   reader->AddVariable("pf_pt30",&m_pf_pt[29]);

    reader->AddVariable("pf_pt31",&m_pf_pt[30]);
   reader->AddVariable("pf_pt32",&m_pf_pt[31]);
   reader->AddVariable("pf_pt33",&m_pf_pt[32]);
   reader->AddVariable("pf_pt34",&m_pf_pt[33]);
   reader->AddVariable("pf_pt35",&m_pf_pt[34]);
   reader->AddVariable("pf_pt36",&m_pf_pt[35]);
   reader->AddVariable("pf_pt37",&m_pf_pt[36]);
   reader->AddVariable("pf_pt38",&m_pf_pt[37]);
   reader->AddVariable("pf_pt39",&m_pf_pt[38]);
   reader->AddVariable("pf_pt40",&m_pf_pt[39]);


    reader->AddVariable("pf_pt41",&m_pf_pt[40]);
   reader->AddVariable("pf_pt42",&m_pf_pt[41]);
   reader->AddVariable("pf_pt43",&m_pf_pt[42]);
   reader->AddVariable("pf_pt44",&m_pf_pt[3]);
   reader->AddVariable("pf_pt45",&m_pf_pt[44]);
   reader->AddVariable("pf_pt46",&m_pf_pt[45]);
   reader->AddVariable("pf_pt47",&m_pf_pt[46]);
   reader->AddVariable("pf_pt48",&m_pf_pt[47]);
   reader->AddVariable("pf_pt49",&m_pf_pt[48]);
   reader->AddVariable("pf_pt50",&m_pf_pt[49]);

    reader->AddVariable("pf_pt51",&m_pf_pt[50]);
   reader->AddVariable("pf_pt52",&m_pf_pt[51]);
   reader->AddVariable("pf_pt53",&m_pf_pt[52]);
   reader->AddVariable("pf_pt54",&m_pf_pt[53]);
   reader->AddVariable("pf_pt55",&m_pf_pt[54]);
   reader->AddVariable("pf_pt56",&m_pf_pt[55]);
   reader->AddVariable("pf_pt57",&m_pf_pt[56]);
   reader->AddVariable("pf_pt58",&m_pf_pt[57]);
   reader->AddVariable("pf_pt59",&m_pf_pt[58]);
   reader->AddVariable("pf_pt60",&m_pf_pt[59]);

    reader->AddVariable("pf_pt61",&m_pf_pt[60]);
   reader->AddVariable("pf_pt62",&m_pf_pt[61]);
   reader->AddVariable("pf_pt63",&m_pf_pt[62]);
   reader->AddVariable("pf_pt64",&m_pf_pt[63]);
   reader->AddVariable("pf_pt65",&m_pf_pt[64]);
   reader->AddVariable("pf_pt66",&m_pf_pt[65]);
   reader->AddVariable("pf_pt67",&m_pf_pt[66]);
   reader->AddVariable("pf_pt68",&m_pf_pt[67]);
   reader->AddVariable("pf_pt69",&m_pf_pt[68]);
   reader->AddVariable("pf_pt70",&m_pf_pt[69]);
   
    reader->AddVariable("pf_pt71",&m_pf_pt[70]);
   reader->AddVariable("pf_pt72",&m_pf_pt[71]);
   reader->AddVariable("pf_pt73",&m_pf_pt[72]);
   reader->AddVariable("pf_pt74",&m_pf_pt[73]);
   reader->AddVariable("pf_pt75",&m_pf_pt[74]);
   reader->AddVariable("pf_pt76",&m_pf_pt[75]);
   reader->AddVariable("pf_pt77",&m_pf_pt[76]);
   reader->AddVariable("pf_pt78",&m_pf_pt[77]);
   reader->AddVariable("pf_pt79",&m_pf_pt[78]);
   reader->AddVariable("pf_pt80",&m_pf_pt[79]);

   
 reader->AddVariable("pf_pt81",&m_pf_pt[80]);
   reader->AddVariable("pf_pt82",&m_pf_pt[81]);
   reader->AddVariable("pf_pt83",&m_pf_pt[82]);
   reader->AddVariable("pf_pt84",&m_pf_pt[83]);
   reader->AddVariable("pf_pt85",&m_pf_pt[84]);
   reader->AddVariable("pf_pt86",&m_pf_pt[85]);
   reader->AddVariable("pf_pt87",&m_pf_pt[86]);
   reader->AddVariable("pf_pt88",&m_pf_pt[87]);
   reader->AddVariable("pf_pt89",&m_pf_pt[88]);
   reader->AddVariable("pf_pt90",&m_pf_pt[89]);

    reader->AddVariable("pf_pt91",&m_pf_pt[90]);
   reader->AddVariable("pf_pt92",&m_pf_pt[91]);
   reader->AddVariable("pf_pt93",&m_pf_pt[92]);
   reader->AddVariable("pf_pt94",&m_pf_pt[93]);
   reader->AddVariable("pf_pt95",&m_pf_pt[94]);
   reader->AddVariable("pf_pt96",&m_pf_pt[95]);
   reader->AddVariable("pf_pt97",&m_pf_pt[96]);
   reader->AddVariable("pf_pt98",&m_pf_pt[97]);
   reader->AddVariable("pf_pt99",&m_pf_pt[98]);
   reader->AddVariable("pf_pt100",&m_pf_pt[99]);
 reader->AddVariable("pf_phi1",&m_pf_phi[0]);
   reader->AddVariable("pf_phi2",&m_pf_phi[1]);
   reader->AddVariable("pf_phi3",&m_pf_phi[2]);
   reader->AddVariable("pf_phi4",&m_pf_phi[3]);
   reader->AddVariable("pf_phi5",&m_pf_phi[4]);
   reader->AddVariable("pf_phi6",&m_pf_phi[5]);
   reader->AddVariable("pf_phi7",&m_pf_phi[6]);
   reader->AddVariable("pf_phi8",&m_pf_phi[7]);
   reader->AddVariable("pf_phi9",&m_pf_phi[8]);
   reader->AddVariable("pf_phi10",&m_pf_phi[9]);

   /*   reader->AddVariable("pf_phi11",&m_pf_phi[10]);
   reader->AddVariable("pf_phi12",&m_pf_phi[11]);
   reader->AddVariable("pf_phi13",&m_pf_phi[12]);
   reader->AddVariable("pf_phi14",&m_pf_phi[13]);
   reader->AddVariable("pf_phi15",&m_pf_phi[14]);
   reader->AddVariable("pf_phi16",&m_pf_phi[15]);
   reader->AddVariable("pf_phi17",&m_pf_phi[16]);
   reader->AddVariable("pf_phi18",&m_pf_phi[17]);
   reader->AddVariable("pf_phi19",&m_pf_phi[18]);
   reader->AddVariable("pf_phi20",&m_pf_phi[19]);*/

    reader->AddVariable("pf_phi21",&m_pf_phi[20]);
   reader->AddVariable("pf_phi22",&m_pf_phi[21]);
   reader->AddVariable("pf_phi23",&m_pf_phi[22]);
   reader->AddVariable("pf_phi24",&m_pf_phi[23]);
   reader->AddVariable("pf_phi25",&m_pf_phi[24]);
   reader->AddVariable("pf_phi26",&m_pf_phi[25]);
   reader->AddVariable("pf_phi27",&m_pf_phi[26]);
   reader->AddVariable("pf_phi28",&m_pf_phi[27]);
   reader->AddVariable("pf_phi29",&m_pf_phi[28]);
   reader->AddVariable("pf_phi30",&m_pf_phi[29]);

    reader->AddVariable("pf_phi31",&m_pf_phi[30]);
   reader->AddVariable("pf_phi32",&m_pf_phi[31]);
   reader->AddVariable("pf_phi33",&m_pf_phi[32]);
   reader->AddVariable("pf_phi34",&m_pf_phi[33]);
   reader->AddVariable("pf_phi35",&m_pf_phi[34]);
   reader->AddVariable("pf_phi36",&m_pf_phi[35]);
   reader->AddVariable("pf_phi37",&m_pf_phi[36]);
   reader->AddVariable("pf_phi38",&m_pf_phi[37]);
   reader->AddVariable("pf_phi39",&m_pf_phi[38]);
   reader->AddVariable("pf_phi40",&m_pf_phi[39]);


    reader->AddVariable("pf_phi41",&m_pf_phi[40]);
   reader->AddVariable("pf_phi42",&m_pf_phi[41]);
   reader->AddVariable("pf_phi43",&m_pf_phi[42]);
   reader->AddVariable("pf_phi44",&m_pf_phi[3]);
   reader->AddVariable("pf_phi45",&m_pf_phi[44]);
   reader->AddVariable("pf_phi46",&m_pf_phi[45]);
   reader->AddVariable("pf_phi47",&m_pf_phi[46]);
   reader->AddVariable("pf_phi48",&m_pf_phi[47]);
   reader->AddVariable("pf_phi49",&m_pf_phi[48]);
   reader->AddVariable("pf_phi50",&m_pf_phi[49]);

    reader->AddVariable("pf_phi51",&m_pf_phi[50]);
   reader->AddVariable("pf_phi52",&m_pf_phi[51]);
   reader->AddVariable("pf_phi53",&m_pf_phi[52]);
   reader->AddVariable("pf_phi54",&m_pf_phi[53]);
   reader->AddVariable("pf_phi55",&m_pf_phi[54]);
   reader->AddVariable("pf_phi56",&m_pf_phi[55]);
   reader->AddVariable("pf_phi57",&m_pf_phi[56]);
   reader->AddVariable("pf_phi58",&m_pf_phi[57]);
   reader->AddVariable("pf_phi59",&m_pf_phi[58]);
   reader->AddVariable("pf_phi60",&m_pf_phi[59]);

    reader->AddVariable("pf_phi61",&m_pf_phi[60]);
   reader->AddVariable("pf_phi62",&m_pf_phi[61]);
   reader->AddVariable("pf_phi63",&m_pf_phi[62]);
   reader->AddVariable("pf_phi64",&m_pf_phi[63]);
   reader->AddVariable("pf_phi65",&m_pf_phi[64]);
   reader->AddVariable("pf_phi66",&m_pf_phi[65]);
   reader->AddVariable("pf_phi67",&m_pf_phi[66]);
   reader->AddVariable("pf_phi68",&m_pf_phi[67]);
   reader->AddVariable("pf_phi69",&m_pf_phi[68]);
   reader->AddVariable("pf_phi70",&m_pf_phi[69]);
   
    reader->AddVariable("pf_phi71",&m_pf_phi[70]);
   reader->AddVariable("pf_phi72",&m_pf_phi[71]);
   reader->AddVariable("pf_phi73",&m_pf_phi[72]);
   reader->AddVariable("pf_phi74",&m_pf_phi[73]);
   reader->AddVariable("pf_phi75",&m_pf_phi[74]);
   reader->AddVariable("pf_phi76",&m_pf_phi[75]);
   reader->AddVariable("pf_phi77",&m_pf_phi[76]);
   reader->AddVariable("pf_phi78",&m_pf_phi[77]);
   reader->AddVariable("pf_phi79",&m_pf_phi[78]);
   reader->AddVariable("pf_phi80",&m_pf_phi[79]);

   
 reader->AddVariable("pf_phi81",&m_pf_phi[80]);
   reader->AddVariable("pf_phi82",&m_pf_phi[81]);
   reader->AddVariable("pf_phi83",&m_pf_phi[82]);
   reader->AddVariable("pf_phi84",&m_pf_phi[83]);
   reader->AddVariable("pf_phi85",&m_pf_phi[84]);
   reader->AddVariable("pf_phi86",&m_pf_phi[85]);
   reader->AddVariable("pf_phi87",&m_pf_phi[86]);
   reader->AddVariable("pf_phi88",&m_pf_phi[87]);
   reader->AddVariable("pf_phi89",&m_pf_phi[88]);
   reader->AddVariable("pf_phi90",&m_pf_phi[89]);

    reader->AddVariable("pf_phi91",&m_pf_phi[90]);
   reader->AddVariable("pf_phi92",&m_pf_phi[91]);
   reader->AddVariable("pf_phi93",&m_pf_phi[92]);
   reader->AddVariable("pf_phi94",&m_pf_phi[93]);
   reader->AddVariable("pf_phi95",&m_pf_phi[94]);
   reader->AddVariable("pf_phi96",&m_pf_phi[95]);
   reader->AddVariable("pf_phi97",&m_pf_phi[96]);
   reader->AddVariable("pf_phi98",&m_pf_phi[97]);
   reader->AddVariable("pf_phi99",&m_pf_phi[98]);
   reader->AddVariable("pf_phi100",&m_pf_phi[99]);
 reader->AddVariable("pf_eta1",&m_pf_eta[0]);
   reader->AddVariable("pf_eta2",&m_pf_eta[1]);
   reader->AddVariable("pf_eta3",&m_pf_eta[2]);
   reader->AddVariable("pf_eta4",&m_pf_eta[3]);
   reader->AddVariable("pf_eta5",&m_pf_eta[4]);
   reader->AddVariable("pf_eta6",&m_pf_eta[5]);
   reader->AddVariable("pf_eta7",&m_pf_eta[6]);
   reader->AddVariable("pf_eta8",&m_pf_eta[7]);
   reader->AddVariable("pf_eta9",&m_pf_eta[8]);
   reader->AddVariable("pf_eta10",&m_pf_eta[9]);

   /*  reader->AddVariable("pf_eta11",&m_pf_eta[10]);
   reader->AddVariable("pf_eta12",&m_pf_eta[11]);
   reader->AddVariable("pf_eta13",&m_pf_eta[12]);
   reader->AddVariable("pf_eta14",&m_pf_eta[13]);
   reader->AddVariable("pf_eta15",&m_pf_eta[14]);
   reader->AddVariable("pf_eta16",&m_pf_eta[15]);
   reader->AddVariable("pf_eta17",&m_pf_eta[16]);
   reader->AddVariable("pf_eta18",&m_pf_eta[17]);
   reader->AddVariable("pf_eta19",&m_pf_eta[18]);
   reader->AddVariable("pf_eta20",&m_pf_eta[19]);*/

    reader->AddVariable("pf_eta21",&m_pf_eta[20]);
   reader->AddVariable("pf_eta22",&m_pf_eta[21]);
   reader->AddVariable("pf_eta23",&m_pf_eta[22]);
   reader->AddVariable("pf_eta24",&m_pf_eta[23]);
   reader->AddVariable("pf_eta25",&m_pf_eta[24]);
   reader->AddVariable("pf_eta26",&m_pf_eta[25]);
   reader->AddVariable("pf_eta27",&m_pf_eta[26]);
   reader->AddVariable("pf_eta28",&m_pf_eta[27]);
   reader->AddVariable("pf_eta29",&m_pf_eta[28]);
   reader->AddVariable("pf_eta30",&m_pf_eta[29]);

    reader->AddVariable("pf_eta31",&m_pf_eta[30]);
   reader->AddVariable("pf_eta32",&m_pf_eta[31]);
   reader->AddVariable("pf_eta33",&m_pf_eta[32]);
   reader->AddVariable("pf_eta34",&m_pf_eta[33]);
   reader->AddVariable("pf_eta35",&m_pf_eta[34]);
   reader->AddVariable("pf_eta36",&m_pf_eta[35]);
   reader->AddVariable("pf_eta37",&m_pf_eta[36]);
   reader->AddVariable("pf_eta38",&m_pf_eta[37]);
   reader->AddVariable("pf_eta39",&m_pf_eta[38]);
   reader->AddVariable("pf_eta40",&m_pf_eta[39]);


    reader->AddVariable("pf_eta41",&m_pf_eta[40]);
   reader->AddVariable("pf_eta42",&m_pf_eta[41]);
   reader->AddVariable("pf_eta43",&m_pf_eta[42]);
   reader->AddVariable("pf_eta44",&m_pf_eta[3]);
   reader->AddVariable("pf_eta45",&m_pf_eta[44]);
   reader->AddVariable("pf_eta46",&m_pf_eta[45]);
   reader->AddVariable("pf_eta47",&m_pf_eta[46]);
   reader->AddVariable("pf_eta48",&m_pf_eta[47]);
   reader->AddVariable("pf_eta49",&m_pf_eta[48]);
   reader->AddVariable("pf_eta50",&m_pf_eta[49]);

    reader->AddVariable("pf_eta51",&m_pf_eta[50]);
   reader->AddVariable("pf_eta52",&m_pf_eta[51]);
   reader->AddVariable("pf_eta53",&m_pf_eta[52]);
   reader->AddVariable("pf_eta54",&m_pf_eta[53]);
   reader->AddVariable("pf_eta55",&m_pf_eta[54]);
   reader->AddVariable("pf_eta56",&m_pf_eta[55]);
   reader->AddVariable("pf_eta57",&m_pf_eta[56]);
   reader->AddVariable("pf_eta58",&m_pf_eta[57]);
   reader->AddVariable("pf_eta59",&m_pf_eta[58]);
   reader->AddVariable("pf_eta60",&m_pf_eta[59]);

    reader->AddVariable("pf_eta61",&m_pf_eta[60]);
   reader->AddVariable("pf_eta62",&m_pf_eta[61]);
   reader->AddVariable("pf_eta63",&m_pf_eta[62]);
   reader->AddVariable("pf_eta64",&m_pf_eta[63]);
   reader->AddVariable("pf_eta65",&m_pf_eta[64]);
   reader->AddVariable("pf_eta66",&m_pf_eta[65]);
   reader->AddVariable("pf_eta67",&m_pf_eta[66]);
   reader->AddVariable("pf_eta68",&m_pf_eta[67]);
   reader->AddVariable("pf_eta69",&m_pf_eta[68]);
   reader->AddVariable("pf_eta70",&m_pf_eta[69]);
   
    reader->AddVariable("pf_eta71",&m_pf_eta[70]);
   reader->AddVariable("pf_eta72",&m_pf_eta[71]);
   reader->AddVariable("pf_eta73",&m_pf_eta[72]);
   reader->AddVariable("pf_eta74",&m_pf_eta[73]);
   reader->AddVariable("pf_eta75",&m_pf_eta[74]);
   reader->AddVariable("pf_eta76",&m_pf_eta[75]);
   reader->AddVariable("pf_eta77",&m_pf_eta[76]);
   reader->AddVariable("pf_eta78",&m_pf_eta[77]);
   reader->AddVariable("pf_eta79",&m_pf_eta[78]);
   reader->AddVariable("pf_eta80",&m_pf_eta[79]);

   
 reader->AddVariable("pf_eta81",&m_pf_eta[80]);
   reader->AddVariable("pf_eta82",&m_pf_eta[81]);
   reader->AddVariable("pf_eta83",&m_pf_eta[82]);
   reader->AddVariable("pf_eta84",&m_pf_eta[83]);
   reader->AddVariable("pf_eta85",&m_pf_eta[84]);
   reader->AddVariable("pf_eta86",&m_pf_eta[85]);
   reader->AddVariable("pf_eta87",&m_pf_eta[86]);
   reader->AddVariable("pf_eta88",&m_pf_eta[87]);
   reader->AddVariable("pf_eta89",&m_pf_eta[88]);
   reader->AddVariable("pf_eta90",&m_pf_eta[89]);

    reader->AddVariable("pf_eta91",&m_pf_eta[90]);
   reader->AddVariable("pf_eta92",&m_pf_eta[91]);
   reader->AddVariable("pf_eta93",&m_pf_eta[92]);
   reader->AddVariable("pf_eta94",&m_pf_eta[93]);
   reader->AddVariable("pf_eta95",&m_pf_eta[94]);
   reader->AddVariable("pf_eta96",&m_pf_eta[95]);
   reader->AddVariable("pf_eta97",&m_pf_eta[96]);
   reader->AddVariable("pf_eta98",&m_pf_eta[97]);
   reader->AddVariable("pf_eta99",&m_pf_eta[98]);
   reader->AddVariable("pf_eta100",&m_pf_eta[99]);

   reader->AddVariable("pf_energy1",&m_pf_energy[0]);
   reader->AddVariable("pf_energy2",&m_pf_energy[1]);
   reader->AddVariable("pf_energy3",&m_pf_energy[2]);
   reader->AddVariable("pf_energy4",&m_pf_energy[3]);
   reader->AddVariable("pf_energy5",&m_pf_energy[4]);
   reader->AddVariable("pf_energy6",&m_pf_energy[5]);
   reader->AddVariable("pf_energy7",&m_pf_energy[6]);
   reader->AddVariable("pf_energy8",&m_pf_energy[7]);
   reader->AddVariable("pf_energy9",&m_pf_energy[8]);
   reader->AddVariable("pf_energy10",&m_pf_energy[9]);

   /* reader->AddVariable("pf_energy11",&m_pf_energy[10]);
   reader->AddVariable("pf_energy12",&m_pf_energy[11]);
   reader->AddVariable("pf_energy13",&m_pf_energy[12]);
   reader->AddVariable("pf_energy14",&m_pf_energy[13]);
   reader->AddVariable("pf_energy15",&m_pf_energy[14]);
   reader->AddVariable("pf_energy16",&m_pf_energy[15]);
   reader->AddVariable("pf_energy17",&m_pf_energy[16]);
   reader->AddVariable("pf_energy18",&m_pf_energy[17]);
   reader->AddVariable("pf_energy19",&m_pf_energy[18]);
   reader->AddVariable("pf_energy20",&m_pf_energy[19]);*/

    reader->AddVariable("pf_energy21",&m_pf_energy[20]);
   reader->AddVariable("pf_energy22",&m_pf_energy[21]);
   reader->AddVariable("pf_energy23",&m_pf_energy[22]);
   reader->AddVariable("pf_energy24",&m_pf_energy[23]);
   reader->AddVariable("pf_energy25",&m_pf_energy[24]);
   reader->AddVariable("pf_energy26",&m_pf_energy[25]);
   reader->AddVariable("pf_energy27",&m_pf_energy[26]);
   reader->AddVariable("pf_energy28",&m_pf_energy[27]);
   reader->AddVariable("pf_energy29",&m_pf_energy[28]);
   reader->AddVariable("pf_energy30",&m_pf_energy[29]);

    reader->AddVariable("pf_energy31",&m_pf_energy[30]);
   reader->AddVariable("pf_energy32",&m_pf_energy[31]);
   reader->AddVariable("pf_energy33",&m_pf_energy[32]);
   reader->AddVariable("pf_energy34",&m_pf_energy[33]);
   reader->AddVariable("pf_energy35",&m_pf_energy[34]);
   reader->AddVariable("pf_energy36",&m_pf_energy[35]);
   reader->AddVariable("pf_energy37",&m_pf_energy[36]);
   reader->AddVariable("pf_energy38",&m_pf_energy[37]);
   reader->AddVariable("pf_energy39",&m_pf_energy[38]);
   reader->AddVariable("pf_energy40",&m_pf_energy[39]);


    reader->AddVariable("pf_energy41",&m_pf_energy[40]);
   reader->AddVariable("pf_energy42",&m_pf_energy[41]);
   reader->AddVariable("pf_energy43",&m_pf_energy[42]);
   reader->AddVariable("pf_energy44",&m_pf_energy[3]);
   reader->AddVariable("pf_energy45",&m_pf_energy[44]);
   reader->AddVariable("pf_energy46",&m_pf_energy[45]);
   reader->AddVariable("pf_energy47",&m_pf_energy[46]);
   reader->AddVariable("pf_energy48",&m_pf_energy[47]);
   reader->AddVariable("pf_energy49",&m_pf_energy[48]);
   reader->AddVariable("pf_energy50",&m_pf_energy[49]);

    reader->AddVariable("pf_energy51",&m_pf_energy[50]);
   reader->AddVariable("pf_energy52",&m_pf_energy[51]);
   reader->AddVariable("pf_energy53",&m_pf_energy[52]);
   reader->AddVariable("pf_energy54",&m_pf_energy[53]);
   reader->AddVariable("pf_energy55",&m_pf_energy[54]);
   reader->AddVariable("pf_energy56",&m_pf_energy[55]);
   reader->AddVariable("pf_energy57",&m_pf_energy[56]);
   reader->AddVariable("pf_energy58",&m_pf_energy[57]);
   reader->AddVariable("pf_energy59",&m_pf_energy[58]);
   reader->AddVariable("pf_energy60",&m_pf_energy[59]);

    reader->AddVariable("pf_energy61",&m_pf_energy[60]);
   reader->AddVariable("pf_energy62",&m_pf_energy[61]);
   reader->AddVariable("pf_energy63",&m_pf_energy[62]);
   reader->AddVariable("pf_energy64",&m_pf_energy[63]);
   reader->AddVariable("pf_energy65",&m_pf_energy[64]);
   reader->AddVariable("pf_energy66",&m_pf_energy[65]);
   reader->AddVariable("pf_energy67",&m_pf_energy[66]);
   reader->AddVariable("pf_energy68",&m_pf_energy[67]);
   reader->AddVariable("pf_energy69",&m_pf_energy[68]);
   reader->AddVariable("pf_energy70",&m_pf_energy[69]);
   
    reader->AddVariable("pf_energy71",&m_pf_energy[70]);
   reader->AddVariable("pf_energy72",&m_pf_energy[71]);
   reader->AddVariable("pf_energy73",&m_pf_energy[72]);
   reader->AddVariable("pf_energy74",&m_pf_energy[73]);
   reader->AddVariable("pf_energy75",&m_pf_energy[74]);
   reader->AddVariable("pf_energy76",&m_pf_energy[75]);
   reader->AddVariable("pf_energy77",&m_pf_energy[76]);
   reader->AddVariable("pf_energy78",&m_pf_energy[77]);
   reader->AddVariable("pf_energy79",&m_pf_energy[78]);
   reader->AddVariable("pf_energy80",&m_pf_energy[79]);

   
 reader->AddVariable("pf_energy81",&m_pf_energy[80]);
   reader->AddVariable("pf_energy82",&m_pf_energy[81]);
   reader->AddVariable("pf_energy83",&m_pf_energy[82]);
   reader->AddVariable("pf_energy84",&m_pf_energy[83]);
   reader->AddVariable("pf_energy85",&m_pf_energy[84]);
   reader->AddVariable("pf_energy86",&m_pf_energy[85]);
   reader->AddVariable("pf_energy87",&m_pf_energy[86]);
   reader->AddVariable("pf_energy88",&m_pf_energy[87]);
   reader->AddVariable("pf_energy89",&m_pf_energy[88]);
   reader->AddVariable("pf_energy90",&m_pf_energy[89]);

    reader->AddVariable("pf_energy91",&m_pf_energy[90]);
   reader->AddVariable("pf_energy92",&m_pf_energy[91]);
   reader->AddVariable("pf_energy93",&m_pf_energy[92]);
   reader->AddVariable("pf_energy94",&m_pf_energy[93]);
   reader->AddVariable("pf_energy95",&m_pf_energy[94]);
   reader->AddVariable("pf_energy96",&m_pf_energy[95]);
   reader->AddVariable("pf_energy97",&m_pf_energy[96]);
   reader->AddVariable("pf_energy98",&m_pf_energy[97]);
   reader->AddVariable("pf_energy99",&m_pf_energy[98]);
   reader->AddVariable("pf_energy100",&m_pf_energy[99]);

   reader->AddVariable("pf_charge1",&m_pf_charge[0]);
   reader->AddVariable("pf_charge2",&m_pf_charge[1]);
   reader->AddVariable("pf_charge3",&m_pf_charge[2]);
   reader->AddVariable("pf_charge4",&m_pf_charge[3]);
   reader->AddVariable("pf_charge5",&m_pf_charge[4]);
   reader->AddVariable("pf_charge6",&m_pf_charge[5]);
   reader->AddVariable("pf_charge7",&m_pf_charge[6]);
   reader->AddVariable("pf_charge8",&m_pf_charge[7]);
   reader->AddVariable("pf_charge9",&m_pf_charge[8]);
   reader->AddVariable("pf_charge10",&m_pf_charge[9]);

   /*  reader->AddVariable("pf_charge11",&m_pf_charge[10]);
   reader->AddVariable("pf_charge12",&m_pf_charge[11]);
   reader->AddVariable("pf_charge13",&m_pf_charge[12]);
   reader->AddVariable("pf_charge14",&m_pf_charge[13]);
   reader->AddVariable("pf_charge15",&m_pf_charge[14]);
   reader->AddVariable("pf_charge16",&m_pf_charge[15]);
   reader->AddVariable("pf_charge17",&m_pf_charge[16]);
   reader->AddVariable("pf_charge18",&m_pf_charge[17]);
   reader->AddVariable("pf_charge19",&m_pf_charge[18]);
   reader->AddVariable("pf_charge20",&m_pf_charge[19]);*/

    reader->AddVariable("pf_charge21",&m_pf_charge[20]);
   reader->AddVariable("pf_charge22",&m_pf_charge[21]);
   reader->AddVariable("pf_charge23",&m_pf_charge[22]);
   reader->AddVariable("pf_charge24",&m_pf_charge[23]);
   reader->AddVariable("pf_charge25",&m_pf_charge[24]);
   reader->AddVariable("pf_charge26",&m_pf_charge[25]);
   reader->AddVariable("pf_charge27",&m_pf_charge[26]);
   reader->AddVariable("pf_charge28",&m_pf_charge[27]);
   reader->AddVariable("pf_charge29",&m_pf_charge[28]);
   reader->AddVariable("pf_charge30",&m_pf_charge[29]);

    reader->AddVariable("pf_charge31",&m_pf_charge[30]);
   reader->AddVariable("pf_charge32",&m_pf_charge[31]);
   reader->AddVariable("pf_charge33",&m_pf_charge[32]);
   reader->AddVariable("pf_charge34",&m_pf_charge[33]);
   reader->AddVariable("pf_charge35",&m_pf_charge[34]);
   reader->AddVariable("pf_charge36",&m_pf_charge[35]);
   reader->AddVariable("pf_charge37",&m_pf_charge[36]);
   reader->AddVariable("pf_charge38",&m_pf_charge[37]);
   reader->AddVariable("pf_charge39",&m_pf_charge[38]);
   reader->AddVariable("pf_charge40",&m_pf_charge[39]);


    reader->AddVariable("pf_charge41",&m_pf_charge[40]);
   reader->AddVariable("pf_charge42",&m_pf_charge[41]);
   reader->AddVariable("pf_charge43",&m_pf_charge[42]);
   reader->AddVariable("pf_charge44",&m_pf_charge[3]);
   reader->AddVariable("pf_charge45",&m_pf_charge[44]);
   reader->AddVariable("pf_charge46",&m_pf_charge[45]);
   reader->AddVariable("pf_charge47",&m_pf_charge[46]);
   reader->AddVariable("pf_charge48",&m_pf_charge[47]);
   reader->AddVariable("pf_charge49",&m_pf_charge[48]);
   reader->AddVariable("pf_charge50",&m_pf_charge[49]);

    reader->AddVariable("pf_charge51",&m_pf_charge[50]);
   reader->AddVariable("pf_charge52",&m_pf_charge[51]);
   reader->AddVariable("pf_charge53",&m_pf_charge[52]);
   reader->AddVariable("pf_charge54",&m_pf_charge[53]);
   reader->AddVariable("pf_charge55",&m_pf_charge[54]);
   reader->AddVariable("pf_charge56",&m_pf_charge[55]);
   reader->AddVariable("pf_charge57",&m_pf_charge[56]);
   reader->AddVariable("pf_charge58",&m_pf_charge[57]);
   reader->AddVariable("pf_charge59",&m_pf_charge[58]);
   reader->AddVariable("pf_charge60",&m_pf_charge[59]);

    reader->AddVariable("pf_charge61",&m_pf_charge[60]);
   reader->AddVariable("pf_charge62",&m_pf_charge[61]);
   reader->AddVariable("pf_charge63",&m_pf_charge[62]);
   reader->AddVariable("pf_charge64",&m_pf_charge[63]);
   reader->AddVariable("pf_charge65",&m_pf_charge[64]);
   reader->AddVariable("pf_charge66",&m_pf_charge[65]);
   reader->AddVariable("pf_charge67",&m_pf_charge[66]);
   reader->AddVariable("pf_charge68",&m_pf_charge[67]);
   reader->AddVariable("pf_charge69",&m_pf_charge[68]);
   reader->AddVariable("pf_charge70",&m_pf_charge[69]);
   
    reader->AddVariable("pf_charge71",&m_pf_charge[70]);
   reader->AddVariable("pf_charge72",&m_pf_charge[71]);
   reader->AddVariable("pf_charge73",&m_pf_charge[72]);
   reader->AddVariable("pf_charge74",&m_pf_charge[73]);
   reader->AddVariable("pf_charge75",&m_pf_charge[74]);
   reader->AddVariable("pf_charge76",&m_pf_charge[75]);
   reader->AddVariable("pf_charge77",&m_pf_charge[76]);
   reader->AddVariable("pf_charge78",&m_pf_charge[77]);
   reader->AddVariable("pf_charge79",&m_pf_charge[78]);
   reader->AddVariable("pf_charge80",&m_pf_charge[79]);

   
 reader->AddVariable("pf_charge81",&m_pf_charge[80]);
   reader->AddVariable("pf_charge82",&m_pf_charge[81]);
   reader->AddVariable("pf_charge83",&m_pf_charge[82]);
   reader->AddVariable("pf_charge84",&m_pf_charge[83]);
   reader->AddVariable("pf_charge85",&m_pf_charge[84]);
   reader->AddVariable("pf_charge86",&m_pf_charge[85]);
   reader->AddVariable("pf_charge87",&m_pf_charge[86]);
   reader->AddVariable("pf_charge88",&m_pf_charge[87]);
   reader->AddVariable("pf_charge89",&m_pf_charge[88]);
   reader->AddVariable("pf_charge90",&m_pf_charge[89]);

    reader->AddVariable("pf_charge91",&m_pf_charge[90]);
   reader->AddVariable("pf_charge92",&m_pf_charge[91]);
   reader->AddVariable("pf_charge93",&m_pf_charge[92]);
   reader->AddVariable("pf_charge94",&m_pf_charge[93]);
   reader->AddVariable("pf_charge95",&m_pf_charge[94]);
   reader->AddVariable("pf_charge96",&m_pf_charge[95]);
   reader->AddVariable("pf_charge97",&m_pf_charge[96]);
   reader->AddVariable("pf_charge98",&m_pf_charge[97]);
   reader->AddVariable("pf_charge99",&m_pf_charge[98]);
   reader->AddVariable("pf_charge100",&m_pf_charge[99]);

  
  
  

 reader->BookMVA("BDTG", "/nfs/dust/cms/user/tlapsien/TMVA/TopTag/weights/PF_BDTG.weights.xml");
}


  if(option=="simple_cuts"){
  reader->AddVariable( "TopJet_mass", &Topjetmass );
  reader->AddVariable( "TopJet_Qjets_volatility", &Q_valatility);
  reader->AddVariable("TopJet_jwj02", &jwj02);
  reader->AddVariable("TopJet_ecf_d3", &d3);
  reader->AddVariable("TopJet_softdrop_mass",&softdrop_mass);
  reader->AddVariable( "t3/t2_pruned := TopJet_pruned_tau3/TopJet_pruned_tau2", &t3t2p);
  reader->AddVariable( "t2/t1_pruned := TopJet_pruned_tau2/TopJet_pruned_tau1", &t2t1p );
  reader->BookMVA("Cuts", "/nfs/dust/cms/user/tlapsien/TMVA/TopTag/weights/TL_newvar_all_simple_cuts_Cuts.weights.xml");
}





if(option=="simple_cuts300"){
  reader->AddVariable( "TopJet_mass", &Topjetmass );
  reader->AddVariable( "TopJet_Qjets_volatility", &Q_valatility);
  reader->AddVariable("TopJet_jwj02", &jwj02);
  reader->AddVariable("TopJet_ecf_d3", &d3);
  reader->AddVariable("TopJet_softdrop_mass",&softdrop_mass);
  reader->AddVariable( "t3/t2_pruned := TopJet_pruned_tau3/TopJet_pruned_tau2", &t3t2p);
  reader->AddVariable( "t2/t1_pruned := TopJet_pruned_tau2/TopJet_pruned_tau1", &t2t1p );
  reader->BookMVA("Cuts", "/nfs/dust/cms/user/tlapsien/TMVA/TopTag/weights/TL_newvar_all_simple_cuts300_Cuts.weights.xml");
}

if(option=="simple_cuts500"){
  reader->AddVariable( "TopJet_mass", &Topjetmass );
  reader->AddVariable( "TopJet_Qjets_volatility", &Q_valatility);
  reader->AddVariable("TopJet_jwj02", &jwj02);
  reader->AddVariable("TopJet_ecf_d3", &d3);
  reader->AddVariable("TopJet_softdrop_mass",&softdrop_mass);
  reader->AddVariable( "t3/t2_pruned := TopJet_pruned_tau3/TopJet_pruned_tau2", &t3t2p);
  reader->AddVariable( "t2/t1_pruned := TopJet_pruned_tau2/TopJet_pruned_tau1", &t2t1p );
  reader->BookMVA("Cuts", "/nfs/dust/cms/user/tlapsien/TMVA/TopTag/weights/TL_newvar_all_simple_cuts300-500_Cuts.weights.xml");
}


if(option=="simple_cuts700"){
  reader->AddVariable( "TopJet_mass", &Topjetmass );
  reader->AddVariable( "TopJet_Qjets_volatility", &Q_valatility);
  reader->AddVariable("TopJet_jwj02", &jwj02);
  reader->AddVariable("TopJet_ecf_d3", &d3);
  reader->AddVariable("TopJet_softdrop_mass",&softdrop_mass);
  reader->AddVariable( "t3/t2_pruned := TopJet_pruned_tau3/TopJet_pruned_tau2", &t3t2p);
  reader->AddVariable( "t2/t1_pruned := TopJet_pruned_tau2/TopJet_pruned_tau1", &t2t1p );
  reader->BookMVA("Cuts", "/nfs/dust/cms/user/tlapsien/TMVA/TopTag/weights/TL_newvar_all_simple_cuts500-700_Cuts.weights.xml");
}


if(option=="simple_cutsInf"){
  reader->AddVariable( "TopJet_mass", &Topjetmass );
  reader->AddVariable( "TopJet_Qjets_volatility", &Q_valatility);
  reader->AddVariable("TopJet_jwj02", &jwj02);
  reader->AddVariable("TopJet_ecf_d3", &d3);
  reader->AddVariable("TopJet_softdrop_mass",&softdrop_mass);
  reader->AddVariable( "t3/t2_pruned := TopJet_pruned_tau3/TopJet_pruned_tau2", &t3t2p);
  reader->AddVariable( "t2/t1_pruned := TopJet_pruned_tau2/TopJet_pruned_tau1", &t2t1p );
  reader->BookMVA("Cuts", "/nfs/dust/cms/user/tlapsien/TMVA/TopTag/weights/TL_newvar_all_simple_cuts700_Cuts.weights.xml");
}







if(option=="TLflat"){
    reader->AddVariable( "TopJet_mass", &Topjetmass );
    reader->AddVariable( "Subjets12_mass", &Subjet12mass);
    reader->AddVariable( "Subjets23_mass", &Subjet23mass);
    reader->AddVariable( "TopJet_Nsubjets", &Nsubjets);
    reader->AddVariable( "TopJet_Qjets_volatility", &Q_valatility);
    reader->AddVariable( "Subjet1pT := sqrt(pow(Subjet1_px,2)+pow(Subjet1_py,2))", &subjet1pt);
    reader->AddVariable( "TopJet_pruned_tau3", &tau3pruned);
    reader->AddVariable( "t3/t2_pruned := TopJet_pruned_tau3/TopJet_pruned_tau2", &t3t2p);
    reader->AddVariable( "t2/t1_pruned := TopJet_pruned_tau2/TopJet_pruned_tau1", &t2t1p );
    reader->AddVariable( "HelAng13", &HelAng13);
      reader->BookMVA("BDTG", "/nfs/dust/cms/user/tlapsien/TMVA/TopTag/weights/flatTL_BDTG.weights.xml");
    // reader->BookMVA("BDTG", "/nfs/dust/cms/user/tlapsien/TMVA/TopTag/weights/highptTL_BDTG.weights.xml");

  }


if(option=="newVar_TL_noCMS"){
    reader->AddVariable( "TopJet_mass", &Topjetmass );
    //  reader->AddVariable( "Subjets12_mass", &Subjet12mass);
    //  reader->AddVariable( "Subjets13_mass", &Subjet12mass);
    // reader->AddVariable( "Subjets23_mass", &Subjet23mass);
    // reader->AddVariable( "TopJet_Nsubjets", &Nsubjets);
    reader->AddVariable( "TopJet_Qjets_volatility", &Q_valatility);
    reader->AddVariable( "TopJet_Qjets_volatility_mmin", &qjet_mmin);
    reader->AddVariable( "TopJet_Qjets_volatility_mass", &qjet_mass);
    reader->AddVariable( "TopJet_Qjets_volatility_nsubjets", &qjet_nsubjets);
    reader->AddVariable( "TopJet_Qjets_volatility_nsubjettiness1", &qjet_nsubjettiness1);
    reader->AddVariable( "TopJet_Qjets_volatility_nsubjettiness2", &qjet_nsubjettiness2);
    reader->AddVariable( "TopJet_Qjets_volatility_nsubjettiness3", &qjet_nsubjettiness3);
    reader->AddVariable("TopJet_jwj01", &jwj01);
    reader->AddVariable("TopJet_jwj02", &jwj02);
    reader->AddVariable("TopJet_jwj03", &jwj03);
    reader->AddVariable("TopJet_jwj04", &jwj04);
    reader->AddVariable("TopJet_ecf_c3", &c3);
    reader->AddVariable("TopJet_ecf_d3", &d3);
    reader->AddVariable("TopJet_softdrop_mass",&softdrop_mass);
    reader->AddVariable("TopJet_tau1",&tau1);
    reader->AddVariable("TopJet_tau2",&tau2);
    reader->AddVariable("TopJet_tau3",&tau3);
    reader->AddVariable( "t2/t1 := TopJet_tau2/TopJet_tau1", &t2t1);
    reader->AddVariable( "t3/t2 := TopJet_tau3/TopJet_tau2", &t3t2);
      
       
      reader->BookMVA("BDTG", "/nfs/dust/cms/user/tlapsien/TMVA/TopTag/weights/TL_newvar_noCMS_BDTG.weights.xml");
 
 }


if(option=="newVar_TL_noCMS2"){
    reader->AddVariable( "TopJet_mass", &Topjetmass );
    //  reader->AddVariable( "Subjets12_mass", &Subjet12mass);
    //  reader->AddVariable( "Subjets13_mass", &Subjet12mass);
    // reader->AddVariable( "Subjets23_mass", &Subjet23mass);
    // reader->AddVariable( "TopJet_Nsubjets", &Nsubjets);
    //reader->AddVariable( "TopJet_Qjets_volatility", &Q_valatility);
    //reader->AddVariable( "TopJet_Qjets_volatility_mmin", &qjet_mmin);
    reader->AddVariable( "TopJet_Qjets_volatility_mass", &qjet_mass);
    //reader->AddVariable( "TopJet_Qjets_volatility_nsubjets", &qjet_nsubjets);
    reader->AddVariable( "TopJet_Qjets_volatility_nsubjettiness1", &qjet_nsubjettiness1);
    reader->AddVariable( "TopJet_Qjets_volatility_nsubjettiness2", &qjet_nsubjettiness2);
    reader->AddVariable( "TopJet_Qjets_volatility_nsubjettiness3", &qjet_nsubjettiness3);
    reader->AddVariable("TopJet_jwj01", &jwj01);
    reader->AddVariable("TopJet_jwj02", &jwj02);
    reader->AddVariable("TopJet_jwj03", &jwj03);
    reader->AddVariable("TopJet_jwj04", &jwj04);
    reader->AddVariable("TopJet_ecf_c3", &c3);
    reader->AddVariable("TopJet_ecf_d3", &d3);
    reader->AddVariable("TopJet_softdrop_mass",&softdrop_mass);
    reader->AddVariable("TopJet_tau1",&tau1);
    reader->AddVariable("TopJet_tau2",&tau2);
    reader->AddVariable("TopJet_tau3",&tau3);
    reader->AddVariable( "t2/t1 := TopJet_tau2/TopJet_tau1", &t2t1);
    reader->AddVariable( "t3/t2 := TopJet_tau3/TopJet_tau2", &t3t2);
      
       
      reader->BookMVA("BDTG", "/nfs/dust/cms/user/tlapsien/TMVA/TopTag/weights/TL_newvar_noCMS2_BDTG.weights.xml");
 
 }



 if(option=="newVar_TL"){
    reader->AddVariable( "TopJet_mass", &Topjetmass );
    reader->AddVariable( "Subjets12_mass", &Subjet12mass);
    reader->AddVariable( "Subjets13_mass", &Subjet12mass);
    reader->AddVariable( "Subjets23_mass", &Subjet23mass);
    reader->AddVariable( "TopJet_Nsubjets", &Nsubjets);
    reader->AddVariable( "TopJet_Qjets_volatility", &Q_valatility);
    reader->AddVariable( "TopJet_Qjets_volatility_mmin", &qjet_mmin);
    reader->AddVariable( "TopJet_Qjets_volatility_mass", &qjet_mass);
    reader->AddVariable( "TopJet_Qjets_volatility_nsubjets", &qjet_nsubjets);
    reader->AddVariable( "TopJet_Qjets_volatility_nsubjettiness1", &qjet_nsubjettiness1);
    reader->AddVariable( "TopJet_Qjets_volatility_nsubjettiness2", &qjet_nsubjettiness2);
    reader->AddVariable( "TopJet_Qjets_volatility_nsubjettiness3", &qjet_nsubjettiness3);
    reader->AddVariable("TopJet_jwj01", &jwj01);
    reader->AddVariable("TopJet_jwj02", &jwj02);
    reader->AddVariable("TopJet_jwj03", &jwj03);
    reader->AddVariable("TopJet_jwj04", &jwj04);
    reader->AddVariable("TopJet_ecf_c3", &c3);
    reader->AddVariable("TopJet_ecf_d3", &d3);
    reader->AddVariable("TopJet_softdrop_mass",&softdrop_mass);
    reader->AddVariable("TopJet_tau1",&tau1);
    reader->AddVariable("TopJet_tau2",&tau2);
    reader->AddVariable("TopJet_tau3",&tau3);
    reader->AddVariable( "t2/t1 := TopJet_tau2/TopJet_tau1", &t2t1);
    reader->AddVariable( "t3/t2 := TopJet_tau3/TopJet_tau2", &t3t2);
      
       
      reader->BookMVA("BDTG", "/nfs/dust/cms/user/tlapsien/TMVA/TopTag/weights/TL_newvar_BDTG.weights.xml");
 
 }

  if(option=="NPVweight"){
    reader->AddVariable( "TopJet_mass", &Topjetmass );
    reader->AddVariable( "Subjets12_mass", &Subjet12mass);
    reader->AddVariable( "Subjets23_mass", &Subjet23mass);
    reader->AddVariable( "TopJet_Nsubjets", &Nsubjets);
    reader->AddVariable( "TopJet_Qjets_volatility", &Q_valatility);
    reader->AddVariable( "Subjet1pT := sqrt(pow(Subjet1_px,2)+pow(Subjet1_py,2))", &subjet1pt);
    reader->AddVariable( "TopJet_pruned_tau3", &tau3pruned);
    reader->AddVariable( "t3/t2_pruned := TopJet_pruned_tau3/TopJet_pruned_tau2", &t3t2p);
    reader->AddVariable( "t2/t1_pruned := TopJet_pruned_tau2/TopJet_pruned_tau1", &t2t1p );
    reader->AddVariable( "HelAng13", &HelAng13);

    //  reader->BookMVA("BDTG", "/nfs/dust/cms/user/tlapsien/TMVA/weights/NPVweight_BDTG.weights.xml");
    reader->BookMVA("BDTG", "/nfs/dust/cms/user/tlapsien/TMVA/TopTag/weights/secondTL_BDTG.weights.xml");
 

  }
  
 if(option=="Uncorr+3"){
    reader->AddVariable( "TopJet_mass", &Topjetmass );
    reader->AddVariable( "Subjets12_mass", &Subjet12mass);
    reader->AddVariable( "Subjets23_mass", &Subjet23mass);
    reader->AddVariable( "TopJet_Nsubjets", &Nsubjets);
    reader->AddVariable( "TopJet_Qjets_volatility", &Q_valatility);
    reader->AddVariable( "Event_NPV", &npv);
    reader->AddVariable( "Subjet1pT := sqrt(pow(Subjet1_px,2)+pow(Subjet1_py,2))", &subjet1pt);
    reader->AddVariable( "TopJet_pruned_tau3", &tau3pruned);
    reader->AddVariable( "t3/t2_pruned := TopJet_pruned_tau3/TopJet_pruned_tau2", &t3t2p);
    reader->AddVariable( "t2/t1_pruned := TopJet_pruned_tau2/TopJet_pruned_tau1", &t2t1p );
    reader->AddVariable( "HelAng13", &HelAng13);

    reader->BookMVA("BDTG", "/nfs/dust/cms/user/tlapsien/TMVA/weights/Uncorr+3_BDTG.weights.xml");
 }

  if(option=="pT"){
    reader->AddVariable( "TopJet_mass", &Topjetmass );
    reader->AddVariable( "Subjets12_mass", &Subjet12mass);
    reader->AddVariable( "Subjets23_mass", &Subjet23mass);
    reader->AddVariable( "TopJet_Nsubjets", &Nsubjets);
    reader->AddVariable( "TopJet_Qjets_volatility", &Q_valatility);
    reader->AddVariable( "Event_NPV", &npv);
    reader->AddVariable( "TopJet_pruned_tau3", &tau3pruned);
    reader->AddVariable( "t3/t2_pruned := TopJet_pruned_tau3/TopJet_pruned_tau2", &t3t2p);
    reader->AddVariable( "t2/t1_pruned := TopJet_pruned_tau2/TopJet_pruned_tau1", &t2t1p );
    reader->AddVariable( "HelAng13", &HelAng13);

    reader->BookMVA("BDTG", "/nfs/dust/cms/user/tlapsien/TMVA/weights/pT_BDTG.weights.xml");
 

  }

 
  if(option=="bestown70"){
     reader->AddVariable( "Subjets12_mass", &Subjet12mass);
    reader->AddVariable( "t2/t1 := TopJet_tau2/TopJet_tau1", &t2t1);
    reader->AddVariable( "Subjets23_pruned_mass", &Subjet23mass_pruned);
    reader->AddVariable( "TopJet_pruned_tau1", &tau1pruned);
    reader->AddVariable( "HelAng12", &HelAng12);


    reader->BookMVA("BDTG", "/nfs/dust/cms/user/tlapsien/TMVA/weights/bestown70_BDTG.weights.xml");
 
    
  }


  if(option=="Q"){
    reader->AddVariable( "TopJet_mass", &Topjetmass );
    reader->AddVariable( "TopJet_Nsubjets", &Nsubjets);
    reader->AddVariable( "Subjets12_mass", &Subjet12mass);
    reader->AddVariable( "Subjets13_mass", &Subjet13mass);
    reader->AddVariable( "Subjets23_mass", &Subjet23mass);
    reader->AddVariable("t3/t2 := TopJet_tau3/TopJet_tau2", &t3t2);
    reader->AddVariable( "TopJet_Qjets_volatility", &Q_valatility);
    
    reader->BookMVA("BDTG", "/nfs/dust/cms/user/tlapsien/TMVA/weights/Qjets_BDTG.weights.xml");
  }
if(option=="Qref_weight"){
     reader->AddVariable( "TopJet_mass", &Topjetmass );
    reader->AddVariable( "Subjets12_mass", &Subjet12mass);
    reader->AddVariable( "Subjets13_mass", &Subjet23mass);
    reader->AddVariable( "Subjets23_mass", &Subjet23mass);
    reader->AddVariable( "TopJet_Nsubjets", &Nsubjets);
    reader->AddVariable( "TopJet_Qjets_volatility", &Q_valatility);
    reader->AddVariable("t3/t2 := TopJet_tau3/TopJet_tau2", &t3t2);
    reader->BookMVA("BDTG", "/nfs/dust/cms/user/tlapsien/TMVA/weights/Qref_BDTG.weights.xml");
   }

if(option=="CMS"){
    reader->AddVariable( "TopJet_mass", &Topjetmass );
    reader->AddVariable( "Subjets12_mass", &Subjet12mass);
    reader->AddVariable( "Subjets13_mass", &Subjet13mass);
    reader->AddVariable( "Subjets23_mass", &Subjet23mass);
    reader->AddVariable( "TopJet_Nsubjets", &Nsubjets);
    
    reader->BookMVA("BDTG", "/nfs/dust/cms/user/tlapsien/TMVA/weights/cmsref_weight_BDTG.weights.xml");
 }

// reader2=reader;
 }

Double_t TMVA_tagger::GetMVA_value(bool BDT){
  // std::cout<<Tmass<<std::endl;
  
  Double_t mvaValue;
  if(BDT) mvaValue = reader->EvaluateMVA("BDTG");
  else mvaValue = reader->EvaluateMVA("Cuts",0.4);
  return mvaValue;

}

void TMVA_tagger::push_variables(TopJet topjet){
  // Tmass=(topjet.v4()).M();
  EventCalc* calc = EventCalc::Instance();
  Softdrop = new SoftDrop();
  jwj = new Jetswithoutjets();
  ecf = new ECF();

  //pf variables

  /* std::vector<PFParticle> jetconst =  calc->GetJetPFParticles(&topjet);
  sort(jetconst.begin(),jetconst.end(),HigherPt());
  for(int i=0; i<jetconst.size();i++){
    if(i<100) m_pf_pt[i]=jetconst[i].pt();
    if(i<100) m_pf_phi[i]=jetconst[i].phi();
    if(i<100) m_pf_eta[i]=jetconst[i].eta();
    if(i<100) m_pf_energy[i]=jetconst[i].energy();
    if(i<100) m_pf_charge[i]=jetconst[i].charge();
    }*/


  

   npv = calc->GetPrimaryVertices()->size();
  Nsubjets=topjet.numberOfDaughters();
  LorentzVector allsubjets(0,0,0,0);

  
  for(int j=0; j<topjet.numberOfDaughters(); ++j){
    allsubjets += topjet.subjets()[j].v4();
  }

  if(!allsubjets.isTimelike()){
    Topjetmass=0;
  } else {
    Topjetmass = allsubjets.M();
  }
  
  //subjet mass
  std::vector<Particle> subjet = topjet.subjets();
  sort(subjet.begin(),subjet.end(),HigherPt());
  if(Nsubjets>=3){
    Subjet12mass=(subjet[0].v4()+subjet[1].v4()).mass();
    Subjet13mass=(subjet[0].v4()+subjet[2].v4()).mass();
    Subjet23mass=(subjet[1].v4()+subjet[2].v4()).mass();
  }
   if(Nsubjets>=2){
    Subjet12mass=(subjet[0].v4()+subjet[1].v4()).mass();
     }


   //nsubjetiness
   JetProps jp(&topjet, calc->GetPFParticles() );
   tau1 = jp.GetNsubjettiness(1, Njettiness::onepass_kt_axes, 1., 0.8);
  tau2 = jp.GetNsubjettiness(2, Njettiness::onepass_kt_axes, 1., 0.8);
  tau3 = jp.GetNsubjettiness(3, Njettiness::onepass_kt_axes, 1., 0.8);
  
  //pruned subjetiness
  tau1pruned = jp.GetPrunedNsubjettiness(1, Njettiness::onepass_kt_axes, 1., 0.8);
  tau2pruned = jp.GetPrunedNsubjettiness(2, Njettiness::onepass_kt_axes, 1., 0.8);
  tau3pruned = jp.GetPrunedNsubjettiness(3, Njettiness::onepass_kt_axes, 1., 0.8);
  //ratio subjetiness
  if(tau2!=0) t3t2=tau3/tau2;
 if(tau1!=0) t2t1=tau2/tau1;
 if(tau2pruned!=0) t3t2p=tau3pruned/tau2pruned;
 if(tau1pruned!=0) t2t1p=tau2pruned/tau1pruned;
   Q_valatility = topjet.qjets_volatility();
   // qjet_mmin=jp.GetQjetVolatility_mmin(calc->GetEventNum(),0.8);
   /* qjet_mass=jp.GetQjetVolatility(calc->GetEventNum(),0.8);
  qjet_nsubjets=jp.GetQjetVolatility_nsubjets(calc->GetEventNum(),0.8);
  qjet_nsubjettiness1= jp.GetQjetVolatility_Nsubjettiness(calc->GetEventNum(), 0.8, 1, Njettiness::onepass_kt_axes , 1.);
  qjet_nsubjettiness2= jp.GetQjetVolatility_Nsubjettiness(calc->GetEventNum(), 0.8, 2, Njettiness::onepass_kt_axes , 1.);
  qjet_nsubjettiness3= jp.GetQjetVolatility_Nsubjettiness(calc->GetEventNum(), 0.8, 3, Njettiness::onepass_kt_axes , 1.);*/
  //jwj

  /*  jwj01=jwj->SubjetMultiplicity(topjet, calc->GetPFParticles(),0.05,0.1);
  jwj02=jwj->SubjetMultiplicity(topjet, calc->GetPFParticles(),0.05,0.2);
  jwj03=jwj->SubjetMultiplicity(topjet, calc->GetPFParticles(),0.05,0.3);
  jwj04=jwj->SubjetMultiplicity(topjet, calc->GetPFParticles(),0.05,0.4);*/


  //ecf

  //  c3=ecf->Get_C(topjet,calc->GetPFParticles(), 3, 1.0);
    //d3=ecf->Get_D3(topjet,calc->GetPFParticles(),2.,0.8,0.6);

  //soft drop
  // fastjet::PseudoJet groomed_jet;
  // Softdrop->GetJet(topjet, calc->GetPFParticles(),0.1,2.0,groomed_jet);
  //softdrop_mass=groomed_jet.m();

 // calculate pruned masses
  std::vector<fastjet::PseudoJet> jets = jp.GetFastJet(2.0);   // something large to make sure jet is inside radius
  if(jets.empty()){
      m_logger << WARNING << "TMVATreeFiller::FillTopJetProperties: no jet found!" << SLogger::endmsg; 
  }
  else{
    fastjet::PseudoJet pjet = jp.GetPrunedJet(jets[0]);
    std::vector<fastjet::PseudoJet> prunedsubjets;
    if (pjet.constituents().size()>=2){
        prunedsubjets = pjet.exclusive_subjets(2);
    }
    if (pjet.constituents().size()>=3){
        prunedsubjets = pjet.exclusive_subjets(3);
    }

    unsigned int pnsubs = prunedsubjets.size();

    fastjet::PseudoJet psubjets(0,0,0,0);
    
    for(unsigned int j=0; j<pnsubs; ++j){
        psubjets += pjet.pieces()[j];
    }

    Topjetmass_pruned = psubjets.m();

    if (pnsubs>=2) {
        Subjet12mass_pruned = (prunedsubjets[0]+prunedsubjets[1]).m();
    }

    if (pnsubs>=3) {
        Subjet13mass_pruned = (prunedsubjets[0]+prunedsubjets[2]).m();
        Subjet23mass_pruned = (prunedsubjets[1]+prunedsubjets[2]).m();
    }
    }
  
  //HelicityAngles && subjet pt
   if(subjet.size()>0) subjet1pt=sqrt(pow(subjet[0].v4().Px(),2)+pow(subjet[0].v4().Py(),2));
  if(subjet.size()>1){
    TLorentzVector subjet1(subjet[0].v4().Px(),subjet[0].v4().Py(),subjet[0].v4().Pz(),subjet[0].v4().E());
    TLorentzVector subjet2(subjet[1].v4().Px(),subjet[1].v4().Py(),subjet[1].v4().Pz(),subjet[1].v4().E());
    subjet1pt=sqrt(pow(subjet[0].v4().Px(),2)+pow(subjet[0].v4().Py(),2));
    subjet2pt=sqrt(pow(subjet[1].v4().Px(),2)+pow(subjet[1].v4().Py(),2));
    HelAng12= HelicityAngle(subjet1,subjet2);
  }
  if(subjet.size()>2){
    TLorentzVector subjet1(subjet[0].v4().Px(),subjet[0].v4().Py(),subjet[0].v4().Pz(),subjet[0].v4().E());
    TLorentzVector subjet2(subjet[1].v4().Px(),subjet[1].v4().Py(),subjet[1].v4().Pz(),subjet[1].v4().E());
    TLorentzVector subjet3(subjet[2].v4().Px(),subjet[2].v4().Py(),subjet[2].v4().Pz(),subjet[2].v4().E());
    subjet1pt=sqrt(pow(subjet[0].v4().Px(),2)+pow(subjet[0].v4().Py(),2));
    subjet2pt=sqrt(pow(subjet[1].v4().Px(),2)+pow(subjet[1].v4().Py(),2));
    subjet3pt=sqrt(pow(subjet[2].v4().Px(),2)+pow(subjet[2].v4().Py(),2));
    HelAng12= HelicityAngle(subjet1,subjet2);
    HelAng13= HelicityAngle(subjet1,subjet3);
    HelAng23= HelicityAngle(subjet2,subjet3);
    }

  

}

