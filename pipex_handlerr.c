/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_handlerr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 03:21:45 by ashahin           #+#    #+#             */
/*   Updated: 2022/12/04 08:59:42 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit_err(int n_ex)
{
	if (n_ex == 1)
	{
		ft_putstr_fd("./pipex infile cmd1 cmd2 outfile", 2);
		exit(0);
	}
	else if (n_ex == 2)
	{
		perror("Error: dup2");
		exit(EXIT_FAILURE);
	}
}

void	check_cmd(char	*cmd)
{
	int	i;

	if (!cmd[0])
	{
		ft_putstr_fd("pipex: permission denied: \n", 2);
		exit(126);
	}
	i = -1;
	while (cmd[++i])
	{
		if (i == 0 && cmd[i] == ' ')
			break ;
		else if (cmd[i] != ' ')
			return ;
	}
	ft_putstr_fd("pipex: command not found: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd("\n", 2);
	exit(127);
}

void	ft_error_cmd(char *cmd)
{
	ft_putstr_fd("pipex: command not found: ", 2);
	ft_putstr_fd(cmd, 2);
	write(2, "\n", 1);
	exit(127);
}

void	ft_error(char *str)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(str, 2);
	write(2, "\n", 1);
}
