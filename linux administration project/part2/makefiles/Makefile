# Main Directories
ROOT_DIR = $(shell pwd)
APP_DIR = $(ROOT_DIR)

# Application Directories
OUT_DIR = $(APP_DIR)/out
GEN_DIR = $(OUT_DIR)/gen
LIBS_DIR = $(OUT_DIR)/libs
APP_BIN = $(APP_DIR)/output

# Modules Directories
CAESAR_CIPHER_DIR = $(ROOT_DIR)/../modules/caesar_cipher
XOR_CIPHER_DIR = $(ROOT_DIR)/../modules/xor_cipher

# Modules Source files
CAESAR_CIPHER_SRC = $(CAESAR_CIPHER_DIR)/src/caesar_encrypt.c $(CAESAR_CIPHER_DIR)/src/caesar_decrypt.c
XOR_CIPHER_SRC = $(XOR_CIPHER_DIR)/src/xor_encrypt.c $(XOR_CIPHER_DIR)/src/xor_decrypt.c

# Modules Object files
#CAESAR_CIPHER_OBJ = $(GEN_DIR)/caesar.o
#XOR_CIPHER_OBJ = $(GEN_DIR)/xor.o

# Modules Library files
CAESAR_CIPHER_LIB = $(LIBS_DIR)/libcaesar.a
XOR_CIPHER_LIB = $(LIBS_DIR)/libxor.so

# Application Source files
APP_SRC = $(APP_DIR)/app.c

# Application Object files
APP_OBJ = $(GEN_DIR)/app.o


# flags
CC = gcc
CFLAGS = -Wall -I$(CAESAR_CIPHER_DIR)/inc -I$(XOR_CIPHER_DIR)/inc
LDFLAGS = -L$(LIBS_DIR) -lcaesar -lxor

#creating out , gen , lib directories and linking all 2 libraries and the object file from the app to produce executable 

all: create_directories $(APP_BIN)

create_directories:
	mkdir -p $(GEN_DIR) $(LIBS_DIR)

# 1) Compile and archive the caesar_cipher static library:

$(CAESAR_CIPHER_LIB):
	$(MAKE) -f $(CAESAR_CIPHER_DIR)/caesar_cipher.mk
	
# 2) Compile and generate the xor_cipher dynamic library

$(XOR_CIPHER_LIB):
	$(MAKE) -f $(XOR_CIPHER_DIR)/xor_cipher.mk

# 3) Compile the app source file to generate the app object file (one rule)

$(APP_OBJ): $(APP_SRC)
	$(CC) $(CFLAGS) -c $(APP_SRC) -o $(APP_OBJ)

# 4) Link them all together (one rule)

$(APP_BIN): $(APP_OBJ) $(CAESAR_CIPHER_LIB) $(XOR_CIPHER_LIB)
	$(CC) $(APP_OBJ) $(LDFLAGS) -o $(APP_BIN)

# 5) one rule to clean the project
clean:
	rm -rf $(OUT_DIR)
	$(MAKE) -f $(CAESAR_CIPHER_DIR)/caesar_cipher.mk clean
	$(MAKE) -f $(XOR_CIPHER_DIR)/xor_cipher.mk clean
	

