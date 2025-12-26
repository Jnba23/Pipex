/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:51:22 by asayad            #+#    #+#             */
/*   Updated: 2024/06/22 00:02:05 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	file_opening(int ac, int *fd, char **av)
{
	fd[0] = open(av[1], O_RDONLY, 0777);
	if (fd[0] == -1)
		return (perror("Error infile "), exit(EXIT_FAILURE));
	fd[1] = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (fd[1] == -1)
		return (perror("Error outfile "), exit(EXIT_FAILURE));
}

void	family_processes(t_input *paths, t_fds *fds, int *i)
{
	pid_t	pid;

	pid = 0;
	pid = fork();
	return_fail(1, pid);
	if (pid == 0)
		child_process(paths, fds, i);
	else
	{
		if ((*i) == 2)
			close(fds->pipe_fd[1]);
		else
		{
			close(fds->pipe_fd[0]);
			close(fds->fd_in_out[1]);
		}
		(*i)++;
	}
}

void	child_process(t_input *paths, t_fds *fds, int *i)
{
	if (*i == 2)
	{
		close(fds->pipe_fd[0]);
		close(fds->fd_in_out[1]);
		dup2(fds->pipe_fd[1], STDOUT_FILENO);
		close(fds->pipe_fd[1]);
	}
	else
	{
		dup2(fds->pipe_fd[0], STDIN_FILENO);
		close(fds->pipe_fd[0]);
		dup2(fds->fd_in_out[1], STDOUT_FILENO);
		close(fds->fd_in_out[1]);
	}
	execute_command(paths->args[*i], paths, NULL);
}

int	return_fail(int i, int pid)
{
	if (pid == -1)
		return (perror("Fork error "), exit(EXIT_FAILURE), 1);
	if (i == 0)
		return (perror("Not enough or too many arguments \n"),
			EXIT_FAILURE);
	return (0);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
