#include "../../inc/minishell.h"

static size_t	ft_count_words(char *str, char *set)
{
	size_t	i;
	size_t	count;
	char	c;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] && ft_strchr(set, str[i]))
			i++;
		if (str[i] && !ft_strchr(set, str[i]) && ++count)
			while (str[i] && !ft_strchr(set, str[i]))
				ft_count_words2(str, &i, set);
	}
	return (count);
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
		while (str[start] && (ft_strchr(set, str[start])
				|| ft_isspace(str[start])))
			start++;
		end = start;
		if (str[start] && !ft_strchr(set, str[start]))
			while (str[end] && !ft_strchr(set, str[end]))
				ft_creat_tab2(str, &end, set, 3);
		tab[i++] = ft_substr(str, start, end - start);
	}
	tab[i] = 0;
	return (tab);
}

char	**ft_split2(char *str, char *set)
{
	char	**tab;
	size_t	word;

	if (!str && !*str)
		return (0);
	word = ft_count_words(str, set);
	tab = malloc(sizeof(char *) * word + 1);
	if (!tab)
		ft_error(2);
	return (ft_creat_tab(tab, str, set, word));
}
