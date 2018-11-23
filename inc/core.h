/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 10:46:01 by vkorniie          #+#    #+#             */
/*   Updated: 2018/10/19 10:46:03 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# define READ_SIZE 4096

# include "../libft/includes/libft.h"
# include "op.h"
# include <fcntl.h>

typedef struct		s_label
{
	char			*label;
	struct s_label	*next;
}					t_label;

typedef struct		s_args
{
	unsigned int	ar_n;
	char			*label;
	int				number;
	int				size;
	int				type;
	struct s_args	*next;
}					t_args;

typedef struct		s_cmd
{
	int				number;
	t_label			*label;
	t_args			*args;
	int				cmd_s;
	unsigned int	size_before;
	unsigned char	codage;
	int				char_c;
	struct s_cmd	*next;
}					t_cmd;

typedef struct		s_c
{
	int				fd;
	char			*f_name;
	char			*file;
	char			*line;
	char			player_n[128];
	char			comment[2048];
	char			*comm;
	char			*c;
	char			flag;
	int				counter;
	unsigned int	size;
	char			checker2;
	t_label			*tmp;
	t_cmd			*cmd_p;
}					t_c;

void				put_zero(t_c *p);

/*
** bot name
*/
void				write_bot_name(t_c *p, int i, int count, int tmp);
void				error(int i);

/*
** start reading
*/
int					is_comment(t_c *p, int i);
void				start_reading(t_c *p, char *str, t_cmd *cmd);
int					empty_string(t_c *p, int i);

/*
** start read command
*/
int					check_point(t_c *p, int k, int c);
void				read_command(t_c *p, int i, int k, t_cmd *cmd);
int					is_command_nolabel(t_c *ps, int i, int k);
void				calc_codage(t_c *p, t_cmd *c, int i, int j);

/*
** writing labels
*/
int					is_str_label(t_c *p);
void				start_label(t_c *p, int k);
void				check_label(t_c *p, t_cmd *c, int i);
t_cmd				*make_new_cmd(t_c *p);

/*
** make command list
*/
void				write_label(t_c *p, t_cmd *c);
void				validate_command(t_c *p, t_cmd *c, int j, int k);
void				write_one_arg(char *ptr, t_cmd *c, t_args *arg);

/*
** write couple arg
*/
void				write_arg_label1(char *s, t_cmd *c, t_args *t, int i);
void				start_search_signs(char **string, int i, t_cmd *c);

/*
** finish validation
*/
void				write_arg_label(char *string, int i, t_cmd *c, t_args *t);
void				make_new_argument(t_args *arg);
void				check_t_ind(char **string, int i, t_cmd *c, t_args *t);
void				error2(int i);
void				new_function(t_c *p);

/*
** write in file
*/
t_cmd				*find_label(t_cmd *t, char *label);
void				find_this_label(t_c *p, t_cmd *t, t_args *ar);
void				find_label_instruct(t_c *p);
void				count_comma(t_c *p, int j, char *ptr);
int					if_not_cmd(char *ptr, t_c *p, int i, int k);

/*
** binary
*/
void				split_del(char **string);
int					comma_existing(t_c *p, int i);
int					file_creator(t_c *file);
void				writting_coomand(t_c *file, int fd);
void				reverse(int fd, unsigned char *n, int count);

/*
** finis ^-^
*/
void				validate_name(t_c *p, int i);
void				check_cm_instring(t_c *p, int i);
int					count_commands(char *p);

/*
** flag_a
*/
void				flag_a(t_c *file);
void				output_first(t_cmd *lst);
void				output_second(t_cmd *lst);
void				write_type(t_cmd *c, int j, int type);
int					label_checker(t_c *p, int i);

/*
** finish assembler
*/
void				check_cmd_args(t_c *p);
void				skip(t_c *p, int *i, int *label);


#endif
