# Relative paths
PROJECT_ROOT := .
SOURCE_DIR := $(PROJECT_ROOT)/characterCeator
BUILD_DIR := $(PROJECT_ROOT)/characterCeator/build-$(CONFIG)/bin

# Compiler and flags
CC := g++
CFLAGS := -O0 -gdwarf-2 -std=gnu++98 -std=c++20 -std=gnu++20 -std=c++17 -std=gnu++17 -std=c++14 -std=gnu++14 -std=c++11 -std=gnu++11 -Wall -fstandalone-debug $(Preprocessors)
CXXFLAGS := $(CFLAGS)

# Output directory
OutputDirectory := $(BUILD_DIR)

# Object files
OBJECTS := $(BUILD_DIR)/main.o $(BUILD_DIR)/generalFunctions.o $(BUILD_DIR)/UIFunctions.o $(BUILD_DIR)/nameFunctions.o $(BUILD_DIR)/pugixml.o $(BUILD_DIR)/abilityFunctions.o $(BUILD_DIR)/classAndRaceFunctions.o $(BUILD_DIR)/ageAndLevelFunctions.o $(BUILD_DIR)/fileFunctions.o $(BUILD_DIR)/Character.o

# Main target
characterCeator: MakeIntermediateDirs $(OBJECTS)
	$(CC) -o $(OutputDirectory)/$@ $(OBJECTS) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	mkdir -p $(BUILD_DIR)

# Object file rules
$(BUILD_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean rule
clean:
	rm -rf $(BUILD_DIR)
