/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hendl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 20:59:52 by akorobov          #+#    #+#             */
/*   Updated: 2019/01/15 18:44:27 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void				ft_link(char *f, char *d)
{
	int				i;
	char			tmp[1024];
	char			name[1024];

	i = 0;
	if (ft_strcmp(f, d) != 0)
		ft_path(tmp, d, f);
	else
		ft_strcpy(tmp, d);
	if (readlink(tmp, name, 1024) != -1)
	{
		ft_putstr(" -> ");
		while (name[i] < 127 && name[i] > 0)
			write(1, &name[i++], 1);
	}
}

void				ft_sorting(t_info *info)
{
	if (g_fl_t == 0)
		ft_sort_alph(info);
	else
		ft_sort_time(info);
}

void				ft_form(t_info *info)
{
	info->form.col1 = 1;
	info->form.col2 = 1;
	info->form.col3 = 1;
	info->form.col4 = 1;
}

void				ft_hendl(t_info *info, char *dir_name)
{
	char			path[1024];
	struct dirent	*sd;
	int				i;
	DIR				*ddir;

	i = 0;
	info->file_name = (char **)malloc(sizeof(char *) * (info->sum_file + 1));
	info->buf = (t_stat *)malloc(sizeof(t_stat) * (info->sum_file + 1));
	if ((ddir = opendir(dir_name)))
	{
		while ((sd = readdir(ddir)))
		{
			CHECK_FLAG_A(g_fl_a, sd->d_name);
			info->file_name[i] = ft_strdup(sd->d_name);
			ft_path(path, dir_name, sd->d_name);
			lstat(path, &info->buf[i++]);
			ft_strclr(path);
		}
		info->file_name[info->sum_file] = NULL;
		closedir(ddir);
	}
	if (g_fl_f == 0)
		ft_sorting(info);
}
