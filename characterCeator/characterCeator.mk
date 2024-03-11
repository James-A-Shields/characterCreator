##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=characterCeator
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=~/Documents/repos/characterCreator
ProjectPath            :=~/Documents/repos/characterCreator/characterCeator
IntermediateDirectory  :=../build-$(WorkspaceConfiguration)/characterCeator
OutDir                 :=$(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=James Shields
Date                   :=02/03/2024
CodeLitePath           :=~/.codelite
MakeDirCommand         :=mkdir -p
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -dynamiclib -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=~/Documents/repos/characterCreator/build-$(WorkspaceConfiguration)/bin
OutputFile             :=../build-$(WorkspaceConfiguration)/bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -O0 -gdwarf-2 -std=gnu++98 -std=c++20 -std=gnu++20 -std=c++17 -std=gnu++17 -std=c++14 -std=gnu++14 -std=c++11 -std=gnu++11 -Wall -fstandalone-debug $(Preprocessors)
CFLAGS   :=  -O0 -gdwarf-2 -std=gnu++98 -std=c++20 -std=gnu++20 -std=c++17 -std=gnu++17 -std=c++14 -std=gnu++14 -std=c++11 -std=gnu++11 -Wall -fstandalone-debug $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/Applications/codelite.app/Contents/SharedSupport/
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/generalFunctions.cpp$(ObjectSuffix) $(IntermediateDirectory)/UIFunctions.cpp$(ObjectSuffix) $(IntermediateDirectory)/nameFunctions.cpp$(ObjectSuffix) $(IntermediateDirectory)/pugixml.cpp$(ObjectSuffix) $(IntermediateDirectory)/abilityFunctions.cpp$(ObjectSuffix) $(IntermediateDirectory)/classAndRaceFunctions.cpp$(ObjectSuffix) $(IntermediateDirectory)/ageAndLevelFunctions.cpp$(ObjectSuffix) $(IntermediateDirectory)/fileFunctions.cpp$(ObjectSuffix) $(IntermediateDirectory)/Character.cpp$(ObjectSuffix) \
	



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) "$(IntermediateDirectory)"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "$(IntermediateDirectory)"
	@$(MakeDirCommand) "$(OutputDirectory)"

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "$(IntermediateDirectory)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "~/Documents/repos/characterCreator/characterCeator/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/generalFunctions.cpp$(ObjectSuffix): generalFunctions.cpp $(IntermediateDirectory)/generalFunctions.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "~/Documents/repos/characterCreator/characterCeator/generalFunctions.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/generalFunctions.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/generalFunctions.cpp$(DependSuffix): generalFunctions.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/generalFunctions.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/generalFunctions.cpp$(DependSuffix) -MM generalFunctions.cpp

$(IntermediateDirectory)/generalFunctions.cpp$(PreprocessSuffix): generalFunctions.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/generalFunctions.cpp$(PreprocessSuffix) generalFunctions.cpp

$(IntermediateDirectory)/UIFunctions.cpp$(ObjectSuffix): UIFunctions.cpp $(IntermediateDirectory)/UIFunctions.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "~/Documents/repos/characterCreator/characterCeator/UIFunctions.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/UIFunctions.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/UIFunctions.cpp$(DependSuffix): UIFunctions.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/UIFunctions.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/UIFunctions.cpp$(DependSuffix) -MM UIFunctions.cpp

$(IntermediateDirectory)/UIFunctions.cpp$(PreprocessSuffix): UIFunctions.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/UIFunctions.cpp$(PreprocessSuffix) UIFunctions.cpp

$(IntermediateDirectory)/nameFunctions.cpp$(ObjectSuffix): nameFunctions.cpp $(IntermediateDirectory)/nameFunctions.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "~/Documents/repos/characterCreator/characterCeator/nameFunctions.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/nameFunctions.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/nameFunctions.cpp$(DependSuffix): nameFunctions.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/nameFunctions.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/nameFunctions.cpp$(DependSuffix) -MM nameFunctions.cpp

