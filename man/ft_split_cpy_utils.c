/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cpy_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 21:15:57 by asayad            #+#    #+#             */
/*   Updated: 2024/06/06 15:33:51 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	f_strchr(char *s, char c, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		if (s[i++] == c)
			return (1);
	}
	return (0);
}

int	search_double_charachter_lenght(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i++] == c)
		{
			while (s[i] != c && s[i++])
				j++;
			break ;
		}
	}
	return (j);
}
