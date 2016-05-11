// $Id: MyCycle.cxx,v 1.10 2012/12/07 14:21:51 peiffer Exp $

#include <iostream>


using namespace std;

// Local include(s):

#include "include/HighEffCycle.h"
#include "../SFrameTools/include/TopFitCalc.h"
#include "include/TMVA_tagger.h"
#include <TMVA/Reader.h>



ClassImp( HighEffCycle );

HighEffCycle::HighEffCycle()
   : AnalysisCycle() {
 m_dobsf = "None";
    m_dotsf = "None";
    m_mttgencut = false;
    m_flavor_selection = "None";
    m_writeeventlist = false;
    m_correctTopPtWeights = false;
  // constructor, declare additional variables that should be 
  // obtained from the steering-xml file
  
  // set the integrated luminosity per bin for the lumi-yield control plots
  DeclareProperty( "BTaggingScaleFactors", m_dobsf );
  DeclareProperty( "CorrectTopPtWeights", m_correctTopPtWeights);

   m_btagtype = e_CSVT;
   x_btagtype = e_CSVM;
   
  /*    tmva_tagger= new TMVA_tagger();
  tmva_tagger->Set_Reader("Qref_weight");
  std::cout<<"BLAAAAAAA"<<std::endl;*/

  

  DeclareProperty( "ApplyMttbarGenCut", m_mttgencut );
  SetIntLumiPerBin(500.);

}

HighEffCycle::~HighEffCycle() 
{
  // destructor
}

void HighEffCycle::BeginCycle() throw( SError ) 
{
  // Start of the job, general set-up and definition of 
  // objects are done here

  // Important: first call BeginCycle of base class
  AnalysisCycle::BeginCycle();

  return;

}

void HighEffCycle::EndCycle() throw( SError ) 
{
  // clean-up, info messages and final calculations after the analysis

  
  // call the base cycle class for all standard methods
  AnalysisCycle::EndCycle();

  return;

}

