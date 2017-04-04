##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=AtlasGenerator
ConfigurationName      :=Debug
WorkspacePath          :=/home/greg/AtlasGenerator2
ProjectPath            :=/home/greg/AtlasGenerator2
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=
Date                   :=04/04/17
CodeLitePath           :=/home/greg/.codelite
LinkerName             :=/usr/bin/clang++
SharedObjectLinkerName :=/usr/bin/clang++ -shared -fPIC
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
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="AtlasGenerator.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)/usr/include/qt $(IncludeSwitch)/usr/include/qt/QtCore $(IncludeSwitch)/usr/include/qt/QtGui/ $(IncludeSwitch)/usr/include/qt/QtWidgets/ 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)Qt5Core $(LibrarySwitch)Qt5Gui 
ArLibs                 :=  "Qt5Core" "Qt5Gui" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)/usr/lib/qt 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/llvm-ar rcu
CXX      := /usr/bin/clang++
CC       := /usr/bin/clang
CXXFLAGS :=  -g -W -std=c++11 -fPIC $(Preprocessors)
CFLAGS   :=  -g -W $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/llvm-as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/atlasgenerator.cpp$(ObjectSuffix) $(IntermediateDirectory)/myimage.cpp$(ObjectSuffix) $(IntermediateDirectory)/atlas.cpp$(ObjectSuffix) $(IntermediateDirectory)/mylargeimage.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/greg/AtlasGenerator2/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/atlasgenerator.cpp$(ObjectSuffix): atlasgenerator.cpp $(IntermediateDirectory)/atlasgenerator.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/greg/AtlasGenerator2/atlasgenerator.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/atlasgenerator.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/atlasgenerator.cpp$(DependSuffix): atlasgenerator.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/atlasgenerator.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/atlasgenerator.cpp$(DependSuffix) -MM atlasgenerator.cpp

$(IntermediateDirectory)/atlasgenerator.cpp$(PreprocessSuffix): atlasgenerator.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/atlasgenerator.cpp$(PreprocessSuffix) atlasgenerator.cpp

$(IntermediateDirectory)/myimage.cpp$(ObjectSuffix): myimage.cpp $(IntermediateDirectory)/myimage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/greg/AtlasGenerator2/myimage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/myimage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/myimage.cpp$(DependSuffix): myimage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/myimage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/myimage.cpp$(DependSuffix) -MM myimage.cpp

$(IntermediateDirectory)/myimage.cpp$(PreprocessSuffix): myimage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/myimage.cpp$(PreprocessSuffix) myimage.cpp

$(IntermediateDirectory)/atlas.cpp$(ObjectSuffix): atlas.cpp $(IntermediateDirectory)/atlas.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/greg/AtlasGenerator2/atlas.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/atlas.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/atlas.cpp$(DependSuffix): atlas.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/atlas.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/atlas.cpp$(DependSuffix) -MM atlas.cpp

$(IntermediateDirectory)/atlas.cpp$(PreprocessSuffix): atlas.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/atlas.cpp$(PreprocessSuffix) atlas.cpp

$(IntermediateDirectory)/mylargeimage.cpp$(ObjectSuffix): mylargeimage.cpp $(IntermediateDirectory)/mylargeimage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/greg/AtlasGenerator2/mylargeimage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mylargeimage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mylargeimage.cpp$(DependSuffix): mylargeimage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mylargeimage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/mylargeimage.cpp$(DependSuffix) -MM mylargeimage.cpp

$(IntermediateDirectory)/mylargeimage.cpp$(PreprocessSuffix): mylargeimage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mylargeimage.cpp$(PreprocessSuffix) mylargeimage.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


