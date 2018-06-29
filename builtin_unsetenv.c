#include "minishell.h"

int		builtin_unsetenv(char *variable, char **envp)
{
	int		index;
	int		find;
	int		length;

	find = 0;
	index = 0;
	while (envp[index] != NULL)
	{
		if ((strncmp(envp[index], variable, strlen(variable)) == 0) 
			&& envp[index][strlen(variable)] == '=')
		{
			find = 1;
			break;
		}
		index++;
	}
	if (!find)
		return (1);
	length = 0;
	while (envp[length] != NULL)
		length++;
	memset(envp[index], 0, strlen(envp[index]));
	while (index < length - 1)
	{
		envp[index] = strdup(envp[index + 1]);
		memset(envp[index + 1], 0, strlen(envp[index + 1]));
		index++;
	}
	envp[index] = NULL;
	return (1);
}
/*
int		main(int argc, char **argv, char **envp)
{
    char	command[64];
    int		status;
    
    status = 1;
    while (status)
    {
        printf("$> ");
        scanf("%s", command);
        //printf("command => %s\n-------------------\n", command);
        if (strcmp(command, "env") == 0)
        {
            for (int i = 0; envp[i] != NULL; i++)
                //printf("envp[%d] > %s\n", i, envp[i]);
                printf("%s\n", envp[i]);
        }
        else if (strcmp("unsetenv", command) == 0)
        {
            char	variable[16];
            printf("variable --> ");
            scanf("%s", variable);
            printf("\n");
            builtin_unsetenv(variable, envp);
        }
        else if (strcmp("exit", command) == 0)
            status = 0;
        else if (strcmp("clear", command) == 0)
            system("clear");
        else
            printf("-testshell: %s: command not found\n", command);
    }
}*/
