/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:44:42 by asayad            #+#    #+#             */
/*   Updated: 2024/06/13 23:40:06 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	execute_command_b(char *arg, t_input *paths, char **environ)
{
	(void)environ;
	if (arg[0] == '/' || arg[0] == '.')
	{
		paths->cmd_nd_flags = ft_split_cpy_b(arg, ' ');
		if (!paths->cmd_nd_flags)
			return (perror("Malloc error "), exit(EXIT_FAILURE));
		if ((execve(paths->cmd_nd_flags[0], paths->cmd_nd_flags, NULL)) == -1)
			return (free_arr_b(paths->cmd_nd_flags),
				free_arr_b(paths->path_slash),
				free_arr_b(paths->splitted_paths),
				perror(". or / exec error "),
				exit(EXIT_FAILURE));
	}
	else
	{
		if (check_cmd_binary_b(arg, paths) == 1)
			return (perror("Binary error "), exit(EXIT_FAILURE));
	}
}

void	paths_slash_b(t_input *paths)
{
	int		i;

	i = 0;
	paths->path_slash = malloc((paths->paths_count + 1) * sizeof(char *));
	if (!paths->path_slash)
		return (perror("Malloc error "), exit(EXIT_FAILURE));
	while (paths->splitted_paths[i])
	{
		paths->path_slash[i] = ft_strjoin_b(paths->splitted_paths[i], "/");
		if (!paths->path_slash[i])
			return (perror("Malloc error "), exit(EXIT_FAILURE));
		i++;
	}
	paths->path_slash[i] = NULL;
}

int	check_cmd_binary_b(char *arg, t_input *paths)
{
	int		i;
	char	**cmd;
	char	*full_cmd_path;
	int		flag;

	flag = 0;
	i = 0;
	cmd = ft_split_cpy_b(arg, ' ');
	while (paths->path_slash[i])
	{
		full_cmd_path = ft_strjoin_b(paths->path_slash[i], cmd[0]);
		if (execve(full_cmd_path, cmd, NULL) == -1)
			flag = 1;
		free(full_cmd_path);
		i++;
	}
	if (flag == 1)
		return (free_arr_b(paths->path_slash), free_arr_b(cmd),
			free_arr_b(paths->splitted_paths),
			perror("Error exec cmd "), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	intialize_paths_b(t_input *paths, char **environ, char **av)
{
	int	i;

	search_path_b(paths, environ);
	i = 0;
	paths->paths_count = 0;
	while (paths->splitted_paths[i++])
		paths->paths_count++;
	paths->cmd_nd_flags = NULL;
	paths->path_slash = NULL;
	paths->environ = environ;
	paths->args = av;
}

void	search_path_b(t_input *paths, char **environ)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (environ[i])
	{
		if (ft_strncmp_b(environ[i], "PATH=", 5) == 0)
		{
			flag = 0;
			paths->splitted_paths = ft_split_b(environ[i] + 5, ':');
			if (!paths->splitted_paths)
				return (perror("Malloc error"), exit(EXIT_FAILURE));
		}
		i++;
	}
	if (flag == 1)
		return (perror("PATH variable not found !\n"), exit(EXIT_FAILURE));
}
