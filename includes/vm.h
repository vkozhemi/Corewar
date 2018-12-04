/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 12:48:16 by vkaidans          #+#    #+#             */
/*   Updated: 2018/10/23 12:48:17 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <fcntl.h>
# include <ncurses.h>
# include <stdio.h>
# include <time.h>
# include "libft.h"
# include "op.h"

# define UC				unsigned char
# define UI				unsigned int

# define MAP(pos) 		core->map[pos % MEM_SIZE]
# define COLOR(pos) 	core->color[pos % MEM_SIZE]
# define STATUS			core->status

# define POS 			proc->pos
# define COMMAND		proc->command
# define REG(i) 		proc->reg[i - 1]

# define SET_COL(col)	(col && col < 9) ? col : 9
# define PRO_COL(col)	(col && col < 9) ? col + 10 : 19

# define C_INDX(val)	(val && val <= REG_NUMBER)
# define ARG1(val) 		(val & 0b11000000) >> 6
# define ARG2(val)		(val & 0b110000) >> 4
# define ARG3(val)		(val & 0b1100) >> 2

typedef struct		s_player
{
	int				number;
	unsigned int	size;
	char			*name;
	char			*comment;
	unsigned char	*code;
	void			*next;
}					t_player;

typedef struct		s_proc
{
	unsigned char	command;
	char			alive;
	char			carry;
	int				pos;
	unsigned int	cycle;
	int				reg[REG_NUMBER];
	void			*next;
}					t_proc;

typedef struct		s_core
{
	unsigned char	status;
	int				alive_shout;
	int				cycle_to_die;
	int				current_era_cycle;
	int				era;
	int				cycle_todecrease;
	int				cycle;
	int				print;
	int				dump;
	unsigned char	*map;
	unsigned char	*color;
	t_player		*last_alive;
	t_player		*player;
	t_proc			*proc;
}					t_core;

typedef struct		s_op
{
	char			*name;
	int				arg;
	int				weight[3];
	int				number;
	int				cycles;
	char			*description;
	int				codage;
	int				carry;
	int				label;
	void			(*func)(t_core *core, t_proc *proc);
}					t_op;

void				op_live(t_core *core, t_proc *proc);
void				op_ld(t_core *core, t_proc *proc);
void				op_st(t_core *core, t_proc *proc);
void				op_fork(t_core *core, t_proc *proc);
void				op_add(t_core *core, t_proc *proc);
void				op_sub(t_core *core, t_proc *proc);
void				op_and(t_core *core, t_proc *proc);
void				op_or(t_core *core, t_proc *proc);
void				op_xor(t_core *core, t_proc *proc);
void				op_zjmp(t_core *core, t_proc *proc);
void				op_ldi(t_core *core, t_proc *proc);
void				op_sti(t_core *core, t_proc *proc);
void				op_lld(t_core *core, t_proc *proc);
void				op_lldi(t_core *core, t_proc *proc);
void				op_lfork(t_core *core, t_proc *proc);
void				op_aff(t_core *core, t_proc *proc);
void				op_ljmp(t_core *core, t_proc *proc);
void				op_lst(t_core *core, t_proc *proc);
void				op_lsti(t_core *core, t_proc *proc);

t_op				g_tab[20];

void				vm_wizard(char **card);
int					vm_isnumber(char *str);

t_player			*vm_readfile(char *str, int number);

void				vm_get_players(t_core *core, char **card);

void				vm_visual(t_core *core);
void				vm_bomj(t_core *core);
void				vm_dump(unsigned char *memory);

void				vm_process_unit(t_core *core);

void				vm_proc_move(unsigned char *map, t_proc *proc, int move);
int					vm_get_gap(unsigned char arg, int label);
int					vm_move(unsigned char i, UC label, UC args);
int					vm_get_val(t_core *core, unsigned int pos, int bytes);
void				vm_set_map(t_core *core, t_proc *proc, UI val, UI addr);

t_player			*vm_list_player_new(int number);
void				vm_list_player_add(t_player **list, t_player *add);
int					vm_list_player_size(t_player *player);

t_proc				*vm_list_proc_new(UI number, UC command, UI pos);
void				vm_list_proc_add(t_proc **list, t_proc *new);
void				vm_list_proc_adde(t_proc **list, t_proc *new);
void				vm_list_proc_del(t_proc **proc);
void				vm_proc_kill(t_proc **proc);

void				vs_init(void);

void				vs_render(t_core *core);
void				vs_input(t_core *core);
void				vs_proc(t_core *core, t_proc *proc, int y, int x);
void				vs_status(t_core *core);
void				vs_stats(t_core *core, int y, int x);
void				vs_info(int y, int x);

#endif
