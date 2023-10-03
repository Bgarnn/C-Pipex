/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_and_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kburalek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:55:43 by kburalek          #+#    #+#             */
/*   Updated: 2023/10/03 09:55:44 by kburalek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_and_exit(char *str, int status)
{
	if (errno == 0)
		ft_putendl_fd(str, 2);
	else
		perror(str);
	exit(status);
}

void	error_file_open(char *file)
{
	ft_putstr_fd("Pipex: ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(errno), 2);
	exit(1);
}

void	free_char_2d(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		ptr[i] = NULL;
		i++;
	}
	free(ptr);
	ptr = NULL;
}

void	free_and_exit_no_msg(t_data *data, int status)
{
	int	**ptr;
	int	i;

	i = 0;
	ptr = data->pipefd_arr;
	if (data->pipefd_arr != NULL)
	{
		while (ptr[i])
		{
			free(ptr[i]);
			ptr[i] = NULL;
			i++;
		}
		free(ptr);
		ptr = NULL;
	}
	if (data->pid_arr != NULL)
		free(data->pid_arr);
	if (access("here_doc", F_OK) == 0)
		unlink("here_doc");
	exit(status);
}

void	free_and_exit(t_data *data, char *str, int status)
{
	int	**ptr;
	int	i;

	i = 0;
	ptr = data->pipefd_arr;
	if (data->pipefd_arr != NULL)
	{
		while (ptr[i])
		{
			free(ptr[i]);
			ptr[i] = NULL;
			i++;
		}
		free(ptr);
		ptr = NULL;
	}
	if (data->pid_arr != NULL)
		free(data->pid_arr);
	if (access("here_doc", F_OK) == 0)
		unlink("here_doc");
	error_and_exit(str, status);
}
