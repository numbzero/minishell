#include "minishell.h"

int		execute(char **args, char **envp)
{
	if (args[0] == NULL)
		return (1);
	//if (strcmp(args[0], "cd") == 0)
	//	return (builtin_cd(args, envp));
	// if (strcmp(args[0], "echo") == 0)
	// 	return (builtin_echo(args));
	// if (strcmp(args[0], "setenv") == 0)
	// 	return (builtin_setenv(args));
	// if (strcmp(args[0], "unsetenv") == 0)
	// 	return (builtin_unsetenv(args));
	if (strcmp(args[0], "exit") == 0)
		return (builtin_exit());
	// if (strcmp(args[0], "env") == 0)
	// 	return (builtin_env(args));
	return (launch(args, envp));
}

int		builtin_exit(void)
{
	return (0);
}
/*
int		builtin_cd(char **args, char **envp)
{
	int		i;

	printf("DEBUG builtin_cd\n");
	if (args[1] == NULL)
	{
		i = 0;
		while (envp[i] != NULL)
		{
			printf("%s\n", envp[i]);
			if (strncmp(envp[i], "HOME", 3) == 0)
				chdir((envp[i] + 6));
			i++;
		}
	}
	else
	{
    	if (chdir(args[1]) != 0) {
      		printf("minishell: cd: %s: No such file or directory\n", args[1]);
    	}
    }
	return 1;
}*/
