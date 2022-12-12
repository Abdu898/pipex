/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:19:53 by ashahin           #+#    #+#             */
/*   Updated: 2022/12/04 09:00:42 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf/libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
# include <sys/wait.h>
# include <signal.h>
# include <errno.h>

void	ft_exit_err(int n_ex);
void	ft_error(char *str);
void	ft_error_cmd(char *cmd);
void	check_cmd(char *cmd);
void	ft_free_dp(char	**dp);
char	**ft_getenvp(char **envp, char *name);
char	*ft_getpath(char **envp, char *cmd, char *allcmd);
int		ft_get_cmd(char *cmd);
void	execute(char *cmd, char **envp);
void	child_process(int *pipefd, char **argv, char **envp);
void	parent_process(int *pipefd, char **argv, char **envp);

#endif