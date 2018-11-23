#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msakovyc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/24 19:35:24 by msakovyc          #+#    #+#              #
#    Updated: 2018/03/24 19:35:28 by msakovyc         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC = ft_count_word.c get_next_line.c ft_atointmxt.c ft_atoi_ptr.c ft_putnstr.c ft_memset.c ft_bzero.c ft_memcpy.c \
ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c \
ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c \
ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
ft_strjoin.c ft_strnjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_strrev.c \
ft_range.c ft_swap.c ft_isprime.c ft_nextprime.c print_puox.c print_str.c print_dc.c print_unicode.c ft_printf.c prints.c counters.c \
ft_splitdel.c
HDR = ./includes/
OBJ = $(SRC:.c=.o)
NAME = libft.a
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC)
	@ gcc $(FLAGS) -c $(SRC) -I $(HDR)
	@ ar rc $(NAME) $(OBJ)

clean:
	@ rm -f $(OBJ)

fclean: clean
	@ rm -f $(NAME)

re: fclean all