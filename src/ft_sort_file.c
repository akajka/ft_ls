/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 03:04:42 by akorobov          #+#    #+#             */
/*   Updated: 2019/01/16 17:28:43 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void				ft_sort_alph(t_info *s)
{
	int				i;
	int				j;

	i = -1;
	while (s->file_name[++i + 1])
	{
		j = 0;
		while (s->file_name[i][j] == s->file_name[i + 1][j])
			j++;
		j = s->file_name[i + 1][j] - s->file_name[i][j];
		if ((j < 0 && g_fl_r == 0) || (j > 0 && g_fl_r != 0))
		{
			ft_swap_file(s, i);
			if (i != 0)
				i -= 2;
		}
	}
}

void				ft_sort_time(t_info *info)
{
	long int		i;
	long int		k;
	long int		j;

	i = -1;
	while (++i + 1 < info->sum_file)
	{
		j = info->buf[i].st_mtime - info->buf[i + 1].st_mtime;
		k = info->buf[i + 1].st_mtimespec.tv_sec;
		if (j == 0)
			j = k - info->buf[i + 1].st_mtimespec.tv_sec;
		if (j == 0)
			j = ft_strcmp(info->file_name[i + 1], info->file_name[i]);
		if ((j < 0 && g_fl_r == 0) || (j > 0 && g_fl_r != 0))
		{
			ft_swap_file(info, i);
			if (i != 0)
				i -= 2;
		}
	}
}