void HighEffCycle::BeginInputData( const SInputData& id ) throw( SError ) 
{
  
  // declaration of histograms and selections

  // Important: first call BeginInputData of base class
  AnalysisCycle::BeginInputData( id );

  // -------------------- set up the selections ---------------------------

  /* Selection* BSel = new Selection( "BSelection");
  BSel->addSelectionModule(new NBTagSelection(1)); //at least one b tag

  Selection* NoBSel = new Selection( "NoBSelection");
  NoBSel->addSelectionModule(new NBTagSelection(0,0)); //no b tags

  Selection* chi2_selection= new Selection("chi2_selection");
  static Chi2Discriminator* m_chi2discr = new Chi2Discriminator();
  chi2_selection->addSelectionModule(new HypothesisDiscriminatorCut( m_chi2discr, -1*double_infinity(), 10));
  chi2_selection->addSelectionModule(new MttbarGenCut(0,700));

  Selection* TopSel = new Selection("TopSelection");
  //DO NOT use trigger selection in PROOF mode at the moment
  //TopSel->addSelectionModule(new TriggerSelection("HLT_PFJet320_v"));
  TopSel->addSelectionModule(new NTopJetSelection(1,int_infinity(),350,2.5));
  TopSel->addSelectionModule(new NTopTagSelection(1,int_infinity()));




  RegisterSelection(BSel);
  RegisterSelection(NoBSel);
  RegisterSelection(TopSel);
  RegisterSelection(chi2_selection);*/



 

  // ---------------- set up the histogram collections --------------------

  // histograms without any cuts
  // RegisterHistCollection( new MyHists("NoCuts") );
    Selection* TopTagSel = new Selection("TopTagSelection");
    TopTagSel->addSelectionModule(new NTopJetSelection(1,int_infinity(),350,2.5));// top jet
    TopTagSel->addSelectionModule(new NTopTagSelection(1,int_infinity()));
    TopTagSel->addSelectionModule(new TopTagOverlapSelection());
   static Chi2Discriminator* m_chi2discr = new Chi2Discriminator();
     RegisterHistCollection( new TopTagHists("test3"));
     RegisterHistCollection( new SubstructureHists("substructure_alljets"));
      RegisterHistCollection( new SubstructureHists("substructure_cms"));
       RegisterHistCollection( new SubstructureHists("substructure_hep"));
       RegisterHistCollection( new SubstructureHists("substructure_mva"));
       RegisterHistCollection( new SubstructureHists("substructure_tobias"));
        RegisterHistCollection( new SubstructureHists("substructure_pt700"));
	 RegisterHistCollection( new MicrojetHists("microjets350"));
	 RegisterHistCollection( new MicrojetHists("microjets500"));
	 RegisterHistCollection( new MicrojetHists("microjets700"));
	 RegisterHistCollection( new HighEffHists("higheffhists"));
	 RegisterHistCollection( new GenJetHists("genjethists"));

 RegisterHistCollection( new SubstructureHists("substructure_CA15jets"));


    RegisterHistCollection( new TopTagcontrol("preSelection"));
   RegisterHistCollection( new TopTagcontrol("postSelection"));

  RegisterHistCollection( new HypothesisHists("Chi2_BTag", m_chi2discr ) );


  RegisterHistCollection( new HypothesisHists("Chi2_Presel", m_chi2discr ) );

    RegisterHistCollection( new EventHists("Event_Presel") );
    //RegisterHistCollection( new JetHists("Jets_Presel") );
    // RegisterHistCollection( new ElectronHists("Electron_Presel") );
    // RegisterHistCollection( new MuonHists("Muon_Presel") );
    // RegisterHistCollection( new TauHists("Tau_Presel") );
    RegisterHistCollection( new TopJetHists("TopJets_Presel") );
    RegisterHistCollection( new EventHists("Event_Postsel") );
    // RegisterHistCollection( new JetHists("Jets_Postsel") );
    // RegisterHistCollection( new ElectronHists("Electron_Postsel") );
    //RegisterHistCollection( new MuonHists("Muon_Postsel") );
    // RegisterHistCollection( new TauHists("Tau_Postsel") );
    RegisterHistCollection( new TopJetHists("TopJets_Postsel") );
  
   
  /*  RegisterHistCollection( new HypothesisHists("Chi2_NoCuts", m_chi2discr ) );

  //histograms with and without b tagging
  RegisterHistCollection( new MyHists("BTag") );
  RegisterHistCollection( new MyHists("NoBTag") );
  RegisterHistCollection( new HypothesisHists("Chi2_BTag", m_chi2discr ) );
  RegisterHistCollection( new HypothesisHists("Chi2_NoBTag", m_chi2discr ) );

  // histograms after the top selection
  RegisterHistCollection( new MyHists("TopSel") );
  RegisterHistCollection( new HypothesisHists("Chi2_TopSel", m_chi2discr ) );*/



  // important: initialise histogram collections after their definition

  //test Histos
  /*  Book( TH1F( "Nmuon","number of muons",7,-0.5,6.5));
   Book(TH1F("muon_pt","pt muon",1000,0,1000));
   Book(TH1F("chargemuon","charge of muon",5,-2,2));
   Book(TH1F("invarmass","invariant mass",1000,0,5000));
   Book(TH1F("MET","missing Et",1000,0,5000));
   Book(TH1F("met_hadr","missing Et hadr",1000,0,5000));
   Book(TH1F("met_lept","missing Et lept",1000,0,5000));
   Book(TH1F("Ht","Ht",1000,0,5000));
   Book(TH1F("pt_ca_jets","pt ca jets",50,0,1000)); 
    Book(TH1F("pt_ca","pt ca jets",50,0,1000)); 
   Book(TH1F("pt_ca_jets2","pt ca jets",50,0,1000));
    Book(TH1F("pt_ca_jets3","pt ca jets",50,0,1000));
   Book(TH1F("pt_ca_jet1","pt ca jet1",50,0,1000));
   Book(TH1F("pt_ca_jet2","pt ca jet2",50,0,1000));
   Book(TH1F("pt_ca_jet3","pt ca jet3",50,0,1000));
   Book(TH1F("pt_ca_jet4","pt ca jet4",50,0,1000));
Book(TH1F("controlplot","controlplot",4,0,3));
   Book(TH1F("flavor_ca_jets","flavor ca jets",3,-1.5,1.5));
   Book(TH1F("flavor_ca_jet1","flavor ca jet1",4,0,3));

 Book(TH1F("flavor_ca_jet2","flavor ca jet2",4,0,3));
Book(TH1F("flavor_ca_jet3","flavor ca jet3",4,0,3));
Book(TH1F("flavor_ca_jet4","flavor ca jet4",4,0,3));
Book(TH1F("pt_ca_jets_tagged_cms","pt ca jets tagged cms",50,0,1000));
   Book(TH1F("pt_ca_jets_tagged","pt ca jets tagged",50,0,1000));
    Book(TH1F("pt_ca_tagged","pt ca jets tagged",50,0,1000));
   Book(TH1F("pt_ca_jets_tagged2","pt ca jets tagged2",50,0,1000));
   Book(TH1F("pt_ca_lept","pt of leptonic ca",50,0,1000));
   Book(TH1F("pt_ca_hadr","pt of hadronic ca",50,0,1000));
   Book(TH1F("M_ca_lept","mass of leptonic ca",50,0,500));
   Book(TH1F("M_ca_hadr","mass of hadronic ca",50,0,500));
   Book(TH1F("NTopJets","N top-jets",1000,0,20));
   Book(TH1F("NJets","number of Jets",101,0,100));
   Book(TH1F("Nsubjets","N subjets",11,0,10));
   Book(TH1F("Nsubjets2","N subjets2",11,0,10));
   Book(TH1F("Q_subjet1","Q subjet1",1000,-10,10));
   Book(TH1F("Msubjets","Mass subjets",1000,0,1000));
   Book(TH1F("invarsub12","ivariant mass of subjet 1 and 2",1000,0,1000));
   Book(TH1F("invarsub12x","invariant mass of subjet 1 and 2",1000,0,1000));
 Book(TH1F("invarsub13","invariant mass of subjet 1 and 3",1000,0,1000));
 Book(TH1F("invarsub23","invariant mass of subjet 2 and 3",1000,0,1000));
 Book(TH1F("genparticles","particles generated",101,0,100));
 Book(TH1F("pttopgen","pt top generated",50,0,1000));
 Book(TH1F("particle_caused_jet_had","particles that caused jet hadr",3,-1.5,1.5));
 Book(TH1F("particle_caused_jet_lep","particles that caused jet lept",3,-1.5,1.5));
 Book(TH1F("particle_caused_jet_all","particles that caused jet all",3,-1.5,1.5));
 Book(TH1F("topdaughter1","daughter1 of W(top)",101,-50,50));
 Book(TH1F("topdaughter2","daughter2 of W(top)",101,-50,50));
 Book(TH1F("ntoptags","n toptags",1001,0,1000));
 Book(TH1F("ntopgen", "number of generated tops (hadr)",1001,0,1000));
 Book(TH1F("Mtopjet","mass of topjet",1001,0,1000));
 Book(TH1F("Mtopjet_sub","mass of topjet(just 3subs)",1001,0,1000));
 Book(TH1F("ptjettag","pt tagged jet",50,0,1000));
 Book(TH1F("pttoptag","pt tagged alg",50,0,1000));
 Book(TH1F("etajettag","eta jet tagged",50,-5,5));
Book(TH1F("etajettagpt","eta jet tagged",50,-5,5));
 Book(TH1F("etatopgen","eta top generated (hadr)",50,-5,5));
Book(TH1F("etatopgenpt","eta top generated",50,-5,5));
 Book(TH1F("phi","phi jet",300,-4,4));
 Book(TH1F("distance","distance between generated and tagged",110,0,10));
  Book(TH1F("distance_s1_s2","distance between subjet1 and 2",110,0,10));
   Book(TH1F("distance_s1_s3","distance between subjet1 and 2",110,0,10));
    Book(TH1F("distance_s2_s3","distance between subjet1 and 2",110,0,10));
    Book(TH1F("pt_jet_div_subj1","pt_jet/pt_subj1",100,0,5));
    Book(TH1F("match_ca_jet","match ca jet",5,-1,3));
 Book(TH1F("match_ca_jet2","match ca jet",5,-1,3));
 Book(TH1F("match","pt match generated tagged",50,0,1000));
   Book(TH1F("GenTop","number of generated tops",1000,0,1000));
   Book(TH1F("tageff","eff vs. pt",50,0,1000));
   Book(TH1F("tageff2","eff vs. pt gegeb",50,0,1000));
   Book(TH1F("tageffeta","eff vs. eta",50,-5,5));
 Book(TH1F("tageffetapt","eff vs. eta (pt>650)",50,-5,5));
Book(TH1F("tageff_ca","eff vs. pt (ca jets)",50,0,1000));
Book(TH1F("tageff_ca2","eff vs. pt2 (ca jets)",50,0,1000));*/
 //Book(TGraphAsymmErrors());
  InitHistos();






 tmva_tagger=new TMVA_tagger();
    
  return;

}

void HighEffCycle::EndInputData( const SInputData& id ) throw( SError ) 
{
  AnalysisCycle::EndInputData( id );
  return;

}

void HighEffCycle::BeginInputFile( const SInputData& id ) throw( SError ) 
{
  // Connect all variables from the Ntuple file with the ones needed for the analysis
  // The variables are commonly stored in the BaseCycleContaincer

  // important: call to base function to connect all variables to Ntuples from the input tree
  AnalysisCycle::BeginInputFile( id );
  
  
  return;

}

void HighEffCycle::ExecuteEvent( const SInputData& id, Double_t weight) throw( SError ) 
{   AnalysisCycle::ExecuteEvent( id, weight );
   EventCalc* calc = EventCalc::Instance();
   BaseHists* HighEffHists=GetHistCollection("higheffhists");
   BaseHists* GenJetHists=GetHistCollection("genjethists");
   HighEffHists->Fill();
   GenJetHists->Fill();
    
 



  
  return;
  
}


