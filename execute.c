#include "minishell.h"

int			execute(char **args, char **envp)
{
	if (args[0] == NULL)
		return (1);
	//if (strcmp(args[0], "cd") == 0)
	//	return (builtin_cd(args, envp));
	if (strcmp(args[0], "env") == 0)
		return (builtin_env(envp));
	// if (strcmp(args[0], "setenv") == 0)
	// 	return (builtin_setenv(args));
	// if (strcmp(args[0], "unsetenv") == 0)
	// 	return (builtin_unsetenv(args, envp));
	if (strcmp(args[0], "exit") == 0)
		return (0);
	return (launch(args, envp));
}
