#include "builtins.h"

t_list *list_env(char **env)
{
    t_list *lst = malloc(sizeof(t_list));
    int i = 1;

    lst = ft_lstnew(env[0]);
    while(env[i])
    {
        t_list *tmp = ft_lstnew(env[i]);
        ft_lstadd_back(&lst, tmp);
        i++;
    }
    return lst;
}

char				**listtotab(t_list *lst)
{
	t_list      *ptr;
	char		**array;
	char		**ptr2;

	if (!(array = malloc(sizeof(char *) * (ft_lstsize(lst) + 1))))
		return (NULL);
	ptr2 = array;
	ptr = lst;
	while (ptr)
	{
			if (!(*ptr2++ = ft_strdup(ptr->content)))
				return (NULL);
		ptr = ptr->next;
	}
	return (array);
}

