/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:51:22 by asayad            #+#    #+#             */
/*   Updated: 2024/06/22 14:19:27 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

size_t	ft_strlcpy_b(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[j])
		j++;
	if (dstsize == 0)
		return (j);
	else
	{
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (j);
}

int	ft_strncmp_b(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (*s1 != '\0' || *s2 != '\0'))
	{
		if (*s1 != *s2)
		{
			return ((unsigned char)(*s1) - (unsigned char)(*s2));
		}
		s1++;
		s2++;
		i++;
	}
	return (0);
}

size_t	ft_strlen_b(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	free_arr_b(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	free_pipes(t_fds *fds)
{
	int	i;

	i = 0;
	while (i < fds->size)
		free(fds->pipe_fd[i++]);
	free(fds->pipe_fd);
}
