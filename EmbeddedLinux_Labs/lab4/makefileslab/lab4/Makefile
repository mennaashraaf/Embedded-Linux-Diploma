INCLUDE_DIR = ./inc
SOURCE_DIR = ./src

CC = gcc
AR = ar
CFLAGS = -I$(INCLUDE_DIR) -lm
OBJ =  main.o
LIB_OBJ = simple_op.o complex_op.o
LIB = libmath_op.a

all: $(OBJ) $(LIB_OBJ)
	$(AR) -cr $(LIB) $(LIB_OBJ)
	$(CC) $(OBJ) -L. $(LIB) $(CFLAGS) -o output
	
simple_op.o: $(SOURCE_DIR)/simple_op.c
	$(CC) -c $(SOURCE_DIR)/simple_op.c $(CFLAGS)

complex_op.o: $(SOURCE_DIR)/complex_op.c
	$(CC) -c $(SOURCE_DIR)/complex_op.c $(CFLAGS)

main.o: $(SOURCE_DIR)/main.c
	$(CC) -c $(SOURCE_DIR)/main.c $(CFLAGS)

clean:
	rm -f output *.o *.a
	
