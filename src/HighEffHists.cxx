#include "include/HighEffHists.h"
#include "SFrameTools/include/EventCalc.h"
#include "include/ZprimeFullHadTools.h"
#include <iostream>
#include "TH3.h"
using namespace std;

HighEffHists::HighEffHists(const char* name) : BaseHists(name)
{
  // named default constructor
   
}

HighEffHists::~HighEffHists()
{
  // default destructor, does nothing
}

void HighEffHists::Init()
{
  // book all histograms here

  double jetpt_bbins[] = {
    20, 30, 40, 50, 60, 70, 80, 100, 120, 160, 210, 260, 320, 400, 500, 600, 800, 1600
  };
 
  Book( TH1F( "pT_s1"," p_{T} matched parton (selection)",50,0,2000));
  Book( TH1F( "pT_s1_mis"," p_{T} topjets (selection)",50,0,2000));
  Book( TH1F( "pT_s1200"," p_{T} topjets (selection)",50,0,2000));
   Book( TH1F( "pT_s1200CA15"," p_{T} topjets (selection)",50,0,2000));
  Book( TH1F( "pT_s1_cms_tagged200"," p_{T} topjets (cms tagged)",50,0,2000));
   Book( TH1F( "pT_s1_cmsnew_tagged200"," p_{T} topjets (cms tagged)",50,0,2000));
  Book( TH1F( "pT_s1_nsub_tagged200"," p_{T} topjets (nsub tagged)",50,0,2000));
  Book( TH1F( "pT_s1_mjet_tagged200"," p_{T} topjets (mjet tagged)",50,0,2000));
 Book( TH1F( "pT_s1_mmin_tagged200"," p_{T} topjets (mmin tagged)",50,0,2000));
 Book( TH1F( "pT_s1_nsubmmin_tagged200"," p_{T} topjets (mmin tagged)",50,0,2000));
 Book( TH1F( "pT_s1_nsubmjet_tagged200"," p_{T} topjets (mmin tagged)",50,0,2000));
  Book( TH1F( "pT_s1_mminmjet_tagged200"," p_{T} topjets (mmin tagged)",50,0,2000));
   Book( TH1F( "pT_s1_nsubjettiness_tagged200"," p_{T} topjets (nsubjettiness tagged)",50,0,2000));
 Book( TH1F( "pT_s1_TL1_tagged200"," p_{T} topjets (TL tagged)",50,0,2000));
  Book( TH1F( "MJet", "m_{jet}", 100,0,400 ) );
  Book( TH1F( "Mmin", "m_{min}", 50,0,160 ) );
  Book( TH1F( "MJetnew", "m_{jet}", 100,0,400 ) );
  Book( TH1F( "Mminnew", "m_{min}", 50,0,160 ) );
  Book( TH1F( "NSubjets", "number of subjets", 6,-0.5,5.5) );
  Book( TH1F( "NSubjetsnew", "number of subjets new", 6,-0.5,5.5) );

  Book( TH1F( "MJet_tag", "m_{jet}", 100,0,400 ) );
 Book( TH1F( "MJet_tag400", "m_{jet}", 100,0,400 ) );
 Book( TH1F( "MJet_tag600", "m_{jet}", 100,0,400 ) );
  Book( TH1F( "MJet_tag800", "m_{jet}", 100,0,400 ) );
 Book( TH1F( "MJet_tag1000", "m_{jet}", 100,0,400 ) );
  Book( TH1F( "Mmin_tag", "m_{min}", 50,0,160 ) );
  Book( TH1F( "MJetnew_tag", "m_{jet}", 100,0,400 ) );
   Book( TH1F( "MJetnew_tag400", "m_{jet}", 100,0,400 ) );
    Book( TH1F( "MJetnew_tag600", "m_{jet}", 100,0,400 ) );
   Book( TH1F( "MJetnew_tag800", "m_{jet}", 100,0,400 ) );
 Book( TH1F( "MJetnew_tag1000", "m_{jet}", 100,0,400 ) );
  Book( TH1F( "Mminnew_tag", "m_{min}", 50,0,160 ) );
  Book( TH1F( "NSubjets_tag", "number of subjets", 6,-0.5,5.5) );
  Book( TH1F( "NSubjetsnew_tag", "number of subjets new", 6,-0.5,5.5) );
 Book( TH1F( "NJets", "number of jets ", 30,-0.5,29.5) );
  Book( TH1F( "NJets_dR", "number of jets ", 30,-0.5,29.5) );
   Book( TH1F( "MAkJets", "ak5 m_{jet}", 100,0,400 ) );



  Book( TH1F( "pT_s1_hep3_tagged_ly"," p_{T} topjets (hep tagged)",50,0,2000));
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
 
  //new top tagging idea
  Book(TH1F("pfpt","pf pt",100,0,100));
  Book( TH1F( "PFpt_par0","Fit parameter 0",2000,0,50));
  Book( TH1F( "PFpt_par1","Fit parameter 1",2000,-10,10));
  Book( TH1F( "PFpt_par2","Fit parameter 2",2000,0,500));

  tmva_tagger=new TMVA_tagger();
  Showerdeconstruction_tagger= new Showerdeconstruction();
  Showerdeconstruction_taggerV2= new ShowerdeconstructionV2();
}

