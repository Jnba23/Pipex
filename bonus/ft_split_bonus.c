/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:24:25 by asayad            #+#    #+#             */
/*   Updated: 2024/06/07 13:23:03 by asayad           ###   ########.fr       */
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
		while (s[i] == c && s[i])
			i++;
		if (s[i] != '\0')
			j++;
		while (s[i] != c && s[i])
			i++;
	}
	return (j);
}

static int	charcount(const char *s, char c, int *p)
{
	int	nw;

	nw = 0;
	while (s[*p] == c && s[*p])
		(*p)++;
	while (s[*p + nw] != c && s[*p + nw])
		nw++;
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

char	**ft_split_b(char *s, char c)
{
	int		i;
	char	**ar;
	int		k;

	k = 0;
	i = 0;
	if (!s)
		return (NULL);
	ar = malloc((countword(s, c) + 1) * sizeof(char **));
	if (!ar)
		return (NULL);
	while (k < countword(s, c))
	{
		ar[k] = malloc((charcount(s, c, &i) + 1) * sizeof(char));
		if (!ar[k])
			return (allocfail(ar, k));
		ft_strlcpy_b(ar[k], s + i, charcount(s, c, &i) + 1);
		k++;
		i += charcount(s, c, &i);
	}
	ar[k] = NULL;
	return (ar);
}
