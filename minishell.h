#ifndef	MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>

char		*read_line(void);
void		ft_putstr(char const *s);
void		ft_putchar(char c);
char		**split_line(char *str);
char		*get_word(char *str, int *i);
int			count_words(char *str);
int			is_blank(char c);
int			execute(char **args, char **envp);
int			builtin_exit(void);
int			builtin_cd(char **args, char **envp);
int			launch(char **args);

#endif
