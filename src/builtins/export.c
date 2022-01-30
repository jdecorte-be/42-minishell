# include "../../inc/minishell.h"

int checkvalid(char *cmd)
{
    int i = 0;
    while(cmd[i])
    {
        if((ft_isalnum(cmd[i]) == 0 && cmd[i] != '\'' && cmd[i] != '"' && cmd[i] != '_') || ft_isdigit(cmd[0]) == 1 || cmd[0] == '=')
        {
            puterror(cmd, "not a valid identifier");
            data->lastret = 1;
            return 0;
        }
        i++;
    }
    return 1;
}

void export_print()
{
    int len = splitlen(data->env);
    int i = 0;
    while(i < len)
    {
        int j = i + 1;
        while (++j < len)
            if (ft_strcmp(data->env[i], data->env[j]) > 0 && data->env[i] && data->env[j]) {
                char* temp = data->env[i]; 
                data->env[i] = data->env[j]; 
                data->env[j] = temp; 
             }
             if(data->env[i])
                format_env(data->env[i]);
        i++;
    }
}

int export(char **cmd)
{
    if(!cmd[1])
    {
        export_print();
        return 0;
    }
    int i = 1;
    while(cmd[i])
    {
        if(checkvalid(cmd[i]))
            return 0;
        my_setenv(cmd[i]);
        i++;
    }
    data->lastret = 0;
    return 0;
}
