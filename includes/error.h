
#ifndef ERROR_H
# define ERROR_H

# define ERROR_INPUT			"Pipex: incorrect input"
# define ERROR_MALLOC_PIPEFD	"Pipex: pipefd_arr malloc failed"
# define ERROR_PIPE_OPEN		"Pipex: open pipe failed"
# define ERROR_FILE_OPEN_HD		"Pipex: open here_doc file failed"
# define ERROR_MALLOC_PID		"Pipex: pid_arr malloc failed"
# define ERROR_FORK				"Pipex: fork() failed"
# define ERROR_DUP2_IN			"Pipex: dup2() in fork_process failed"
# define ERROR_DUP2_OUT			"Pipex: dup2() in outfile_open failed"
# define ERROR_DUP2_IN_2		"Pipex: dup2() in close_pipe_infile failed"
# define ERROR_DUP2_OUT_2		"Pipex: dup2() in close_pipe_outfile failed"
# define ERROR_DUP2_CHILD		"Pipex: dup2() in close_pipe_child(1) failed"
# define ERROR_DUP2_CHILD_2		"Pipex: dup2() in close_pipe_child(2)failed"
# define ERROR_CMD_NOT_FOUND	"Pipex: command not found"
# define ERROR_PATH_SPLIT		"Pipex: path split failed in get_cmd"
# define ERROR_SPLIT_PATH		"Pipex: path_arr malloc failed in path_split"
# define ERROR_EXECVE			"Pipex: execve() in execute_cmd failed"

#endif
