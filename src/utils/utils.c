#include "../../inc/minishell.h"

int	ft_free(char *line)
{
	free(line);
	return (1);
}

int	ft_str_isspace(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (!str[i])
		return (1);
	return (0);
}

int	ft_exist(char *str, size_t len)
{
	size_t	i;

	i = 0;
	while (str[i] && i < len)
		i++;
	if (i == len)
		return (1);
	return (0);
}

char	*ft_lstmerge(t_list *lst)
{
	char	*str;

	if (!lst)
		return (0);
	str = 0;
	while (lst)
	{
		str = ft_trijoin(str, lst->content, " ");
		lst = lst->next;
	}
	return (str);
}
