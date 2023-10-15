# Include the sub-makefile for tool and library installation specific defines
include ../00_build_env/tool_lib_defs.mk

# Define the source file directories
SRC_DIR = src
BIN_DIR = bin
DATA_DIR = data

# Define the source and object files
RANDOM_DEMO_SRC = $(SRC_DIR)/random_demo.c

# Define the output executable
RANDOM_DEMO_EXE = $(BIN_DIR)/random_demo.exe

all: $(BIN_DIR) random_demo

$(BIN_DIR):
	$(MKDIR) $(BIN_DIR)

random_demo: $(RANDOM_DEMO_SRC)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(RANDOM_DEMO_EXE) $(RANDOM_DEMO_SRC)

run: random_demo
	$(RANDOM_DEMO_EXE)

clean:
	$(RMDIR) /s /q $(BIN_DIR)
