
#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
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
void	error_infile_open(char *file);
void	free_and_exit(t_data *data, char *str, int status);
void	fork_process(t_data *data, int argc, char **argv, char **env);

#endif
