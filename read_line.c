#include "minishell.h"

char	*read_line(void)
{
	char	*buffer;
	char	ch;
	int		bufsize;
	int		position;

	buffer = (char *)malloc(sizeof(char));
	*buffer = '\0';
	position = 0;
	bufsize = 2;
	while ((read(0, &ch, 1) > 0) && ch != '\n')
	{
		*(buffer + position) = ch;
		buffer = (char *)realloc(buffer, bufsize);
		position++;
		bufsize++;
	}
	buffer[position] = '\0';
	return (buffer);
}
