ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so
LINK = libft_malloc.so

INC= inc

CC= gcc
CFLAGS= -Wall -Wextra -Werror -fPIC
LFLAGS= -shared

SRC=	src/lib/malloc.c \
		src/lib/free.c \
		src/lib/realloc.c \
		src/lib/show_alloc_mem.c \
		src/utils/alloc.c \
		src/utils/dealloc.c \
		src/utils/get.c \
		src/utils/global.c \
		src/utils/init.c \
		src/utils/search.c \
		src/utils/resize.c \
		src/utils/realloc.c \
		src/utils/print.c \
		src/utils/libft.c \

OBJ= $(SRC:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LFLAGS) -o $(NAME) $(OBJ)
	ln -s $(NAME) $(LINK)
	ls -l $(LINK)

.PHONY: clean
clean:
	rm -rf $(OBJ)

.PHONY: fclean
fclean: clean
	rm -rf $(NAME)
	rm -rf $(LINK)

.PHONY: re
re: fclean $(NAME)

.PHONY: re_bonus
re_bonus: fclean bonus
