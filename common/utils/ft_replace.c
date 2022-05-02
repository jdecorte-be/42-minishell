/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:52:07 by lyaiche           #+#    #+#             */
/*   Updated: 2022/04/25 15:39:54 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_replace(char *str, char *search, char *replace)
{
	size_t	i;
	size_t	start;
	size_t	end;
	size_t	len;
	char	*ret;

	i = 0;
	end = 0;
	ret = 0;
	while (str[end])
	{
		start = end;
		len = ft_strlen(search);
		if (!ft_strrcmp(str + end, search, len - 1))
		{
			while (str[end] && !ft_strrcmp(str + end, search, len - 1))
				end++;
			ret = ft_strjoin3(ret, ft_substr(str, start, end - start - 1));
		}
		if (str[end] && ft_strrcmp(str + end, search, len - 1))
			ret = ft_strjoin3(ret, replace);
	}
	return (ret);
}