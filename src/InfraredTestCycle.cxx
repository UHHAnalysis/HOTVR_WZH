// $Id: RocCycle.cxx,v 1.10 2012/12/07 14:21:51 peiffer Exp $

#include <iostream>

using namespace std;

#include "include/InfraredTestCycle.h"
#include "include/InfraredTestCMS.h"
#include "include/InfraredTestJetClu.h"
#include "include/InfraredTestHHTT.h"
#include "include/RocHists.h"
#include "include/RocHists2.h"
#include "include/RocHists3.h"
#include "include/RocHistsComb.h"

#include "SFrameAnalysis/include/SelectionModules.h"
//#include "SFrameAnalysis/include/HypothesisHists.h"

ClassImp( InfraredTestCycle );

InfraredTestCycle::InfraredTestCycle()
   : AnalysisCycle() {

  // constructor, declare additional variables that should be 
  // obtained from the steering-xml file
  
  // set the integrated luminosity per bin for the lumi-yield control plots
  SetIntLumiPerBin(500.);

}

InfraredTestCycle::~InfraredTestCycle() 
{
  // destructor
}

void InfraredTestCycle::BeginCycle() throw( SError ) 
{
  // Start of the job, general set-up and definition of 
  // objects are done here

  // Important: first call BeginCycle of base class
  AnalysisCycle::BeginCycle();

  return;

}

void InfraredTestCycle::EndCycle() throw( SError ) 
{
  // clean-up, info messages and final calculations after the analysis

  
  // call the base cycle class for all standard methods
  AnalysisCycle::EndCycle();

  return;

}

void InfraredTestCycle::BeginInputData( const SInputData& id ) throw( SError ) 
{
  // declaration of histograms and selections.
  // AnalysisCyle expects Selections and HistCollections to be registered here.
  // Their memory will be released in AnalysisCycle::EndInputData.

  // Important: first call BeginInputData of base class
  AnalysisCycle::BeginInputData( id );

  // -------------------- set up the selections ---------------------------
  //DO NOT use trigger selection in PROOF mode at the moment
  //TopSel->addSelectionModule(new TriggerSelection("HLT_PFJet320_v"));
  //TriggerSel = new Selection("TriggerSel");
  //TriggerSel->addSelectionModule(new TriggerSelection("HLT_DiJet80Eta2p6_BTagIP3DFastPVLoose"));

  // ---------------- set up the histogram collections --------------------

  RegisterHistCollection( new InfraredTestCMS("IR_CMS"));
  RegisterHistCollection( new InfraredTestJetClu("IR_JetClu"));
   RegisterHistCollection( new InfraredTestHHTT("IR_HHTT"));
  /* RegisterHistCollection( new RocHists2("NoCutsHistos2"));
  RegisterHistCollection( new RocHists3("NoCutsHistos3"));
  RegisterHistCollection( new RocHistsComb("NoCutsHistosComb"));
  RegisterHistCollection( new SubstructureHists("before_cms_Tag_pt400"));
  RegisterHistCollection( new SubstructureHists("after_cms_Tag_pt400"));
  RegisterHistCollection( new SubstructureHists("before_cms_Tag_pt600"));
  RegisterHistCollection( new SubstructureHists("after_cms_Tag_pt600"));
  RegisterHistCollection( new SubstructureHists("before_cms_Tag_pt800"));
  RegisterHistCollection( new SubstructureHists("after_cms_Tag_pt800"));*/



  // important: initialise histogram collections after their definition
  InitHistos();

}

void InfraredTestCycle::EndInputData( const SInputData& id ) throw( SError ) 
{
  AnalysisCycle::EndInputData( id );
}

void InfraredTestCycle::BeginInputFile( const SInputData& id ) throw( SError ) 
{
  // Connect all variables from the Ntuple file with the ones needed for the analysis
  // The variables are commonly stored in the BaseCycleContaincer
  // important: call to base function to connect all variables to Ntuples from the input tree
  AnalysisCycle::BeginInputFile( id );
}

void InfraredTestCycle::ExecuteEvent( const SInputData& id, Double_t weight) throw( SError ) 
{
  // this is the most important part: here the full analysis happens
  // user should implement selections, filling of histograms and results

  // first step: call Execute event of base class to perform basic consistency checks
  // also, the good-run selection is performed there and the calculator is reset
  AnalysisCycle::ExecuteEvent( id, weight );

  // get the histogram collections. NOTE: this could be done more performant by making
  // all thse BaseHists* vairables private member variables of RocCycle and
  // setting them in BeginInputData. Then, there is no need here to call GetHistColletion ...

  BaseHists* IR_CMS = GetHistCollection("IR_CMS");
  BaseHists* IR_JetClu = GetHistCollection("IR_JetClu");
   BaseHists* IR_HHTT = GetHistCollection("IR_HHTT");
  /* BaseHists* NoCutsHistos = GetHistCollection("NoCutsHistos2");
  BaseHists* NoCutsHistos3 = GetHistCollection("NoCutsHistos3");
  BaseHists* NoCutsHistosComb = GetHistCollection("NoCutsHistosComb");
  BaseHists* cms400 = GetHistCollection("before_cms_Tag_pt400");
  BaseHists* cms400tag = GetHistCollection("after_cms_Tag_pt400");
  BaseHists* cms600 = GetHistCollection("before_cms_Tag_pt600");
  BaseHists* cms600tag = GetHistCollection("after_cms_Tag_pt600");
  BaseHists* cms800 = GetHistCollection("before_cms_Tag_pt800");
  BaseHists* cms800tag = GetHistCollection("after_cms_Tag_pt800");*/

  EventCalc* calc = EventCalc::Instance();
  BaseCycleContainer* bcc = calc->GetBaseCycleContainer();
  bool IsRealData = calc->IsRealData();
  ((InfraredTestCMS*)IR_CMS)->SetIdVersion(id.GetVersion());
  ((InfraredTestJetClu*)IR_JetClu)->SetIdVersion(id.GetVersion());
   ((InfraredTestHHTT*)IR_HHTT)->SetIdVersion(id.GetVersion());
  //((RocHists*)NoCutsHistos3)->SetIdVersion(id.GetVersion());
  //((RocHists*)NoCutsHistosComb)->SetIdVersion(id.GetVersion());
  // NoCutsHistos->Fill();
  //NoCutsHistos3->Fill();
  // NoCutsHistosComb->Fill();
  //  IR_JetClu->Fill();
    IR_CMS->Fill();
   //  IR_HHTT->Fill();
  
  return;
  
}


