#include "../inc/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	char	*line;
	char	**tab;


	while (1)
	{
		line = readline("caca->");
		data.line = ft_epur_str(ft_pgross_str(ft_chwc(line)));
		printf("%s|\n", data.line);
		line = 0;
		// data.cmd = ft_creat_cmd(data.line);
		// printf("4\n");
	}

	// int i = 0;
	// tab = ft_split2(line, "\t\f\r\v\n ");
	// while(tab[i])
	// {
	// 	printf("|%s|\n", tab[i]);
	// 	i++;
	// }
	// printf("")
	// system("leaks a.out");
}
