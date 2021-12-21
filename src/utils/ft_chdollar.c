#include "../../inc/minishell.h"

char	*ft_changedollar(char *line, t_list **dollar)
{
	char	*str;

	if (ft_strcmp(line, "$-"))
		str = getenv(line + 1);
	else
		str = "569JNRXZghiklms";
	printf("%s\n", str);
	ft_lstadd_back(dollar, ft_lstnew(str));
	return (str);
}

size_t	ft_chdollar_len(char *line, t_list **dollar)
{
	size_t	i;
	long	count;
	long	start;
	long	end;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (ft_strchr("\'\"", line[i]))
		{
			if (line[i] == '\'' && ++i)
			{
				while (line[i] && line[i] != '\'')
					i++;
				i++;
			}
			else if (line[i] == '\"' && ++i)
			{
					printf("%zu\n", i);
				while (line[i] && line[i] != '\"')
				{
					while (line[i] && line[i] != '\"' && line[i] != '$')
						i++;
					if (line[i] && line[i + 1] && line[i] == '$' && !ft_strchr("\n\f\v\r\t \"+/%^~:.,    …•¶§∞¢£™¡", line[i + 1]))
					{
						start = i++;
						if (line[i++] == '-')
						{
							end = i;
							count += start - end;
							count += ft_strlen(ft_changedollar(ft_substr(line, start, end - start), dollar));
						}
						else
						{
							while (line[i] && !ft_strchr("\"\'+/%^~:.,-", line[i]) && !ft_isspace(line[i]))
								i++;
							end = i;
							count += start - end;
							count += ft_strlen(ft_changedollar(ft_substr(line, start, end - start), dollar));
						}
					}
					else
						i++;
				}
				i++;
			}
		}
		else if (line[i] && line[i + 1] && line[i] == '$' && !ft_strchr("\n\f\v\r\t \"+/%^~:.,   …•¶§∞¢£™¡", line[i + 1]))
		{
			start = i++;
			if (ft_strchr("\'\"", line[i]) && ++i)
				count--;
			else if (line[i] == '-')
			{
				count += -2;
				count += ft_strlen(ft_changedollar(ft_substr(line, start, end - start), dollar));
			}
			else
			{
				while (line[i] && !ft_strchr("\"\'+/%^~:.,-", line[i]) && !ft_isspace(line[i]))
					i++;
				end = i;
				count += start - end;
				count += ft_strlen(ft_changedollar(ft_substr(line, start, end - start), dollar));
			}
		}
		else
			i++;
	}
	return (i + count);
}

char	*ft_chdollar_str(char *str, char *line, t_list *dollar, size_t len)
{
	size_t	i;
	size_t	i2;
	t_list	*tmp;

	i = 0;
	i2 = 0;
	while (line[i])
	{
		if (ft_strchr("\'\"", line[i]))
		{
			if (line[i] == '\'')
			{
				str[i2++] = line[i++];
				while (line[i] && line[i] != '\'')
					str[i2++] = line[i++];
				str[i2++] = line[i++];
			}
			else if (line[i] == '\"')
			{
				str[i2++] = line[i++];
				while (line[i] && line[i] != '\"')
				{
					while (line[i] && line[i] != '\"' && line[i] != '$')
						str[i2++] = line[i++];
					if (line[i] && line[i + 1] && line[i] == '$' && !ft_strchr("\n\f\v\r\t \"\'+/%^~:.,   …•¶§∞¢£™¡", line[i + 1]) && ++i)
					{
						if (line[i++] == '-')
						{
							i2 = ft_strlcat(str, dollar->content, len);
							tmp = dollar;
							dollar = dollar->next;
							free(tmp);
						}
						else
						{
							while (line[i] && !ft_strchr("\"\'+/%^~:.,-", line[i]) && !ft_isspace(line[i]))
								i++;
							i2 = ft_strlcat(str, dollar->content, len);
							tmp = dollar;
							dollar = dollar->next;
							free(tmp);
						}
					}
					else
						str[i2++] = line[i++];
				}
				str[i2++] = line[i++];
			}
		}
		else if (line[i] && line[i + 1] && line[i] == '$' && !ft_strchr("\n\f\v\r\t +/%^~:.,\"\'   …•¶§∞¢£™¡", line[i + 1]) && ++i)
		{
			if (line[i] == '-' && ++i)
			{
				i2 = ft_strlcat(str, dollar->content, len);
				tmp = dollar;
				dollar = dollar->next;
				free(tmp);
			}
			else
			{
				while (line[i] && !ft_strchr("+/%^~:.,-", line[i]) && !ft_isspace(line[i]))
					i++;
				i2 = ft_strlcat(str, dollar->content, len);
				tmp = dollar;
				dollar = dollar->next;
				free(tmp);
			}
		}
		else if (line[i] && line[i] == '$' && line[i + 1] && ft_strchr("\'\"", line[i + 1]))
			i++;
		else
			str[i2++] = line[i++];
	}
	str[i2] = 0;
	return (str);
}

char	*ft_chdollar(char *line)
{
	size_t	len;
	char	*str;
	t_list	*dollar;

	if (!line)
		return (0);
	dollar = 0;
	len = ft_chdollar_len(line, &dollar);
	printf("len = %zu\n", len);
	str = malloc(sizeof(*str) * len + 1);
	str = ft_chdollar_str(str, line, dollar, len);
	printf("line line = %s\n", str);
	return (str);
}