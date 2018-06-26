#include "minishell.h"

int		launch(char **args)
{
	pid_t	child_pid;
	pid_t	w_pid;
	int		status;

	child_pid = fork();
	if (child_pid == 0)
	{
		execvp(args[0], args);
	}
	else
		w_pid = waitpid(child_pid, &status, WUNTRACED);
	return (1);

}