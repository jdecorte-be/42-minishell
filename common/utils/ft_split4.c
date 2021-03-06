/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:52:33 by lyaiche           #+#    #+#             */
/*   Updated: 2022/04/25 15:39:54 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static size_t	ft_count_words(char *str, char *set)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] && ft_strchr(set, str[i]) && ++count)
			while (str[i] && ft_strchr(set, str[i]))
				i++;
		else if (str[i] && !ft_strchr(set, str[i]) && ++count)
		{
			while (str[i] && !ft_strchr(set, str[i]))
			{
				while (str[i] && ft_strchr("\'\"", str[i]))
					ft_creat_tab2(str, &i, 0, 1);
				while (str[i] && !ft_strchr(set, str[i])
					&& !ft_strchr("\'\"", str[i]))
					i++;
			}
		}
	}
	return (count);
}

static void	ft_creat_tab_2(char *str, size_t *end, char *set)
{
	while (str[*end] && ft_strchr("\'\"", str[*end]))
		ft_skip_q(str, end);
	while (str[*end] && !ft_strchr(set, str[*end])
		&& !ft_strchr("\'\"", str[*end]))
		(*end)++;
}

static char	**ft_creat_tab(char **tab, char *str, char *set, size_t word)
{
	size_t	i;
	size_t	start;
	size_t	end;

	i = 0;
	end = 0;
	while (i < word)
	{
		start = end;
		if (str[end] && ft_strchr(set, str[end]))
			while (str[end] && ft_strchr(set, str[end]))
				end++;
		else if (str[end] && !ft_strchr(set, str[end]))
		{
			while (str[end] && !ft_strchr(set, str[end]))
				ft_creat_tab_2(str, &end, set);
		}
		tab[i++] = ft_substr(str, start, end - start);
	}
	return (tab);
}

char	**ft_split4(char *str, char *set)
{
	char	**tab;
	size_t	word;

	if (!str && !*str)
		return (0);
	word = ft_count_words(str, set);
	tab = ft_calloc(sizeof(char *), word + 1);
	if (!tab)
		ft_error(2);
	tab = ft_creat_tab(tab, str, set, word);
	return (tab);
}
