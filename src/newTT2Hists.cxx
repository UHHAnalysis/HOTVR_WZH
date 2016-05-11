#include "include/newTT2Hists.h"
#include "SFrameTools/include/EventCalc.h"
#include "include/ZprimeFullHadTools.h"
#include "NtupleWriter/include/JetProps.h"
#include "NtupleWriter/interface/GenJetProps.h"
#include <fastjet/JetDefinition.hh>
#include <fastjet/PseudoJet.hh>
#include <fastjet/ClusterSequence.hh>
#include <fastjet/ClusterSequenceArea.hh>
#include <fastjet/GhostedAreaSpec.hh>
#include <iostream>
#include "TH3.h"
using namespace std;

newTT2Hists::newTT2Hists(const char* name) : BaseHists(name)
{
  // named default constructor
   
}

newTT2Hists::~newTT2Hists()
{
  // default destructor, does nothing
}

void newTT2Hists::Init()
{
  // book all histograms here

  double jetpt_bbins[] = {
    20, 30, 40, 50, 60, 70, 80, 100, 120, 160, 210, 260, 320, 400, 500, 600, 800, 1600
  };
 
  Book( TH1F( "pT_s1"," p_{T} matched parton (selection)",50,0,2000));
   Book( TH1F( "pT_s1_cms1"," p_{T} matched parton (cms1)",50,0,2000));
    Book( TH1F( "pT_s1_cms2"," p_{T} matched parton (cms2)",50,0,2000));
 Book( TH1F( "pT_s1_cms3"," p_{T} matched parton (cms3)",50,0,2000));
 Book( TH1F( "pT_s1_cms4"," p_{T} matched parton (cms4)",50,0,2000));
  Book( TH1F("pT_gen","gen p_{T}",50,0,2000));
  Book( TH1F("pT_gen_match_kt1","gen p_{T}",50,0,2000));
   Book( TH1F("pT_gen_match_ca1","gen p_{T}",50,0,2000));
    Book( TH1F("pT_gen_match_akt1","gen p_{T}",50,0,2000));
     Book( TH1F("pT_gen_match_topjet1","gen p_{T}",50,0,2000));
 Book( TH1F("pT_gen_match_kt2","gen p_{T}",50,0,2000));
   Book( TH1F("pT_gen_match_ca2","gen p_{T}",50,0,2000));
    Book( TH1F("pT_gen_match_akt2","gen p_{T}",50,0,2000));
     Book( TH1F("pT_gen_match_topjet2","gen p_{T}",50,0,2000));
      Book( TH1F("pT_gen_match_kt3","gen p_{T}",50,0,2000));
   Book( TH1F("pT_gen_match_ca3","gen p_{T}",50,0,2000));
    Book( TH1F("pT_gen_match_akt3","gen p_{T}",50,0,2000));
     Book( TH1F("pT_gen_match_topjet3","gen p_{T}",50,0,2000));
      Book( TH1F("pT_gen_match_kt4","gen p_{T}",50,0,2000));
   Book( TH1F("pT_gen_match_ca4","gen p_{T}",50,0,2000));
    Book( TH1F("pT_gen_match_akt4","gen p_{T}",50,0,2000));
     Book( TH1F("pT_gen_match_topjet4","gen p_{T}",50,0,2000));
      Book( TH1F("pT_gen_match_kt5","gen p_{T}",50,0,2000));
   Book( TH1F("pT_gen_match_ca5","gen p_{T}",50,0,2000));
    Book( TH1F("pT_gen_match_akt5","gen p_{T}",50,0,2000));
     Book( TH1F("pT_gen_match_topjet5","gen p_{T}",50,0,2000));
 Book( TH1F("pT_gen_match_kt6","gen p_{T}",50,0,2000));
   Book( TH1F("pT_gen_match_ca6","gen p_{T}",50,0,2000));
    Book( TH1F("pT_gen_match_akt6","gen p_{T}",50,0,2000));
     Book( TH1F("pT_gen_match_topjet6","gen p_{T}",50,0,2000));
 Book( TH1F("pT_gen_match_kt7","gen p_{T}",50,0,2000));
   Book( TH1F("pT_gen_match_ca7","gen p_{T}",50,0,2000));
    Book( TH1F("pT_gen_match_akt7","gen p_{T}",50,0,2000));
     Book( TH1F("pT_gen_match_topjet7","gen p_{T}",50,0,2000));
 Book( TH1F("pT_gen_match_kt8","gen p_{T}",50,0,2000));
   Book( TH1F("pT_gen_match_ca8","gen p_{T}",50,0,2000));
    Book( TH1F("pT_gen_match_akt8","gen p_{T}",50,0,2000));
     Book( TH1F("pT_gen_match_topjet8","gen p_{T}",50,0,2000));
 Book( TH1F("pT_gen_match_kt9","gen p_{T}",50,0,2000));
   Book( TH1F("pT_gen_match_ca9","gen p_{T}",50,0,2000));
    Book( TH1F("pT_gen_match_akt9","gen p_{T}",50,0,2000));
     Book( TH1F("pT_gen_match_topjet9","gen p_{T}",50,0,2000));
      Book( TH1F("pT_gen_match_kt10","gen p_{T}",50,0,2000));
   Book( TH1F("pT_gen_match_ca10","gen p_{T}",50,0,2000));
    Book( TH1F("pT_gen_match_akt10","gen p_{T}",50,0,2000));
     Book( TH1F("pT_gen_match_topjet10","gen p_{T}",50,0,2000));
 Book( TH1F("pT_gen_match_kt11","gen p_{T}",50,0,2000));
   Book( TH1F("pT_gen_match_ca11","gen p_{T}",50,0,2000));
    Book( TH1F("pT_gen_match_akt11","gen p_{T}",50,0,2000));
     Book( TH1F("pT_gen_match_topjet11","gen p_{T}",50,0,2000));
 Book( TH1F("pT_gen_match_kt12","gen p_{T}",50,0,2000));
   Book( TH1F("pT_gen_match_ca12","gen p_{T}",50,0,2000));
    Book( TH1F("pT_gen_match_akt12","gen p_{T}",50,0,2000));
     Book( TH1F("pT_gen_match_topjet12","gen p_{T}",50,0,2000));
 Book( TH1F("pT_gen_match_kt13","gen p_{T}",50,0,2000));
   Book( TH1F("pT_gen_match_ca13","gen p_{T}",50,0,2000));
    Book( TH1F("pT_gen_match_akt13","gen p_{T}",50,0,2000));
     Book( TH1F("pT_gen_match_topjet13","gen p_{T}",50,0,2000));
 Book( TH1F("pT_gen_match_kt14","gen p_{T}",50,0,2000));
   Book( TH1F("pT_gen_match_ca14","gen p_{T}",50,0,2000));
    Book( TH1F("pT_gen_match_akt14","gen p_{T}",50,0,2000));
     Book( TH1F("pT_gen_match_topjet14","gen p_{T}",50,0,2000));
 Book( TH1F("pT_gen_match_kt15","gen p_{T}",50,0,2000));
   Book( TH1F("pT_gen_match_ca15","gen p_{T}",50,0,2000));
    Book( TH1F("pT_gen_match_akt15","gen p_{T}",50,0,2000));
     Book( TH1F("pT_gen_match_topjet15","gen p_{T}",50,0,2000));
     Book( TH1F( "NSubjets_ca", "number of subjets ca", 6,-0.5,5.5) );
      Book( TH1F( "NSubjets_kt", "number of subjets kt", 6,-0.5,5.5) );
       Book( TH1F( "NSubjets_akt", "number of subjets akt", 6,-0.5,5.5) );


  Book(TH1F("pT_ca1","pT",50,0,2000));
   Book(TH1F("pT_kt1","pT",50,0,2000));
    Book(TH1F("pT_akt1","pT",50,0,2000));
      Book(TH1F("pT_ca2","pT",50,0,2000));
   Book(TH1F("pT_kt2","pT",50,0,2000));
    Book(TH1F("pT_akt2","pT",50,0,2000));
  Book(TH1F("pT_ca3","pT",50,0,2000));
   Book(TH1F("pT_kt3","pT",50,0,2000));
    Book(TH1F("pT_akt3","pT",50,0,2000));
  Book(TH1F("pT_ca4","pT",50,0,2000));
   Book(TH1F("pT_kt4","pT",50,0,2000));
    Book(TH1F("pT_akt4","pT",50,0,2000));
  Book(TH1F("pT_ca5","pT",50,0,2000));
   Book(TH1F("pT_kt5","pT",50,0,2000));
    Book(TH1F("pT_akt5","pT",50,0,2000));
  Book(TH1F("pT_ca6","pT",50,0,2000));
   Book(TH1F("pT_kt6","pT",50,0,2000));
    Book(TH1F("pT_akt6","pT",50,0,2000));
  Book(TH1F("pT_ca7","pT",50,0,2000));
   Book(TH1F("pT_kt7","pT",50,0,2000));
    Book(TH1F("pT_akt7","pT",50,0,2000));
  Book(TH1F("pT_ca8","pT",50,0,2000));
   Book(TH1F("pT_kt8","pT",50,0,2000));
    Book(TH1F("pT_akt8","pT",50,0,2000));
  Book(TH1F("pT_ca9","pT",50,0,2000));
   Book(TH1F("pT_kt9","pT",50,0,2000));
    Book(TH1F("pT_akt9","pT",50,0,2000));
  Book(TH1F("pT_ca10","pT",50,0,2000));
   Book(TH1F("pT_kt10","pT",50,0,2000));
    Book(TH1F("pT_akt10","pT",50,0,2000));
  Book(TH1F("pT_ca11","pT",50,0,2000));
   Book(TH1F("pT_kt11","pT",50,0,2000));
    Book(TH1F("pT_akt11","pT",50,0,2000));
  Book(TH1F("pT_ca12","pT",50,0,2000));
   Book(TH1F("pT_kt12","pT",50,0,2000));
    Book(TH1F("pT_akt12","pT",50,0,2000));
  Book(TH1F("pT_ca13","pT",50,0,2000));
   Book(TH1F("pT_kt13","pT",50,0,2000));
    Book(TH1F("pT_akt13","pT",50,0,2000));
  Book(TH1F("pT_ca14","pT",50,0,2000));
   Book(TH1F("pT_kt14","pT",50,0,2000));
    Book(TH1F("pT_akt14","pT",50,0,2000));
  Book(TH1F("pT_ca15","pT",50,0,2000));
   Book(TH1F("pT_kt15","pT",50,0,2000));
    Book(TH1F("pT_akt15","pT",50,0,2000));

 
       Book(TH1F("pT_cms_ca1","CMSTT ca alg",50,0,2000));
        Book(TH1F("pT_cms_kt1","CMSTT ca alg",50,0,2000));
	 Book(TH1F("pT_cms_akt1","CMSTT ca alg",50,0,2000));
	   Book(TH1F("pT_cms_ca2","CMSTT ca alg",50,0,2000));
        Book(TH1F("pT_cms_kt2","CMSTT ca alg",50,0,2000));
	 Book(TH1F("pT_cms_akt2","CMSTT ca alg",50,0,2000));
	   Book(TH1F("pT_cms_ca3","CMSTT ca alg",50,0,2000));
        Book(TH1F("pT_cms_kt3","CMSTT ca alg",50,0,2000));
	 Book(TH1F("pT_cms_akt3","CMSTT ca alg",50,0,2000));
	   Book(TH1F("pT_cms_ca4","CMSTT ca alg",50,0,2000));
        Book(TH1F("pT_cms_kt4","CMSTT ca alg",50,0,2000));
	 Book(TH1F("pT_cms_akt4","CMSTT ca alg",50,0,2000));
	   Book(TH1F("pT_cms_ca5","CMSTT ca alg",50,0,2000));
        Book(TH1F("pT_cms_kt5","CMSTT ca alg",50,0,2000));
	 Book(TH1F("pT_cms_akt5","CMSTT ca alg",50,0,2000));
	   Book(TH1F("pT_cms_ca6","CMSTT ca alg",50,0,2000));
        Book(TH1F("pT_cms_kt6","CMSTT ca alg",50,0,2000));
	 Book(TH1F("pT_cms_akt6","CMSTT ca alg",50,0,2000));
	   Book(TH1F("pT_cms_ca7","CMSTT ca alg",50,0,2000));
        Book(TH1F("pT_cms_kt7","CMSTT ca alg",50,0,2000));
	 Book(TH1F("pT_cms_akt7","CMSTT ca alg",50,0,2000));
  Book(TH1F("pT_cms_ca8","CMSTT ca alg",50,0,2000));
        Book(TH1F("pT_cms_kt8","CMSTT ca alg",50,0,2000));
	 Book(TH1F("pT_cms_akt8","CMSTT ca alg",50,0,2000));
  Book(TH1F("pT_cms_ca9","CMSTT ca alg",50,0,2000));
        Book(TH1F("pT_cms_kt9","CMSTT ca alg",50,0,2000));
	 Book(TH1F("pT_cms_akt9","CMSTT ca alg",50,0,2000));
  Book(TH1F("pT_cms_ca10","CMSTT ca alg",50,0,2000));
        Book(TH1F("pT_cms_kt10","CMSTT ca alg",50,0,2000));
	 Book(TH1F("pT_cms_akt10","CMSTT ca alg",50,0,2000));
  Book(TH1F("pT_cms_ca11","CMSTT ca alg",50,0,2000));
        Book(TH1F("pT_cms_kt11","CMSTT ca alg",50,0,2000));
	 Book(TH1F("pT_cms_akt11","CMSTT ca alg",50,0,2000));
  Book(TH1F("pT_cms_ca12","CMSTT ca alg",50,0,2000));
        Book(TH1F("pT_cms_kt12","CMSTT ca alg",50,0,2000));
	 Book(TH1F("pT_cms_akt12","CMSTT ca alg",50,0,2000));

	   Book(TH1F("pT_cms_ca13","CMSTT ca alg",50,0,2000));
        Book(TH1F("pT_cms_kt13","CMSTT ca alg",50,0,2000));
	 Book(TH1F("pT_cms_akt13","CMSTT ca alg",50,0,2000));
  Book(TH1F("pT_cms_ca14","CMSTT ca alg",50,0,2000));
        Book(TH1F("pT_cms_kt14","CMSTT ca alg",50,0,2000));
	 Book(TH1F("pT_cms_akt14","CMSTT ca alg",50,0,2000));




	 Book(TH1F("delta_pT_ca1","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_kt1","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_akt1","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_ca2","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_kt2","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_akt2","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_ca3","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_kt3","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_akt3","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_ca4","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_kt4","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_akt4","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_ca5","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_kt5","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_akt5","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_ca6","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_kt6","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_akt6","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_ca7","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_kt7","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_akt7","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_ca8","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_kt8","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_akt8","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_ca9","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_kt9","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_akt9","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_ca10","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_kt10","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_akt10","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_ca11","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_kt11","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_akt11","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_ca12","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_kt12","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_akt12","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_ca13","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_kt13","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_akt13","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_ca14","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_kt14","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_akt14","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_ca15","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_kt15","delta pT ca01",50,-50,50));
	 Book(TH1F("delta_pT_akt15","delta pT ca01",50,-50,50));
	 
	 Book(TH1F("delta_phi_ca1","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_kt1","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_akt1","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_ca2","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_kt2","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_akt2","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_ca3","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_kt3","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_akt3","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_ca4","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_kt4","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_akt4","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_ca5","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_kt5","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_akt5","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_ca6","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_kt6","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_akt6","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_ca7","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_kt7","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_akt7","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_ca8","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_kt8","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_akt8","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_ca9","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_kt9","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_akt9","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_ca10","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_kt10","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_akt10","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_ca11","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_kt11","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_akt11","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_ca12","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_kt12","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_akt12","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_ca13","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_kt13","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_akt13","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_ca14","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_kt14","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_akt14","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_ca15","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_kt15","delta phi ca01",50,-3,3));
	 Book(TH1F("delta_phi_akt15","delta phi ca01",50,-3,3));

	 Book(TH1F("delta_eta_ca1","delta eta ca01",50,-50,50));
	 Book(TH1F("delta_eta_kt1","delta eta kt01",50,-50,50));
	 Book(TH1F("delta_eta_akt1","delta eta akt01",50,-50,50));
	 Book(TH1F("delta_eta_ca2","delta eta ca01",50,-50,50));
	 Book(TH1F("delta_eta_kt2","delta eta kt01",50,-50,50));
	 Book(TH1F("delta_eta_akt2","delta eta akt01",50,-50,50));
	 Book(TH1F("delta_eta_ca3","delta eta ca01",50,-50,50));
	 Book(TH1F("delta_eta_kt3","delta eta kt01",50,-50,50));
	 Book(TH1F("delta_eta_akt3","delta eta akt01",50,-50,50));
	 Book(TH1F("delta_eta_ca4","delta eta ca01",50,-50,50));
	 Book(TH1F("delta_eta_kt4","delta eta kt01",50,-50,50));
	 Book(TH1F("delta_eta_akt4","delta eta akt01",50,-50,50));
	 Book(TH1F("delta_eta_ca5","delta eta ca01",50,-50,50));
	 Book(TH1F("delta_eta_kt5","delta eta kt01",50,-50,50));
	 Book(TH1F("delta_eta_akt5","delta eta akt01",50,-50,50));
	 Book(TH1F("delta_eta_ca6","delta eta ca01",50,-50,50));
	 Book(TH1F("delta_eta_kt6","delta eta kt01",50,-50,50));
	 Book(TH1F("delta_eta_akt6","delta eta akt01",50,-50,50));
	 Book(TH1F("delta_eta_ca7","delta eta ca01",50,-50,50));
	 Book(TH1F("delta_eta_kt7","delta eta kt01",50,-50,50));
	 Book(TH1F("delta_eta_akt7","delta eta akt01",50,-50,50));
	 Book(TH1F("delta_eta_ca8","delta eta ca01",50,-50,50));
	 Book(TH1F("delta_eta_kt8","delta eta kt01",50,-50,50));
	 Book(TH1F("delta_eta_akt8","delta eta akt01",50,-50,50));
	 Book(TH1F("delta_eta_ca9","delta eta ca01",50,-50,50));
	 Book(TH1F("delta_eta_kt9","delta eta kt01",50,-50,50));
	 Book(TH1F("delta_eta_akt9","delta eta akt01",50,-50,50));
	 Book(TH1F("delta_eta_ca10","delta eta ca01",50,-50,50));
	 Book(TH1F("delta_eta_kt10","delta eta kt01",50,-50,50));
	 Book(TH1F("delta_eta_akt10","delta eta akt01",50,-50,50));
	 Book(TH1F("delta_eta_ca11","delta eta ca01",50,-50,50));
	 Book(TH1F("delta_eta_kt11","delta eta kt01",50,-50,50));
	 Book(TH1F("delta_eta_akt11","delta eta akt01",50,-50,50));
	 Book(TH1F("delta_eta_ca12","delta eta ca01",50,-50,50));
	 Book(TH1F("delta_eta_kt12","delta eta kt01",50,-50,50));
	 Book(TH1F("delta_eta_akt12","delta eta akt01",50,-50,50));
	 Book(TH1F("delta_eta_ca13","delta eta ca01",50,-50,50));
	 Book(TH1F("delta_eta_kt13","delta eta kt01",50,-50,50));
	 Book(TH1F("delta_eta_akt13","delta eta akt01",50,-50,50));
	 Book(TH1F("delta_eta_ca14","delta eta ca01",50,-50,50));
	 Book(TH1F("delta_eta_kt14","delta eta kt01",50,-50,50));
	 Book(TH1F("delta_eta_akt14","delta eta akt01",50,-50,50));
	  Book(TH1F("delta_eta_ca15","delta eta ca01",50,-50,50));
	 Book(TH1F("delta_eta_kt15","delta eta kt01",50,-50,50));
	 Book(TH1F("delta_eta_akt15","delta eta akt01",50,-50,50));


       Book(TH1F("topmass", "pf top mass",100,0,400));
       
 Book(TH1F("topmass_jet", "pf top mass",100,0,400));
        Book(TH2F("JetDisplay","Jet event disply",100,-PI,PI,100,-6,6));

	Book(TH1F("pT_jet","topjet pT",100,0,2000));
	Book(TH1F("pT_softdrop","softdrop pT",100,0,2000));
	Book(TH1F("mass_jet","topjet mass",100,0,300));
	Book(TH1F("mass_softdrop","sofdrop mass",100,0,300));
	Book(TH1F("mass_jet200","topjet mass",100,0,300));
	Book(TH1F("mass_softdrop200","sofdrop mass",100,0,300));
	Book(TH1F("mass_jet400","topjet mass",100,0,300));
	Book(TH1F("mass_softdrop400","sofdrop mass",100,0,300));
	Book(TH1F("mass_jet600","topjet mass",100,0,300));
	Book(TH1F("mass_softdrop600","sofdrop mass",100,0,300));

	
	Book(TH1F("bkg_pT_jet","topjet pT",100,0,2000));
	Book(TH1F("bkg_pT_softdrop","softdrop pT",100,0,2000));
	Book(TH1F("bkg_mass_jet","topjet mass",100,0,300));
	Book(TH1F("bkg_mass_softdrop","sofdrop mass",100,0,300));
	Book(TH1F("bkg_mass_jet200","topjet mass",100,0,300));
	Book(TH1F("bkg_mass_softdrop200","sofdrop mass",100,0,300));
	Book(TH1F("bkg_mass_jet400","topjet mass",100,0,300));
	Book(TH1F("bkg_mass_softdrop400","sofdrop mass",100,0,300));
	Book(TH1F("bkg_mass_jet600","topjet mass",100,0,300));
	Book(TH1F("bkg_mass_softdrop600","sofdrop mass",100,0,300));

	for(int conesize=1;conesize<15;conesize++){
	for(int t=0;t<5;t++) {
	  for(int L=0;L<6;L++){
	    TString hname1 = TString::Format("distance_subjet%d_decaypro%d", t,L);
	    TString hname2 = TString::Format("distance between subjet%d and decay product %d", t,L);
	    Book(TH1F(hname1,hname2,20,0,7));
	  }
	  TString hnamey1 = TString::Format("delta_pT_subjet%d_ca%d", t,conesize);
	  TString hnamey2 = TString::Format("delta_phi_subjet%d_ca%d", t,conesize);
	  TString hnamey3 = TString::Format("delta_eta_subjet%d_ca%d", t,conesize);
	  TString hnamey5 = TString::Format("delta_pT_subjet%d_kt%d", t,conesize);
	  TString hnamey6 = TString::Format("delta_phi_subjet%d_kt%d", t,conesize);
	  TString hnamey7 = TString::Format("delta_eta_subjet%d_kt%d", t,conesize);
	  TString hnamey8 = TString::Format("delta_pT_subjet%d_akt%d", t,conesize);
	  TString hnamey9 = TString::Format("delta_phi_subjet%d_akt%d", t,conesize);
	  TString hnamey10 = TString::Format("delta_eta_subjet%d_akt%d", t,conesize);
	  Book(TH1F(hnamey1,"subjet",50,-50,50));
	  Book(TH1F(hnamey2,"subjet",50,-3,3));
	  Book(TH1F(hnamey3,"subjet",50,-20,20));
	  Book(TH1F(hnamey5,"subjet",50,-50,50));
	  Book(TH1F(hnamey6,"subjet",50,-3,3));
	  Book(TH1F(hnamey7,"subjet",50,-20,20));
	  Book(TH1F(hnamey8,"subjet",50,-50,50));
	  Book(TH1F(hnamey9,"subjet",50,-3,3));
	  Book(TH1F(hnamey10,"subjet",50,-20,20));
	}}
	//	Book(TH1F("pT_decay","pT decay",100,0,2000));
	for(int conesize=1;conesize<15;conesize++)
	  for(int L=0;L<6;L++) {
	    TString effname = TString::Format("pT_decay%d_%d", L,conesize);
	  TString effname1 = TString::Format("pT_decay%d_ca%d", L,conesize);
	  TString effname2 = TString::Format("pT_decay%d_kt%d", L,conesize);
	  TString effname3 = TString::Format("pT_decay%d_akt%d", L,conesize);
	  Book(TH1F(effname,"pt decay products",100,0,2000));
	  Book(TH1F(effname1,"pT decay products",100,0,2000));
	  Book(TH1F(effname2,"pT decay products",100,0,2000));
	  Book(TH1F(effname3,"pT decay products",100,0,2000));
}



  tmva_tagger=new TMVA_tagger();
  Showerdeconstruction_tagger= new Showerdeconstruction();
  Showerdeconstruction_taggerV2= new ShowerdeconstructionV2();
  Softdrop = new SoftDrop();			
  jwj = new Jetswithoutjets();
  varR = new VariableR();
}

