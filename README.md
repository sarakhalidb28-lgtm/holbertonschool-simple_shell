holbertonschool-simple_shell
Simple Shell Project

Before starting the project, what are the requirements?
All code files must end with a new line
A README.md file is required
Global variables are not allowed
No more than 5 functions per file
A main.h header file must contain all prototypes
Code must follow Betty style
The shell must not contain memory leaks
All header files must be include guarded
 
What functions and system calls are allowed?
Main allowed functions include:
fork
execve
wait
waitpid
getline
malloc
free
strtok
access
perror
write
read
exit
_exit
These functions are used for:
Reading input
Creating processes
Executing commands
Managing memory
Handling errors

What builtins are supported?
The shell supports:
exit
env

What features does this shell support?
Interactive mode
Non-interactive mode
Command execution
PATH handling
Builtin commands
Error handling
Child process management

What features are NOT supported?
This shell does not support:
Pipes
Redirections
Wildcards
Quotes handling
Advanced shell features

This is a simplified version of a UNIX shell

<img width="600" alt="Simple Shell Diagram" src="https://github.com/user-attachments/assets/d1cdf272-66e1-4516-b7ea-13ebd55e8dec" />
How can we approach and solve this project?
Understand how a UNIX shell works
Break the project into small tasks
Start with reading user input
Implement parsing step by step
Add fork() and execve()
Handle PATH searching
Add builtin commands
Test and debug continuously
Work as a team and understand every step

 <img width="700" alt="Simple Shell Diagram" src="https://github.com/user-attachments/assets/b1979fcb-48aa-4fc8-8b25-8cff70231c70" />
What is the purpose of this project?
This project is about creating a custom UNIX command interpreter
The goal is to understand:
How shells work internally
How Linux executes commands
How processes are created
How programs communicate with the operating system

How does Simple Shell work?
The shell displays a prompt
The user enters a command
The command is parsed
The shell checks for builtins
The shell searches inside PATH
fork() creates a child process
execve() executes the command
The parent process waits
The shell returns to the prompt

What are the steps of execution?
Start the shell
Display the prompt
Read input using getline
Parse commands using strtok
Check builtins
Search PATH
Verify the executable using access
Create a child process using fork
Execute using execve
Wait for the child process
Return to the prompt

What did we learn from this project?
UNIX shell behavior
Process management
Using fork and execve
Memory management
PATH handling
System calls
Debugging
Team collaboration

What are the limitations of this project?
This shell is a simplified version of the original shell
It does not support:
Pipes
Redirections
Shell scripting
Advanced parsing
Complex shell features

Why is this project important?
This project teaches:
Operating system fundamentals
Low-level programming
Process creation
Command execution
Memory handling
Real UNIX shell behavior

What are the reasons for the success of this project?
This project succeeded because:
The work was divided clearly
The project was built step by step
Each part was tested immediately
Errors were fixed quickly
Teamwork and communication were strong
<p>
  <img align="left" width="220" src="https://github.com/user-attachments/assets/d90025a4-54cf-4c0a-8f3f-dfb70b441929" />

  We did not postpone the work and maintained consistent progress throughout the project.
</p>
<br clear="left"/>
We did not postpone the work
We focused on understanding the project
Memory leaks were handled carefully
Betty style and project requirements were followed
The shell was tested continuously

These factors helped us build a stable and functional Simple Shell project

Flow of Execution Diagram
<img width="850" alt="Simple Shell Flowchart" src="https://github.com/user-attachments/assets/be4f3bbc-493f-431b-aecb-fbb0e02341da" />
This diagram illustrates the workflow of the Simple Shell project from reading input to command execution and returning to the prompt.

Authors
Eman Hamdan
Sara Al-Buraidi
<img width="948" height="541" alt="IMG_2605" src="https://github.com/user-attachments/assets/11a9c2db-2607-4d98-aad1-2754e12e2933" />
