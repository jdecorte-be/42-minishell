#include "libft/libft.h"
#include <stdio.h>

static int	count_words(char const *s, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	printf("%d words\n", count);
	return (count);
}

static char	*ft_str(char const *s, char c)
{
	int		i;
	char	*ptr;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	ptr = malloc(sizeof(char) * (i + 1));
	if (!(ptr))
	{
		free(ptr);
		return (NULL);
	}
	ft_strlcpy(ptr, s, i + 1);
	return (ptr);
}

static void	ft_free_tab(char **tab)
{
	char	**pos;

	if (tab == NULL)
		return ;
	pos = tab;
	while (*pos != NULL)
		free(*(pos++));
	free(tab);
}

char	**ft_split5(char const *s, char c)
{
	int		i;
	int		strs_len;
	char	**ptr;

	strs_len = count_words(s, c);
	ptr = ft_calloc(sizeof(char *), (strs_len + 1));
	if (!(ptr))
		return (NULL);
	i = -1;
	while (++i < strs_len)
	{
		while (s[0] == c)
			s++;
		ptr[i] = ft_str(s, c);
		if (!(ptr[i]))
		{
			free(ptr);
			return (NULL);
		}
		s += ft_strlen(ptr[i]);
	}
	ptr[i] = 0;
	return (ptr);
}