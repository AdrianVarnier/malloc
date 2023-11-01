ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so

INC= inc

CC= clang
# CFLAGS= -Wall -Wextra -Werror
CFLAGS= -fsanitize=address

AR= ar
ARFLAGS= rcs

SRC=	src/lib/malloc.c \
		src/utils/global.c \
		src/utils/alloc_heap.c \
		src/utils/alloc_block.c \

OBJ= $(SRC:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	$(CC) $(CFLAGS) -I $(INC) main.c $(NAME)

.PHONY: clean
clean:
	rm -rf $(OBJ)

.PHONY: fclean
fclean: clean
	rm -rf $(NAME)
	rm -rf a.out

.PHONY: re
re: fclean $(NAME)

.PHONY: re_bonus
re_bonus: fclean bonus