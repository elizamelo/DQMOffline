#include <iostream>
#include <algorithm>
#include <math.h>  
// #include <stdlib.h>

#include "TFile.h"
#include "TMath.h"
#include "TLorentzVector.h"
#include "TTree.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"
#include "TTreeReaderArray.h"
// #include "TRandom3.h"
// #include "TROOT.h"
#include "TH1.h"
#include "TDirectory.h"
#include "THStack.h"
#include "TCanvas.h"
#include "TColor.h"
#include "TLegend.h"
#include "TLatex.h"


#include "tdrstyle.C"
// #include "plugins/ggNtuplesFilesReader.h"
// #include "plugins/roccor2016/RoccoR.cc"
// #include "plugins/deltaR_deltaPhi.h"
// #include "plugins/anaObjects.h"
// #include "plugins/puWeight.h"
// #include "plugins/upsilonPolarizationAngle.h"
// #include "plugins/getSF.h"


// #ifdef __CINT__
// #pragma link C++ class anaMuon+;
// #pragma link C++ class anaPhoton+;
// #pragma link C++ class anaGenPart+;
// // #pragma link C++ class TLorentzVector+;
// #endif

using namespace std;

void plotter_DataMC(TH1D * h_DataC, TH1D * h_DataD, TH1D * h_DataE, TH1D * h_DataF, string outputFilePath, bool isLogY = false, bool isLogX = false) {
setTDRStyle();

    //h_DataC->Sumw2();	h_DataD->Sumw2();	h_DataE->Sumw2();	h_DataF->Sumw2();	

	h_DataC->SetMarkerStyle(20);
	h_DataC->SetMarkerSize(2);
	h_DataC->SetMarkerColor(kBlack);
	
	h_DataD->SetMarkerStyle(21);
	h_DataD->SetMarkerSize(2);
	h_DataD->SetMarkerColor(kBlue);
	
	h_DataE->SetMarkerStyle(22);
	h_DataE->SetMarkerSize(2);
	h_DataE->SetMarkerColor(kRed);
	
	h_DataF->SetMarkerStyle(24);
	h_DataF->SetMarkerSize(2);
	h_DataF->SetMarkerColor(kGreen);
	

	auto c1 = new TCanvas("c1","c1",1050*2.0,750*2.0);	

	if (isLogY) c1->SetLogy();
	if (isLogX) c1->SetLogx();

	//double histoMax = max(h_DataC->GetMaximum())*1.3;
	//h_DataC->SetMaximum(histoMax);
	h_DataC->Draw("E1");	
	h_DataC->GetYaxis()->SetTitle("Efficiency");
	//h_DataC->GetXaxis()->SetTitle("#gamma p_{T}");
	h_DataC->GetXaxis()->SetTitleOffset(1.0);
	h_DataC->GetYaxis()->SetTitleOffset(1.5);
	h_DataD->Draw("E1 same");
	h_DataE->Draw("E1 same");
	h_DataF->Draw("E1 same");


	// auto legend = new TLegend(0.1,0.7,0.48,0.9, "", "NB");
	auto legend = new TLegend(0.74,0.76,1.03,0.93);
	legend->SetBorderSize(0);
	legend->SetFillStyle(0);
	legend->AddEntry(h_DataC, "Era C", "lpe");
	legend->AddEntry(h_DataD, "Era D", "lpe");
    legend->AddEntry(h_DataE, "Era E", "lpe"); 
    legend->AddEntry(h_DataF, "Era F", "lpe"); 
	legend->Draw();

    auto latex = new TLatex();
    latex->SetNDC();
    latex->SetTextFont(61);
    latex->SetTextSize(0.05);
    latex->DrawLatex(.17, 0.96, "CMS");
    latex->SetTextFont(52);
    latex->SetTextSize(0.04);
    latex->SetTextAlign(11);
    latex->DrawLatex(.25, 0.96, "Preliminary");
    latex->SetTextFont(42);
    latex->SetTextSize(0.04);
    latex->SetTextAlign(31);
    latex->DrawLatex(0.99, 0.96, "24.3 fb^{-1} (13 TeV, 2017) ");

	c1->Update();

	system(("mkdir -p  `dirname plotFiles/"+outputFilePath+".png`").c_str());
	c1->SaveAs(("plotFiles/"+outputFilePath+".png").c_str());
	c1->SaveAs(("plotFiles/"+outputFilePath+".pdf").c_str());
	c1->SaveAs(("plotFiles/"+outputFilePath+".root").c_str());

	delete c1;
	delete legend;
	delete latex;
}
void plotter_ZtoUpsilonPhoton(string histoDataCFilePath, string histoDataDFilePath, string histoDataEFilePath, string histoDataFFilePath)  
{
	auto * histoDataCFile = TFile::Open(histoDataCFilePath.c_str());
	auto * histoDataDFile = TFile::Open(histoDataDFilePath.c_str());
	auto * histoDataEFile = TFile::Open(histoDataEFilePath.c_str());
	auto * histoDataFFile = TFile::Open(histoDataFFilePath.c_str());



	// plotter
	setTDRStyle();
    system("rm -fr plotFiles; mkdir plotFiles");
    
    
    
 /*	plotter_DataMC(
		(TH1D*)histoDataCFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_phPt"), 
		(TH1D*)histoDataDFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_phPt"), 
		(TH1D*)histoDataEFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_phPt"), 
		(TH1D*)histoDataFFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_phPt"), 
		"dataDQM/photon1/h_Eff_pT",
		false
); */

 	plotter_DataMC(
		(TH1D*)histoDataCFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_phEta"), 
		(TH1D*)histoDataDFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_phEta"), 
		(TH1D*)histoDataEFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_phEta"), 
		(TH1D*)histoDataFFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_phEta"), 
		"dataDQM/photonv2/h_Eff_eta",
		false
); 

 	plotter_DataMC(
		(TH1D*)histoDataCFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_phPhi"), 
		(TH1D*)histoDataDFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_phPhi"), 
		(TH1D*)histoDataEFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_phPhi"), 
		(TH1D*)histoDataFFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_phPhi"), 
		"dataDQM/photonv2/h_Eff_phi",
		false
); 

 	plotter_DataMC(
		(TH1D*)histoDataCFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_DiMuEta"), 
		(TH1D*)histoDataDFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_DiMuEta"), 
		(TH1D*)histoDataEFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_DiMuEta"), 
		(TH1D*)histoDataFFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_DiMuEta"), 
		"dataDQM/muons1_v2/h_Eff_DiMuEta",
		false
); 

 /*	plotter_DataMC(
		(TH1D*)histoDataCFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_DiMuPt"), 
		(TH1D*)histoDataDFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_DiMuPt"), 
		(TH1D*)histoDataEFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_DiMuPt"), 
		(TH1D*)histoDataFFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_DiMuPt"), 
		"dataDQM/muons1/h_Eff_DiMuPt",
		false
); 

 	plotter_DataMC(
		(TH1D*)histoDataCFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_DiMuPhi"), 
		(TH1D*)histoDataDFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_DiMuPhi"), 
		(TH1D*)histoDataEFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_DiMuPhi"), 
		(TH1D*)histoDataFFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_DiMuPhi"), 
		"dataDQM/muons1/h_Eff_DiMuPhi",
		false
);

 	plotter_DataMC(
		(TH1D*)histoDataCFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_mu1Phi"), 
		(TH1D*)histoDataDFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_mu1Phi"), 
		(TH1D*)histoDataEFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_mu1Phi"), 
		(TH1D*)histoDataFFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_mu1Phi"), 
		"dataDQM/muons1/h_Eff_mu1_Phi",
		false
);

 	plotter_DataMC(
		(TH1D*)histoDataCFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_mu1Pt"), 
		(TH1D*)histoDataDFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_mu1Pt"), 
		(TH1D*)histoDataEFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_mu1Pt"), 
		(TH1D*)histoDataFFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_mu1Pt"), 
		"dataDQM/muons1/h_Eff_mu1_Pt",
		false
);

 	plotter_DataMC(
		(TH1D*)histoDataCFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_mu1Eta"), 
		(TH1D*)histoDataDFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_mu1Eta"), 
		(TH1D*)histoDataEFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_mu1Eta"), 
		(TH1D*)histoDataFFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_mu1Eta"), 
		"dataDQM/muons1/h_Eff_mu1_Eta",
		false
);

 	plotter_DataMC(
		(TH1D*)histoDataCFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_mu2Phi"), 
		(TH1D*)histoDataDFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_mu2Phi"), 
		(TH1D*)histoDataEFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_mu2Phi"), 
		(TH1D*)histoDataFFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_mu2Phi"), 
		"dataDQM/muons1/h_Eff_mu2_Phi",
		false
);

 	plotter_DataMC(
		(TH1D*)histoDataCFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_mu2Pt"), 
		(TH1D*)histoDataDFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_mu2Pt"), 
		(TH1D*)histoDataEFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_mu2Pt"), 
		(TH1D*)histoDataFFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_mu2Pt"), 
		"dataDQM/muons1/h_Eff_mu2_Pt",
		false
);

 	plotter_DataMC(
		(TH1D*)histoDataCFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_mu2Eta"), 
		(TH1D*)histoDataDFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_mu2Eta"), 
		(TH1D*)histoDataEFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_mu2Eta"), 
		(TH1D*)histoDataFFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_mu2Eta"), 
		"dataDQM/muons1/h_Eff_mu2_Eta",
		false
);

 	plotter_DataMC(
		(TH1D*)histoDataCFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_L3TnP_ZtoUpsilonPhoton1/Tag_and_Probe/effic_muPt"), 
		(TH1D*)histoDataDFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_L3TnP_ZtoUpsilonPhoton1/Tag_and_Probe/effic_muPt"), 
		(TH1D*)histoDataEFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_L3TnP_ZtoUpsilonPhoton1/Tag_and_Probe/effic_muPt"), 
		(TH1D*)histoDataFFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_L3TnP_ZtoUpsilonPhoton1/Tag_and_Probe/effic_muPt"), 
		"dataDQM/tagandprobe/h_Eff_mu_Pt",
		false
);
*/
/* 	plotter_DataMC(
		(TH1D*)histoDataCFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_L3TnP_ZtoUpsilonPhoton1/Tag_and_Probe/effic_muEta"), 
		(TH1D*)histoDataDFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_L3TnP_ZtoUpsilonPhoton1/Tag_and_Probe/effic_muEta"), 
		(TH1D*)histoDataEFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_L3TnP_ZtoUpsilonPhoton1/Tag_and_Probe/effic_muEta"), 
		(TH1D*)histoDataFFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_L3TnP_ZtoUpsilonPhoton1/Tag_and_Probe/effic_muEta"), 
		"dataDQM/tagandprobe_v2/h_Eff_mu_Eta",
		false
);
 	plotter_DataMC(
		(TH1D*)histoDataCFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_L3TnP_ZtoUpsilonPhoton1/Tag_and_Probe/effic_muPhi"), 
		(TH1D*)histoDataDFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_L3TnP_ZtoUpsilonPhoton1/Tag_and_Probe/effic_muPhi"), 
		(TH1D*)histoDataEFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_L3TnP_ZtoUpsilonPhoton1/Tag_and_Probe/effic_muPhi"), 
		(TH1D*)histoDataFFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_L3TnP_ZtoUpsilonPhoton1/Tag_and_Probe/effic_muPhi"), 
		"dataDQM/tagandprobe_v2/h_Eff_mu_Phi",
		false
);*/
/*
 	plotter_DataMC(
		(TH1D*)histoDataCFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_L3TnP_ZtoUpsilonPhoton/Tag_and_Probe/effic_mu1Pt"), 
		(TH1D*)histoDataDFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_L3TnP_ZtoUpsilonPhoton/Tag_and_Probe/effic_mu1Pt"), 
		(TH1D*)histoDataEFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_L3TnP_ZtoUpsilonPhoton/Tag_and_Probe/effic_mu1Pt"), 
		(TH1D*)histoDataFFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_L3TnP_ZtoUpsilonPhoton/Tag_and_Probe/effic_mu1Pt"), 
		"dataDQM/tagandprobe/h_Eff_mu1_Pt",
		false
);

 	plotter_DataMC(
		(TH1D*)histoDataCFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_L3TnP_ZtoUpsilonPhoton/Tag_and_Probe/effic_DiMuPt"), 
		(TH1D*)histoDataDFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_L3TnP_ZtoUpsilonPhoton/Tag_and_Probe/effic_DiMuPt"), 
		(TH1D*)histoDataEFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_L3TnP_ZtoUpsilonPhoton/Tag_and_Probe/effic_DiMuPt"), 
		(TH1D*)histoDataFFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_L3TnP_ZtoUpsilonPhoton/Tag_and_Probe/effic_DiMuPt"), 
		"dataDQM/tagandprobe/h_Eff_DiMuPt",
		false
);


 	plotter_DataMC(
		(TH1D*)histoDataCFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_L3TnP_ZtoUpsilonPhoton/Tag_and_Probe/effic_DiMuMass"), 
		(TH1D*)histoDataDFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_L3TnP_ZtoUpsilonPhoton/Tag_and_Probe/effic_DiMuMass"), 
		(TH1D*)histoDataEFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_L3TnP_ZtoUpsilonPhoton/Tag_and_Probe/effic_DiMuMass"), 
		(TH1D*)histoDataFFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_L3TnP_ZtoUpsilonPhoton/Tag_and_Probe/effic_DiMuMass"), 
		"dataDQM/tagandprobe/h_Eff_DiMuMass",
		false
);

 	plotter_DataMC(
		(TH1D*)histoDataCFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_L3TnP_ZtoUpsilonPhoton/Tag_and_Probe/effic_DiMudR"), 
		(TH1D*)histoDataDFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_L3TnP_ZtoUpsilonPhoton/Tag_and_Probe/effic_DiMudR"), 
		(TH1D*)histoDataEFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_L3TnP_ZtoUpsilonPhoton/Tag_and_Probe/effic_DiMudR"), 
		(TH1D*)histoDataFFile->Get("DQMData/Run 1/HLT/Run summary/BPH/DiMu0_L3TnP_ZtoUpsilonPhoton/Tag_and_Probe/effic_DiMudR"), 
		"dataDQM/tagandprobe/h_Eff_DiMudR",
		false
);
*/
//DQM_V0001_R000000001__Global__CMSSW_X_Y_Z__RECO_RunC.root
//DQM_V0001_R000000001__Global__CMSSW_X_Y_Z__RECO_RunD.root
//DQM_V0001_R000000001__Global__CMSSW_X_Y_Z__RECO_RunE.root
//DQM_V0001_R000000001__Global__CMSSW_X_Y_Z__RECO_RunF.root
//DQMData/Run 1/HLT/Run summary/BPH/DiMu0_Lowmass_L1_photon1/effic_phPt"
//
} //end plotter_ZtoUpsilonPhoton
