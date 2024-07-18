/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:54:01 by asayad            #+#    #+#             */
/*   Updated: 2024/06/07 12:53:36 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	l1;
	size_t	l2;
	char	*r;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	r = malloc(l1 + l2 + 1);
	if (!r)
		return (NULL);
	ft_strlcpy(r, s1, l1 + 1);
	ft_strlcat(r, s2, l1 + l2 + 1);
	return (r);
}
