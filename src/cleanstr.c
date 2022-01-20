#include "../inc/minishell.h"

char    *ft_ecrase_q(char *word)
{
	char	*new_word;
	size_t	i;
	size_t	start;
	size_t	end;
	char	c;

	if (!word)
		return (0);
	i = 0;
	end = 0;
	new_word = 0;
	while (word[end])
	{
		c = 0;
		start = end;
		if (word[end] && ft_strchr("\'\"", word[end]))
		{
			c = word[end++];
			start = end;
			while (word[end] && word[end] != c)
				end++;
			new_word = ft_strjoin1(new_word, ft_substr(word, start, end - start));
			if (word[end])
				end++;
		}
		else
		{
			while (word[end] && !ft_strchr("\'\"", word[end]))
				end++;
 			new_word = ft_strjoin1(new_word, ft_substr(word, start, end - start));
		}
	}
	return (new_word);
}

char *tokenize(char *line)
{
	size_t i = 0;

	if (!line)
		return NULL;
	char *res = ft_ecrase_q(ft_strjoin(ft_strjoin(" ", line), " "));
	while(res[i])
	{
		if (((res[i] == '&' && res[i + 1] == '&') || (res[i] == '|' && res[i + 1] == '|')) && res[i + 2] && res[i - 1])
		{
			res[i + 2] = 1;
			res[i - 1] = 1;
		}
		else if((res[i] == '>' || res[i] == '<') || (res[i] == '(' || res[i] == ')'))
		{
			res[i + 1] = 1;
			res[i - 1] = 1;
		}
		i++;
	}

	return res;
}
