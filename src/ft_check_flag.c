/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 00:15:22 by akorobov          #+#    #+#             */
/*   Updated: 2019/01/15 18:27:54 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	ft_check_dir(t_info *info, int argc, char **argv)
{
	info->dir_name = (char **)malloc(sizeof(char *) * (argc + 1));
	while (argc > 0 && *argv)
	{
		info->dir_name[info->sum_dir++] = ft_strdup(*argv);
		argv++;
		argc--;
	}
	if (info->sum_dir == 0)
		info->dir_name[info->sum_dir++] = ft_strdup(".");
	info->dir_name[info->sum_dir] = NULL;
}

void	ft_fl_f_ss(int i)
{
	if (i == 0)
	{
		__FL_F();
	}
	else
	{
		__FL_SS();
	}
}

int		ft_isflag(char c)
{
	if (c == 'l')
		g_fl_l = 1;
	else if (c == 'r')
		g_fl_r = 1;
	else if (c == 'g')
		g_fl_g = 1;
	else if (c == 'R')
		g_fl_rr = 1;
	else if (c == 'a')
		g_fl_a = 1;
	else if (c == 'C')
		g_fl_cc = 1;
	else if (c == 'f')
		ft_fl_f_ss(0);
	else if (c == 't')
		g_fl_t = 1;
	else if (c == '1')
		write(1, "", 0);
	else if (c == '@')
		ft_fl_f_ss(1);
	else
		return (-1);
	return (0);
}

int		ft_check_flag(t_info *info, int argc, char **argv, int sig)
{
	while (argc-- >= 2 && argv++ && sig == 0)
	{
		__BONUS_PART(*argv, "-yo");
		if (*argv[0] == '-')
		{
			if (!(ft_strcmp(*argv, "-")))
				break ;
			while (++(*argv) && **argv != '\0')
			{
				if (ft_isflag(**argv) == -1)
					return ((int)**argv);
			}
		}
		else
			break ;
	}
	ft_check_dir(info, argc, argv);
	return (0);
}
