/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 18:47:05 by akorobov          #+#    #+#             */
/*   Updated: 2019/02/07 19:48:31 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

static void		ft_dir_path(char **path, char *dir_name, char *file_name)
{
	char		*tmp;

	if (ft_strcmp(dir_name, "/"))
	{
		*path = ft_strdup(dir_name);
		tmp = ft_strjoin(*path, "/");
		ft_memdel((void **)path);
		*path = ft_strjoin(tmp, file_name);
		free(tmp);
	}
	else
	{
		tmp = ft_strdup(dir_name);
		*path = ft_strjoin(tmp, file_name);
		free(tmp);
	}
}

void			ft_rec(t_info *info, char *dir_name)
{
	char		*tmp[2];
	int			i;

	i = -1;
	while (++i < info->sum_file)
		if (S_ISDIR(info->buf[i].st_mode))
		{
			if (!(ft_strcmp(info->file_name[i], ".")) ||
					(!(ft_strcmp(info->file_name[i], ".."))))
				continue ;
			write(1, "\n", 1);
			ft_dir_path(&tmp[1], dir_name, info->file_name[i]);
			ft_print_dir_name(tmp[1]);
			ft_ls(2, tmp, 1);
			ft_strdel(&tmp[1]);
		}
}

void			ft_input_list_file(t_info *info, t_stat buf, int i)
{
	t_stat		tmp_buf;
	int			j;

	j = -1;
	while (++j < info->sum_dir && i == 0)
		if (lstat(info->dir_name[j], &tmp_buf) == 0 &&
				!S_ISDIR(tmp_buf.st_mode))
			ft_format(tmp_buf, info);
	if (lstat(info->dir_name[i], &buf) == 0)
		ft_list(buf, info, info->dir_name[i], info->dir_name[i]);
}

void			ft_input(t_info *info)
{
	int			i;
	int			l;
	t_stat		buf;

	i = -1;
	ft_form(info);
	if (info->fail != 0)
		write(1, "\n", 1);
	while (info->dir_name[++i])
	{
		l = lstat(info->dir_name[i], &buf);
		if (!l && (!S_ISDIR(buf.st_mode) & !S_IFLNK) && !g_fl_l)
			ft_input_elem(buf, info->dir_name[i]);
		else if (!l && g_fl_l && (!S_ISDIR(buf.st_mode) | !S_ISVTX))
			ft_input_list_file(info, buf, i);
		else if (!l && g_fl_l)
			ft_input_list(info, info->dir_name[i], i);
		else if (!l)
			ft_std_input(info, info->dir_name[i], i);
		ft_strdel(&info->dir_name[i]);
	}
	free(info->dir_name);
}
