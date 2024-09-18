#include "pipeline.h"

static char	**path_split(t_data *data, char **cmd_arr, char **env)
{
	char	**path_arr;

	path_arr = NULL;
	while (*env != NULL && ft_strncmp(*env, "PATH=", 5) != 0)
		env++;
	if (*env == NULL)
	{
		ft_putstr_fd("pipeline: ", 2);
		ft_putstr_fd(cmd_arr[0], 2);
		ft_putendl_fd(": No such file or directory", 2);
		free_char_2d(cmd_arr);
		free_and_exit_no_msg(data, 127);
	}
	if (ft_strncmp(*env, "PATH=", 5) == 0)
	{
		path_arr = ft_split(*env + 5, ':');
		if (path_arr == NULL)
			free_and_exit(data, ERROR_SPLIT_PATH, 1);
	}
	return (path_arr);
}

static char	*path_from_env(t_data *data, char **cmd_arr, char **env)
{
	char	**path_arr;
	char	*path_tmp;
	char	*path;
	int		i;

	path_arr = path_split(data, cmd_arr, env);
	i = 0;
	while (path_arr[i] != NULL)
	{
		path_tmp = ft_strjoin(path_arr[i], "/");
		path = ft_strjoin(path_tmp, cmd_arr[0]);
		if (path_tmp != NULL)
			free(path_tmp);
		if (access (path, F_OK) == 0)
			break ;
		if (path != NULL)
			free(path);
		path = NULL;
		i++;
	}
	free_char_2d(path_arr);
	return (path);
}

static char	*get_path(t_data *data, char **cmd_arr, char **env)
{
	char	*path;

	path = NULL;
	if (ft_strchr(cmd_arr[0], '/') != NULL)
		path = ft_strdup(cmd_arr[0]);
	else
		path = path_from_env(data, cmd_arr, env);
	if (path == NULL)
	{
		ft_putstr_fd("pipeline: ", 2);
		ft_putstr_fd(cmd_arr[0], 2);
		ft_putendl_fd(": command not found", 2);
		free_char_2d(cmd_arr);
		free_and_exit_no_msg(data, 127);
	}
	if (access(path, F_OK) == -1)
	{
		ft_putstr_fd("pipeline: ", 2);
		perror(path);
		free(path);
		free_char_2d(cmd_arr);
		free_and_exit_no_msg(data, 127);
	}
	return (path);
}

static char	**get_cmd(t_data *data, char *cmd_argv)
{
	char	**cmd_arr;

	if (cmd_argv == NULL || ft_strlen(cmd_argv) == 0)
	{
		ft_putendl_fd("pipeline: : command not found", 2);
		free_and_exit_no_msg(data, 127);
	}
	cmd_arr = ft_split(cmd_argv, ' ');
	if (cmd_arr == NULL)
		free_and_exit(data, ERROR_PATH_SPLIT, 1);
	if (cmd_arr[0] == NULL)
	{
		ft_putendl_fd("pipeline: : command not found", 2);
		free_and_exit_no_msg(data, 127);
	}
	return (cmd_arr);
}

void	execute_cmd(t_data *data, char *cmd_argv)
{
	char	**cmd_arr;
	char	*path;

	cmd_arr = get_cmd(data, cmd_argv);
	path = get_path(data, cmd_arr, data->env);
	if ((access(cmd_arr[0], X_OK) == -1) && (errno == 13))
	{
		ft_putstr_fd("pipeline: ", 2);
		perror(cmd_arr[0]);
		free(path);
		free_char_2d(cmd_arr);
		free_and_exit_no_msg(data, 126);
	}
	if (execve(path, cmd_arr, data->env) == -1)
	{
		free(path);
		free_char_2d(cmd_arr);
		free_and_exit_no_msg(data, 1);
	}
}
