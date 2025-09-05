
#include "../minishell.h"

void    copy_env(t_shell *s, char **env)
{
    int i;

    i = 0;
    s->environment = NULL;
    while (env[i])
    {
        ft_lstadd_back(&s->environment, ft_lstnew(env[i]));
        i++;
    }
    s->environment_num = i;
}