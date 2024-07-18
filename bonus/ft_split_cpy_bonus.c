/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cpy_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:24:25 by asayad            #+#    #+#             */
/*   Updated: 2024/06/07 13:22:31 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	countword(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while ((s[i] == c || s[i] == '\t') && s[i])
			i++;
		if (s[i] != '\0')
			j++;
		if (s[i] == '\'')
		{
			i++;
			while (s[i] && s[i] != '\'')
				i++;
		}
		while ((s[i] != c && s[i] != '\t') && s[i])
			i++;
	}
	return (j);
}

static int	charcount(const char *s, char c, int *p)
{
	int	nw;
	int	j;

	nw = 0;
	j = 0;
	while ((s[*p] == c || s[*p] == '\t') && s[*p])
		(*p)++;
	if (s[*p] != '\'')
	{
		while ((s[*p + nw] != c && s[*p + nw] != '\t') && s[*p + nw])
			nw++;
	}
	else
	{
		nw = search_double_charachter_lenght_b(s, '\'');
		(*p)++;
	}
	return (nw);
}

static void	*allocfail(char **ar, int k)
{
	int	i;

	i = 0;
	while (i < k)
	{
		free(ar[i]);
		i++;
	}
	free(ar);
	return (NULL);
}

char	**ft_split_cpy_b(char *s, char c)
{
	int		i;
	char	**ar;
	int		k;

	k = -1;
	i = 0;
	if (!s)
		return (NULL);
	ar = malloc((countword(s, c) + 1) * sizeof(char **));
	if (!ar)
		return (NULL);
	while (++k < countword(s, c))
	{
		ar[k] = malloc((charcount(s, c, &i) + 1) * sizeof(char));
		if (!ar[k])
			return (allocfail(ar, k));
		if (!f_strchr_b(s + i, '\'', charcount(s, c, &i)))
		{
			ft_strlcpy_b(ar[k], s + i, charcount(s, c, &i) + 1);
		}
		else
			ft_strlcpy_b(ar[k], s + i, charcount(s, c, &i));
		i += charcount(s, c, &i);
	}
	return (ar[k] = NULL, ar);
}