void HighEffHists::SetIdVersion(TString s)
{
  idVersion=s;
}

void HighEffHists::Fill()
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
      /* minDeltaR=10000;
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
      */



      //	if (minDeltaR>1.0) bestjetindex=-1;//protect against large deltaR


	 
	/*
		if((bestjetindex>-1) && (bestjetindex!=oldbestjet)){
	 oldbestjet=bestjetindex;
	   TopJet Ca15jet=bcc->toptagjets->at(bestjetindex);
	 double m12,m13,m23,fw,m123,m_pruned,m_unfiltered;
	  if (Had_Tops[j].pt()>200.0) Hist("pT_s1200CA15")->Fill(Had_Tops[j].pt(),weight);
	  if(HepTopTagFull(Ca15jet, calc->GetPFParticles() ,m12, m13, m23, fw, m123, m_pruned, m_unfiltered)){
	     if (Had_Tops[j].pt()>200.0) Hist("pT_s1_hep3_tagged200")->Fill(Had_Tops[j].pt(),weight);
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
	  //  chi= Showerdeconstruction_tagger->ChiMicro(Ca15jet,Nmicrojets,Mmicrojet,microconesize,microjets);
	 Hist("SD")->Fill(log(chi),weight);
	 if(Had_Tops[j].pt()>350) Hist("SD_350")->Fill(log(chi),weight);
	 if(Had_Tops[j].pt()>600) Hist("SD_600")->Fill(log(chi),weight); 
	 Hist("NMicrojets")->Fill(Nmicrojets,weight);
	 if(chi!=0) Hist("NMicrojetspass")->Fill(Nmicrojets,weight);
	 Hist("MMicrojet")->Fill(Mmicrojet,weight);
	 if(log(chi)>3.5) {
	 if (Had_Tops[j].pt()>200.0)  Hist("pT_s1_sd_tagged200")->Fill(Had_Tops[j].pt(),weight);
	  
	 }   
	 }*/



	 
    
	 
	  	sort(bcc->topjets->begin(), bcc->topjets->end(), HigherPt());
        double minDeltaR2=10000;
	int bestjetindex2=-1;
        for(unsigned int i=0; i<bcc->topjets->size(); ++i)
	{
	  double DeltaR2=Had_Tops[j].deltaR(bcc->topjets->at(i));
	  if(DeltaR2<minDeltaR2)
	  {
	    minDeltaR2=DeltaR2;
	    bestjetindex2=i;
	  }
	}
    	if (minDeltaR2>1.0) bestjetindex2=-1;//protect against large deltaR
	if((bestjetindex2>-1) && (bestjetindex2!=oldbestjet2)){
	  oldbestjet2=bestjetindex2;
	  TopJet Ca8jet=bcc->topjets->at(bestjetindex2);
	
	  if(Ca8jet.pt()>0 && bestjetindex2<2){
	   double mva_value=100;
	   double mmin=0;
	  double mjet=0;
	  int nsubjets=0;


	  	  TH1F * PFpt = new TH1F("PFpt","PFpt",100,0,100);
	   std::vector<PFParticle> jetconst =  calc->GetJetPFParticles(&Ca8jet);
	   for(int t=0;t<jetconst.size();t++){
	     PFpt->Fill(jetconst[t].pt(),1);
	      Hist("pfpt")->Fill(jetconst[t].pt(),1);
	     if(t==0) std::cout<<jetconst[t].pt()<<std::endl;
	     
	   }
	  TF1* fit = new TF1("PFpt","[0]+exp([1]*x)*[2]",0,100);
	  PFpt->Fit("PFpt","","",0,100);
	 
	  std::cout<<"par1 "<<fit->GetParameter(1)<<std::endl;
	  std::cout<<"parerror1 "<<fit->GetParError(1)<<std::endl;
	  if(fit->GetParameter(0)!=0) Hist("PFpt_par0")->Fill(fit->GetParameter(0),weight);
	   if(fit->GetParameter(0)!=0) Hist("PFpt_par1")->Fill(fit->GetParameter(1),weight);
	   if(fit->GetParameter(0)!=0) Hist("PFpt_par2")->Fill(fit->GetParameter(2),weight);
	  delete PFpt;
	  
	  sort(bcc->jets->begin(), bcc->jets->end(), HigherPt());
	  Hist("NJets")->Fill(bcc->jets->size(),weight);
	  int numberjets=0;
	  int nmax=0;
	  LorentzVector ak5jetvec;
	  for(int L=0;L<bcc->jets->size();L++){
	    if(Ca8jet.deltaR(bcc->jets->at(L))<1.0 && nmax<3) {
	      numberjets++;
	      Jet ak5jet=bcc->jets->at(L);
	      ak5jetvec+=ak5jet.v4();
	      nmax++;

	  }
	  }
	  double ak5jetmass=ak5jetvec.M();
	   Hist("NJets_dR")->Fill(numberjets,weight);
	   Hist("MAkJets")->Fill(ak5jetmass,weight);




	  //TopTag(Ca8jet,mjet,nsubjets,mmin);
	   if(TopTag(Ca8jet,mjet,nsubjets,mmin)) {
	  //if(mjet>140 && mjet<250 && Ca8jet.pt()>350 && mmin>50){
	  //if(variableMassHepTopTag(bcc->toptagjets->at(bestjetindex2),200,0.505,1.495,0.35,0.35,140,250)){  
	     if (Had_Tops[j].pt()>200.0){  
	       Hist("pT_s1_cms_tagged200")->Fill(Had_Tops[j].pt(),weight);
	       Hist("Mmin_tag")->Fill(mmin,weight);
	       Hist("MJet_tag")->Fill(mjet,weight);
	       Hist("NSubjets_tag")->Fill(nsubjets,weight);


	     }
	      if (Had_Tops[j].pt()>400.0)  Hist("MJet_tag400")->Fill(mjet,weight);
	      if (Had_Tops[j].pt()>600.0)  Hist("MJet_tag600")->Fill(mjet,weight);
	      if (Had_Tops[j].pt()>800.0)  Hist("MJet_tag800")->Fill(mjet,weight);
	      if (Had_Tops[j].pt()>1000.0)  Hist("MJet_tag1000")->Fill(mjet,weight);
	    // if (Had_Tops[j].pt()>600.0)  Hist("pT_s1_cms_tagged600")->Fill(Had_Tops[j].pt(),weight);
	    // if (Had_Tops[j].pt()>800.0)  Hist("pT_s1_cms_tagged800")->Fill(Had_Tops[j].pt(),weight);
	    
	  }

	    if(nsubjets>2) {
	  //if(mjet>140 && mjet<250 && Ca8jet.pt()>350 && mmin>50){
	  //if(variableMassHepTopTag(bcc->toptagjets->at(bestjetindex2),200,0.505,1.495,0.35,0.35,140,250)){  
	    if (Had_Tops[j].pt()>200.0)  Hist("pT_s1_nsub_tagged200")->Fill(Had_Tops[j].pt(),weight);
	    
	    
	  }

	    if(mjet>140 && mjet<250&& Ca8jet.pt()>350 ) {
	  //if(mjet>140 && mjet<250 && Ca8jet.pt()>350 && mmin>50){
	  //if(variableMassHepTopTag(bcc->toptagjets->at(bestjetindex2),200,0.505,1.495,0.35,0.35,140,250)){  
	    if (Had_Tops[j].pt()>400.0)  Hist("pT_s1_mjet_tagged200")->Fill(Had_Tops[j].pt(),weight);
	   
	    
	  }
	    
	      if(mmin>50) {
	  //if(mjet>140 && mjet<250 && Ca8jet.pt()>350 && mmin>50){
	  //if(variableMassHepTopTag(bcc->toptagjets->at(bestjetindex2),200,0.505,1.495,0.35,0.35,140,250)){  
	    if (Had_Tops[j].pt()>200.0)  Hist("pT_s1_mmin_tagged200")->Fill(Had_Tops[j].pt(),weight);
	   
	    
	  }

	      if(nsubjets>2 && mmin>50 ) {
	  //if(mjet>140 && mjet<250 && Ca8jet.pt()>350 && mmin>50){
	  //if(variableMassHepTopTag(bcc->toptagjets->at(bestjetindex2),200,0.505,1.495,0.35,0.35,140,250)){  
	    if (Had_Tops[j].pt()>200.0)  Hist("pT_s1_nsubmmin_tagged200")->Fill(Had_Tops[j].pt(),weight);
	    
	    
	  }

	      if(nsubjets>2 && mjet>140 && mjet<250 ) {
	  //if(mjet>140 && mjet<250 && Ca8jet.pt()>350 && mmin>50){
	  //if(variableMassHepTopTag(bcc->toptagjets->at(bestjetindex2),200,0.505,1.495,0.35,0.35,140,250)){  
	    if (Had_Tops[j].pt()>200.0)  Hist("pT_s1_nsubmjet_tagged200")->Fill(Had_Tops[j].pt(),weight);
	    
	    
	  }

	       if(mmin>50 && mjet>140 && mjet<250 ) {
	  //if(mjet>140 && mjet<250 && Ca8jet.pt()>350 && mmin>50){
	  //if(variableMassHepTopTag(bcc->toptagjets->at(bestjetindex2),200,0.505,1.495,0.35,0.35,140,250)){  
	    if (Had_Tops[j].pt()>200.0)  Hist("pT_s1_mminmjet_tagged200")->Fill(Had_Tops[j].pt(),weight);
	    
	    
	  } 
	  
	       if(Ca8jet.tau3()/Ca8jet.tau2()<0.7 && Ca8jet.tau2()!=0){
		 if (Had_Tops[j].pt()>200.0)  Hist("pT_s1_nsubjettiness_tagged200")->Fill(Had_Tops[j].pt(),weight);
	  }

	  
	  if(nsubjets>2 && mjet>140 && mjet<250 && Ca8jet.tau3()/Ca8jet.tau2()<0.7  && Ca8jet.tau2()!=0){
	     if (Had_Tops[j].pt()>200.0)  Hist("pT_s1_TL1_tagged200")->Fill(Had_Tops[j].pt(),weight);
	  }

	  
	      
	    
	   
	  Hist("pT_s1")->Fill(Had_Tops[j].pt(),weight);
	  if (Had_Tops[j].pt()>200.0 ) Hist("pT_s1200")->Fill(Had_Tops[j].pt(),weight);
	  //if (Had_Tops[j].pt()>600.0) Hist("pT_s1600")->Fill(Had_Tops[j].pt(),weight);
	  //if (Had_Tops[j].pt()>800.0) Hist("pT_s1800")->Fill(Had_Tops[j].pt(),weight);
	  
	  int nsubjets2;
	  double mjet2,mmin2;
	  double conesize=3.0;
	  if(CMSTopTagFull(Ca8jet, calc->GetPFParticles(),conesize,0.05,0.4,0.0004, mjet2, nsubjets2, mmin2) ){
	     std::cout<<"mmin "<<mmin<<" "<<mmin2<<std::endl;
	    std::cout<<"mjet "<<mjet<<" "<<mjet2<<std::endl;
	    std::cout<<"subjets "<<nsubjets<<" "<<nsubjets2<<std::endl;
	    if (Had_Tops[j].pt()>200.0){  Hist("pT_s1_cmsnew_tagged200")->Fill(Had_Tops[j].pt(),weight);
	     if(mmin2!=0) Hist("Mminnew_tag")->Fill(mmin2,weight);
	     if(mjet2!=0) Hist("MJetnew_tag")->Fill(mjet2,weight);
	     if(nsubjets2!=0) Hist("NSubjetsnew_tag")->Fill(nsubjets2,weight);
	    }
	     if (Had_Tops[j].pt()>400.0) Hist("MJetnew_tag400")->Fill(mjet2,weight);
	     if (Had_Tops[j].pt()>600.0) Hist("MJetnew_tag600")->Fill(mjet2,weight);
	     if (Had_Tops[j].pt()>800.0) Hist("MJetnew_tag800")->Fill(mjet2,weight);
	      if (Had_Tops[j].pt()>1000.0) Hist("MJetnew_tag1000")->Fill(mjet2,weight);
	  }
	  // if(mmin2>50 /*mjet2>140 && mjet2<250 */ && Ca8jet.pt()>350) if (Had_Tops[j].pt()>200.0)  Hist("pT_s1_cmsnew_tagged200")->Fill(Had_Tops[j].pt(),weight);
	  Hist("Mmin")->Fill(mmin,weight);
	  Hist("MJet")->Fill(mjet,weight);
	  if(mmin2!=0) Hist("Mminnew")->Fill(mmin2,weight);
	  if(mjet2!=0) Hist("MJetnew")->Fill(mjet2,weight);
	  Hist("NSubjets")->Fill(nsubjets,weight);
	  if(nsubjets2!=0) Hist("NSubjetsnew")->Fill(nsubjets2,weight);

	  
	  }
	}

	   

    }
  

      
  }
}

void HighEffHists::Finish()
{
  // final calculations, like division and addition of certain histograms
 

}

