/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:58:41 by blakehal          #+#    #+#             */
/*   Updated: 2023/03/12 14:50:33 by blakehal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "../libft/libft.h"

# define ARG_ERROR		"Invalid parameters:"
# define PIPE_MODEL		"./pipex file1 cmd1 cmd2 file2"
# define FORK_ERROR		"Fork error"
# define EXEC_ERROR		"Execution Error"
# define PATH_PREFIX	"PATH="

typedef struct s_pip
{
	int		**pipe;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
	char	*env_path;
	int		*pid;
	int		infile;
	int		outfile;
	int		index;
	int		nb_cmd;
	int		argc;
	char	**argv;
	char	**split_parsing;
}	t_pipe;

// files_utils
void	create_pipes(t_pipe *p);
void	close_pipes(t_pipe *p);
char	*find_path(char **env);
int		check_right(t_pipe *pipex);
int		check_cmd_without_env_path(t_pipe *pipex, char *cmd);

// free_utils
void	parent_free(t_pipe *p);
void	ft_close(int *fd);
void	ft_exit(t_pipe *pipex, char *str);
void	ft_close_everything(t_pipe *pipex);
int		pipex_split_parsing(t_pipe *pipex, int i);

// parsing
int		parsing_error_cmd(t_pipe *pipex);

// process
void	process(t_pipe *pipex, char **env);
void	ft_free_split(char **to_free);

//process_utils
char	*get_cmd(char **path, char *cmd, t_pipe *pipex);

#endif 