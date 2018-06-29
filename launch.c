#include "minishell.h"

/*
static void	check(char **paths, char *bin)
{
	for (int i = 0; paths[i] != NULL; i++)
		printf("\t\tpath[%d] = %s/\%s\n", i , paths[i], bin);
}*/

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

static char	*get_right_path(char *bin,char **paths)
{
	char	*right_path;
	int		i;

	//right_path = NULL;
	i = 0;
	while (paths[i] != NULL)
	{
		right_path = ft_strjoin(ft_strjoin(paths[i], "/"), bin);
		if (is_file(right_path))
			return (right_path);
		i++;
	}
	return (NULL);
}

int			launch(char **args, char **envp)
{
	char	**paths;
	char	*path;
	char	*command;
	int 	status;

	status = 1;	
	path = get_value_variable("PATH", envp);
	paths = ft_strsplit((path + 5), ':');
	//check(paths, args[0]);
	if (is_file(args[0]))
		command = strdup(args[0]);
	else
		command = get_right_path(args[0], paths);
	//printf("\tcommand => %s\n", command);
	if (command == NULL)
		printf("-minishell: %s: command not found\n", args[0]);
	else
		status = launch_command(command, args, envp);
	free(paths);
	free(path);
	free(command);
	return (status);
}
