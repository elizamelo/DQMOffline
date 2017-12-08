# Auto generated configuration file
# using: 
# Revision: 1.19 
# Source: /local/reps/CMSSW/CMSSW/Configuration/Applications/python/ConfigBuilder.py,v 
# with command line options: hltBPHdqm -s DQM:bphMonitorHLT --conditions=92X_dataRun2_Prompt_v8 --geometry DB:Extended --eventcontent DQM --datatier DQMIO --data --era Run2_2017 --filetype=EDM --filein file:/afs/cern.ch/work/a/aboletti/public/BPH_DQM/CMSSW_930p1_test/src/DQMOffline/Trigger/test/Run2017C-Charmonium-AOD-PRv1.root -n -1 --fileout DQM_onlyBPHHLT.root --no_exec
import FWCore.ParameterSet.Config as cms

from Configuration.StandardSequences.Eras import eras

process = cms.Process('DQM',eras.Run2_2017)

# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.MagneticField_AutoFromDBCurrent_cff')
process.load('DQMOffline.Configuration.DQMOffline_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

# Input source
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
    'file:../../../../../CMSSW_940pre2_DQMtest/src/DQMOffline/Trigger/test/uerj/00B4AD9F-6CB2-E711-8992-02163E013458.root'),
    #'file:/afs/cern.ch/work/a/aboletti/public/BPH_DQM/CMSSW_930p1_test/src/DQMOffline/Trigger/test/Run2017C-Charmonium-AOD-PRv1.root'),
#    'file:/afs/cern.ch/work/e/eliza/public/DQM/CMSSW_940pre2_DQMtest/src/DQMOffline/Trigger/test/uerj/00B4AD9F-6CB2-E711-8992-02163E013458.root'),
    secondaryFileNames = cms.untracked.vstring()
)

process.options = cms.untracked.PSet(

)
process.options.numberOfThreads = cms.untracked.uint32(4)
# Production Info
process.configurationMetadata = cms.untracked.PSet(
    annotation = cms.untracked.string('hltBPHdqm nevts:-1'),
    name = cms.untracked.string('Applications'),
    version = cms.untracked.string('$Revision: 1.19 $')
)

# Output definition

process.DQMoutput = cms.OutputModule("DQMRootOutputModule",
    dataset = cms.untracked.PSet(
        dataTier = cms.untracked.string('DQMIO'),
        filterName = cms.untracked.string('')
    ),
    fileName = cms.untracked.string('DQM_onlyBPHHLT.root'),
    outputCommands = process.DQMEventContent.outputCommands,
    splitLevel = cms.untracked.int32(0)
)

# Additional output definition

# Other statements
from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, '92X_dataRun2_Prompt_v8', '')

# Path and EndPath definitions
process.dqmoffline_step = cms.EndPath(process.bphMonitorHLT)
process.dqmofflineOnPAT_step = cms.EndPath(process.bphMonitorHLT)
process.DQMoutput_step = cms.EndPath(process.DQMoutput)

# Schedule definition
process.schedule = cms.Schedule(process.dqmoffline_step,process.dqmofflineOnPAT_step,process.DQMoutput_step)
from PhysicsTools.PatAlgos.tools.helpers import associatePatAlgosToolsTask
associatePatAlgosToolsTask(process)


# Customisation from command line

# Add early deletion of temporary data products to reduce peak memory need
from Configuration.StandardSequences.earlyDeleteSettings_cff import customiseEarlyDelete
process = customiseEarlyDelete(process)
# End adding early deletion
