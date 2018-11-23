/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_first.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:48:48 by vkorniie          #+#    #+#             */
/*   Updated: 2018/11/07 11:48:49 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/core.h"

t_op	g_optab[20] =
{
	{"live", 1, {{0, 1, 0}, {0, 0, 0}, {0, 0, 0}}, 4, 1, 10, "alive", 0, 4},
	{"ld", 2, {{0, 1, 1}, {1, 0, 0}, {0, 0, 0}}, 4, 2, 5, "load", 1, 4},
	{"st", 2, {{1, 0, 0}, {1, 0, 1}, {0, 0, 0}}, 4, 3, 5, "store", 1, 4},
	{"add", 3, {{1, 0, 0}, {1, 0, 0}, {1, 0, 0}}, 4, 4, 10, "addition", 1, 4},
	{"sub", 3, {{1, 0, 0}, {1, 0, 0}, {1, 0, 0}}, 4, 5, 10,
		"substraction", 1, 4},
	{"and", 3, {{1, 1, 1}, {1, 1, 1}, {1, 0, 0}}, 4, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 4},
	{"or", 3, {{1, 1, 1}, {1, 1, 1}, {1, 0, 0}}, 4, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 4},
	{"xor", 3, {{1, 1, 1}, {1, 1, 1}, {1, 0, 0}}, 4, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 4},
	{"zjmp", 1, {{0, 1, 0}, {0, 0, 0}, {0, 0, 0}}, 2, 9, 20,
		"jump if zero", 0, 2},
	{"ldi", 3, {{1, 1, 1}, {1, 1, 0}, {1, 0, 0}}, 2, 10, 25,
		"load index", 1, 2},
	{"sti", 3, {{1, 0, 0}, {1, 1, 1}, {1, 1, 0}}, 2, 11, 25,
		"store index", 1, 2},
	{"fork", 1, {{0, 1, 0}, {0, 0, 0}, {0, 0, 0}}, 2, 12, 800, "fork", 0, 2},
	{"lld", 2, {{0, 1, 1}, {1, 0, 0}, {0, 0, 0}}, 4, 13, 10, "long load", 1, 4},
	{"lldi", 3, {{1, 1, 1}, {1, 1, 0}, {1, 0, 0}}, 2, 14, 50,
		"long load index", 1, 2},
	{"lfork", 1, {{0, 1, 0}, {0, 0, 0}, {0, 0, 0}}, 2, 15, 1000, "long fork",
		0, 2},
	{"aff", 1, {{1, 0, 0}, {0, 0, 0}, {0, 0, 0}}, 4, 16, 2, "aff", 1, 4},
	{"ljmp", 1, {{0, 1, 0}, {0, 0, 0}, {0, 0, 0}}, 2, 17, 20,
		"jump if zero", 0, 2},
	{"lst", 2, {{1, 0, 0}, {1, 0, 1}, {0, 0, 0}}, 4, 18, 5, "store", 1, 4},
	{"lsti", 3, {{1, 0, 0}, {1, 1, 1}, {1, 1, 0}}, 2, 19, 25,
		"store index", 1, 2},
	{0, 0, {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, 0, 0, 0, 0, 0, 0}
};

void	put_zero(t_c *p)
{
	int i;

	i = 0;
	while (p->line[i])
	{
		if ((p->line[i] == '#') || (p->line[i] == ';'))
		{
			p->line[i] = '\0';
			break ;
		}
		i++;
	}
}

void	get_file(t_c *p)
{
	char	buff[READ_SIZE + 1];
	int		ret;
	char	*temp;

	p->file = ft_strnew(0);
	while ((ret = read(p->fd, buff, READ_SIZE)))
	{
		buff[ret] = '\0';
		temp = p->file;
		p->file = ft_strjoin(p->file, buff);
		free(temp);
	}
	close(p->fd);
	write_bot_name(p, 0, 0, 0);
}

void	check_file_name(char *str, t_c *p)
{
	char	*tmp;
	t_cmd	*cmd;

	cmd = NULL;
	p->f_name = NULL;
	p->f_name = ft_strsub(str, 0, ft_strlen(str) - 2);
	tmp = p->f_name;
	p->f_name = ft_strjoin(p->f_name, ".cor");
	free(tmp);
	start_reading(p, str, cmd);
	check_cmd_args(p);
}

void	open_file(t_c *ptr, char *str)
{
	char *p;

	if ((p = ft_strchr(str, '.')))
	{
		while (*p)
			p++;
		if (*(p - 1) == 's' && *(p - 2) == '.')
		{
			ptr->fd = open(str, O_RDONLY);
			if (ptr->fd < 0)
				error(1);
			get_file(ptr);
			check_file_name(str, ptr);
		}
		else
			error(10);
	}
	else
		error(10);
}

int		main(int argc, char **argv)
{
	t_c *ptr;

	ptr = (t_c *)malloc(sizeof(t_c));
	ptr->flag = 0;
	if (argc == 2 || (argc == 3 &&
		(!ft_strcmp("-a", argv[1]) || !ft_strcmp("-a", argv[2]))))
		open_file(ptr, (argc == 3 && !ft_strcmp("-a", argv[1]))
			? argv[2] : argv[1]);
	else
		ft_printf("%s\n", "Usage: ./asm <sourcefile.s>");
	file_creator(ptr);
	if (argc == 3)
		flag_a(ptr);
	else
		ft_printf("Writing output program to %s\n", ptr->f_name);
	return (0);
}
