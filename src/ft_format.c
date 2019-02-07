/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 00:34:22 by akorobov          #+#    #+#             */
/*   Updated: 2019/01/07 22:19:52 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void				ft_format(t_stat buf, t_info *info)
{
	struct passwd	*psw;
	struct group	*grp;
	int				size;

	size = ft_digit_size(buf.st_nlink);
	if (info->form.col1 < size)
		info->form.col1 = size;
	psw = getpwuid(buf.st_uid);
	size = ft_strlen(psw->pw_name);
	if (info->form.col2 < size)
		info->form.col2 = size;
	grp = getgrgid(buf.st_gid);
	size = ft_strlen(grp->gr_name);
	if (info->form.col3 < size)
		info->form.col3 = size;
	size = ft_digit_size(buf.st_size);
	if (info->form.col4 < size)
		info->form.col4 = size;
}
