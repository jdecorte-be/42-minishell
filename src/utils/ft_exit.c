/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdecorte42 <jdecorte42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:09:50 by lyaiche           #+#    #+#             */
/*   Updated: 2022/04/15 14:34:01 by jdecorte42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_exit(int numerror)
{
	free(g_data);
	tcsetattr(0, TCSANOW, &g_data->new);
	exit(numerror);
}
