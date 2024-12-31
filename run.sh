#!/bin/bash

# Define color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Create a directory for executables
BIN_DIR="./bin"

# Check if the C++ file path is provided
if [ -z "$1" ]; then
  echo -e "${RED}Usage: ./run.sh <path/to/file.cpp> [-r]${NC}"
  echo -e "${YELLOW}  -r: Run without compiling${NC}"
  exit 1
fi

# Ensure the bin directory exists
mkdir -p "$BIN_DIR"

# Extract the filename without extension
filename=$(basename -- "$1")
filename_no_ext="${filename%.*}"

# Set the path for the executable in the bin directory
executable="$BIN_DIR/$filename_no_ext"

# Option to run without compiling
if [ "$2" == "-r" ]; then
  if [ ! -f "$executable" ]; then
    echo -e "${RED}Error: Executable not found in $BIN_DIR. Compile it first.${NC}"
    exit 1
  fi
  echo -e "${BLUE}Running existing executable from $BIN_DIR...${NC}"
else
  # Compile the C++ file
  echo -e "${YELLOW}Compiling $filename...${NC}"
  g++ "$1" -o "$executable"
  compile_status=$?

  # Check if compilation was successful
  if [ $compile_status -ne 0 ]; then
    echo -e "${RED}Compilation failed${NC}"
    exit 1
  fi

  echo -e "${GREEN}Compilation successful.${NC} Executable created: ${BLUE}$executable${NC}"
fi

# Run the executable
echo -e "${GREEN}Running the executable from $BIN_DIR...${NC}"
"$executable"
