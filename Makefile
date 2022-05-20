CC				= gcc
LD				= ld

C_FLAGS 		= -W -Wall -Wextra -ffreestanding -std=c99
LD_FLAGS 		=

C_SRC			= src/main.c
OBJ  			= $(C_SRC:.c=.o)

BIN  			= jack
BIN_i386  		= jack_i386

all: build

build: clean $(OBJ)
	$(CC) -o $(BIN) $(OBJ)

build_i386: CC = i386-elf-gcc
build_i386: LD = i386-elf-ld
build_i386: LD_FLAGS = -nostdlib -m elf_i386
build_i386: clean $(OBJ)	
	$(LD) $(LD_FLAGS) -o $(BIN_i386) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(BIN)
	$(RM) $(BIN_i386)

re: fclean all

%.o: %.c
	$(CC) -c $(C_FLAGS) -o $@ $<

.PHONY: all build build_i386 clean fclean re
