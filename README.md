Pipex - Command-Line Process Execution and Redirection

Welcome to Pipex, a project designed to simulate the behavior of the shell's pipe operator ('|') in command-line processes. Pipex enables users to execute commands from the command line while redirecting the standard input and output between processes, providing a versatile and efficient method for data manipulation.

** Project Overview **

- What does Pipex do?
    - Pipex allows users to execute a sequence of commands from the command line, similar to how the shell processes pipelines. It employs the fork, dup2, and execve system calls to redirect the standard input and output between processes, creating a pipeline of commands. Pipex enhances understanding of process manipulation and the inner workings of command-line utilities.

- Key Features
    - Command-Line Execution: Pipex executes commands provided in the command line, allowing for a sequence of operations.
    - Input and Output Redirection: The project simulates the behavior of the shell's pipe operator, redirecting standard input and output between processes.
    - Error Handling: Robust error handling is implemented to provide informative messages in case of unexpected scenarios or command-related issues.
- How to Compile Pipex

To compile the Pipex program, follow these straightforward steps:

  - Clone the Repository:
      - git clone git@github.com:Bgarnn/02-Pipex.git
      - cd 02-Pipex
  - Compile the Program:
      - make: This will generate the pipex executable.
  - Clean the Build:
      - make clean: This removes the object files, leaving only the compiled program.

** Now you can use Pipex to execute command-line processes with input and output redirection!

** Usage Example

./pipex file1 "cmd1" "cmd2" file2

(This will execute cmd1 with file1 as input and cmd2 with the output redirected to file2.)
