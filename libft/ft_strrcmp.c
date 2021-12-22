/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu-wu <lxu-wu@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 21:17:38 by lxu-wu            #+#    #+#             */
/*   Updated: 2021/12/22 21:21:31 by lxu-wu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strrcmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;

	i = n;
	while (i && ((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
		i--;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}