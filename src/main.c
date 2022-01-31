#include "../inc/minishell.h"
#include <errno.h>

int syntax_check(t_token *token)
{
    t_token *tmp = token;
    int is_ope = 1;
    int start = 1;
    int old_ope;

    while(tmp)
    {
        old_ope = is_ope;
        if(what_im(tmp->cmd) == 0)
            is_ope = 0;
        else
            is_ope = 1;
        if((is_ope == old_ope )|| (start == 1 && is_ope == 1))
        {
            data->lastret = 2;
            return 0;
        }
        start = 0;
        tmp = tmp->next;
    }
    return 1;
}


void printlist(t_token *token)
{
    int i = 0;
    while(token)
    {
        printf("%s\n", token->cmd);
        printf("%d\n", token->redirect.infd);
        printf("%d\n", token->redirect.outfd);
        printf("================================================================\n");
    // if (token->sub_token)
    //     token = token->sub_token;
    // else if (token->next)
    //     token = token->next;
    // else if (!token->next && token->sup_token)
    //     token = token->sup_token->next;
    // else
        token = token->next;
    }
}

void shlvlhandler()
{
    char *var = getenv("SHLVL");
    if(var)
    {
        int shlvl = ft_atoi(var) + 1;
        my_setenv(ft_strjoin("SHLVL", ft_itoa(shlvl)));
    }
}

char *prompt()
{
    char    *path = NULL;
    char    *line;

    ft_putstr_fd("\e[0;36m", 1);
    path = getcwd(path, 1024);
    int i = ft_strlen(path);
    while(path[--i] != '/');
    line = ft_strjoin(ft_substr(path, i + 1, ft_strlen(path)),"\e[0;37m ❯ ");
    return line;
}

int	main(int ac, char **av, char **env)
{
    (void)av;
	char	*line;

    if(!(data = malloc(sizeof(t_data))))
        return 0;
    data->lastret = 0;
    data->env = env;
    data->hd = 0;

    
    shlvlhandler();
    my_setenv("_=/usr/bin/env");



    if (ac >= 3 && !ft_strncmp(av[1], "-c", 2))
    {
        char *tmp = ft_strdup(av[2]);
        line = ft_epur_str(ft_chdir(ft_pgross_str((tmp))));
        t_token *token = ft_parsing(line);
        execute(token);
        exit(data->lastret);
    }




    if(ac != 1)
        puterror("\e[0;37mUse", "./minishell without arguments");
    while (1)
    {
        // signal(SIGINT, newprompt);
        line = readline(prompt());
        if (!line)
        {
            ft_putstr_fd("\b\bexit\n", 2);
            exit (0);
        }
        if(*line)
            add_history(line);
    
        line = ft_epur_str(ft_chdir(ft_pgross_str((line))));
        t_token *token = ft_parsing(line);
        if(syntax_check(token) == 0)
            puterror("syntax error near unexpected token", "test");
        else
            execute(token);

        // to delete
    }
        // exit(ret);


}
