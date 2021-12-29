#include "../../inc/minishell.h"


void	ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	ft_strncmp2(const char *s1, const char *s2, size_t n)
{
	size_t			i;

	i = 0;
	// printf("nn %s == %s\n", s1, s2);
	while (i < n && ((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
		i++;
	// printf("nn %d\n", ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

int	ft_strrcmp2(const char *s1, const char *s2, size_t n)
{
	size_t			i;

	i = n;
	// printf("rr %s == %s\n", s1, s2);
	while (*(unsigned char *)s1)
		s1++;
	while (i && (*(unsigned char *)s1 == ((unsigned char *)s2)[i]))
	{
		s1--;
		i--;
	}
	// printf("rr %c, %c\n", ((unsigned char *)s1)[i], ((unsigned char *)s2)[i]);
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
