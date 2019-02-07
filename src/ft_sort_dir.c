/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 00:47:28 by akorobov          #+#    #+#             */
/*   Updated: 2019/01/09 22:30:20 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		ft_sort_time_dir(t_info *s)
{
	int		i;
	int		j;
	t_stat	buf1;
	t_stat	buf2;

	i = -1;
	while (s->dir_name[++i + 1])
	{
		lstat(s->dir_name[i], &buf1);
		lstat(s->dir_name[i + 1], &buf2);
		j = buf1.st_mtime - buf2.st_mtime;
		if ((j < 0 && g_fl_r == 0) || (j > 0 && g_fl_r != 0))
		{
			ft_swap(&s->dir_name[i], &s->dir_name[i + 1]);
			if (i != 0)
				i -= 2;
		}
	}
}

void		ft_sort_file_dir(t_info *s)
{
	int		i;
	t_stat	buf1;
	t_stat	buf2;

	i = -1;
	while (s->dir_name[++i + 1])
	{
		lstat(s->dir_name[i], &buf1);
		lstat(s->dir_name[i + 1], &buf2);
		if (S_ISDIR(buf1.st_mode) && !S_ISDIR(buf2.st_mode))
		{
			ft_swap(&s->dir_name[i], &s->dir_name[i + 1]);
			if (i != 0)
				i -= 2;
		}
	}
}

void		ft_sort_alph_dir(t_info *s)
{
	int		i;
	int		j;

	i = -1;
	while (s->dir_name[++i + 1])
	{
		j = 0;
		while (s->dir_name[i][j] == s->dir_name[i + 1][j])
			j++;
		j = s->dir_name[i + 1][j] - s->dir_name[i][j];
		if ((j < 0 && g_fl_r == 0) || (j > 0 && g_fl_r != 0))
		{
			ft_swap(&s->dir_name[i], &s->dir_name[i + 1]);
			if (i != 0)
				i -= 2;
		}
	}
}

void		ft_sort_dir(t_info *info)
{
	if (g_fl_t != 0)
		ft_sort_time_dir(info);
	else
		ft_sort_alph_dir(info);
	ft_sort_file_dir(info);
}
