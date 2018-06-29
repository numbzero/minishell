#include "minishell.h"

char	*get_value_variable(char *variable, char **envp)
{
    char	*var;
    int		i;
    
    if (envp[0] == NULL)
        return (NULL);
    var = NULL;
    i = 0;
    while (envp[i] != NULL)
    {
        if ((strncmp(envp[i], variable, strlen(variable)) == 0) && 
				(envp[i][strlen(variable)] == '='))
            var = strdup(envp[i]);
        i++;
    }
    return (var);
}
