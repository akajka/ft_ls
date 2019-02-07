/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 11:45:03 by akorobov          #+#    #+#             */
/*   Updated: 2019/01/04 08:11:30 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	how_many_w(char *s, char c)
{
	int	word;

	word = 0;
	while (*s)
	{
		if (*s != c)
		{
			word++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (word);
}

static int	ft_s(char *s, char c)
{
	int		i;

	i = 0;
	while (*s && *s != c)
	{
		s++;
		i++;
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**new_str;
	int		w;
	int		i;

	if (!s)
		return (NULL);
	w = how_many_w((char *)s, c);
	if (!(new_str = (char**)malloc(sizeof(char*) * (w + 1))))
		return (NULL);
	i = 0;
	*(new_str + w) = 0;
	while (i < w)
	{
		while (*s && *s == c)
			s++;
		*new_str++ = ft_strsub(s, 0, ft_s((char *)s, c));
		while (*s && *s != c)
			s++;
		i++;
	}
	return (new_str - w);
}
