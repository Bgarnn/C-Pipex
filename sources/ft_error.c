# include "pipex.h"

void	error_and_exit(char *str, int status)
{
	if (errno == 0)
		ft_putendl_fd(str, 2);
	else
		perror(str);
	exit(status);
}