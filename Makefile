NAME = asm

CC = gcc
FLAGS = -Wall -Wextra -Werror

SRCS = flag_a.c core_first.c finish_assembler.c make_cmd_list.c start_reading.c write_binary.c write_couple_arg.c finish_validation.c start_read_cmd.c start_write_infile.c write_bot_name.c writing_labels.c calc_codage.c
OBJ = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

OBJ_DIR = ./objects/
SRC_DIR = ./srcs/

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME) libft/libft.a
	@tput setaf 2; echo made

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) -c $< -o $@ $(FLAGS)

clean:
	@make clean -C libft
	@rm -f $(OBJ)
	@tput setaf 4; echo cleaned

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)
	@tput setaf 1; echo fcleaned

re: fclean all