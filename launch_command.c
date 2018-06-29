#include "minishell.h"

int	launch_command(char *command, char **args, char **envp)
{
	pid_t	child_pid;
	int		stat;

	child_pid = fork();
	if (child_pid == 0)
	{
		execve(command, args, envp);
		exit(1);
	}
	else
	{
		waitpid(child_pid, &stat, WUNTRACED);
		while (!WIFEXITED(stat) && !WIFSIGNALED(stat));
	}	
	return (1);
}
