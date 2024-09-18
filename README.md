** ExecPipeline - Command-Line Process Execution and Redirection

Welcome to ExecPipeline, a project designed to simulate the behavior of the shell's pipe operator ('|') for command-line processes. ExecPipeline enables users to execute commands from the command line while redirecting the standard input and output between processes, providing an efficient and versatile method for data manipulation.

** Project Overview **

- What does ExecPipeline do?
    - ExecPipeline allows users to execute a sequence of commands from the command line, similar to how the shell processes pipelines. It uses the `fork`, `dup2`, and `execve` system calls to manage standard input and output redirection between processes, creating a pipeline of commands. This project enhances understanding of process manipulation and the inner workings of command-line utilities.

- Key Features
    - Command-Line Execution: ExecPipeline executes commands provided in the command line, facilitating a sequence of operations.
    - Input and Output Redirection: The project simulates the behavior of the shell's pipe operator, redirecting standard input and output between processes.
    - Error Handling: Robust error handling is included to provide informative messages in case of unexpected scenarios or command-related issues.

** How to Compile ExecPipeline **

To compile the ExecPipeline program, follow these straightforward steps:

  - Clone the Repository:
      - `git clone git@github.com:Bgarnn/C-ExecPipeline.git`
      - `cd C-ExecPipeline`
  - Compile the Program:
      - `make`: This will generate the `pipeline` executable.
  - Clean the Build:
      - `make clean`: This removes the object files, leaving only the compiled program.

** Now you can use ExecPipeline to execute command-line processes with input and output redirection! **

** Usage Example **

`./pipeline file1 "cmd1" "cmd2" file2`

(This will execute `cmd1` with `file1` as input and `cmd2` with the output redirected to `file2`.)