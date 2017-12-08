#!/usr/bin/env python

##############
# Multi CRAB #
##############

import time 

if __name__ == '__main__':
  from CRABAPI.RawCommand import crabCommand
#from CRABClient.UserUtilities import config, getUsernameFromSiteDB
#config = config()
def submit(config):
  res = crabCommand('submit', config = config)

from CRABClient.UserUtilities import config
config = config()

dataset = {
        #'MuonEG' : '/MuonEG/Run2016H-v1/RAW',
        'MuonEG_D':'/MuonEG/Run2017D-PromptReco-v1/AOD',
        'MuonEG_E':'/MuonEG/Run2017E-PromptReco-v1/AOD',
        'MuonEG_F':'/MuonEG/Run2017F-PromptReco-v1/AOD',
        'DoubleMuonv1':'/DoubleMuon/Run2017C-PromptReco-v1/AOD',
        'DoubleMuonv2':'/DoubleMuon/Run2017C-PromptReco-v2/AOD',
        'DoubleMuonv3':'/DoubleMuon/Run2017C-PromptReco-v3/AOD'
       }

nfiles = -1 
#nfiles = 16 
filesPerJob = 1
mask = 'https://cms-service-dqm.web.cern.ch/cms-service-dqm/CAF/certification/Collisions17/13TeV/PromptReco/Cert_294927-306462_13TeV_PromptReco_Collisions17_JSON.txt'
#mask = 'https://cms-service-dqm.web.cern.ch/cms-service-dqm/CAF/certification/Collisions17/13TeV/DCSOnly/json_DCSONLY.txt'
#mask = 'https://cms-service-dqm.web.cern.ch/cms-service-dqm/CAF/certification/Collisions17/13TeV/DCSOnly/json_DCSONLY.txt' #DCSOnly
#mask='https://cms-service-dqm.web.cern.ch/cms-service-dqm/CAF/certification/Collisions17/13TeV/PromptReco/Cert_294927-303825_13TeV_PromptReco_Collisions17_JSON.txt'
config.General.transferOutputs = True
config.General.transferLogs = True
config.JobType.pluginName = 'Analysis'
#config.JobType.psetName = 'hlt_L1_V9_GRun_Data_v02_UERJ_v18.py'
config.JobType.numCores = 4
config.JobType.maxMemoryMB = 3000
config.Data.inputDBS = 'global'
config.Data.splitting = 'LumiBased'
# config.Data.splitting = 'FileBased'
config.Data.publication = False
config.JobType.outputFiles = ['DQM_onlyBPHHLT.root'] #,'DQMIO.root']
config.Site.storageSite = 'T2_US_Nebraska'
#config.Site.storageSite = 'T3_US_FNALLPC'
config.Data.ignoreLocality = True 
#config.Site.whitelist = ['T3_CH_CERN_CAF'] #Required for CAF submission
#config.Site.whitelist = ['T2_US_Nebraska'] 
config.Site.whitelist = ['T2_US_*']
config.JobType.allowUndistributedCMSSW = True
#config.Site.whitelist = ['T3_US_FNALLPC']
config.Site.ignoreGlobalBlacklist = True
#config.Site.ignoreGlobalBlacklist = False
config.Data.ignoreLocality = True
listOfSamples = ['DoubleMuonv1','DoubleMuonv2','DoubleMuonv3']
listOfSamples = ['MuonEG_D','MuonEG_E','MuonEG_F']
#listOfSamples = ['DoubleMuon']
#listOfSamples = ['HLTPhysics']

def doSubmit(listOfSamples):
  for sample in listOfSamples:
    newName = sample+name
    config.General.workArea = 'crab_'+newName
    config.General.requestName = sample
    config.Data.inputDataset = dataset[sample]
    config.Data.unitsPerJob = filesPerJob
    config.Data.totalUnits = nfiles
    config.Data.outputDatasetTag = sample
    config.Data.lumiMask = mask
    config.Data.outLFNDirBase = '/store/user/eliza'# + newName # or '/store/group/<subdir>'
    #config.Data.outLFNDirBase = '/store/user/%s/' % (getUsernameFromSiteDB())
    submit(config)

config.JobType.psetName = 'hltBPHdqm_DQM.py' 

nfiles = -1 
filesPerJob = 20
#mask = 'https://cms-service-dqm.web.cern.ch/cms-service-dqm/CAF/certification/Collisions17/13TeV/PromptReco/Cert_294927-303825_13TeV_PromptReco_Collisions17_JSON.txt' 
name = '_DQMBPH_Run2017D'
listOfSamples = ['MuonEG_D']
doSubmit(listOfSamples)

nfiles = -1
filesPerJob = 20
#mask = 'https://cms-service-dqm.web.cern.ch/cms-service-dqm/CAF/certification/Collisions17/13TeV/PromptReco/Cert_294927-303825_13TeV_PromptReco_Collisions17_JSON.txt' 
name = '_DQMBPH_Run2017E'
listOfSamples = ['MuonEG_E']
doSubmit(listOfSamples)

nfiles = -1
filesPerJob = 20
#mask = 'https://cms-service-dqm.web.cern.ch/cms-service-dqm/CAF/certification/Collisions17/13TeV/PromptReco/Cert_294927-303825_13TeV_PromptReco_Collisions17_JSON.txt' 
name = '_DQMBPH_Run2017F'
listOfSamples = ['MuonEG_F']
doSubmit(listOfSamples)


nfiles = -1 
filesPerJob = 20
#mask = '/afs/cern.ch/user/n/ndaci/public/STEAM/Scripts/columns_2016H/columns_1p15e34.txt' #HLTPhysics - Nadir
name = '_TagAndProbeNtuples_Run2017C'
listOfSamples = ['DoubleMuonv1']
doSubmit(listOfSamples)


nfiles = -1 
filesPerJob = 20
#mask = '/afs/cern.ch/user/n/ndaci/public/STEAM/Scripts/columns_2016H/columns_1p25e34.txt' #HLTPhysics - Nadir
name = '_TagAndProbeNtuples_Run2017C'
listOfSamples = ['DoubleMuonv2']
doSubmit(listOfSamples)


nfiles = -1 
filesPerJob = 20
#mask = '/afs/cern.ch/user/n/ndaci/public/STEAM/Scripts/columns_2016H/columns_1p45e34.txt' #HLTPhysics - Nadir
name = '_TagAndProbeNtuples_Run2017C'
listOfSamples = ['DoubleMuonv3']
doSubmit(listOfSamples)

