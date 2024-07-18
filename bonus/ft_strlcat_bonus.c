/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:15:08 by asayad            #+#    #+#             */
/*   Updated: 2024/06/07 11:32:23 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

size_t	ft_strlcat_b(char *dst, char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	j;
	size_t	slen;

	dlen = 0;
	slen = 0;
	j = 0;
	if (dst == NULL && dstsize == 0)
		return (ft_strlen_b(src));
	while (dst[dlen])
		dlen++;
	while (src[slen])
		slen++;
	if (dlen >= dstsize)
		return (dstsize + slen);
	while (j < dstsize - dlen - 1 && src[j])
	{
		dst[dlen + j] = src[j];
		j++;
	}
	dst[dlen + j] = '\0';
	return (dlen + slen);
}
