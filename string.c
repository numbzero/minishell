#include "minishell.h"

void	ft_putstr(char const *s)
{
	int		i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}