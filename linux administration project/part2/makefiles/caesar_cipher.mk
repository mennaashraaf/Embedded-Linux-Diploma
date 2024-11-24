# Main Directories
GEN_DIR = /home/menna/project/Application/out/gen
LIBS_DIR = /home/menna/project/Application/out/libs

# Modules Source files
CAESAR_ENCRYPT_SRC = /home/menna/project/modules/caesar_cipher/src/caesar_encrypt.c
CAESAR_DECRYPT_SRC = /home/menna/project/modules/caesar_cipher/src/caesar_decrypt.c

# Modules Object files
CAESAR_ENCRYPT_OBJ = $(GEN_DIR)/caesar_encrypt.o
CAESAR_DECRYPT_OBJ = $(GEN_DIR)/caesar_decrypt.o

# Modules Library files
CAESAR_CIPHER_LIB = $(LIBS_DIR)/libcaesar.a

# flags
CC = gcc
CFLAGS = -Wall -I/home/menna/project/modules/caesar_cipher/inc

all: $(CAESAR_CIPHER_LIB)

#- a rule to compile the 2 source files and generate 2 object files

$(CAESAR_ENCRYPT_OBJ): $(CAESAR_ENCRYPT_SRC)
	$(CC) $(CFLAGS) -c $(CAESAR_ENCRYPT_SRC) -o $(CAESAR_ENCRYPT_OBJ)
	
$(CAESAR_DECRYPT_OBJ): $(CAESAR_DECRYPT_SRC)
	$(CC) $(CFLAGS) -c $(CAESAR_DECRYPT_SRC) -o $(CAESAR_DECRYPT_OBJ)

#a rule to archive these 2 object files into a library file
	
$(CAESAR_CIPHER_LIB): $(CAESAR_ENCRYPT_OBJ) $(CAESAR_DECRYPT_OBJ)
	ar rcs $(CAESAR_CIPHER_LIB) $(CAESAR_ENCRYPT_OBJ) $(CAESAR_DECRYPT_OBJ)
	
clean:
	rm -f $(CAESAR_ENCRYPT_OBJ) $(CAESAR_DECRYPT_OBJ) $(CAESAR_CIPHER_LIB)

