#include "simplshel.h"
#include <sys/stat.h>

/**
 * main - entry pt that print a smilly prompt.
 *
 * @ac: argument counter
 * @gmt: argument vector
 *
 * Return: Always 0.
 */

int main(__attribute__((unused)) int ac, char **gmt)
{
	char *command = NULL;
	size_t n = 0;
	int count = 0, num_read = 1;

	while (num_read != -1)
	{
		num_read++;
		signal(SIGINT, sig_handl);
		if (isatty(STDIN_FILENO) == 1)
		{
			write(STDOUT_FILENO, ":) ", 2);
		}

		num_read = getline(&command, &n, stdin);
		if (num_read < 0)
		{
			free(command);
			exit(0);
		}
		toknizor(command, count, gmt);
		free(command);
		command = NULL;
	}
	return (0);
}

/**
 * toknizor - a fun breaks a strings into tokens.
 * @comandl: a string.
 * @count: line counter
 * @argmt: argument vector
 * Return: A list of strings.
 */

int toknizor(char *comandl, int count, char **argmt)
{
	char **argv, *token, *cpycomandl = 0, *exit = {"exit"}, *envi = {"envt"};
	int num_tokens = 0, i = 0, j, k, exit_status = 0;

	cpycomandl = _strdup(comandl);
	token = strtok(cpycomandl, _delim);
	while (token != NULL)
	{
		token = strtok(NULL, _delim), num_tokens++;
	}
	if (num_tokens != 0)
	{
		argv = _malloc1((num_tokens + 1), (sizeof(char *)));
		if (argv == NULL)
			return ('\0');
		token = strtok(comandl, _delim);
		while (token != NULL)
		{
			argv[i] = _malloc1((_strlen(token) + 1), sizeof(char));
			if (argv[i] == NULL)
			{
				for (j = 0; j < i; j++)
					free(argv[j]);;
				free(argv);
			}
			_strncpy(argv[i], token, _strlen(token) + 1);
			token = strtok(NULL, _delim), i++;
		}
		argv[i] = NULL;
		if (_strcomp(argv[0], envi) == 0 ||
				_strcomp(argv[0], "printenv") == 0)
			_envt();
		if (_strcomp(argv[0], exit) == 0)
			an_exit(argv, num_tokens, comandl, exit_status);
		exit_status = _exec(argv, num_tokens, comandl, count, argmt);
		for (k = 0; k < num_tokens; k++)
			free(argv[k]);
	}
		free(argv);

	return (exit_status);
}

/**
 * _exec - Creates a child processs to start a new programm.
 *
 * @comand_lst: Array of strings, input
 * @i: number of arguments the user typed.
 * @count: line counter
 * @argmt: argument vector
 * @comandl: Command line passed to the function.
 *
 * Return: 0 if success, 1 if failed.
 */

int _exec(char **comand_lst, int i, char *comandl, int count, char **argmt)
{
	pid_t child_pid;
	int status, exit_status = 0;
	struct stat st;
	char *directory, *not_command = {"it is not a command"};

	switch (child_pid = fork())
	{
	case -1:
		perror("fork error");
		return (1);
	case 0:
		if (stat(comand_lst[0], &st) == 0 && st.st_mode & S_IXUSR)
		{
			if (execve(comand_lst[0], comand_lst, environ) == -1)
				perror(":( Error"), exit(exit_status);
			else
				exit(EXIT_SUCCESS);
		}
		else
		{
			directory = _path(comand_lst[0]);
			if (_strcomp(directory, not_command) == 0)
			{
				no_command(i, comand_lst, count, argmt), free(comandl);
				exit(EXIT_FAILURE);
			}
			else
			{
				if (execve(directory, comand_lst, environ) == -1)
					free(directory), perror(":) Error"), exit(exit_status);
				else
					exit(EXIT_SUCCESS);
			}
		}
	default:
		wait(&status);
		if (WIFEXITED(status))
			exit_status = WEXITSTATUS(status);
	}
	return (exit_status);
}

/**
 * _path - Returns all the directories from PATH.
 * @command: The first argument the user typed.
 * Return: Directories from PATH.
 */

char *_path(char *command)
{
	int i = 0;
	char var[] = "PATH", *path, *token, *env, *dir_temp;

	while (environ[i])
	{
		env = _strdup(environ[i]);
		token = strtok(env, "=");
		if (_strcomp(token, var) == 0)
		{
			token = strtok(NULL, "=");
			dir_temp = _strdup(token);
			path = directory(dir_temp, command);
			free(dir_temp);
		}
		free(env);
		i++;
	}
	return (path);
}

/**
 * directory - a function to checks if User command input is in fact a command.
 * @temporal_dir: string that contains the temporal directory.
 * @command: First command typed by user.
 * Return: The path if the command exists, not_command if it doesnt.
 */

char *directory(char *temporal_dir, char *command)
{
	char *path, *token, slash[] = {'/'}, flag = 0;
	char *not_command = {"it is not a command"};
	struct stat st;

	token = strtok(temporal_dir, ":");
	while (token != NULL)
	{
		path = _malloc1(_strlen(token) + _strlen(command) + 2, sizeof(char));
		stringcpy(path, token);
		_strcat(path, slash);
		_strcat(path, command);
		if (stat(path, &st) == 0 && st.st_mode & S_IXUSR)
		{
			flag++;
			break;
		}
		token = strtok(NULL, ":");
		free(path);
	}
	if (flag == 1)
		return (path);
	else
		return (not_command);
}

