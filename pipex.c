/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:16:57 by ashahin           #+#    #+#             */
/*   Updated: 2022/12/04 09:00:29 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute(char *cmd, char **envp)
{
	char	**cmd_args;
	char	*path;
	int		exec;

	cmd_args = ft_split(cmd, ' ');
	path = ft_getpath(envp, cmd_args[0], cmd);
	exec = execve(path, cmd_args, envp);
	ft_free_dp(cmd_args);
	free(path);
	if (exec == -1)
		ft_error_cmd(cmd);
}

void	child_process(int *pipefd, char **argv, char **envp)
{
	int	fd;

	fd = open(argv[1], O_RDONLY, 0777);
	if (fd == -1)
	{
		ft_error(argv[1]);
		exit(0);
	}
	if (dup2(fd, STDIN_FILENO) < 0)
		ft_exit_err(2);
	if (dup2(pipefd[1], STDOUT_FILENO) < 0)
		ft_exit_err(2);
	close(pipefd[0]);
	close(fd);
	close(pipefd[1]);
	check_cmd(argv[2]);
	execute(argv[2], envp);
}

void	parent_process(int *pipefd, char **argv, char **envp)
{
	int	fd;

	wait(NULL);
	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
	{
		ft_error(argv[4]);
		exit(1);
	}
	if (dup2(fd, STDOUT_FILENO) < 0)
		ft_exit_err(2);
	if (dup2(pipefd[0], STDIN_FILENO) < 0)
		ft_exit_err(2);
	close(pipefd[1]);
	close(fd);
	close(pipefd[0]);
	check_cmd(argv[3]);
	execute(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int	pid;
	int	pipefd[2];

	if (argc != 5)
		ft_exit_err(1);
	if (pipe(pipefd) == -1)
	{
		perror("Error: pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("ERROR: fork");
		exit(EXIT_FAILURE);
	}
	else if (!pid)
		child_process(pipefd, argv, envp);
	else
		parent_process(pipefd, argv, envp);
	return (0);
}
