# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/28 16:58:58 by iseletsk          #+#    #+#              #
#    Updated: 2018/05/12 15:23:01 by vkaidans         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

ASM = asm

SRC_DIR :=		./sources/
OBJ_DIR :=		./objects/
INC_DIR :=		./includes/
LIB_DIR :=		./libraries/

SRC :=		vm_main.c vm_wizard.c op.c\
			vm_get_players.c vm_readfile.c\
			vm_cycle_manage.c vm_process_unit.c vm_dump.c vm_proc_sidekick.c\
			vm_oper_def.c vm_oper_math.c vm_oper_bit.c\
			vm_oper_ilong.c vm_oper_spec.c vm_oper_bonus.c\
			vm_list_player.c vm_list_proc.c\
			vs_visual.c vs_nstuff.c vs_status.c vs_stuff.c vs_draw_proc.c

ASRC :=		flag_a.c core_first.c finish_assembler.c \
			make_cmd_list.c start_reading.c write_binary.c \
			write_couple_arg.c finish_validation.c start_read_cmd.c \
			start_write_infile.c write_bot_name.c writing_labels.c calc_codage.c

OBJ =		$(addprefix $(OBJ_DIR), $(SRC:.c=.o))
AOBJ =		$(addprefix $(OBJ_DIR), $(ASRC:.c=.o))

LIBFT =			$(LIBFT_DIR)libft.a
LIBFT_DIR :=	$(LIB_DIR)libft/
LIBFT_INC :=	$(LIBFT_DIR)includes/
LIBFT_FLAGS :=	-lft -L $(LIBFT_DIR)

CC_FLAGS :=		-Wall -Wextra -Werror

LINK_FLAGS :=	$(LIBFT_FLAGS)

HEADER_FLAGS :=	-I $(INC_DIR) -I $(LIBFT_INC)

CC :=		gcc

.SILENT:

all: $(NAME) $(ASM)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CC_FLAGS)  $(OBJ) $(LINK_FLAGS) -lncurses -o $(NAME)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Created corewar"
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Created asm"

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
	$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)

$(ASM): $(LIBFT) $(AOBJ)
	$(CC) $(CC_FLAGS) $(AOBJ) $(LINK_FLAGS) -o $(ASM)

$(AOBJ): | $(OBJ_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ) $(AOBJ)
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Cleaned temp files"

fclean: clean
	rm -f $(NAME) $(ASM)
	make fclean -C $(LIBFT_DIR)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fully cleaned"

re: fclean all

vpath %.c $(SRC_DIR)

.PHONY: all clean fclean re
