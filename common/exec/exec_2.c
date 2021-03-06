/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu-wu <lxu-wu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:55:04 by lyaiche           #+#    #+#             */
/*   Updated: 2022/05/10 18:53:00 by lxu-wu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	pipex(char *cmd)
{
	pid_t		pid;
	int			ret;
	int			p_fd[2];

	ret = 0;
	pipe(p_fd);
	pid = fork();
	if (pid < 0)
		return (-1);
	if (!pid)
	{
		close(p_fd[0]);
		dup2(p_fd[1], 1);
		ret = exec(cmd);
		exit(ret);
	}
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], 0);
	}
	waitpid(pid, NULL, 0);
	return (ret);
}

int	subshell(char *line)
{
	t_token	*token;

	line = ft_ecrase_p(line);
	if (ft_isprohibited(line) == 1)
	{
		free(line);
		exit (1);
	}
	line = ft_epur_str(((ft_chdir((ft_pgross_str((line)))))));
	token = ft_parsing(line);
	free(line);
	execute(token);
	ft_tokenclean_all(&token);
	return (g_data->lastret);
}

char	*access_path(char **allpath, char **s_cmd, char *cmd)
{
	char	*path_part;
	char	*exec;
	int		i;

	i = -1;
	while (allpath[++i])
	{
		path_part = ft_strjoin(allpath[i], "/");
		exec = ft_strjoin(path_part, s_cmd[0]);
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
			return (exec);
		free(exec);
	}
	return (cmd);
}

char	*get_path(char *cmd)
{
	char	**allpath;
	char	**s_cmd;
	char	*exec;
	char	*ret;

	allpath = ft_split(my_getenv("PATH", NULL), ":");
	if (!allpath)
		return (cmd);
	s_cmd = ft_split2(cmd, " ");
	if (access(s_cmd[0], F_OK | X_OK) == 0)
	{
		ret = s_cmd[0];
		return (ret);
	}
	exec = access_path(allpath, s_cmd, cmd);
	ft_free_tab(allpath);
	ft_free_tab(s_cmd);
	return (exec);
}
