
#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"
# include "error.h"

typedef struct s_data
{
	
	int			status;
	char		mode;
	int			cmd1_i;
	int			cmd_num;
	int			pipe_num;
	int			**pipefd_arr;
}				t_data;

void	error_and_exit(char *str, int status);
void	free_and_exit(t_data *data, char *str, int status);

#endif
