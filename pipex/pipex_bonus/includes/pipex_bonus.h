/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeh_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:58:41 by blakehal          #+#    #+#             */
/*   Updated: 2023/03/05 13:58:42 by blakehal         ###   ########.fr       */
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
	int		pid;
	int		outfile;
	int		index;
	int		err_infile;
	int		err_outfile;
	int		nb_cmd;
}	t_pipe;

typedef enum e_error
{
	FILES,
	PIPES,
	FORK,
	ARGC,
	NONE,
	PARSING,
}	t_error;

typedef enum e_print
{
	YES,
	NO,
}	t_print;

// files_utils
void	create_pipes(t_pipe *p);
void	close_pipes(t_pipe *p);
char	*find_path(char **env);

// free_utils
void	parent_free(t_pipe *p);
void	ft_error_argc(void);
void	ft_exit(t_pipe *pipex, char *str, t_error exit, t_print print);

// parsing
void	parsing_error_cmd(t_pipe *p, int argc, char **argv);

// process
void	process(t_pipe *p, int argc, char **argv, char **env);

#endif 