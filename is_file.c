#include "minishell.h"

int	is_file(char *str)
{
    struct stat sb;
    
    if (stat(str, &sb) < 0)
        return (0);
    if (S_ISREG(sb.st_mode) || S_ISCHR(sb.st_mode) || S_ISBLK(sb.st_mode) ||
        S_ISFIFO(sb.st_mode) || S_ISLNK(sb.st_mode) || S_ISSOCK(sb.st_mode))
        return (1);
    else
        return (0);
}
