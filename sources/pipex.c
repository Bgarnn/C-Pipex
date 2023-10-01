
#include "pipex.h"

int	main(int ac, char *av[])
{
//test command
	if (ac != 2 || av[1] == NULL)
		write (1, "error", 5);
	else
		write (1, "correct", 7);
	return (0);
}
