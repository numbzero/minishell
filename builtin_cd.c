#include "minishell.h"

int		builtin_cd(char *directory, char **envp)
{
	int		status;

	if (directory == NULL)
	{
		status = 
			builtin_setenv("OLDPWD", get_value_of_variable(get_value_variable("PWD", envp)), envp);
		status = 
			builtin_setenv("PWD", get_value_of_variable(get_value_variable("HOME", envp)), envp);
		chdir(get_value_of_variable(get_value_variable("HOME", envp)));
		return (1);
	}
	if (is_dir(directory))
	{
		status = builtin_setenv("OLDPWD", get_value_of_variable(get_value_variable("PWD", envp)), envp);
		status = builtin_setenv("PWD", directory, envp);
		chdir(directory);
	}
	else if (is_file(directory))
		printf("-minishell: cd: %s: Not a directory\n", directory);
	else
		printf("-minishell: cd: %s: No such file or directory\n", directory);
	return 1;
}
