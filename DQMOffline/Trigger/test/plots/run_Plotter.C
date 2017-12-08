{
	gSystem->AddIncludePath("-Iexternal");
	gSystem->SetBuildDir("tmpdir", kTRUE);
	gROOT->ProcessLine(".L plotter_ZtoUpsilonPhoton.C+"); 
	gStyle->SetOptStat(0);

	plotter_ZtoUpsilonPhoton("RootFiles/DQM_V0001_R000000001__Global__CMSSW_X_Y_Z__RECO_C.root", "RootFiles/DQM_V0001_R000000001__Global__CMSSW_X_Y_Z__RECO_D.root","RootFiles/DQM_V0001_R000000001__Global__CMSSW_X_Y_Z__RECO_E.root","RootFiles/DQM_V0001_R000000001__Global__CMSSW_X_Y_Z__RECO_F.root"); 

}

