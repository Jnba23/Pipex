/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:54:41 by asayad            #+#    #+#             */
/*   Updated: 2024/06/07 12:47:00 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

int	ft_strlen_gnl(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr(char *s, char c)
{
	int	i;
	int	l;

	i = 0;
	if (!s)
		return (-2);
	l = ft_strlen_gnl(s);
	while (*(s + i))
	{
		if (*(s + i) == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strdup(char *s, int i)
{
	char	*r;
	int		j;

	if (!s)
		return (NULL);
	j = 0;
	r = malloc(i + 2);
	if (!r)
		return (NULL);
	while (j <= i)
	{
		r[j] = s[j];
		j++;
	}
	r[j] = '\0';
	return (r);
}

char	*ft_substr(char *s, int start)
{
	char	*d;
	int		i;
	int		l;

	i = 0;
	l = ft_strlen_gnl(s);
	if (!s)
		return (NULL);
	if (start >= l)
		return (ft_strdup("", 0));
	d = malloc(l - start + 1);
	if (!d)
		return (NULL);
	while (i < l - start)
	{
		d[i] = s[start + i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

char	*make_stash(char *line_read)
{
	char	*stash;
	int		i;

	stash = NULL;
	if (!line_read)
		return (NULL);
	i = ft_strchr(line_read, '\n');
	if (i >= 0)
		stash = ft_substr(line_read, i + 1);
	free(line_read);
	line_read = NULL;
	return (stash);
}
