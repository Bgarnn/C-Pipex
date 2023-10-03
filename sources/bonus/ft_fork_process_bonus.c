/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kburalek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:56:04 by kburalek          #+#    #+#             */
/*   Updated: 2023/10/03 09:56:06 by kburalek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	outfile_open(t_data *data, int argc, char **argv)
{
	int	fd;

	fd = 0;
	if (data->mode == 'M')
		fd = open(argv[argc - 1], O_TRUNC | O_WRONLY | O_CREAT, 0644);
	else if (data->mode == 'H')
		fd = open(argv[argc - 1], O_APPEND | O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
		error_file_open(data, argv[argc - 1]);
	if (dup2(fd, STDOUT_FILENO) == -1)
		free_and_exit(data, ERROR_DUP2_OUT, 1);
	close(fd);
}

static void	child_process(t_data *data, int argc, char **argv, int i)
{
	int	fd;

	if (i == 0)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			error_file_open(data, argv[1]);
		if (dup2(fd, STDIN_FILENO) == -1)
			free_and_exit(data, ERROR_DUP2_IN, 1);
		close(fd);
		close_pipe_infile(data);
	}
	else if (i == (data->cmd_num - 1))
	{
		outfile_open(data, argc, argv);
		close_pipe_outfile(data, i);
	}
	else
		close_pipe_child(data, i);
	execute_cmd(data, argv[data->cmd1_i + i]);
}

void	fork_process(t_data *data, int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < data->cmd_num)
	{
		data->pid_arr[i] = fork();
		if (data->pid_arr[i] == -1)
		{
			close_pipe_main(data);
			free_and_exit(data, ERROR_FORK, 1);
		}
		else if (data->pid_arr[i] == 0)
			child_process(data, argc, argv, i);
		i++;
	}
	close_pipe_main(data);
}
