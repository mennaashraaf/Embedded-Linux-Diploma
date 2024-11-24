# Main Directories
GEN_DIR = /home/menna/project/Application/out/gen
LIBS_DIR = /home/menna/project/Application/out/libs

# Modules Source files
XOR_ENCRYPT_SRC = /home/menna/project/modules/xor_cipher/src/xor_encrypt.c
XOR_DECRYPT_SRC = /home/menna/project/modules/xor_cipher/src/xor_decrypt.c

# Modules Object files
XOR_ENCRYPT_OBJ = $(GEN_DIR)/xor_encrypt.o
XOR_DECRYPT_OBJ = $(GEN_DIR)/xor_decrypt.o

# Modules Library files
XOR_CIPHER_LIB = $(LIBS_DIR)/libxor.so

# flags
CC = gcc
CFLAGS = -Wall -I/home/menna/project/modules/xor_cipher/inc
LDFLAGS = -shared

all: $(XOR_CIPHER_LIB)

#- a rule to compile the 2 source files and generate 2 object files

$(XOR_ENCRYPT_OBJ): $(XOR_ENCRYPT_SRC)
	$(CC) $(CFLAGS) -fPIC -c $(XOR_ENCRYPT_SRC) -o $(XOR_ENCRYPT_OBJ)
	
$(XOR_DECRYPT_OBJ): $(XOR_DECRYPT_SRC)
	$(CC) $(CFLAGS) -fPIC -c $(XOR_DECRYPT_SRC) -o $(XOR_DECRYPT_OBJ)

#a rule to archive these 2 object files into a library file
	
$(XOR_CIPHER_LIB): $(XOR_ENCRYPT_OBJ) $(XOR_DECRYPT_OBJ)
	$(CC) $(LDFLAGS) -o $(XOR_CIPHER_LIB) $(XOR_ENCRYPT_OBJ) $(XOR_DECRYPT_OBJ)
	
clean:
	rm -f $(XOR_ENCRYPT_OBJ) $(XOR_DECRYPT_OBJ) $(XOR_CIPHER_LIB)

