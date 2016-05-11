#include "include/GenJetHists.h"
#include "SFrameTools/include/EventCalc.h"
#include "include/ZprimeFullHadTools.h"
#include <iostream>
#include "TH3.h"
using namespace std;


GenJetHists::GenJetHists(const char* name) : BaseHists(name)
{
  // named default constructor
   
}

GenJetHists::~GenJetHists()
{
  // default destructor, does nothing
}

void GenJetHists::Init()
{
  // book all histograms here

  double jetpt_bbins[] = {
    20, 30, 40, 50, 60, 70, 80, 100, 120, 160, 210, 260, 320, 400, 500, 600, 800, 1600
  };
 
  Book( TH1F( "pT_s1200"," p_{T} matched parton (selection)",50,0,2000));
  Book( TH1F( "pT_s1_mis"," p_{T} topjets (selection)",50,0,2000));
  Book( TH1F( "pT_s1400"," p_{T} topjets (selection)",50,0,2000));
  Book( TH1F( "pT_s1_cms_tagged400"," p_{T} topjets (cms tagged)",50,0,2000));
   Book( TH1F( "pT_s1_cmsnew_tagged200"," p_{T} topjets (cms tagged)",50,0,2000));
  Book( TH1F( "pT_s1_nsub_tagged400"," p_{T} topjets (nsub tagged)",50,0,2000));
  Book( TH1F( "pT_s1_mjet_tagged400"," p_{T} topjets (mjet tagged)",50,0,2000));
 Book( TH1F( "pT_s1_mmin_tagged400"," p_{T} topjets (mmin tagged)",50,0,2000));
 Book( TH1F( "pT_s1_nsubmmin_tagged400"," p_{T} topjets (mmin tagged)",50,0,2000));
 Book( TH1F( "pT_s1_nsubmjet_tagged400"," p_{T} topjets (mmin tagged)",50,0,2000));
  Book( TH1F( "pT_s1_mminmjet_tagged400"," p_{T} topjets (mmin tagged)",50,0,2000));
   Book( TH1F( "pT_s1_nsubjettiness_tagged400"," p_{T} topjets (nsubjettiness tagged)",50,0,2000));
 Book( TH1F( "pT_s1_TL1_tagged400"," p_{T} topjets (TL tagged)",50,0,2000));
  Book( TH1F( "MJet", "m_{jet}", 100,0,400 ) );
  Book( TH1F( "Mmin", "m_{min}", 50,0,160 ) );
  Book( TH1F( "MJetnew", "m_{jet}", 100,0,400 ) );
  Book( TH1F( "Mminnew", "m_{min}", 50,0,160 ) );
  Book( TH1F( "NSubjets", "number of subjets", 6,-0.5,5.5) );
  Book( TH1F( "NSubjetsnew", "number of subjets new", 6,-0.5,5.5) );


  Book( TH1F( "pT_s1_hep3_tagged_ly"," p_{T} topjet (hep tagged)",50,0,2000));
  Book( TH1F( "pT_s1_hep3_tagged200"," p_{T} matched parton (hep tagged)",50,0,2000));
  Book( TH1F( "hep_fw", "hep fw", 25,0,160 ) );
  Book( TH1F( "hep_m12", "hep m12", 25,0,160 ) );
  Book( TH1F( "hep_m13", "hep m13", 25,0,160 ) );
  Book( TH1F( "hep_m23", "hep m23", 25,0,160 ) );
  Book( TH1F( "hep_m123", "hep m_123", 25,0,400 ) );
  Book( TH1F( "hep_m_pruned", "hep m_pruned", 25,0,400 ) );
  Book( TH1F( "hep_m_unfiltered", "hep m_unfiltered", 25,0,400 ) );



//shower deconstruction
   Book( TH1F( "pT_s1_sd_tagged200"," p_{T} matched parton (sd tagged)",50,0,2000));
  Book(TH1F("SD","log(chi) shower deconstruction",21,-10,10));
  Book(TH1F("SD_350","log(chi) shower deconstruction PT>350",21,-10,10));
  Book(TH1F("SD_600","log(chi) shower deconstruction PT>600",21,-10,10));
  Book( TH1F( "NMicrojets", "number of microjets", 11,-0.5,10.5) );
  Book( TH1F( "NMicrojetspass", "number of microjets passed", 11,-0.5,10.5) );
  Book( TH1F( "MMicrojet", "leading m_{microjets}", 50,0,400 ) );


  //cms
 Book( TH1F( "MJetnew", "m_{jet}", 100,0,400 ) );
  Book( TH1F( "Mminnew", "m_{min}", 50,0,160 ) );
   Book( TH1F( "NSubjetsnew", "number of subjets new", 6,-0.5,5.5) );


  tmva_tagger=new TMVA_tagger();
  Showerdeconstruction_tagger= new Showerdeconstruction();
  Showerdeconstruction_taggerV2= new ShowerdeconstructionV2();
}

