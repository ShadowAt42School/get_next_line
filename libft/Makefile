# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 21:51:41 by maghayev          #+#    #+#              #
#    Updated: 2018/02/02 03:10:30 by maghayev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a
PURPLE = "\033[35m\c"
RED = "\033[31m\c"
NC="\033[0m\c"
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEPS = libft.h
SRC  = ft_bzero.c  ft_memcpy.c ft_memset.c ft_memccpy.c ft_memchr.c \
		ft_memmove.c ft_memcmp.c ft_memalloc.c ft_memdel.c ft_memrealloc.c \
		ft_memjoin.c ft_memdup.c ft_memshrink.c \
		\
		ft_putchar.c ft_putstr.c ft_putnbr.c ft_print_byte.c \
		ft_object_bit_print.c ft_putendl.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c \
		\
		ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
		ft_strncat.c ft_strsub.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
		ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_strnew.c \
		ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
		ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strjoin.c ft_strtrim.c \
		ft_strsplit.c ft_strwordsdelim.c ft_strlendelim.c ft_strdupdelim.c \
		ft_strtrimdelim.c \
		\
		ft_isdigit.c ft_isalpha.c ft_isascii.c ft_isprint.c ft_isalnum.c \
		ft_toupper.c ft_tolower.c ft_atoi.c ft_itoa.c \
		\
		ft_lstnew.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstmap.c \
		ft_lstiter.c ft_lstpush.c ft_lstfrem.c ft_lstlrem.c ft_lstanydel.c \

OBJECT = $(SRC:.c=.o)

%.o: %.c $(DEPS)
	@echo $(PURPLE)
	$(CC) $(CFLAGS) -g -c -o $@ $<
	@echo $(NC)

all: $(NAME)

$(NAME): $(OBJECT)
	@ar rc $@ $^
	@ranlib $@
	@echo "Finished Building LibFT!"

clean:
	@echo $(RED)
	@echo "*sadly* Cleanning LibFT... Wait... *sniffs*"
	@/bin/rm -f $(OBJECT)
	@echo "Cleaned LibFT! Bye Bye! *without intusiasm*"
	@echo $(NC)

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "LibFT .a has been deleted! *sign*"

re: fclean all

.PHONY: all clean fclean re
