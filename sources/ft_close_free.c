# include "pipex.h"

static void	free_int_2d(int **ptr)
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

void	free_and_exit(t_data *data, char *str, int status)
{
	if (data->pipefd_arr != NULL)
		free_int_2d(data->pipefd_arr);
	// if (data->pid != NULL)
	// 	free(data->pid);
	error_and_exit(str, status);
}