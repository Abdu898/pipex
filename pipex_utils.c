/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:22:47 by ashahin           #+#    #+#             */
/*   Updated: 2022/11/30 07:56:52 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_dp(char	**dp)
{
	int	i;

	i = -1;
	while (dp[++i])
		free(dp[i]);
	free(dp);
}

char	**ft_getenvp(char **envp, char *name)
{
	char	*sub;
	char	**pathes;
	int		i;

	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], name, 5) == 0)
		{
			sub = ft_substr(envp[i], 6, ft_strlen(envp[i]) - 6);
			pathes = ft_split(sub, ':');
			free(sub);
			return (pathes);
		}
	}
	return (NULL);
}

char	*ft_getpath(char **envp, char *cmd, char *allcmd)
{
	char	**pathes;
	int		i;
	char	*tmp;
	char	*path;

	pathes = ft_getenvp(envp, "PATH=");
	if (!pathes)
		ft_error_cmd(allcmd);
	i = -1;
	while (pathes[++i])
	{
		tmp = ft_strjoin(pathes[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, F_OK | X_OK) == 0)
		{
			ft_free_dp(pathes);
			return (path);
		}
		free(path);
	}
	ft_free_dp(pathes);
	return (NULL);
}

int	ft_get_cmd(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i] && cmd[i] != ' ')
		i++;
	return (i);
}
