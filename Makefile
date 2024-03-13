# Relative paths (adjusted based on provided information)
PROJECT_ROOT := /Users/jamesshields/Documents/repos/characterCreator
SOURCE_DIR := $(PROJECT_ROOT)/characterCeator

# Build directory (based on information provided)
BUILD_DIR := $(PROJECT_ROOT)/characterCeator/build-

# Compiler and flags
CC := g++
CFLAGS := -O0 -gdwarf-2 -std=c++20 -Wall -fstandalone-debug $(Preprocessors)

# Output directories (assuming separate folders for each architecture)
OutputDirectory_x86_64 := $(BUILD_DIR)/x86_64
OutputDirectory_arm64 := $(BUILD_DIR)/arm64

# Object files for each architecture (based on directory listing)
OBJECTS_x86_64 := $(OutputDirectory_x86_64)/Character.o $(OutputDirectory_x86_64)/UIFunctions.o $(OutputDirectory_x86_64)/generalFunctions.o $(OutputDirectory_x86_64)/abilityFunctions.o $(OutputDirectory_x86_64)/ageAndLevelFunctions.o $(OutputDirectory_x86_64)/fileFunctions.o $(OutputDirectory_x86_64)/classAndRaceFunctions.o $(OutputDirectory_x86_64)/nameFunctions.o $(OutputDirectory_x86_64)/main.o

OBJECTS_arm64 := $(OutputDirectory_arm64)/Character.o $(OutputDirectory_arm64)/UIFunctions.o $(OutputDirectory_arm64)/generalFunctions.o $(OutputDirectory_arm64)/abilityFunctions.o $(OutputDirectory_arm64)/ageAndLevelFunctions.o $(OutputDirectory_arm64)/fileFunctions.o $(OutputDirectory_arm64)/classAndRaceFunctions.o $(OutputDirectory_arm64)/nameFunctions.o $(OutputDirectory_arm64)/main.o

# Main target
characterCeator: MakeIntermediateDirs $(OBJECTS_x86_64) $(OBJECTS_arm64) 
  # Explicit build rule for x86_64 executable (linking step)
  characterCeator_x86_64: $(OBJECTS_x86_64) 
    $(CC) $(CFLAGS) -arch x86_64 -o $(BUILD_DIR)/x86_64/characterCeator $(OBJECTS_x86_64) :
  cp $(BUILD_DIR)/x86_64/characterCeator ./characterCeator_x86_64 :
  lipo -create -output ./characterCeator_arm64 $(OBJECTS_arm64) :

MakeIntermediateDirs:
	mkdir -p $(OutputDirectory_x86_64)
	mkdir -p $(OutputDirectory_arm64)

# Object file rules (assuming architecture specific folders)
$(OutputDirectory_x86_64)/%.o: $(SOURCE_DIR)/%.cpp
	@echo "Compiling $(@F) for x86_64..."
	$(CC) $(CFLAGS) -arch x86_64 -c -o $@ $<

$(OutputDirectory_arm64)/%.o: $(SOURCE_DIR)/%.cpp
	@echo "Compiling $(@F) for arm64..."
	$(CC) $(CFLAGS) -arch arm64 -c -o $@ $<

# Clean rule
clean:
	rm -rf $(BUILD_DIR)

