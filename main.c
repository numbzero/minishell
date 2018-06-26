#include "minishell.h"

extern char **environ;

int	main(void)
{
	int		status;
	char	*line;
	char	**args;
	
	status = 1;
	while (status)
	{
		ft_putstr("$> ");
		line = read_line();
		args = split_line(line);
		status = execute(args, environ);
		free(line);
		free(args);
	}
	return (0);
}