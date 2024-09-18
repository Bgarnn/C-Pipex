#ifndef ERROR_H
# define ERROR_H

# define ERROR_INPUT			"pipeline: incorrect input"
# define ERROR_MALLOC_PIPEFD	"pipeline: pipefd_arr malloc failed"
# define ERROR_PIPE_OPEN		"pipeline: open pipe failed"
# define ERROR_FILE_OPEN_HD		"pipeline: open here_doc file failed"
# define ERROR_MALLOC_PID		"pipeline: pid_arr malloc failed"
# define ERROR_FORK				"pipeline: fork() failed"
# define ERROR_DUP2_IN			"pipeline: dup2() in fork_process failed"
# define ERROR_DUP2_OUT			"pipeline: dup2() in outfile_open failed"
# define ERROR_DUP2_IN_2		"pipeline: dup2() in close_pipe_infile failed"
# define ERROR_DUP2_OUT_2		"pipeline: dup2() in close_pipe_outfile failed"
# define ERROR_DUP2_CHILD		"pipeline: dup2() in close_pipe_child(1) failed"
# define ERROR_DUP2_CHILD_2		"pipeline: dup2() in close_pipe_child(2)failed"
# define ERROR_CMD_NOT_FOUND	"pipeline: command not found"
# define ERROR_PATH_SPLIT		"pipeline: path split failed in get_cmd"
# define ERROR_SPLIT_PATH		"pipeline: path_arr malloc failed in path_split"
# define ERROR_EXECVE			"pipeline: execve() in execute_cmd failed"

#endif
