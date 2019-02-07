/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 02:08:36 by akorobov          #+#    #+#             */
/*   Updated: 2019/01/15 18:44:17 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		ft_fail(t_info *s)
{
	int		i;
	t_stat	buf;

	i = -1;
	while (s->dir_name[++i])
		if (lstat(s->dir_name[i], &buf) != 0)
		{
			if (s->fail++)
				write(1, "\n", 1);
			write(1, "ft_ls: ", 7);
			ft_putstr(s->dir_name[i]);
			write(1, ": ", 2);
			ft_putstr(strerror(errno));
		}
}

void		ft_start_input(t_info *info)
{
	if (info->sum_dir > 1)
		ft_sort_dir(info);
	if (info->sig == 0)
		ft_fail(info);
	ft_input(info);
}
