
#ifndef ERROR_H
# define ERROR_H

# define ERROR_INPUT			"Error: incorrect input"
# define ERROR_MALLOC_PIPEFD	"Error: pipefd_arr malloc failed"
# define ERROR_PIPE_OPEN		"Error: open pipe failed"
# define ERROR_FILE_OPEN_HD		"Error: open here_doc file failed"
# define ERROR_MALLOC_PID		"Error: pid_arr malloc failed"
# define ERROR_FORK				"Error: fork() failed"
# define ERROR_DUP2_IN			"Error: dup2() in fork_process failed"
# define ERROR_DUP2_OUT			"Error: dup2() in outfile_open failed"
# define ERROR_DUP2_IN_2		"Error: dup2() in close_pipe_infile failed"
# define ERROR_DUP2_OUT_2		"Error: dup2() in close_pipe_outfile failed"
# define ERROR_DUP2_CHILD		"Error: dup2() in close_pipe_child(1) failed"
# define ERROR_DUP2_CHILD_2		"Error: dup2() in close_pipe_child(2)failed"
# define ERROR_CMD_NOT_FOUND	"Pipex: command not found"
# define ERROR_PATH_SPLIT		"Error: path split failed in get_cmd"
# define ERROR_SPLIT_PATH		"Error: path_arr malloc failed in path_split"
# define ERROR_EXECVE			"Error: execve() in execute_cmd failed"


#endif
