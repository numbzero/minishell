#include "minishell.h"

static char	*get_path(char **envp)
{
	char	*path;
	int		i;

	if (envp[0] == NULL)
		return (NULL);
	path = NULL;
	i = 0;
	while (envp[i] != NULL)
	{
		if (strncmp(envp[i], "PATH", 4) == 0)
			path = strdup(envp[i]);
		i++;
	}
	return (path);
}

static void	check(char **paths, char *bin)
{
	for (int i = 0; paths[i] != NULL; i++)
		printf("\t\tpath[%d] = %s/\%s\n", i , paths[i], bin);
}
/*
static char	*get_right_path(char *bin,char **paths)
{
	
}
*/
int			launch(char **args, char **envp)
{
	char	**paths;
	char	*path;
	char	*comand;
	pid_t	child_pid;
	pid_t	w_pid;
	int		status;

	path = get_path(envp);
	paths = ft_strsplit((path + 5), ':');
	check(paths, args[0]);
	comand = get_right_path(args[0], paths);
	child_pid = fork();
	if (child_pid == 0)
	{
		execve("./minishell", args, NULL);
	}
	else
	{
		w_pid = waitpid(child_pid, &status, WUNTRACED);
		printf("w_pid = %d", w_pid);
	}
	free(paths);
	free(path);
	free(comand);
	return (1);
}
