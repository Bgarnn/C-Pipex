
# include "pipex.h"

static void open_pipe(t_data *data)
{
	int	i;

	data->pipefd_arr = (int**)malloc(data->pipe_num * sizeof(int*));
	if (!data->pipefd_arr)
		free_and_exit(data, ERROR_MALLOC_PIPEFD, 1);
	i = 0;
	while (i < data->pipe_num)
	{
		data->pipefd_arr[i] = (int*)malloc(2 * sizeof(int));
		if (!data->pipefd_arr[i])
			free_and_exit(data, ERROR_MALLOC_PIPEFD, 1);
		if (pipe(data->pipefd_arr[i]) == -1)
			free_and_exit(data, ERROR_PIPE_OPEN, 1);
		i++;
	}
}

static void	heredoc_input(t_data *data, char *limiter)
{
	char	*line;
	int		fd;

	fd = open("here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
		free_and_exit(data, ERROR_FILE_OPEN_HD, 1);
	while (1)
	{
		write(STDOUT_FILENO, "heredoc> ", 9);
		line = get_next_line(STDIN_FILENO);
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0 && ((ft_strlen(line) - 1) == ft_strlen(limiter)))
			break;
		write(fd, line, ft_strlen(line));
		free(line);
	}
	close(fd);
	free(line);
}

static void	init_and_pipe(t_data *data, int argc, char **argv, char **env)
{
	data->status = 0;
	data->env = env;
	data->mode = 'M';
	data->cmd1_i = 2;
	if (ft_strncmp("here_doc", argv[1], 9) == 0)
	{
		if (argc < 6)
			error_and_exit(ERROR_INPUT, 1);
		data->mode = 'H';
		data->cmd1_i = 3;
		heredoc_input(data, argv[2]);
	}
	data->cmd_num = argc - data->cmd1_i - 1;
	data->pipe_num = data->cmd_num - 1;
	data->pid_arr = (pid_t *)malloc (data->cmd_num * sizeof(pid_t));
	if(!data->pid_arr)
		free_and_exit(data, ERROR_MALLOC_PID, 1);
	open_pipe(data);
}

int	main(int argc, char **argv, char **env)
{
	t_data data;
	int	i;

// mandatory: (argc != 5)
// bonus: (argc < 5)
	if (argc < 5)
		error_and_exit(ERROR_INPUT, 1);
	init_and_pipe(&data, argc, argv, env);
	fork_process(&data, argc, argv);
	i = 0;
	while(i < data.cmd_num)
		waitpid(data.pid_arr[i++], &data.status, WUNTRACED);
	if (data.mode == 'H')
		unlink("here_doc");
	free_and_exit_no_msg(&data, WEXITSTATUS(data.status));
}


	// printf("status = %d \n", data.status);
	// printf("mode = %c \n", data.mode);
	// printf("cmd1_i = %d \n", data.cmd1_i);
	// printf("cmd_num = %d \n", data.cmd_num);
	// printf("pipe_num = %d \n", data.pipe_num);
	// int i = 0;
	// while (data.pipefd_arr[i])
	// {
	// 	printf("pipefd = %d \n", data.pipefd_arr[i][0]);
	// 	printf("pipefd = %d \n", data.pipefd_arr[i][1]);
	// 	i++;
	// }
	// return (0);
