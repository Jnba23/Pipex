/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:30:54 by asayad            #+#    #+#             */
/*   Updated: 2024/06/22 14:18:38 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	pipes_allocation(t_fds *fds, int ac, char **av)
{
	int	i;

	fds->pipe_n = 0;
	fds->pipe_index = 0;
	i = 0;
	if (ac >= 6 && !ft_strncmp_b("here_doc", av[1], ft_strlen_b(av[1])))
	{
		fds->pipe_fd = malloc((ac - 5) * sizeof(int *));
		if (!fds->pipe_fd)
			return (perror("Malloc fail "), exit(EXIT_FAILURE));
		pipes_allocation_for_each(fds, ac - 5);
	}
	else
	{
		fds->pipe_fd = malloc((ac - 4) * sizeof(int *));
		if (!fds->pipe_fd)
			return (perror("Malloc fail "), exit(EXIT_FAILURE));
		pipes_allocation_for_each(fds, ac - 4);
	}
}

void	pipes_allocation_for_each(t_fds *fds, int pipes_n)
{
	int	i;

	i = 0;
	fds->size = pipes_n;
	while (pipes_n)
	{
		fds->pipe_fd[i] = malloc(2 * sizeof(int));
		if (!fds->pipe_fd[i])
			return (pipe_allocfail(fds->pipe_fd, i), perror("Malloc fail "),
				exit(EXIT_FAILURE));
		pipes_n--;
		i++;
	}
}

void	open_pipes(t_fds *fds)
{
	int	i;

	i = 0;
	while (i < fds->size)
	{
		if (pipe(fds->pipe_fd[i]) == -1)
		{
			perror("Pipe error ");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	close_pipes(t_fds *fds)
{
	int	i;

	i = 0;
	while (i < fds->size)
	{
		close(fds->pipe_fd[i][0]);
		close(fds->pipe_fd[i][1]);
		i++;
	}
	free_pipes(fds);
}

void	pipe_allocfail(int **ar, int k)
{
	int	i;

	i = 0;
	while (i < k)
	{
		free(ar[i]);
		i++;
	}
	free(ar);
}
