if __name__ == '__main__':

# Usage : python crabConfig.py (to create jobs)
#         ./multicrab -c status -d <work area> (to check job status)

    from CRABAPI.RawCommand import crabCommand
    from httplib import HTTPException

    from CRABClient.UserUtilities import config
    config = config()
    
    from multiprocessing import Process

    # Common configuration

    config.General.workArea     = 'crab_projects_ntuples'
    config.General.transferLogs = False
    config.JobType.pluginName   = 'Analysis' # PrivateMC
    config.JobType.psetName     = 'hltBPHdqm_DQM.py'
    config.JobType.sendExternalFolder = True
    config.Data.inputDBS        = 'global'    
    config.Data.splitting       = 'LumiBased' # EventBased, FileBased, LumiBased (1 lumi ~= 300 events)
    config.Data.totalUnits      = -1
    config.Data.publication     = False
    config.Site.storageSite     = 'T2_US_Wisconsin'
#    config.Site.storageSite     = 'T3_US_FNALLPC'
    config.Data.ignoreLocality = True
    config.JobType.numCores = 4
    config.JobType.maxMemoryMB = 2500
    mask = 'https://cms-service-dqm.web.cern.ch/cms-service-dqm/CAF/certification/Collisions17/13TeV/PromptReco/Cert_294927-306462_13TeV_PromptReco_Collisions17_JSON.txt'
    def submit(config):
        try:
            crabCommand('submit', config = config)
        except HTTPException, hte:
            print hte.headers

    # dataset dependent configuration

#    config.General.requestName = 'job_spring16_ZZ'
#    config.Data.unitsPerJob    = 40
#    config.Data.inputDataset   = '/ZZ_TuneCUETP8M1_13TeV-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM'
#    config.Data.outLFNDirBase  = '/store/user/cmkuo/job_spring16_ZZ'
#    p = Process(target=submit, args=(config,))
#    p.start()
#    p.join()

    config.General.requestName = 'job_DATA_DoubleMuon_Run2017C_v1'
    config.Data.unitsPerJob    = 40
    config.Data.inputDataset   = '/DoubleMuon/Run2017C-PromptReco-v1/AOD'
    config.Data.outLFNDirBase  = '/store/user/eliza'
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'job_DATA_DoubleMuon_Run2017C_v2'
    config.Data.unitsPerJob    = 40
    config.Data.inputDataset   = '/DoubleMuon/Run2017C-PromptReco-v2/AOD'
    config.Data.outLFNDirBase  = '/store/user/eliza'
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()

    config.General.requestName = 'job_DATA_DoubleMuon_Run2017C_v3'
    config.Data.unitsPerJob    = 40
    config.Data.inputDataset   = '/DoubleMuon/Run2017C-PromptReco-v3/AOD'
    config.Data.outLFNDirBase  = '/store/user/eliza'
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'job_DATA_MuonEG_Run2017D_v1'
    config.Data.unitsPerJob    = 40
    config.Data.inputDataset   = '/MuonEG/Run2017D-PromptReco-v1/AOD'
    config.Data.outLFNDirBase  = '/store/user/eliza'
    p= Process(target=submit, args=(config,))
    p.start()
    p.join()

    config.General.requestName = 'job_DATA_MuonEG_Run2017E_v1'
    config.Data.unitsPerJob    = 40
    config.Data.inputDataset   = '/MuonEG/Run2017E-PromptReco-v1/AOD'
    config.Data.outLFNDirBase  = '/store/user/eliza'
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()

    config.General.requestName = 'job_DATA_MuonEG_Run2017F_v1'
    config.Data.unitsPerJob    = 40
    config.Data.inputDataset   = '/MuonEG/Run2017F-PromptReco-v1/AOD'
    config.Data.outLFNDirBase  = '/store/user/eliza'
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()