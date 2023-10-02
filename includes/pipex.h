
#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include "libft.h"
# include "error.h"

typedef struct s_data
{
	
	int			status;
	char		**env;
	char		mode;
	int			cmd1_i;
	int			cmd_num;
	int			pipe_num;
	int			**pipefd_arr;
	pid_t		*pid_arr; 
}				t_data;

void	error_and_exit(char *str, int status);
void	error_file_open(char *file);
void	free_and_exit(t_data *data, char *str, int status);
void	free_and_exit_no_msg(t_data *data, int status);
void	free_char_2d(char **ptr);
void	fork_process(t_data *data, int argc, char **argv);
void	execute_cmd(t_data *data, char *cmd_argv);
void	close_pipe_outfile(t_data *data, int i);
void	close_pipe_infile(t_data *data);
void	close_pipe_child(t_data *data, int i);
void	close_pipe_main(t_data *data);

#endif
