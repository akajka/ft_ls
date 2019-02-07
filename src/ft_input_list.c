/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 00:27:35 by akorobov          #+#    #+#             */
/*   Updated: 2019/01/15 18:53:17 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void				ft_run_up(DIR *ddir, t_info *info, char *dir_name)
{
	char			path[1024];
	struct dirent	*sd;
	t_stat			buf;
	int				j;

	info->sum_file = 0;
	j = 0;
	while ((sd = readdir(ddir)))
	{
		CHECK_FLAG_A(g_fl_a, sd->d_name);
		ft_path(path, dir_name, sd->d_name);
		lstat(path, &buf);
		ft_format(buf, info);
		j += buf.st_blocks;
		info->sum_file++;
	}
	if (info->sum_file != 0)
	{
		ft_hendl(info, dir_name);
		write(1, "total ", 6);
		ft_putnbr(j);
		write(1, "\n", 1);
	}
}

void				ft_list(t_stat buf, t_info *info, char *f_n, char *d_n)
{
	int				tmp;

	ft_chmd(buf);
	if (g_fl_cc)
		ft_extended_attributes(f_n, d_n);
	tmp = info->form.col1 - ft_digit_size(buf.st_nlink) + (g_fl_cc ? 2 : 3);
	while (--tmp)
		write(1, " ", 1);
	ft_putnbr(buf.st_nlink);
	ft_uid(buf, info->form.col2);
	ft_gid(buf, info->form.col3);
	ft_write_size(buf, info->form.col4);
	ft_write_time(buf);
	CHECK_G(buf.st_mode);
	ft_putstr(f_n);
	if (S_ISLNK(buf.st_mode))
		ft_link(f_n, d_n);
	if (g_fl_g)
		ft_putstr("\033[0m");
	if (g_fl_ss && g_ex_atr[0] != '\0')
		ft_ex_write(f_n, d_n);
	ft_strclr(g_ex_atr);
	if (info->sum_file)
		write(1, "\n", 1);
}

void				ft_file_type(int st_mode)
{
	if (st_mode & S_IFMT)
	{
		if (S_ISDIR(st_mode))
			write(1, "d", 1);
		else if (S_ISCHR(st_mode))
			write(1, "c", 1);
		else if (S_ISBLK(st_mode))
			write(1, "b", 1);
		else if (S_ISREG(st_mode))
			write(1, "-", 1);
		else if (S_ISLNK(st_mode))
			write(1, "l", 1);
		else if (S_ISSOCK(st_mode))
			write(1, "s", 1);
	}
}

void				ft_free_list(t_info *info)
{
	int				i;

	i = -1;
	while (++i < info->sum_file)
		ft_strdel(&info->file_name[i]);
	free(info->buf);
	free(info->file_name);
}

void				ft_input_list(t_info *info, char *dir_name, int g)
{
	DIR				*ddir;
	int				i;
	t_stat			buf;

	i = -1;
	ft_form(info);
	if (lstat(dir_name, &buf) == 0 && (!S_ISLNK(buf.st_mode) | !S_ISVTX) &&
			(ddir = opendir(dir_name)))
	{
		if (g > 0)
			write(1, "\n", 1);
		if (info->sum_dir > 1)
			ft_print_dir_name(dir_name);
		ft_run_up(ddir, info, dir_name);
		while (++i < info->sum_file)
			ft_list(info->buf[i], info, info->file_name[i], dir_name);
		if (g_fl_rr)
			ft_rec(info, dir_name);
		if (info->sum_file != 0)
			ft_free_list(info);
		closedir(ddir);
	}
	else
		ft_print_err(dir_name);
}
