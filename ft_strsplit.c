/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstroia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:08:45 by mstroia           #+#    #+#             */
/*   Updated: 2017/12/11 15:28:41 by mstroia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_cword(const char *str, char c)
{
	int	w;
	int	i;

	i = 0;
	w = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c)
			w++;
		i++;
	}
	if (str[0] != '\0')
		w++;
	return (w);
}

static char	*ft_isword(const char *str, char c, int *i)
{
	char	*p;
	int		j;

	if (!(p = (char *)malloc(sizeof(p) * (strlen(str)))))
		return (NULL);
	j = 0;
	while (str[*i] != c && str[*i])
	{
		p[j] = str[*i];
		j++;
		*i += 1;
	}
	p[j] = '\0';
	while (str[*i] == c && str[*i])
		*i += 1;
	return (p);
}

char		**ft_strsplit(const char *str, char c)
{
	int		i;
	int		j;
	int		w;
	char	**p;

	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	w = ft_cword(str, c);
	if (!(p = (char **)malloc(sizeof(p) * (w + 2))))
		return (NULL);
	while (str[i] == c && str[i])
		i++;
	while (j < w && str[i])
	{
		p[j] = ft_isword(str, c, &i);
		j++;
	}
	p[j] = NULL;
	return (p);
}
