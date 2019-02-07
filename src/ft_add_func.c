/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 19:05:05 by akorobov          #+#    #+#             */
/*   Updated: 2019/01/09 18:00:43 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		ft_print_dir_name(char *d_name)
{
	ft_putstr(d_name);
	write(1, ":\n", 2);
}

void		ft_print_err(char *d_name)
{
	write(1, "ft_ls: ", 7);
	ft_putstr(d_name);
	write(1, ": ", 2);
	ft_putendl(strerror(errno));
}

void		ft_swap_file(t_info *info, int i)
{
	t_stat	st_tmp;

	ft_swap(&info->file_name[i], &info->file_name[i + 1]);
	st_tmp = info->buf[i];
	info->buf[i] = info->buf[i + 1];
	info->buf[i + 1] = st_tmp;
}

void		ft_swap(char **f1, char **f2)
{
	char	*tmp;

	tmp = *f1;
	*f1 = *f2;
	*f2 = tmp;
}

void		ft_path(char *path, char *dir_name, char *d_name)
{
	ft_strcpy(path, dir_name);
	if (dir_name[ft_strlen(dir_name) - 1] != '/')
		ft_strcat(path, "/");
	ft_strcat(path, d_name);
}
