/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decortejohn <decortejohn@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:25:24 by decortejohn       #+#    #+#             */
/*   Updated: 2022/01/26 14:22:17 by decortejohn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int exec(char *cmd)
{
    char **s_cmd = ft_split(cmd," ");

    if(cmd[0] == '(')
       return subshell(ft_substr(cmd, 1, ft_strlen(cmd) - 2), data);
	else if(ft_strcmp(s_cmd[0], "echo") == 0)
        return echo(s_cmd);
    else if(ft_strcmp(s_cmd[0], "cd") == 0)
        return cd(s_cmd);
    else if(ft_strcmp(s_cmd[0], "pwd") == 0)
        return pwd();
    else if(ft_strcmp(s_cmd[0], "env") == 0)
        return print_env(data->env);
    else if(ft_strcmp(s_cmd[0], "export") == 0)
        return export(s_cmd, data);
    else if(ft_strcmp(s_cmd[0], "unset") == 0)
        return unset(s_cmd, data);
    else if(ft_strcmp(s_cmd[0], "exit") == 0)
        exit_cmd(s_cmd);
	else
		return cmd_sys(cmd);
	return -1;
}

char *get_path(char *cmd)
{
	int i;
	char **args = ft_split(cmd, " ");
	char *exec;
	char **allpath = ft_split(getenv("PATH"), ":");
	i = -1;
	if (access(args[0], X_OK) == 0)
		exec = args[0];
	else
	{
		while (allpath[++i])
		{
			allpath[i] = ft_strjoin(allpath[i], "/");
			exec = ft_strjoin(allpath[i], args[0]);
			free(allpath[i]);
			if (access(exec, F_OK | X_OK) == 0)
				break ;
			free(exec);
		}
	}
	return exec;
}

int cmd_sys(char *cmd)
{
	char **args = ft_split(cmd, " ");
	pid_t	pid;
	int		ret;
	
	
	pid = fork();
	if (pid < 0)
		return errno;
	if (!pid)
	{
		if(data->stdin != 0)
			close(data->stdin);
		if(data->stdout != 1)
			dup2(data->stdout, 1);	
		execve(get_path(cmd), &args[0], data->env);
	}
	else
	{
		if(data->stdout != 1)
			close(data->stdout);
		if(data->stdin != 0)
			dup2(data->stdin, 0);
		waitpid(pid, &ret, 0);
	}
	if(data->stdin != 0)
		close(data->stdin);
	if(data->stdout != 1)
		close(data->stdout);
	return ret;
}

int subshell(char *line, t_data *data)
{
    int ret;

    line = ft_epur_str(ft_chwc(ft_add_q_dollar(ft_chdir(ft_chdollar(ft_pgross_str((line)))))));
	t_token *token = ft_parsing(line);
    ret = execute(token);
	return ret;
}