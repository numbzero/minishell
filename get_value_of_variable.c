#include "minishell.h"

char    *get_value_of_variable(char *variable)
{
    int i;
    
    if (!variable)
		return (NULL);
	i = 0;
    while (variable[i] != '=')
        i++;
    return ((variable + i + 1));
}