$(IntermediateDirectory)/nameFunctions.cpp$(PreprocessSuffix): nameFunctions.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/nameFunctions.cpp$(PreprocessSuffix) nameFunctions.cpp

$(IntermediateDirectory)/pugixml.cpp$(ObjectSuffix): pugixml.cpp $(IntermediateDirectory)/pugixml.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "~/Documents/repos/characterCreator/characterCeator/pugixml.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/pugixml.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/pugixml.cpp$(DependSuffix): pugixml.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/pugixml.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/pugixml.cpp$(DependSuffix) -MM pugixml.cpp

$(IntermediateDirectory)/pugixml.cpp$(PreprocessSuffix): pugixml.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/pugixml.cpp$(PreprocessSuffix) pugixml.cpp

$(IntermediateDirectory)/abilityFunctions.cpp$(ObjectSuffix): abilityFunctions.cpp $(IntermediateDirectory)/abilityFunctions.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "~/Documents/repos/characterCreator/characterCeator/abilityFunctions.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/abilityFunctions.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/abilityFunctions.cpp$(DependSuffix): abilityFunctions.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/abilityFunctions.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/abilityFunctions.cpp$(DependSuffix) -MM abilityFunctions.cpp

$(IntermediateDirectory)/abilityFunctions.cpp$(PreprocessSuffix): abilityFunctions.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/abilityFunctions.cpp$(PreprocessSuffix) abilityFunctions.cpp

$(IntermediateDirectory)/classAndRaceFunctions.cpp$(ObjectSuffix): classAndRaceFunctions.cpp $(IntermediateDirectory)/classAndRaceFunctions.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "~/Documents/repos/characterCreator/characterCeator/classAndRaceFunctions.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/classAndRaceFunctions.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/classAndRaceFunctions.cpp$(DependSuffix): classAndRaceFunctions.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/classAndRaceFunctions.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/classAndRaceFunctions.cpp$(DependSuffix) -MM classAndRaceFunctions.cpp

$(IntermediateDirectory)/classAndRaceFunctions.cpp$(PreprocessSuffix): classAndRaceFunctions.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/classAndRaceFunctions.cpp$(PreprocessSuffix) classAndRaceFunctions.cpp

$(IntermediateDirectory)/ageAndLevelFunctions.cpp$(ObjectSuffix): ageAndLevelFunctions.cpp $(IntermediateDirectory)/ageAndLevelFunctions.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "~/Documents/repos/characterCreator/characterCeator/ageAndLevelFunctions.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ageAndLevelFunctions.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ageAndLevelFunctions.cpp$(DependSuffix): ageAndLevelFunctions.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ageAndLevelFunctions.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ageAndLevelFunctions.cpp$(DependSuffix) -MM ageAndLevelFunctions.cpp

$(IntermediateDirectory)/ageAndLevelFunctions.cpp$(PreprocessSuffix): ageAndLevelFunctions.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ageAndLevelFunctions.cpp$(PreprocessSuffix) ageAndLevelFunctions.cpp

$(IntermediateDirectory)/fileFunctions.cpp$(ObjectSuffix): fileFunctions.cpp $(IntermediateDirectory)/fileFunctions.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "~/Documents/repos/characterCreator/characterCeator/fileFunctions.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/fileFunctions.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/fileFunctions.cpp$(DependSuffix): fileFunctions.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/fileFunctions.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/fileFunctions.cpp$(DependSuffix) -MM fileFunctions.cpp

$(IntermediateDirectory)/fileFunctions.cpp$(PreprocessSuffix): fileFunctions.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/fileFunctions.cpp$(PreprocessSuffix) fileFunctions.cpp

$(IntermediateDirectory)/Character.cpp$(ObjectSuffix): Character.cpp $(IntermediateDirectory)/Character.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "~/Documents/repos/characterCreator/characterCeator/Character.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Character.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Character.cpp$(DependSuffix): Character.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Character.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Character.cpp$(DependSuffix) -MM Character.cpp

$(IntermediateDirectory)/Character.cpp$(PreprocessSuffix): Character.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Character.cpp$(PreprocessSuffix) Character.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