void GenJetHists::SetIdVersion(TString s)
{
  idVersion=s;
}

void GenJetHists::Fill()
{
  // fill the histograms


    EventCalc* calc = EventCalc::Instance();
    BaseCycleContainer* bcc = calc->GetBaseCycleContainer();
  bool IsRealData = calc->IsRealData();
  LuminosityHandler* lumih = calc->GetLumiHandler();

  // important: get the event weight
  double weight = calc->GetWeight();

  int run = calc->GetRunNum();
  int lumiblock = calc->GetLumiBlock();
  int Npvs = calc->GetPrimaryVertices()->size();


 
 

  //double npu = bcc.genInfo->pileup_TrueNumInteractions();
  //if(npu>50) npu=49.9999;
  //Hist( "N_pileup_hist" )->Fill( npu, weight );

  //MET* met = calc->GetMET();
  //Hist("MET_lx")->Fill(met->pt(), weight);

  //double HT = calc->GetHT();
  //Hist("HT_lx")->Fill(HT, weight);

  //double HTlep = calc->GetHTlep();
  //Hist("HTlep_lx")->Fill(HTlep, weight);

 

  
  float minDeltaR=10000;
  int bestjetindex=-1;
  int bestjetindex2=-1;
  

  
  
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  

 
  
  
//####################################################################  
  
  
  int nsteps=50;
  double wmin=0.0;
  double wmax=0.5;
  double nsubmin=0.0;
  double nsubmax=1.0;
  double csvmin=0.0;
  double csvmax=1.0;
  
//   double mwl_step=(1.0-0.5)/nsteps;
//   double mwu_step=(1.5-1.0)/nsteps;
//   double rsa_step=(0.5-0.0)/nsteps;
//   double rsb_step=(0.5-0.0)/nsteps;
//   double tml_step=(160.0-90.0)/nsteps;
//   double tmu_step=(260.0-190.0)/nsteps;
//   double nsub_step=(1.0-0.5)/nsteps;
//   double w_step=(0.5-0.0)/nsteps;
  
  double nsub_step=(nsubmax-nsubmin)/nsteps;
  double w_step=(wmax-wmin)/nsteps;
  double csv_step=(csvmax-csvmin)/nsteps;

//EFFICIENCY
  if(!IsRealData )
  {
    TTbarGen* Decay = calc->GetTTbarGen();
    std::vector<GenParticle> Had_Tops;
    bool isHadronic=false;
    if (Decay->IsTopHadronicDecay()) Had_Tops.push_back(Decay->Top());
    if (Decay->IsAntiTopHadronicDecay()) Had_Tops.push_back(Decay->Antitop());
     TTbarGen::E_DecayChannel decaymode= Decay->DecayChannel();
     // std::cout<<"decaymode "<<decaymode<<std::endl;
    int oldbestjet=-1;
     int oldbestjet2=-1;
     // std::cout<<"1"<<std::endl;
   
    for (unsigned int j=0; j<Had_Tops.size(); j++)//if (isHadronic)
    {
        minDeltaR=10000;
	bestjetindex=-1;
        for(unsigned int i=0; i<bcc->toptagjets->size(); ++i)
	{
	  double DeltaR=Had_Tops[j].deltaR(bcc->toptagjets->at(i));
	  if(DeltaR<minDeltaR)
	  {
	    minDeltaR=DeltaR;
	    bestjetindex=i;
	  }
	}

	bcc->genjetswithparts->size();

	sort(bcc->genjetswithparts->begin(), bcc->genjetswithparts->end(), HigherPt());
        double minDeltaR2=10000;
	int bestjetindex2=-1;
        for(unsigned int i=0; i<bcc->genjetswithparts->size(); ++i)
	{
	  double DeltaR2=Had_Tops[j].deltaR(bcc->genjetswithparts->at(i));
	  if(DeltaR2<minDeltaR2)
	  {
	    minDeltaR2=DeltaR2;
	    bestjetindex2=i;
	  }
	}


	if (minDeltaR>1.0) bestjetindex=-1;//protect against large deltaR
	if (minDeltaR2>1.0) bestjetindex2=-1;//protect against large deltaR

	 
	  
	
	
	
	  
	 
	  
	
	if((bestjetindex2>-1) && (bestjetindex2!=oldbestjet2)){
	  oldbestjet2=bestjetindex2;
	   GenJetWithParts genjet15=bcc->genjetswithparts->at(bestjetindex2);
	  if(genjet15.pt()>0 && bestjetindex2<2){
	    if(Had_Tops[j].pt()>200) Hist("pT_s1200")->Fill(Had_Tops[j].pt(),weight);
	    Hist("MJet")->Fill(genjet15.v4().M(),weight);
	    std::vector<GenParticle>* genparts= calc->GetGenParticles();
	    double m12,m13,m23,fw,m123,m_pruned,m_unfiltered;
	    if(HepTopTagFullGen(genjet15, genparts,m12, m13, m23, fw, m123, m_pruned, m_unfiltered)){
	      if(Had_Tops[j].pt()>200) Hist("pT_s1_hep3_tagged200")->Fill(Had_Tops[j].pt(),weight);
	     
	      Hist("hep_fw")->Fill(fw,weight);
	      Hist("hep_m12")->Fill(m12,weight);
	      Hist("hep_m13")->Fill(m13,weight);
	      Hist("hep_m23")->Fill(m23,weight);
	      Hist("hep_m123")->Fill(m123,weight);
	      Hist("hep_m_pruned")->Fill(m_pruned,weight);
	      Hist("hep_m_unfiltered")->Fill(m_unfiltered,weight);
	    }
	  //SHower deconstruction
	  double chi;
	  double Mmicrojet=0;
	  std::vector<fastjet::PseudoJet> microjets;
	  int Nmicrojets=0;
	  double microconesize=0.3;
	  if(Had_Tops[j].pt()>500) microconesize=0.2;
	  if(Had_Tops[j].pt()>700) microconesize=0.1;
	  chi= Showerdeconstruction_tagger->ChiMicroGen(genjet15,Nmicrojets,Mmicrojet,microconesize,microjets);
	 Hist("SD")->Fill(log(chi),weight);
	 if(Had_Tops[j].pt()>350) Hist("SD_350")->Fill(log(chi),weight);
	 if(Had_Tops[j].pt()>600) Hist("SD_600")->Fill(log(chi),weight); 
	 Hist("NMicrojets")->Fill(Nmicrojets,weight);
	 if(chi!=0) Hist("NMicrojetspass")->Fill(Nmicrojets,weight);
	 Hist("MMicrojet")->Fill(Mmicrojet,weight);
	 if(log(chi)>3.5) {
	 if (Had_Tops[j].pt()>200.0)  Hist("pT_s1_sd_tagged200")->Fill(Had_Tops[j].pt(),weight);
	  
	 }   
	 double conesize=3.0;
	 double mjet2,mmin2;
	 int nsubjets2;
	  if(CMSTopTagFullGen(genjet15, genparts,conesize, mjet2, nsubjets2, mmin2) ){
	    if (Had_Tops[j].pt()>200.0)  Hist("pT_s1_cmsnew_tagged200")->Fill(Had_Tops[j].pt(),weight);
	  }
	  // if(mmin2>50 /*mjet2>140 && mjet2<250 */ && Ca8jet.pt()>350) if (Had_Tops[j].pt()>200.0)  Hist("pT_s1_cmsnew_tagged200")->Fill(Had_Tops[j].pt(),weight);
	  if(mmin2!=0) Hist("Mminnew")->Fill(mmin2,weight);
	  if(mjet2!=0) Hist("MJetnew")->Fill(mjet2,weight);
	  if(nsubjets2!=0) Hist("NSubjetsnew")->Fill(nsubjets2,weight);


 

	  }
	}
    }
  }
}

void GenJetHists::Finish()
{
  // final calculations, like division and addition of certain histograms
 

}

