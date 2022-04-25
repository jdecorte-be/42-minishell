/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:15:03 by lyaiche           #+#    #+#             */
/*   Updated: 2022/04/25 16:35:24 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	newprompt(int sig)
{
	printf("\n");
	rl_on_new_line();
	rl_redisplay();
}

void	c_handler(int sig)
{
	newprompt(sig);
}

void	c_handler_fork(int sig)
{
	printf("^C\n");
	rl_on_new_line();
}

void	q_handler_fork(int sig)
{
	printf("^\\\n");
	rl_on_new_line();
}

void	here_doc_sig1(int sig)
{
	(void)sig;
	g_data->hd_stop = 1;
}

void	here_doc_sig2(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	exit(0);
}
