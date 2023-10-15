# Include the sub-makefile for tool and library installation specific defines from the 00_build_env directory
include ../00_build_env/tool_lib_defs.mk

# Define the source file directories
SRC_DIR = src
BIN_DIR = bin
DATA_DIR = data

# Define the source and object files
RSA_DEMO_SRC = $(SRC_DIR)/rsa_encrypt.c  $(SRC_DIR)/rsa_decrypt.c $(SRC_DIR)/rsa_demo.c $(SRC_DIR)/rsa_helper.c $(SRC_DIR)/applink.c

# Define the output executables
RSA_DEMO_EXE = $(BIN_DIR)/demo.exe

# Define the names of the key files
PRIVATE_KEY_FILE = $(DATA_DIR)/private_key.pem
PUBLIC_KEY_FILE = $(DATA_DIR)/public_key.pem

all: $(BIN_DIR)  rsa_demo

$(BIN_DIR):
	md $(BIN_DIR)

rsa_demo: $(RSA_DEMO_SRC)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(RSA_DEMO_EXE) $(RSA_DEMO_SRC)

demo: rsa_demo
	$(RSA_DEMO_EXE)

# Target to generate RSA keys
keys:
	openssl genpkey -algorithm RSA -out $(PRIVATE_KEY_FILE)
	openssl rsa -pubout -in $(PRIVATE_KEY_FILE) -out $(PUBLIC_KEY_FILE)

clean:
	rmdir /s /q $(BIN_DIR)
