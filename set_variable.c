#include "minishell.h"

void	set_variable(char *variable, char *value, char **envp)
{
	int	find;
	int	index;

	if (variable == NULL)
		return ;
	find = 1;
	index = 0;
	while (envp[index] != NULL)
		if (strncmp(variable, envp[index], strlen(variable) == 0))
			find = index + 1;
	if (find - 1 == 0)
		return ;
	find--;
	free(envp[find]);
	envp[find] = strdup(ft_strjoin((envp[find] + strlen(variable + 1)), value));
	printf("variable => %s\nvalue =>%s\nenvp[%d] => %s\n",
			variable, value, find - 1, envp[find]);
	return ;
}
