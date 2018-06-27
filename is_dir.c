#include "minishell.h"

int	is_dir(char *str)
{
    struct stat sb;
    
    if (stat(str, &sb) < 0)
        return (0);
    return (S_ISDIR(sb.st_mode));
}
