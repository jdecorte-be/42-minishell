/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdecorte42 <jdecorte42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:24:56 by lyaiche           #+#    #+#             */
/*   Updated: 2022/05/02 12:21:38 by jdecorte42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	end_setenv(char *c, char *name, char *value, int *offset)
{
	c = (char *)name;
	while (*c && *c != '=')
		++c;
	(g_data->env)[*offset] = malloc((size_t)((int)(c - name) \
		+ ft_strlen(value) + 2));
	if (!((g_data->env)[*offset]))
		ft_exit(-1);
	c = (g_data->env)[*offset];
	while (*name && *c && *c != '=')
	{
		*c = *name++;
		++c;
	}
	*c++ = '=';
	ft_strlcpy(c, value, ft_strlen(value) + 1);
	g_data->offset = *offset;
}

void	dont_exist(int *offset)
{
	static int	alloced;
	int			cnt;
	char		**p;

	p = g_data->env;
	cnt = splitlen(p);
	if (alloced)
	{
		g_data->env = (char **)ft_realloc((char *)g_data->env, \
			(size_t)(sizeof(char *) * (cnt + 2)));
		if (!g_data->env)
			ft_exit(-1);
	}
	else
	{
		alloced = 1;
		p = malloc((size_t)(sizeof(char *) * (cnt + 2)));
		if (!p)
			ft_exit(-1);
		ft_memmove(p, g_data->env, cnt * sizeof(char *));
		g_data->env = p;
	}
	(g_data->env)[cnt + 1] = NULL;
	*offset = cnt;
}

int	my_setenv(char *var)
{
	char		*c;
	int			offset;
	char		*value;
	char		*name;
	char		*tmp;

	name = ft_substr(var, 0, egal_len(var));
	if (var[egal_len(var)] == '=')
		value = ft_substr(var, egal_len(var) + 1, ft_strlen(var));
	else
		value = ft_strdup("");
	c = my_getenv(name, &offset);
	if (c && (ft_strlen(c) >= ft_strlen(value)))
	{
		tmp = value;
		while (*c && *value)
			*c++ = *value++;
		free(tmp);
		return (0);
	}
	else
		dont_exist(&offset);
	end_setenv(c, name, value, &offset);
	return (0);
}

char	*my_getenv(char *name, int *index)
{
	int		i;
	int		j;
	char	*sub;

	i = -1;
	while (g_data->env[++i])
	{
		j = 0;
		while (g_data->env[i][j] && g_data->env[i][j] != '=')
			j++;
		sub = ft_substr(g_data->env[i], 0, j);
		if (ft_strcmp(sub, name) == 0)
		{
			free(sub);
			if (index != NULL)
				*index = i;
			return (g_data->env[i] + j + 1);
		}
		free(sub);
	}
	return (NULL);
}