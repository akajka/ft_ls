/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_list1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 02:06:32 by akorobov          #+#    #+#             */
/*   Updated: 2019/01/15 20:47:24 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void				ft_write_size(t_stat buf, int form_col4)
{
	int				size;
	int				tmp;

	size = ft_digit_size(buf.st_size);
	tmp = form_col4 - size + 1;
	while (--tmp > 0)
		write(1, " ", 1);
	ft_putnbr(buf.st_size);
	write(1, " ", 1);
}

void				ft_write_time(t_stat buf)
{
	char			**s;
	int				i;

	i = 0;
	s = ft_strsplit(ctime(&buf.st_mtime), ' ');
	WRITE_MONTH(s[1]);
	if (ft_strlen(s[2]) > 1)
		write(1, s[2], 2);
	else
	{
		write(1, " ", 1);
		write(1, s[2], 1);
	}
	write(1, " ", 1);
	if (time(NULL) - (long)buf.st_mtime > 15768000 ||
			time(NULL) - (long)buf.st_mtime < -15768000)
	{
		WRITE_YEAR(s[4]);
	}
	else
		WRITE_TIME(s[3]);
	write(1, " ", 1);
	while (s[i])
		free(s[i++]);
	free(s);
}

void				ft_chmd(t_stat buf)
{
	ft_file_type(buf.st_mode);
	write(1, (buf.st_mode & S_IRUSR) ? "r" : "-", 1);
	write(1, (buf.st_mode & S_IWUSR) ? "w" : "-", 1);
	write(1, (buf.st_mode & S_IXUSR) ? "x" : "-", 1);
	write(1, (buf.st_mode & S_IRGRP) ? "r" : "-", 1);
	write(1, (buf.st_mode & S_IWGRP) ? "w" : "-", 1);
	write(1, (buf.st_mode & S_IXGRP) ? "x" : "-", 1);
	write(1, (buf.st_mode & S_IROTH) ? "r" : "-", 1);
	write(1, (buf.st_mode & S_IWOTH) ? "w" : "-", 1);
	if (buf.st_mode & S_ISVTX)
		write(1, "t", 1);
	else if (buf.st_mode & S_IXOTH)
		write(1, "x", 1);
	else
		write(1, "-", 1);
}

void				ft_uid(t_stat buf, int form_col2)
{
	struct passwd	*psw;
	int				tmp;
	int				size;

	psw = getpwuid(buf.st_uid);
	size = ft_strlen(psw->pw_name);
	tmp = form_col2 - size + 3;
	write(1, " ", 1);
	write(1, psw->pw_name, size);
	while (--tmp > 0)
		write(1, " ", 1);
}

void				ft_gid(t_stat buf, int form_col3)
{
	struct group	*gr;
	int				tmp;
	int				size;

	gr = getgrgid(buf.st_gid);
	size = ft_strlen(gr->gr_name);
	tmp = form_col3 - size + 3;
	write(1, gr->gr_name, size);
	while (--tmp > 0)
		write(1, " ", 1);
}
