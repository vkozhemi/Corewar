# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/21 09:57:07 by vkaidans          #+#    #+#              #
#    Updated: 2018/04/16 18:39:00 by vkaidans         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OBJ_DIR := ./objects/

SRC :=	ft_atoi.c ft_card_destructor.c ft_box_destructor.c ft_bzero.c\
		ft_count_c.c ft_factorial.c ft_intlen.c ft_isalnum.c ft_isalpha.c\
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c\
		ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c\
		ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
		ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c\
		ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c\
		ft_putstr_fd.c ft_skip_char.c ft_strcat.c ft_strchr.c ft_strclr.c\
		ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c\
		ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c\
		ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c\
		ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c\
		ft_strstr.c ft_strsub.c ft_strtrim.c ft_swap.c ft_swap_char.c\
		ft_tolower.c ft_toupper.c ft_word_count.c get_next_line.c\
		ft_error.c ft_abs.c\
		ft_printf.c ft_putc.c ft_puts.c\
		ft_putn.c ft_putlnbr.c ft_putllnbr.c\
		ft_uni.c ft_unichar.c ft_unistring.c\
		ft_putx.c ft_putlx.c ft_putllx.c ft_putu.c ft_conver.c ft_converh.c\
		ft_string.c ft_number.c ft_octal.c ft_hex.c ft_char.c ft_unsigned.c\

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: $(NAME)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
	gcc -c $< -o $@ -Wall -Werror -Wextra -I ./includes/

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

