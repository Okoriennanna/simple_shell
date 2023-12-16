# 0x16. C - Simple Shell
  C Group project Syscall


## The lists of all contributors to the repository.

	- this project is done in teams of 2 people 
	- this team: 
  			* Alexander Asfaw, alexandersahle@gmail.com and
   			* Nnanna Nnanna, raymondnnanna246@gmail.com


## Learning Objectives

	At the end of this project, we will  expected to be able to explain to anyone, without the help of Google:

	General
		Who designed and implemented the original Unix operating system
		Who wrote the first version of the UNIX shell
		Who invented the B programming language (the direct predecessor to the C programming language)
		Who is Ken Thompson
		How does a shell work
		What is a pid and a ppid
		How to manipulate the environment of the current process
		What is the difference between a function and a system call
		How to create processes
		What are the three prototypes of main
		How does the shell use the PATH to find the programs
		How to execute another program with the execve system call
		How to suspend the execution of a process until one of its children terminates
		What is EOF / “end-of-file”?

## tasks 

 	 there are a total of seventeen (17) taks for this project (6 mandatory & 11 advanced) listed below

*  0. Betty would be proud
                           - Write a beautiful code that passes the Betty checks
             
            * 1. Simple shell 0.1
                           - Write a UNIX command line interpreter
                       
                                       Display a prompt and wait for the user to type a command. A command line always ends with a new line.
                                       The prompt is displayed again each time a command has been executed.
                                       The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
                                       The command lines are made only of one word. No arguments will be passed to programs.
                                       If an executable cannot be found, print an error message and display the prompt again.
                                       Handle errors.
                                       You have to handle the “end of file” condition (Ctrl+D)

*  Simple shell 0.2

		Simple shell 0.1 +

		Handle command lines with arguments

*  Simple shell 0.3

		Simple shell 0.2 +

		Handle the PATH
		fork must not be called if the command doesn’t exist
*  Simple shell 0.4

		Simple shell 0.3 +

		Implement the exit built-in, that exits the shell
		Usage: exit
		You don’t have to handle any argument to the built-in exit*
*  Simple shell 1.0

		Simple shell 0.4 +

		Implement the env built-in, that prints the current environment
*  Simple shell 0.1.1

		Simple shell 0.1 +

			Write your own getline function
			Use a buffer to read many chars at once and call the least possible the read system call
			You will need to use static variables
			You are not allowed to use getline
*  Simple shell 0.2.1

   		Simple shell 0.2 +

			You are not allowed to use strtok
*  Simple shell 0.4.1

                Simple shell 0.4 +

			handle arguments for the built-in exit
			Usage: exit status, where status is an integer used to exit the shell
*  setenv, unsetenv

		Simple shell 1.0 +

			Implement the setenv and unsetenv builtin commands

			setenv
			Initialize a new environment variable, or modify an existing one
			Command syntax: setenv VARIABLE VALUE
			Should print something on stderr on failure
			unsetenv
			Remove an environment variable
			Command syntax: unsetenv VARIABLE
			Should print something on stderr on failure

*  cd

		Simple shell 1.0 +

			Implement the builtin command cd:

			Changes the current directory of the process.
			Command syntax: cd [DIRECTORY]
			If no argument is given to cd the command must be interpreted like cd $HOME
			You have to handle the command cd -
			You have to update the environment variable PWD when you change directory
			man chdir, man getcwd

*  ;

               Simple shell 1.0 +

			Handle the commands separator ;


*  && and ||

		Simple shell 1.0 +

			Handle the && and || shell logical operators


*  alias

		Simple shell 1.0 +

			Implement the alias builtin command
			Usage: alias [name[='value'] ...]
			alias: Prints a list of all aliases, one per line, in the form name='value'
			alias name [name2 ...]: Prints the aliases name, name2, etc 1 per line, in the form name='value'
			alias name='value' [...]: Defines an alias for each name whose value is given. If name is already an alias, replaces its value with value


*  Variables

		Simple shell 1.0 +

			Handle variables replacement
			Handle the $? variable
H			andle the $$ variable


*  Comments

		Simple shell 1.0 +

			Handle comments (#)


*   File as input

		Simple shell 1.0 +

			Usage: simple_shell [filename]
			Your shell can take a file as a command line argument
			The file contains all the commands that your shell should run before exiting
			The file should contain one command per line
			In this mode, the shell should not print a prompt and should not read from stdin
			Well done on completing this project! Let the world hear about this milestone achieved.
