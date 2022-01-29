#include "../../inc/minishell.h"

t_list	*ft_wcsearch(char *line)
{
	size_t	start;
	size_t	end;
	char	c1;
	t_list	*wc;

	end = 0;
	wc = 0;
	while (line[end])
	{
		c1 = 0;
		start = end;
		if (line[end] && ft_strchr("<>", line[end]))
			end = ft_next_word(line, ft_next_word(line, end));
		else if (line[end] && !ft_isspace(line[end]) && !ft_strchr("&|", line[end]))
		{
			while (line[end] && !ft_isspace(line[end]))
			{
				if (line[end] && ft_strchr("\"\'", line[end]))
					ft_creat_tab2(line, &end, 0, 1);
				if (line[end] && line[end] == '*' && ++end)
					c1 = 1;
				else if (line[end])
					end++;
			}
			if (c1 == 1)
				ft_lstadd_back(&wc, ft_lstnew(ft_substr(line, start, end - start)));
		}
		else if (line[end])
			end++;
	}
	return (wc);
}

int	ft_wcmatch(char **wc_tab, char *file)
{
	size_t	i;
	size_t	len;
	char	*woq;

	i = 0;
	if (wc_tab[0][0] != '.' && *file == '.')
		return (0);
	while (wc_tab[i])
	{
		woq = ft_woquote(wc_tab[i]);
		len = ft_strlen(woq);
		// printf("woq == %s && %zu\n", woq, len);

		if (wc_tab[i] && *wc_tab[i] == '*' && ++i)
		{
			// printf("1\n");
			free(woq);
			woq = ft_woquote(wc_tab[i]);
			len = ft_strlen(woq);
			if (wc_tab[i])
			{
				// printf("2\n");
				while (*file && ft_exist(file, len - 1) && ft_strncmp(file, woq, len - 1))
				{
					// printf("file++\n");
					file++;
				}
			}
			else
			{
				// printf("3\n");
				while (*file)
				{
					// printf("file++\n");
					file++;
				}
			}
		}
		else if (*file && wc_tab[i] && wc_tab[i + 1] && ft_exist(file, len - 1) && !ft_strncmp(file, woq, len - 1) && ++i)
		{
			// printf("4\n");
			file += len;
		}
		else if (*file && wc_tab[i] && !wc_tab[i + 1] && ft_exist(file, len - 1) && !ft_strrcmp(file, woq, len) && ++i)
		{
			// printf("5\n");
			while (*file)
				file++;
		}
		else
		{
			free(woq);
			break ;
		}
		free(woq);
	}
	if (!wc_tab[i] && !*file)
		return (1);
	return (0);
}

t_list	*ft_readfile(char *wc, DIR *loc, char mode, char *add)
{
	(void)mode;
	(void)add;
	struct dirent	*file;
	char			**wc_tab;
	t_list			*match;
	size_t			i;

	match = 0;
	wc_tab = ft_split4(wc, "*");
	
	// i = 0;
	// while (wc_tab[i])
	// {
	// 	printf("wc == %s\n", wc_tab[i++]);
	// }


	i = 0;
	file = readdir(loc);
	while (file)
	{
	// 	printf("%s\n", file->d_name);
	// 	if (mode == 1 || mode == 2)
	// 	{
	// 		if (file->d_type == 4)
	// 			if (ft_wcmatch(wc_tab, file->d_name))
	// 				ft_lstadd_back(&match, ft_lstnew(ft_strjoin(file->d_name, add)));
	// 	}
	// 	else
		if (ft_wcmatch(wc_tab, file->d_name))
			ft_lstadd_back(&match, ft_lstnew(ft_strdup(file->d_name)));
				// ft_lstadd_back(&match, ft_lstnew(ft_trijoin("\'", file->d_name, "\'")));
		file = readdir(loc);
	}
	// str = ft_lstmerge(match);
	ft_free_tab(wc_tab);
	ft_sort_word(match);
	// ft_lstclear(&match, free);
	return (match);
}

t_list	*ft_wcfile(char *wc, char *path, char mode, char *add)
{
	DIR				*loc;
	t_list			*match;

	loc = opendir(path);
	if (loc == 0)
		ft_error(5);
	match = ft_readfile(wc, loc, mode, add);
	if (closedir(loc) == -1)
		ft_error(6);
	return (match);
}
