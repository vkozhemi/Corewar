/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 12:08:17 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/04 02:56:36 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_op g_tab[20] =
{
	{0, 0, {0}, 0, 0, 0, 0, 0, 0, 0},
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0, 4, &op_live},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0, 4, &op_ld},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0, 4, &op_st},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0, 4, &op_add},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0, 4, &op_sub},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0, 4, &op_and},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0, 4, op_or},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0, 4, &op_xor},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1, 2, &op_zjmp},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1, 2, &op_ldi},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1, 2, &op_sti},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1, 2, &op_fork},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0, 4, &op_lld},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1, 2, &op_lldi},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1, 2, &op_lfork},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0, 4, &op_aff},
	{"ljmp", 1, {T_DIR}, 17, 40, "ljmp", 0, 1, 2, &op_ljmp},
	{"lst", 2, {T_REG, T_IND | T_REG}, 18, 10, "lst", 1, 0, 4, &op_lst},
	{"lsti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 19, 50,
		"lsti", 1, 1, 2, &op_lsti},
};
