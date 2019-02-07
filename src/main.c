/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 23:57:29 by akorobov          #+#    #+#             */
/*   Updated: 2019/01/16 16:57:33 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		ft_inic_flag(void)
{
	g_fl_l = 0;
	g_fl_t = 0;
	g_fl_r = 0;
	g_fl_rr = 0;
	g_fl_a = 0;
	g_fl_f = 0;
	g_fl_g = 0;
	g_fl_cc = 0;
	g_fl_ss = 0;
}

int			ft_ls(int argc, char **argv, int sig)
{
	t_info	info;
	char	i;

	info.sum_dir = 0;
	info.sig = sig;
	info.fail = 0;
	if ((i = ft_check_flag(&info, argc, argv, sig)))
	{
		ft_putstr("./ft_ls: illegal option -- ");
		write(1, &i, 1);
		write(1, "\n", 1);
		ft_putstr("usage: ./ft_ls [-RCafglrt]");
		ft_putendl(" [file ...]");
		exit(1);
	}
	ft_start_input(&info);
	return (0);
}

int			main(int argc, char **argv)
{
	int		i;

	ft_inic_flag();
	i = ft_ls(argc, argv, 0);
	return (i);
}
