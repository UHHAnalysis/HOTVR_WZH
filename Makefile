# Package information
LIBRARY = MyAnalysis
OBJDIR  = obj
DEPDIR  = $(OBJDIR)/dep
SRCDIR  = src
INCDIR  = include

INCLUDES += -I$(SFRAME_DIR)/NtupleWriter/include
INCLUDES += -I$(SFRAME_DIR)/NtupleWriter
INCLUDES += -I$(SFRAME_DIR)/SFrameTools/include
INCLUDES += -I$(SFRAME_DIR)/SFrameTools
INCLUDES += -I$(SFRAME_DIR)/SFrameTools/JetMETObjects/interface
INCLUDES += -I$(SFRAME_DIR)/SFrameAnalysis/include
INCLUDES += -I$(SFRAME_DIR)/SFrameAnalysis/
INCLUDES += -I$(SFRAME_DIR)/core
INCLUDES += -I$(SFRAME_DIR)/core/include

# configure FastJet
INCLUDES += -I$(FASTJETDIR)/include
INCLUDES += -I$(FASTJETDIR)/../include
INCLUDES += -I$(FASTJETDIR)/include/contribs/RecursiveTools


USERLDFLAGS += $(shell root-config --libs) -lMinuit 
USERLDFLAGS +=  /nfs/dust/cms/user/trappeu/CMSSW_7_4_15_patch1/src/UHH2/common/include/3.1.3-install/lib/libRecursiveTools.a
USERLDFLAGS +=  /nfs/dust/cms/user/trappeu/CMSSW_7_4_15_patch1/src/UHH2/common/include/3.1.3-install/lib/libJetsWithoutJets.a
USERLDFLAGS +=  /nfs/dust/cms/user/trappeu/CMSSW_7_4_15_patch1/src/UHH2/common/include/3.1.3-install/lib/libEnergyCorrelator.a
USERLDFLAGS +=  /nfs/dust/cms/user/trappeu/CMSSW_7_4_15_patch1/src/UHH2/common/include/3.1.3-install/lib/libVariableR.a	
USERLDFLAGS +=  /nfs/dust/cms/user/trappeu/CMSSW_7_4_15_patch1/src/UHH2/common/include/3.1.3-install/lib/libClusteringVetoPlugin.a
USERLDFLAGS +=  /nfs/dust/cms/user/trappeu/CMSSW_7_4_15_patch1/src/UHH2/common/include/3.1.3-install/lib/libHHTopTagger.a
USERLDFLAGS +=  /nfs/dust/cms/user/trappeu/CMSSW_7_4_15_patch1/src/UHH2/common/include/3.1.3-install/lib/libfastjetplugins.a


#INCLUDES += -I$(LHAPDFDIR)/include
INCLUDES += -I/afs/cern.ch/sw/lcg/external/MCGenerators/lhapdf/5.8.8/x86_64-slc5-gcc46-opt/include


# Include the generic compilation rules
include $(SFRAME_DIR)/Makefile.common
