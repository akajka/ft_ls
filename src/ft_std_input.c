/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_std_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 02:38:54 by akorobov          #+#    #+#             */
/*   Updated: 2019/01/15 21:27:14 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void				ft_std_run_up(DIR *ddir, t_info *info, char *dir_name)
{
	char			path[1024];
	struct dirent	*sd;
	int				len;
	t_stat			buf;
	int				j;

	info->sum_file = 0;
	j = 0;
	while ((sd = readdir(ddir)))
	{
		CHECK_FLAG_A(g_fl_a, sd->d_name);
		ft_path(path, dir_name, sd->d_name);
		lstat(path, &buf);
		if ((len = ft_strlen(sd->d_name)) > info->form.col1)
			info->form.col1 = len;
		j += buf.st_blocks;
		info->sum_file++;
	}
	if (info->sum_file != 0)
		ft_hendl(info, dir_name);
}

void				ft_input_elem(t_stat buf, char *f_n)
{
	CHECK_G(buf.st_mode);
	ft_putendl(f_n);
	if (g_fl_g)
		ft_putstr("\033[0m");
}

void				ft_std_input(t_info *info, char *dir_name, int g)
{
	DIR				*ddir;
	int				i;

	i = -1;
	ft_form(info);
	if ((ddir = opendir(dir_name)))
	{
		if (g > 0)
			write(1, "\n", 1);
		if (info->sum_dir > 1)
			ft_print_dir_name(dir_name);
		ft_std_run_up(ddir, info, dir_name);
		while (++i < info->sum_file)
			ft_input_elem(info->buf[i], info->file_name[i]);
		if (g_fl_rr)
			ft_rec(info, dir_name);
		if (info->sum_file != 0)
			ft_free_list(info);
		closedir(ddir);
	}
	else
		ft_print_err(dir_name);
}
