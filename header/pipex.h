/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:30:15 by shinckel          #+#    #+#             */
/*   Updated: 2023/06/14 15:46:28 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
/* write, close, pipe, access, read, dup, dup2, execve, fork */
/* pid_t datatype it is defined in <sys/types.h> */
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

/* malloc, free, exit */
# include <stdlib.h>

/* open, unlink */
# include <fcntl.h>

/* waitpid, wait */
# include <sys/wait.h>

/* strerror, perror */
# include <string.h>
# include <stdio.h>
# include <errno.h>

/* libft functions */
# include "../libft/header/libft.h"

/* "e" stands for special ANSI codes */
# define SUCCESS "\e[1;42m Success \e[0m \n"
# define ERR_INFILE "\e[1;41m Infile \e[0m"
# define ERR_OUTFILE "\e[1;41m Outfile \e[0m"
# define ERR_INPUT "\e[1;41m Invalid number of arguments \e[0m \n"
# define ERR_PIPE "\e[1;41m Pipe \e[0m"
# define ERR_1CMD "\e[1;41m First command not found \e[0m \n"
# define ERR_2CMD "\e[1;41m Second command not found \e[0m \n"

// pipe() will save its array of fd's here -> int fd[2]

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];
	int		infile;
	int		outfile;
	int		status1;
	int		status2;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}t_pipex;

/* find path */
char	*find_path(char **envp, t_pipex *pipex, char *cmd);
/* create and close pipe */
int		create_pipe(char **argv, char **envp, t_pipex *pipex);
/* childs */
void	first_child(char **argv, char **envp, t_pipex *pipex);
void	second_child(char **argv, char **envp, t_pipex *pipex);
/* free */
// void	child_free(t_pipex *pipex);
void	cmd_free(char **cmd);
/* error */
void	msg_error(char *err);

#endif