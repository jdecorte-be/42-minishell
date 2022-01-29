#include "../../inc/minishell.h"


//  export bon'jour=salut'hello"blabla"dodo*'riri'

char	*ft_add_q_str(char *str, char *line, size_t *end)
{
	int		trig;
	char	c;
	size_t	start;
	char	*s1;
	size_t	i;

	i = 0;
	if (!line[*end])
		return (str);
	start = *end;
	while (line[*end] && !ft_isspace(line[*end]))
		(*end)++;
	s1 = ft_ecrase_q(ft_substr(line, start, *end - start));
	while (s1[i] && !ft_isspace(s1[i]) && s1[i] != '=')
		i++;
	if (s1[i] == '=')
	{
		i++;
	// printf("s1 == %s\n", s1);
		str = ft_strjoin2(str, ft_substr(s1, 0, i));
		str = ft_quajoin(str, "\"", s1 + i, "\"");
	}
	return (str);
	// trig = 0;
	// c = 0;
	// while (line[*end])
	// {
	// 	start = *end;
	// 	while (line[*end] && line[*end] != '=')
	// 	{
	// 		if (line[*end] && !ft_isspace(line[*end]) && ft_strchr("\'\"", line[*end]) && c != 0)
	// 		{
	// 			c = 0;
	// 			(*end)++;
	// 		}
	// 		else if (line[*end] && !ft_isspace(line[*end]) && ft_strchr("\'\"", line[*end]) && c == 0)
	// 		{
	// 			c = line[(*end)++];
	// 		}
	// 		else
	// 			(*end)++;
	// 	}
	// 	// if (c == 0)
	// 	// {
	// 	str = ft_strjoin1(str, ft_substr(line, start, *end - start + 1));
	// 	start = *end;
	// 		// printf("2 str = %s\n", str);
	// 	// }
	// 	if (line[*end] && line[*end] == '=' && ++(*end))
	// 	{
	// 		start = *end;
	// 		while (line[*end] && (!ft_isspace(line[*end]) || c))
	// 		{
	// 			if (c != 0)
	// 			{
	// 				while (line[*end] && line[*end] != c)
	// 				{
	// 					(*end)++;
	// 				}
	// 				if (line[*end])
	// 				{
	// 					(*end)++;
	// 					c = 0;
	// 				}
	// 				str = ft_strjoin1(str, ft_substr(line, start, *end - start));
	// 				start = *end;
	// 			}
	// 			else if (line[*end] && !ft_isspace(line[*end]) && c == 0)
	// 			{
	// 				while (line[*end] && !ft_isspace(line[*end]) && !ft_strchr("\'\"", line[*end]) && c == 0)
	// 				{
	// 					(*end)++;
	// 				}
	// 				if (*end != start)
	// 				{
	// 					str = ft_quajoin(str, "\"", ft_substr(line, start, *end - start), "\"");
	// 					start = *end;
	// 					// printf("3 str = %s\n", str);
	// 				}
	// 				if (line[*end] && ft_strchr("\'\"", line[*end]))
	// 				{
	// 					c = line[(*end)++];
	// 				}
	// 			}
	// 			// else
	// 			// 	i++;
	// 		}
	// 	}
		
		
	// }
	// // printf("4 str = %s\n", str);
	// return (str);
}

char	*ft_add_q_dollar(char *line)
{
	size_t	end;
	size_t	start;
	char	*str;
	int		trig;
	char	c;

	if (!line)
		return (line);
	trig = 0;
	end = 0;
	str = 0;
	while (line[end])
	{
		start = end;
		if (!ft_strncmp(line + end, "export ", 6))
		{
			// printf("a = %s\n", str);
			end = ft_next_word(line, end);
			str = ft_strjoin1(str, ft_substr(line, start, end - start));
			str = ft_add_q_str(str, line, &end);
			end = ft_next_cmd(line, end);
			// printf("5 str = %s\n", str);
			// while (line[end] && !ft_isspace(line[end]))
			// {
			// 	while (line[end] && !ft_isspace(line[end] && !ft_strchr("\'\"", line[end]) && line[end] != '=' && trig != 1)
			// 		end++;
			// 	if (line[end] && !ft_isspace(line[end]) && ft_strchr("\'\"", line[end]))
			// 	{
			// 		c = line[end++];
			// 		while (line[end] && !ft_isspace(line[end]) && line[end] != c)
			// 		{
			// 			if (line[end] == '=')
			// 				trig = 1;
			// 			end++;
			// 		}
			// 	}
			// 	if (line[end] && !ft_isspace(line[end]) && line[end] == '=')
			// 		trig = 1;
			// }
			//pas fini, penser a faire --> export da'da=$ad'$a* ----> export dada="$ad<arg $a>*"
			
			// printf("add_q = %s\n", line + end);
			// printf("export found\n");
			// break;
		}
		else
		{
			end = ft_next_cmd(line, end);
			str = ft_strjoin1(str, ft_substr(line, start, end - start));
		}
		// printf("end %zu\n", end);
		// printf("1 str = %s\n", str);
			// end = ft_next_word(line, end);
	}
	// printf("str == %s\n", str);
	return (str);
}






/*

-> export hello=""

*/