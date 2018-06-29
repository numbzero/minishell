#include "minishell.h"

extern char **environ;

int	main(void)
{
	char	**args;
	char	*line;
	int		status;
	
	status = 1;
	while (status)
	{
		ft_putstr("$> ");
		line = read_line();
		//printf("read_line => %s\n", line);
		args = split_line(line);
		//printf("splited_line:\n");		
		//for (int i = 0; args[i] != NULL; i++)
		//	printf("\t--> word[%d] = %s\n", i, args[i]);
		status = execute(args, environ);
		//printf("status - %d\n", status);
		free(line);
		free(args);
	}
	return (0);
}
