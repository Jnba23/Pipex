/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:26:25 by asayad            #+#    #+#             */
/*   Updated: 2024/06/14 11:51:53 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	pre_execution_b(t_input *paths, char **environ, char **av, int ac)
{
	paths->ac = ac;
	intialize_paths_b(paths, environ, av);
	paths_slash_b(paths);
}

void	family_processes_b(t_input *paths, t_fds fds, int i, char **av)
{
	pid_t	pid;

	pid = fork();
	return_fail_b(i, pid);
	if (pid == 0)
		child_process_b(paths, fds, i, av);
}

void	child_process_b(t_input *paths, t_fds fds, int i, char **av)
{
	if (i == 2 + fds.here_doc)
	{
		dup2(fds.fd_in_out[0], STDIN_FILENO);
		dup2(fds.pipe_fd[0][1], STDOUT_FILENO);
	}
	else if (i < paths->ac - 2)
	{
		dup2(fds.pipe_fd[fds.pipe_index - 1][0], STDIN_FILENO);
		dup2(fds.pipe_fd[fds.pipe_index][1], STDOUT_FILENO);
	}
	else
	{
		dup2(fds.pipe_fd[fds.pipe_index][0], STDIN_FILENO);
		dup2(fds.fd_in_out[1], STDOUT_FILENO);
	}
	close_pipes(&fds);
	execute_command_b(av[i], paths, NULL);
}

int	return_fail_b(int i, int pid)
{
	if (pid == -1)
		return (perror("Fork error "), exit(EXIT_FAILURE), 1);
	if (i == 0)
		return (perror("Not enough or too many arguments \n"),
			EXIT_FAILURE);
	return (0);
}
