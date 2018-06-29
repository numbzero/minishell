#include "minishell.h"

static char	*ft_strjoin(char const *s1, char const *s2)
{
    int		i;
    int		n1;
    int		n2;
    char	*p;
    int		j;
    
    if (!s1 || !s2)
        return (NULL);
    n1 = strlen(s1);
    n2 = strlen(s2);
    p = (char *)malloc(n1 + n2 + 1);
    if (!p)
        return (NULL);
    i = 0;
    while (i < n1)
    {
        p[i] = s1[i];
        i++;
    }
    j = 0;
    while (i < n1 + n2)
        p[i++] = s2[j++];
    p[i] = '\0';
    return (p);
}

int				builtin_setenv(char *variable, char *value, char **envp)
{
	int	find;
	int	index;

	if (variable == NULL)
		return (1);
	find = 1;
	index = 0;
	while (envp[index] != NULL)
	{
		//printf("index - %d\n", index);
		if (strncmp(variable, envp[index], strlen(variable)) == 0)
		{
			//printf("variable -> %s\n", variable);
			//printf("envp[%d] -> %s\n", index, envp[index]);
			find = index + 1;
			//printf("find - %d\n", find);
		}
		index++;
	}
	//printf("(after while) find - %d\n", find);
	if (find - 1 == 0)
		return (1);
	find--;
	//printf("(after decrementation) find - %d\n", find);
	//printf("envp[%d] -> %s\n", find, envp[find]);
	memset(envp[find], 0, strlen(envp[find]));
	//printf("envp[%d] after memset  -> %s\n", find, envp[find]);
	envp[find] = strdup(ft_strjoin(ft_strjoin(variable, "="), value));
	//printf("variable => %s\nvalue =>%s\nenvp[%d] => %s\n",
	//		variable, value, find, envp[find]);
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
		else if (strcmp("setenv", command) == 0)
		{
			char	variable[16];
			char	value[128];
			printf("variable --> ");
			scanf("%s", variable);
			printf("\nvalue --> ");
			scanf("%s", value);
			printf("\n");
			set_variable(variable, value, envp);	
		}
		else if (strcmp("exit", command) == 0)
			status = 0;
		else if (strcmp("clear", command) == 0)
			system("clear");
		else
			printf("-testshell: %s: command not found\n", command);
	}
}*/
