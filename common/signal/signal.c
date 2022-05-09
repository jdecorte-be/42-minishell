/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:15:03 by lyaiche           #+#    #+#             */
/*   Updated: 2022/05/09 19:40:15 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	newprompt(int sig)
{
	(void) sig;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	c_handler(int sig)
{
	(void) sig;
	newprompt(sig);
}

void	c_handler_fork(int sig)
{
	(void) sig;
	rl_on_new_line();
}

void	q_handler_fork(int sig)
{
	(void) sig;
	printf("^\\\n");
	rl_on_new_line();
}
