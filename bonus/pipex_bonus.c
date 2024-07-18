/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:24:32 by asayad            #+#    #+#             */
/*   Updated: 2024/06/21 23:59:17 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	increment(int *i, t_fds *fds, int ac)
{
	if ((*i) < ac - 3)
		fds->pipe_index++;
	(*i)++;
}

void	close_in_out(t_fds *fds)
{
	close(fds->fd_in_out[0]);
	close(fds->fd_in_out[1]);
}

int	main(int ac, char **av, char **environ)
{
	t_input	paths;
	t_fds	fds;
	int		i;

	i = 2;
	if (ac >= 5)
	{
		pre_execution_b(&paths, environ, av, ac);
		file_opening_b(ac, &fds, av);
		open_pipes(&fds);
		if (ac >= 6 && !ft_strncmp_b("here_doc", av[1], ft_strlen_b(av[1])))
			here_doc_b(av[2], &fds, &i);
		while (i < ac - 1)
		{
			family_processes_b(&paths, fds, i, av);
			increment(&i, &fds, ac);
		}
		close_pipes(&fds);
		close_in_out(&fds);
		while (waitpid(-1, NULL, 0) != -1)
			;
		return (free_arr_b(paths.path_slash), free_arr_b(paths.splitted_paths),
			EXIT_SUCCESS);
	}
	return (return_fail_b(0, 3));
}
