/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kburalek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:55:33 by kburalek          #+#    #+#             */
/*   Updated: 2023/10/03 09:55:35 by kburalek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_pipe_outfile(t_data *data, int i)
{
	int	j;

	j = 0;
	while (j < data->pipe_num)
	{
		if (j != i - 1)
			close(data->pipefd_arr[j][0]);
		close(data->pipefd_arr[j][1]);
		j++;
	}
	if (dup2(data->pipefd_arr[i - 1][0], STDIN_FILENO) == -1)
		free_and_exit(data, ERROR_DUP2_OUT_2, 1);
	close(data->pipefd_arr[i - 1][0]);
}

void	close_pipe_infile(t_data *data)
{
	int	j;

	j = 0;
	while (j < data->pipe_num)
	{
		if (j != 0)
			close(data->pipefd_arr[j][1]);
		close(data->pipefd_arr[j][0]);
		j++;
	}
	if (dup2(data->pipefd_arr[0][1], STDOUT_FILENO) == -1)
		free_and_exit(data, ERROR_DUP2_IN_2, 1);
	close(data->pipefd_arr[0][1]);
}

void	close_pipe_child(t_data *data, int i)
{
	int	j;

	j = 0;
	while (j < data->pipe_num)
	{
		if (j != i - 1)
			close(data->pipefd_arr[j][0]);
		if (j != i)
			close(data->pipefd_arr[j][1]);
		j++;
	}
	if (dup2(data->pipefd_arr[i - 1][0], STDIN_FILENO) == -1)
		free_and_exit(data, ERROR_DUP2_CHILD, 1);
	if (data->pipe_num > 1)
	{
		if (dup2(data->pipefd_arr[i][1], STDOUT_FILENO) == -1)
			free_and_exit(data, ERROR_DUP2_CHILD_2, 1);
		close(data->pipefd_arr[i][1]);
	}
	close(data->pipefd_arr[i - 1][0]);
}

void	close_pipe_main(t_data *data)
{
	int	j;

	j = 0;
	while (j < data->pipe_num)
	{
		close(data->pipefd_arr[j][0]);
		close(data->pipefd_arr[j][1]);
		j++;
	}
}
