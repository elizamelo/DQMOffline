# Auto generated configuration file
# using: 
# Revision: 1.19 
# Source: /local/reps/CMSSW/CMSSW/Configuration/Applications/python/ConfigBuilder.py,v 
# with command line options: step4 --data --filetype DQM --conditions auto:run2_data_relval -s HARVESTING:@standardDQM+@miniAODDQM --scenario pp -n 100 --filein file:step3_inDQM.root --fileout file:step4.root
import FWCore.ParameterSet.Config as cms
import FWCore.Utilities.FileUtils as FileUtils

process = cms.Process('HARVESTING')

# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.MagneticField_AutoFromDBCurrent_cff')
process.load('Configuration.StandardSequences.DQMSaverAtJobEnd_cff')
#process.load('Configuration.StandardSequences.DQMSaverAtRunEnd_cff')
process.load('Configuration.StandardSequences.Harvesting_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

process.dqmSaver.saveByRun = cms.untracked.int32(-1) ## multirun harvesting
#process.dqmSaver.forceRunNumber = 999999

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

# Input source
# Input source
#filelist = open('/afs/cern.ch/work/a/aboletti/public/BPH_DQM/CMSSW_930pre3_DQMtest/src/DQMOffline/Trigger/test/hltDQM_DMLM-Dv1_19Sep.list', 'r').readlines()
#filelist = open('/afs/cern.ch/work/e/eliza/private/ZtoJpsiGamma/DQM/TEST/CMSSW_940pre2_DQMtest/src/DQMOffline/Trigger/test/listTotal.list', 'r').readlines() #
filelist = open('/afs/cern.ch/work/e/eliza/public/DQM/CMSSW_1000pre1_DQMtest/src/DQMOffline/Trigger/test/listcrab_MuonEG_F_v2.list', 'r').readlines()
process.source = cms.Source("DQMRootSource",
    fileNames = cms.untracked.vstring(
#       'file:DQM_onlyBPHHLT.root'
       #'file:DQM_onlyBPHHLT_CharmAle.root'
#       'file:DQM_onlyBPHHLT_MuonEG_ph1_1_ph2_2_tnp_true.root'
#         'file:DQM_onlyBPHHLT_MuonEG.root'
#        'file:DQM_onlyBPHHLT_MuonEG.root'
#         'file:DQM_onlyBPHHLT.root'     
       filelist
#         'file:DQM_onlyEGMHLT.root'
#        'file:DQM_onlyEXOHLT_1.root',
#        'file:DQM_onlyEXOHLT_2.root'
    ),
    # skipBadFiles = cms.untracked.bool(True)
)
process.options = cms.untracked.PSet(
    Rethrow = cms.untracked.vstring('ProductNotFound'),
    fileMode = cms.untracked.string('FULLMERGE')
)

# Production Info
process.configurationMetadata = cms.untracked.PSet(
    annotation = cms.untracked.string('step4 nevts:100'),
    name = cms.untracked.string('Applications'),
    version = cms.untracked.string('$Revision: 1.19 $')
)

# Output definition

# Additional output definition

# Other statements
from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, 'auto:run2_data_relval', '')

# Path and EndPath definitions
process.harvesting = cms.Path(process.hltOfflineDQMClient)
process.dqmsave_step = cms.Path(process.DQMSaver)

# Schedule definition
process.schedule = cms.Schedule(process.harvesting,process.dqmsave_step)


# Customisation from command line

# Add early deletion of temporary data products to reduce peak memory need
from Configuration.StandardSequences.earlyDeleteSettings_cff import customiseEarlyDelete
process = customiseEarlyDelete(process)
# End adding early deletion
