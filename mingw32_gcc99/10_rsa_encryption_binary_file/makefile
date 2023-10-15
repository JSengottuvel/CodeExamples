# Include the sub-makefile for tool and library installation specific defines from the 00_build_env directory
include ../00_build_env/tool_lib_defs.mk

# Define the source file directories
SRC_DIR = src
BIN_DIR = bin
DATA_DIR = data

# Define the source and object files
RSA_ENCRYPT_SRC = $(SRC_DIR)/rsa_encrypt.c $(SRC_DIR)/rsa_helper.c $(SRC_DIR)/applink.c
RSA_DECRYPT_SRC = $(SRC_DIR)/rsa_decrypt.c $(SRC_DIR)/rsa_helper.c $(SRC_DIR)/applink.c

# Define the output executables
RSA_ENCRYPT_EXE = $(BIN_DIR)/encrypt.exe
RSA_DECRYPT_EXE = $(BIN_DIR)/decrypt.exe

# Define the names of the key files
PRIVATE_KEY_FILE = $(DATA_DIR)/private_key.pem
PUBLIC_KEY_FILE = $(DATA_DIR)/public_key.pem

all: $(BIN_DIR)  rsa_encrypt rsa_decrypt

$(BIN_DIR):
	md $(BIN_DIR)

rsa_encrypt: $(RSA_ENCRYPT_SRC)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(RSA_ENCRYPT_EXE) $(RSA_ENCRYPT_SRC)

rsa_decrypt: $(RSA_DECRYPT_SRC)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(RSA_DECRYPT_EXE) $(RSA_DECRYPT_SRC)

encrypt: rsa_encrypt
	$(RSA_ENCRYPT_EXE)

decrypt: rsa_decrypt
	$(RSA_DECRYPT_EXE)

# Target to generate RSA keys
keys:
	openssl genpkey -algorithm RSA -out $(PRIVATE_KEY_FILE)
	openssl rsa -pubout -in $(PRIVATE_KEY_FILE) -out $(PUBLIC_KEY_FILE)

clean:
	rmdir /s /q $(BIN_DIR)
