/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:27:42 by asayad            #+#    #+#             */
/*   Updated: 2025/12/26 01:05:33 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <sys/wait.h>
# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

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
	int		fd_in_out[3];
	int		**pipe_fd;
	int		pipe_n;
	int		size;
	int		pipe_index;
	bool	here_doc;

}	t_fds;

/* split funcs */

int			f_strchr_b(char *s, char c, int length);
int			search_double_charachter_lenght_b(const char *s, char c);

/* Pipex bonus funcs */
void		pre_execution_b(t_input *paths, char **environ, char **av, int ac);
void		open_pipes(t_fds *fds);
void		close_pipes(t_fds *fds);
void		file_opening_b(int ac, t_fds *fds, char **av);
void		family_processes_b(t_input *paths, t_fds fds, int i, char **av);
void		child_process_b(t_input *paths, t_fds fds, int i, char **av);
void		here_doc_files(int ac, t_fds *fds, char **av);
void		execute_command_b(char *arg, t_input *paths, char **environ);
int			check_cmd_binary_b(char *arg, t_input *paths);
char		**ft_split_b(char *s, char c);
char		**ft_split_cpy_b(char *s, char c);
size_t		ft_strlcpy_b(char *dst, char *src, size_t dstsize);
void		paths_slash_b(t_input *paths);
int			ft_strncmp_b(char *s1, char *s2, size_t n);
size_t		ft_strlcat_b(char *dst, char *src, size_t dstsize);
size_t		ft_strlcpy_b(char *dst, char *src, size_t dstsize);
char		*ft_strjoin_b(char *s1, char *s2);
void		free_arr_b(char **arr);
void		intialize_paths_b(t_input *paths, char **environ, char **av);
void		search_path_b(t_input *paths, char **environ);
size_t		ft_strlen_b(char *s);
void		here_doc_b(char *limiter, t_fds *fd, int *i);
int			return_fail_b(int i, int pid);
void		pipes_allocation(t_fds *fds, int ac, char **av);
void		pipes_allocation_for_each(t_fds *fds, int pipes_n);
void		pipe_allocfail(int **ar, int k);
void		increment(int *i, t_fds *fds, int ac);
void		free_pipes(t_fds *fds);

/* gnl funcs */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int			ft_strlen_gnl(char *s);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strlcpy_gnl(char *s1, char *s2, char *line, int l);
char		*make_line(char *line_read);
char		*get_next_line(int fd);
int			ft_strchr(char *s, char c);
char		*ft_strdup(char *s, int i);
char		*ft_substr(char *s, int start);
char		*make_stash(char *line_read);

#endif
