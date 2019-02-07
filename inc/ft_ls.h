/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 00:07:22 by akorobov          #+#    #+#             */
/*   Updated: 2019/01/16 17:00:52 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/xattr.h>
# include <dirent.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/acl.h>
# include <errno.h>
# include <pwd.h>
# include <time.h>
# include <grp.h>
# define __BONUS_PART(x, y) if (!ft_strcmp(x, y)) {ft_show_pic(); exit(0);}
# define CHECK_FLAG_A(x, y) if (!(x) && !(ft_strncmp(".", y, 1))) continue ;
# define CHECK_FLAG_A(x, y) if (!(x) && !(ft_strncmp(".", y, 1))) continue ;
# define CHECK_G_D(x) if (S_ISDIR(x)) ft_putstr("\033[1;32m");
# define CHECK_G_L(x) if (S_ISLNK(x)) ft_putstr("\033[1;35m");
# define CHECK_G_F(x) if (!S_ISDIR(x) && !S_ISLNK(x)) ft_putstr("\033[1;36m");
# define CHECK_G(x) if (g_fl_g) {CHECK_G_D(x); CHECK_G_L(x); CHECK_G_F(x);}
# define WRITE_MONTH(x) write(1, x, 3); write(1, " ", 1);
# define WRITE_YEAR(x) write(1, " ", 1); write(1, x, (ft_strlen(x) - 1));
# define WRITE_TIME(x) write(1, x, 5);
# define __FL_F() g_fl_a = 1; g_fl_f = 1;
# define __FL_SS() g_fl_cc = 1; g_fl_ss = 1;

typedef struct stat		t_stat;

typedef struct		s_format
{
	int				col1;
	int				col2;
	int				col3;
	int				col4;
}					t_format;

typedef struct		s_info
{
	int				fail;
	int				sig;
	int				sum_file;
	int				sum_dir;
	t_format		form;
	char			**file_name;
	char			**dir_name;
	t_stat			*buf;
}					t_info;

int					g_fl_a;
int					g_fl_l;
int					g_fl_t;
int					g_fl_r;
int					g_fl_f;
int					g_fl_rr;
int					g_fl_g;
int					g_fl_cc;
int					g_fl_ss;
int					g_a;
char				g_ex_atr[1024];
int					ft_ls(int argc, char **argv, int sig);
int					ft_check_flag(t_info *info, int argc, char **argv, int sig);
void				ft_start_input(t_info *info);
void				ft_sort_dir(t_info *info);
void				ft_print_err(char *d_name);
void				ft_path(char *path, char *dir_name, char *d_name);
void				ft_swap_file(t_info *info, int i);
void				ft_sort_time(t_info *info);
void				ft_swap(char **f1, char **f2);
void				ft_format(t_stat buf, t_info *info);
void				ft_hendl(t_info *info, char *dir_name);
void				ft_sorting(t_info *info);
void				ft_input(t_info *info);
void				ft_input_list(t_info *info, char *dir_name, int g);
void				ft_list(t_stat buf, t_info *info, char *file_name, char *d);
void				ft_link(char *f_n, char *d);
void				ft_run_up(DIR *ddir, t_info *info, char *dir_name);
void				ft_uid(t_stat buf, int form_col2);
void				ft_chmd(t_stat buf);
void				ft_write_time(t_stat buf);
void				ft_write_size(t_stat buf, int form_col3);
void				ft_show_pic(void);
void				ft_sort_alph_dir(t_info *info);
void				ft_sort_alph(t_info *info);
void				ft_sort_time_dir(t_info *s);
void				ft_print_dir_name(char *d_name);
void				ft_times(t_stat buf);
void				ft_rec(t_info *info, char *dir_name);
void				ft_std_input(t_info *info, char *dir_name, int g);
void				ft_std_run_up(DIR *ddir, t_info *info, char *dir_name);
void				ft_form(t_info *info);
void				ft_free_list(t_info *info);
void				ft_file_type(int st_mode);
void				ft_input_elem(t_stat buf, char *f_n);
void				ft_gid(t_stat buf, int form_col2);
void				ft_extended_attributes(char *f_n, char *d_n);
void				ft_ex_write(char *f_n, char *d_n);
void				ft_fail(t_info *s);

#endif
