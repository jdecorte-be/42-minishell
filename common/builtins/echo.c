/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:22:28 by lyaiche           #+#    #+#             */
/*   Updated: 2022/04/25 15:39:54 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	echo_2(char **cmd, int *i, int *option)
{
	int	j;

	while (cmd[*i] && cmd[*i][0] == '-')
	{
		j = 1;
		while (cmd[*i][j] && cmd[*i][j] == 'n')
			j++;
		if (cmd[*i][j] == '\0')
		{
			*i += 1;
			*option = 1;
		}
		else
			break ;
	}
}

int	echo(char **cmd)
{
	int	i;
	int	option;

	i = 1;
	option = 0;
	if (!cmd[1])
	{
		ft_putstr_fd("\n", 1);
		return (0);
	}
	echo_2(cmd, &i, &option);
	while (cmd[i])
	{
		ft_putstr_fd(cmd[i], 1);
		if (cmd[i + 1])
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (option == 0)
		ft_putstr_fd("\n", 1);
	return (0);
}
