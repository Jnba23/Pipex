/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:27:42 by asayad            #+#    #+#             */
/*   Updated: 2025/12/26 01:04:14 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// # include "libc.h" 
# include <sys/wait.h>
# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct input
{
	char	**splitted_paths;
	char	**path_slash;
	char	**cmd_nd_flags;
	int		paths_count;
	char	**environ;
	char	**args;
	int		ac;
}	t_input;

typedef struct fds
{
	int	fd_in_out[2];
	int	pipe_fd[2];
}	t_fds;

/* split funcs */

int			f_strchr(char *s, char c, int length);
int			search_double_charachter_lenght(const char *s, char c);

/* Pipex man funcs */

void		pre_execution(t_input *paths, char **environ, char **av, int ac);
void		ft_pipe(t_fds *fds);
void		file_opening(int ac, int *fd, char **av);
void		family_processes(t_input *paths, t_fds *fds, int *i);
void		child_process(t_input *paths, t_fds *fds, int *i);
void		execute_command(char *arg, t_input *paths, char **environ);
int			check_cmd_binary(char *arg, t_input *paths);
char		**ft_split(char *s, char c);
char		**ft_split_cpy(char *s, char c);
size_t		ft_strlcpy(char *dst, char *src, size_t dstsize);
void		paths_slash(t_input *paths);
int			ft_strncmp(char *s1, char *s2, size_t n);
size_t		ft_strlcat(char *dst, char *src, size_t dstsize);
size_t		ft_strlcpy(char *dst, char *src, size_t dstsize);
char		*ft_strjoin(char *s1, char *s2);
void		free_arr(char **arr);
void		intialize_paths(t_input *paths, char **environ, char **av, int ac);
size_t		ft_strlen(char *s);
int			return_fail(int i, int pid);
void		search_path(t_input *paths, char **environ);

#endif
