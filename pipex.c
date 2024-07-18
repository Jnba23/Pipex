/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:31:44 by asayad            #+#    #+#             */
/*   Updated: 2024/06/14 21:04:10 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "stdio.h"

int	main(int ac, char **av, char **environ)
{
	t_input	paths;
	t_fds	fds;
	int		i;

	i = 2;
	if (ac == 5)
	{
		pre_execution(&paths, environ, av, ac);
		file_opening(ac, fds.fd_in_out, av);
		ft_pipe(&fds);
		dup2(fds.fd_in_out[0], STDIN_FILENO);
		close(fds.fd_in_out[0]);
		while (i < ac - 1)
			family_processes(&paths, &fds, &i);
		while (waitpid(-1, NULL, 0) != -1)
			;
		return (free_arr(paths.path_slash), free_arr(paths.splitted_paths),
			EXIT_SUCCESS);
	}
	else
		return (return_fail(0, 3));
}
