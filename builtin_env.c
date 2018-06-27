#include "minishell.h"

int		builtin_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
		printf("%s\n", envp[i++]);
	return (1);
}
