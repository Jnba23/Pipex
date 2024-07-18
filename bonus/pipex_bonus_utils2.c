/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:51:22 by asayad            #+#    #+#             */
/*   Updated: 2024/06/21 23:59:25 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	file_opening_b(int ac, t_fds *fds, char **av)
{
	fds->here_doc = FALSE;
	if (!ft_strncmp_b("here_doc", av[1], ft_strlen_b(av[1])))
		here_doc_files(ac, fds, av);
	else
	{
		fds->fd_in_out[0] = open(av[1], O_RDONLY);
		if (fds->fd_in_out[0] == -1)
			return (perror("Error infile "), exit(EXIT_FAILURE));
		fds->fd_in_out[1] = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (fds->fd_in_out[1] == -1)
			return (perror("Error outfile "), exit(EXIT_FAILURE));
	}
	pipes_allocation(fds, ac, av);
}

void	here_doc_files(int ac, t_fds *fds, char **av)
{
	if (ac >= 6)
	{
		fds->fd_in_out[2] = open("Here_doc_in", O_CREAT | O_RDWR | O_TRUNC,
				0644);
		if (fds->fd_in_out[0] == -1)
			return (perror("Error infile "), exit(EXIT_FAILURE));
		fds->fd_in_out[1] = open(av[ac - 1], O_CREAT | O_RDWR | O_APPEND, 0644);
		if (fds->fd_in_out[1] == -1)
			return (perror("Error outfile "), exit(EXIT_FAILURE));
		fds->here_doc = TRUE;
	}
	else
		return (perror("Here doc few args "), exit(EXIT_FAILURE));
}

void	here_doc_b(char *limiter, t_fds *fd, int *i)
{
	char	*gnl;

	while (1)
	{
		gnl = get_next_line(0);
		if (!gnl || (!strncmp(gnl, limiter, ft_strlen_b(gnl) - 1)
				&& ft_strlen_b(gnl) - 1 == ft_strlen_b(limiter)))
			break ;
		write (fd->fd_in_out[2], gnl, ft_strlen_b(gnl));
		free(gnl);
	}
	if (gnl)
		free(gnl);
	close(fd->fd_in_out[2]);
	fd->fd_in_out[0] = open("Here_doc_in", O_RDWR);
	if (fd->fd_in_out[0] == -1)
		return (perror("Error infile "), exit(EXIT_FAILURE));
	unlink("Here_doc_in");
	(*i)++;
}
