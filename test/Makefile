ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

LIB = libft_malloc_$(HOSTTYPE).so

NAME = test

INC= inc

CC= clang
CFLAGS= -Wall -Wextra -Werror

SRC=	malloc.c \
		free.c \
		realloc.c \
		utils.c \
		test.c \

OBJ= $(SRC:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -I $(INC) $(OBJ) $(LIB) -o $(NAME)

.PHONY: clean
clean:
	rm -rf $(OBJ)

.PHONY: fclean
fclean: clean
	rm -rf $(NAME)

.PHONY: re
re: fclean $(NAME)

.PHONY: re_bonus
re_bonus: fclean bonus
