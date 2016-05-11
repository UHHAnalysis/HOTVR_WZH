// $Id: MyCycle.cxx,v 1.10 2012/12/07 14:21:51 peiffer Exp $

#include <iostream>


using namespace std;

// Local include(s):

#include "include/newTTCycle.h"
#include "../SFrameTools/include/TopFitCalc.h"
#include "include/TMVA_tagger.h"
#include <TMVA/Reader.h>



ClassImp( newTTCycle );

newTTCycle::newTTCycle()
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

newTTCycle::~newTTCycle() 
{
  // destructor
}

void newTTCycle::BeginCycle() throw( SError ) 
{
  // Start of the job, general set-up and definition of 
  // objects are done here

  // Important: first call BeginCycle of base class
  AnalysisCycle::BeginCycle();

  return;

}

void newTTCycle::EndCycle() throw( SError ) 
{
  // clean-up, info messages and final calculations after the analysis

  
  // call the base cycle class for all standard methods
  AnalysisCycle::EndCycle();

  return;

}

void newTTCycle::BeginInputData( const SInputData& id ) throw( SError ) 
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
   
     RegisterHistCollection( new newTTHists("newTThists"));
	


  
  InitHistos();






 tmva_tagger=new TMVA_tagger();
    
  return;

}

void newTTCycle::EndInputData( const SInputData& id ) throw( SError ) 
{
  AnalysisCycle::EndInputData( id );
  return;

}

void newTTCycle::BeginInputFile( const SInputData& id ) throw( SError ) 
{
  // Connect all variables from the Ntuple file with the ones needed for the analysis
  // The variables are commonly stored in the BaseCycleContaincer

  // important: call to base function to connect all variables to Ntuples from the input tree
  AnalysisCycle::BeginInputFile( id );
  
  
  return;

}

void newTTCycle::ExecuteEvent( const SInputData& id, Double_t weight) throw( SError ) 
{   AnalysisCycle::ExecuteEvent( id, weight );
   EventCalc* calc = EventCalc::Instance();
   BaseHists* TTHists=GetHistCollection("newTThists");
   ((newTTHists*)TTHists)->SetIdVersion(id.GetVersion());
   TTHists->Fill();
  
    
 



  
  return;
  
}


