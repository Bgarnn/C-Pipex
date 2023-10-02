
# include "pipex.h"

// void	fork_process(t_data *data, int argc, char **argv, char **env)
// {
// 	int	i;
// 	int	fd;

// 	(void)data;
// 	(void)argc;
// 	(void)env;
// 	i = 0;
// 	fd = open(argv[1], O_RDONLY);
// 	if (fd == -1)
// 		error_infile_open(argv[1]);
// 	dup2(fd, STDIN_FILENO);
// 	close(fd);

// }