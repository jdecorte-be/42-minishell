#include "../../inc/minishell.h"


//  export bon'jour=salut'hello"blabla"dodo*'riri'

char	*ft_add_q_str(char *str, char *line, size_t i)
{
	int		trig;
	char	c;
	size_t	start;

	trig = 0;
	c = 0;
	while (line[i])
	{
		start = i;
		while (line[i] && line[i] != '=')
		{
			if (line[i] && !ft_isspace(line[i]) && ft_strchr("\'\"", line[i]) && c != 0)
			{
				c = 0;
				i++;
			}
			else if (line[i] && !ft_isspace(line[i]) && ft_strchr("\'\"", line[i]) && c == 0)
			{
				c = line[i++];
			}
			else
				i++;
		}
		// if (c == 0)
		// {
		str = ft_strjoin1(str, ft_substr(line, start, i - start + 1));
		start = i;
			// printf("2 str = %s\n", str);
		// }
		if (line[i] && line[i] == '=' && ++i)
		{
			start = i;
			while (line[i] && !ft_isspace(line[i]))
			{
				if (c != 0)
				{
					while (line[i] && line[i] != c)
					{
						i++;
					}
					if (line[i])
					{
						i++;
						c = 0;
					}
					str = ft_strjoin1(str, ft_substr(line, start, i - start));
					start = i;
				}
				else if (line[i] && !ft_isspace(line[i]) && c == 0)
				{
					while (line[i] && !ft_isspace(line[i]) && !ft_strchr("\'\"", line[i]) && c == 0)
					{
						i++;
					}
					if (line[i] && ft_strchr("\'\"", line[i]))
					{
						c = line[i];
					}
					else if (i != start)
					{
						str = ft_quajoin(str, "\"", ft_substr(line, start, i - start), "\"");
						start = i;
						// printf("3 str = %s\n", str);
					}
				}
				else
					i++;
			}
		}
		
		
	}
	// printf("4 str = %s\n", str);
	return (str);
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
			str = ft_add_q_str(str, line, end);
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
			break;
		}
		// else
		end = ft_next_cmd(line, end);
		// printf("end %zu\n", end);
		str = ft_strjoin1(str, ft_substr(line, start, end - start));
		// printf("1 str = %s\n", str);
			// end = ft_next_word(line, end);
	}
	// printf("str == %s\n", str);
	return (str);
}






/*

-> export hello=""

*/