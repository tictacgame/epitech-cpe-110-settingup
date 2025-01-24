##
## EPITECH PROJECT, 2024
## B-CPE-110-TLS-1-1-settingup
## File description:
## Makefile
##

SRC = $(shell find src -name "*.c")
OBJ = $(SRC:.c=.o)
NAME = setting_up

all: $(NAME)

CFLAGS += -Isrc/include
$(NAME): $(OBJ)
		gcc -o $(NAME) $(OBJ)

debug: CFLAGS += -g3 -o3 -ggdb
debug: fclean all

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
.SILENT: fclean all $(NAME) $(OBJ)