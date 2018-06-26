#include "minishell.h"

char	**split_line(char *str)
{
	char	**args;
	int		w;
	int		i;
	int		j;

	w = count_words(str);
	if (!(args = (char **)malloc(sizeof(char *) * (w + 2))))
		return (NULL);
	i = 0;
	while (is_blank(str[i]) && str[i])
		i++;
	j = 0;
	while (j < w && str[i])
	{
		args[j] = get_word(str, &i);
		j++;
	}
	args[j] = NULL;
	return (args);
}

char	*get_word(char *str, int *i)
{
	char	*word;
	int		j;

	if (!(word = (char *)malloc(sizeof(char) * strlen(str))))
		return (NULL);
	j = 0;
	while ((!(is_blank(str[*i]))) && str[*i])
	{
		word[j] = str[*i];
		j++;
		*i += 1;
	}
	word[j] = '\0';
	while (is_blank(str[*i]) && str[*i])
		*i += 1;
	return (word);
}

int		count_words(char *str)
{
	int	i;
	int	w;

	if (!str)
		return (0);
	i = 0;
	w = 0;
	while (str[i])
	{
		if (is_blank(str[i]) && !(is_blank(str[i + 1])))
			w++;
		i++;
	}
	if (str[0] != '\0')
		w++;
	return (w);
}

int		is_blank(char c)
{
	if (c == ' ')
		return (1);
	else if (c == '\t')
		return (1);
	else
		return (0);
}