void newTT2Hists::SetIdVersion(TString s)
{
  idVersion=s;
}

void newTT2Hists::Fill()
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


 
 

 
  
  float minDeltaR2=10000;
  int bestjetindex=-1;
  int bestjetindex2=-1;
  // int algo=1;

//EFFICIENCY
   if(!IsRealData && (idVersion=="TTbarPF" || idVersion=="TTbarEff_1" || idVersion=="TTbarEff_2" || idVersion=="TTbarEff_3"))
    {
    TTbarGen* Decay = calc->GetTTbarGen();
    std::vector<GenParticle> Had_Tops;
    std::vector<GenParticle> decay_products;
    bool isHadronic=false;
    if (Decay->IsTopHadronicDecay()) {
      Had_Tops.push_back(Decay->Top());
      decay_products.push_back(Decay->Wdecay1());
      decay_products.push_back(Decay->Wdecay2());
      decay_products.push_back(Decay->bTop());
    }
    if (Decay->IsAntiTopHadronicDecay()){ 
      Had_Tops.push_back(Decay->Antitop());
      decay_products.push_back(Decay->WMinusdecay1());
      decay_products.push_back(Decay->WMinusdecay2());
      decay_products.push_back(Decay->bAntitop());
    }
     TTbarGen::E_DecayChannel decaymode= Decay->DecayChannel();
     // std::cout<<"decaymode "<<decaymode<<std::endl;
    int oldbestjet2=-1;
    // double PI=3.14/*159265358979323846*/;
     // std::cout<<"1"<<std::endl;


     


    
    for (unsigned int j=0; j<Had_Tops.size(); j++)//if (isHadronic)
    {
      double DeltaR2=1000;
     bestjetindex2=-1;
     fastjet::ClusterSequence clusterSq;
     vector<fastjet::PseudoJet> jets=varR->Get_varRJet(clusterSq);
      for(int i=0;i<jets.size();i++){
		fastjet::PseudoJet Jet=jets[i];
		if(Jet.phi()>PI)  DeltaR2=sqrt(pow(Had_Tops[j].phi()-(Jet.phi()-2*PI),2)+pow(Had_Tops[j].eta()-Jet.eta(),2));
		else DeltaR2=sqrt(pow(Had_Tops[j].phi()-Jet.phi(),2)+pow(Had_Tops[j].eta()-Jet.eta(),2));
		 if(DeltaR2<minDeltaR2)
		   {
		     minDeltaR2=DeltaR2;
		     bestjetindex2=i;
		   }
      }
      	if((bestjetindex2>-1) && (bestjetindex2!=oldbestjet2)){
	  	  oldbestjet2=bestjetindex2;
	}
    	      
    }
    
    
    }



  if(!IsRealData && idVersion=="QCDPF")
  {
     fastjet::JetDefinition *JetDef1, *JetDef2 ,  *JetDef3 ; 
     fastjet::ClusterSequence *JetFinder1,*JetFinder2,*JetFinder3;
    // std::cout<<"new event"<<std::endl;
    std::vector<GenParticle>* genparticles = calc->GetGenParticles();
    // for(unsigned int i=0; i<bcc->topjets->size(); ++i)
   {
     //minDeltaR=10000;
    
     int bestjetindex=-1;
     int bestindex=-1;
	 
	 // std::cout<<"test"<<std::endl;
     std::vector<fastjet::PseudoJet> SortedJets1, SortedJets2,SortedJets3;
	 for(int algo=0;algo<4;algo++){
	    int bestjetindex=-1;
	     int bestindex=-1;
	     double highestPt=-1;
	     double minDeltaR=10000;
	   for(int conesize=8;conesize<9;conesize++){
	     int bestjetindex=-1;
	     int bestindex=-1;
	     double highestPt=-1;
	     double minDeltaR=10000;
	     for(unsigned int j=0; j<genparticles->size();j++)
	       {
		 if (abs(genparticles->at(j).pdgId())<=6 || abs(genparticles->at(j).pdgId())==21)
		   {
	    int oldbestjet2=-1;
	    double microjet_cone=(double)conesize/10.;
	    double DeltaR2=100;
	    //sort(bcc->topjets->begin(), bcc->topjets->end(), HigherPt());
	  
	    // bestjetindex=-1;
	    //bestindex=-1;
	    //getjet
	    TopJet topjet;
	    JetProps jp(&topjet,calc->GetPFParticles());
	     std::vector<fastjet::PseudoJet> Jet;
	    std::vector<fastjet::PseudoJet> Jet1;
	    std::vector<fastjet::PseudoJet> Jet2;
	    std::vector<fastjet::PseudoJet> jetpart = jp.Get_all_pfparticles();
	     fastjet::JetDefinition *JetDef1 = new fastjet::JetDefinition(fastjet::cambridge_algorithm,conesize/10.); 
	     fastjet::ClusterSequence *JetFinder1 = new fastjet::ClusterSequence(jetpart, *JetDef1);
	    std::vector<fastjet::PseudoJet> tops1 = JetFinder1->inclusive_jets(400.);
	   SortedJets1 = sorted_by_pt(tops1);
	  
	    fastjet::JetDefinition *JetDef2 = new fastjet::JetDefinition(fastjet::kt_algorithm,conesize/10.); 
	   fastjet::ClusterSequence *JetFinder2 = new fastjet::ClusterSequence(jetpart, *JetDef2);
	    std::vector<fastjet::PseudoJet> tops2 = JetFinder2->inclusive_jets(400.);
	    SortedJets2 = sorted_by_pt(tops2);

	     fastjet::JetDefinition *JetDef3 = new fastjet::JetDefinition(fastjet::antikt_algorithm,conesize/10.); 
	    	fastjet::ClusterSequence *JetFinder3 = new fastjet::ClusterSequence(jetpart, *JetDef3);
	    std::vector<fastjet::PseudoJet> tops3 = JetFinder3->inclusive_jets(400.);
	    SortedJets3 = sorted_by_pt(tops3);/*
	      std::cout<<"jets1 "<<SortedJets1.size()<<std::endl;
	    std::cout<<"jets2 "<<SortedJets2.size()<<std::endl;
	    std::cout<<"jets3 "<<SortedJets3.size()<<std::endl;*/
	    
	 
	    // std::cout<<"test2"<<std::endl;
	   
	    	     if(algo==0 && SortedJets1.size()>0 ) {
	   for(int i=0;i<SortedJets1.size();i++){
	     fastjet::PseudoJet Jet=SortedJets1[i];
	     GenParticle parton=genparticles->at(j);
	     if(Jet.phi()>PI)  DeltaR2=sqrt(pow(parton.phi()-(Jet.phi()-2*PI),2)+pow(parton.eta()-Jet.eta(),2));
	     else DeltaR2=sqrt(pow(parton.phi()-Jet.phi(),2)+pow(parton.eta()-Jet.eta(),2));
	     // std::cout<<"R "<<DeltaR2<<std::endl;
	     //std::cout<<"pt"<<highestPt<<std::endl;
	     if(DeltaR2<1.0 &&  genparticles->at(j).pt()>highestPt && DeltaR2<minDeltaR)
	       {
		 //	 std::cout<<"loop"<<std::endl;
		 bestjetindex=j;
		 bestindex=i;
		 highestPt=genparticles->at(j).pt();
		 minDeltaR=DeltaR2; 
	       }
	   }
	     }
	     // std::cout<<algo<<" "<<minDeltaR<<std::endl;
	 // std::cout<<"j "<<j<<std::endl;
	     //	     std::cout<<bestjetindex<<" "<<bestindex<<"algo "<<algo<<" deltar "<<minDeltaR2<<std::endl;

	 if(algo==1 && SortedJets2.size()>0 ) {
	   for(int i=0;i<SortedJets2.size();i++){
	     fastjet::PseudoJet Jet=SortedJets2[i];
	     GenParticle parton=genparticles->at(j);
	     if(Jet.phi()>PI)  DeltaR2=sqrt(pow(parton.phi()-(Jet.phi()-2*PI),2)+pow(parton.eta()-Jet.eta(),2));
	     else DeltaR2=sqrt(pow(parton.phi()-Jet.phi(),2)+pow(parton.eta()-Jet.eta(),2));
	      if(DeltaR2<1.0 &&  genparticles->at(j).pt()>highestPt  && DeltaR2<minDeltaR)
	       {
		 // std::cout<<"loop2"<<std::endl;
		 bestjetindex=j;
		 bestindex=i;
		 highestPt=genparticles->at(j).pt();
		 minDeltaR=DeltaR2; 
	       }
	   }
	 }

	 
	 if(algo==2 && SortedJets3.size()>0 ) {
	   for(int i=0;i<SortedJets3.size();i++){
	     fastjet::PseudoJet Jet=SortedJets3[i];
	     GenParticle parton=genparticles->at(j);
	     if(Jet.phi()>PI)  DeltaR2=sqrt(pow(parton.phi()-(Jet.phi()-2*PI),2)+pow(parton.eta()-Jet.eta(),2));
	     else DeltaR2=sqrt(pow(parton.phi()-Jet.phi(),2)+pow(parton.eta()-Jet.eta(),2));
	       if(DeltaR2<1.0 &&  genparticles->at(j).pt()>highestPt && DeltaR2<minDeltaR)
	       {
		 // std::cout<<"3"<<DeltaR2<<"genpt "<<genparticles->at(j).pt()<<" highest pt "<<highestPt<<std::endl;
		 bestjetindex=j;
		 bestindex=i;
		 highestPt=genparticles->at(j).pt();
		 minDeltaR=DeltaR2; 
	       }
	   }
	 }

	    
	    
	 /*  delete JetDef1;
	    delete JetFinder1;
	    delete JetDef2;
	    delete JetFinder2;
	    delete JetDef3;
	    delete JetFinder3;*/

		   
	       
     


	   


	   


	    

     if (bestjetindex>-1)
     {
        std::cout<<algo<<std::endl;
       fastjet::PseudoJet probejet;
       
         if(algo==0) probejet=SortedJets1[bestindex];
       if(algo==1)  probejet=SortedJets2[bestindex];
       if(algo==2)  probejet=SortedJets3[bestindex];
       TString hname1 = TString::Format("pT_ca%d", conesize);
       TString hname2 = TString::Format("pT_kt%d", conesize);
       TString hname3 = TString::Format("pT_akt%d",conesize);
       if (algo==0) Hist(hname1)->Fill(genparticles->at(bestjetindex).pt(),weight);
       if (algo==1) Hist(hname2)->Fill(genparticles->at(bestjetindex).pt(),weight);
       if (algo==2) Hist(hname3)->Fill(genparticles->at(bestjetindex).pt(),weight);
       /* if(algo==0) std::cout<<"test2"<<std::endl;
       if(algo==1) std::cout<<"test"<<std::endl;
       if(algo==2) std::cout<<"test3"<<std::endl;*/
	 

        double mjet,mmin;
	     int nsubjets;
        fastjet::PseudoJet CMSjet;
	 std::vector<fastjet::PseudoJet> subjets;
	 if(CMSTopTagFull_pseudo(probejet,3.0,0.05,0.4,0.0004,mjet, nsubjets,mmin,subjets)){
	     std::cout<<"jetmass "<<mjet<<std::endl;
	     std::cout<<"nsubjets "<<nsubjets<<std::endl;
	     std::cout<<"mmin "<<mmin<<std::endl;
	     TString hname4 = TString::Format("pT_cms_ca%d", conesize);
	    TString hname5 = TString::Format("pT_cms_kt%d", conesize);
	    TString hname6 = TString::Format("pT_cms_akt%d",conesize);
	    //std::cout<<hname4<<std::endl;
	     if(algo==0) Hist(hname4)->Fill(genparticles->at(bestjetindex).pt(),weight);
	     if(algo==1) Hist(hname5)->Fill(genparticles->at(bestjetindex).pt(),weight);
	     if(algo==2) Hist(hname6)->Fill(genparticles->at(bestjetindex).pt(),weight);

	     }


       /* TopJet Ca8jet=bcc->topjets->at(i); 
       fastjet::PseudoJet groomed_jet;
       Softdrop->GetJet(Ca8jet, calc->GetPFParticles(),0.1,2.0,groomed_jet);
       std::cout<<"soft drop "<<groomed_jet.perp()<<"orginal jet "<<Ca8jet.pt()<<std::endl;
       Hist("bkg_pT_jet")->Fill(Ca8jet.pt(),weight);
       Hist("bkg_mass_jet")->Fill(Ca8jet.v4().M(),weight);
       Hist("bkg_pT_softdrop")->Fill(groomed_jet.perp(),weight);
       Hist("bkg_mass_softdrop")->Fill(groomed_jet.m(),weight);
       if(Ca8jet.pt()>200){
	 Hist("bkg_mass_jet200")->Fill(Ca8jet.v4().M(),weight);
	 Hist("bkg_mass_softdrop200")->Fill(groomed_jet.m(),weight);
       }
       if(Ca8jet.pt()>400){
	 Hist("bkg_mass_jet400")->Fill(Ca8jet.v4().M(),weight);
	 Hist("bkg_mass_softdrop400")->Fill(groomed_jet.m(),weight);
       }
       if(Ca8jet.pt()>600){
	 Hist("bkg_mass_jet600")->Fill(Ca8jet.v4().M(),weight);
	 Hist("bkg_mass_softdrop600")->Fill(groomed_jet.m(),weight);
       }
      */ 
     }
 delete JetDef1;
	    delete JetFinder1;
	    delete JetDef2;
	    delete JetFinder2;
	    delete JetDef3;
	    delete JetFinder3;
		   }}
	   }

   }
  
     

	 }}

}


void newTT2Hists::Finish()
{
  // final calculations, like division and addition of certain histograms
 

}

