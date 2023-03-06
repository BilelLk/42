/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:58:41 by blakehal          #+#    #+#             */
/*   Updated: 2023/03/06 20:21:19 by blakehal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <sys/wait.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define ARG_ERROR		"Invalid parameters:"
# define PIPE_MODEL		"./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2"
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
	int		infile;
	int		*pid;
	int		outfile;
	int		index;
	int		err_infile;
	int		err_outfile;
	int		nb_cmd;
	int		argc;
	char	**argv;
}	t_pipe;

// files_utils
void	create_pipes(t_pipe *p);
void	close_pipes(t_pipe *p);
char	*find_path(char **env);

// free_utils
void	parent_free(t_pipe *p);
void	ft_close(int *fd);
// void	ft_exit(t_pipe *pipex, char *str, t_error exit, t_print print);
void	ft_exit(t_pipe *pipex, char *str);

// parsing
int	parsing_error_cmd(t_pipe *pipex);

// process
void	process(t_pipe *pipex, char **env);
void	ft_close_everything(t_pipe *pipex);
void	ft_free_split(char **to_free);

#endif 