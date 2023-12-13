#include "simplshel.h"

/**
 * main - entry pt that print a smilly prompt.
 *
 * @ac: argument counter
 * @argmt: argument vector
 *
 * Return: Always 0.
 */

int main(__attribute__((unused)) int ac, char **argmt)
{
	char *command = NULL;
	size_t n = 0;
	int count = 0,
	ssize_t num_read = 1;

	while (num_read != -1)
	{
		num_read++;
		signal(SIGINT, signal_handler);
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
		toknizer(command, count, argmt);
		free(command);
		command = NULL;
	}
	return (0);
}

/**
 * toknizor - a fun breaks a strings into tokens.
 * @comandl: a string.
 * @countl: line counter
 * @argmt: argument vector
 * Return: A list of strings.
 */

int toknizor(char *comandl, int countl, char **argmt)
{
	char **argv, *token, *cpycomandl = 0, *exit = {"exit"}, *envi = {"envt"};
	int num_tokens = 0, i = 0, j = 0, k = 0, exit_status = 0;

	cpycomandl = _strdup(comandl);
	token = strtok(cpycomandl, _delim);
	while (token != NULL)
	{
		token = strtok(NULL, _delim), num_tokens++;
	free(cpycomandl);
	}
	if (num_tokens != 0)
	{
		token_array = _calloc((num_tokens + 1), (sizeof(char *)));
		if (token_array == NULL)
			return ('\0');
		token = strtok(comandl, _delim);
		while (token != NULL)
		{
			token_array[i] = _calloc((_strlen(token) + 1), sizeof(char));
			if (token_array[i] == NULL)
			{
				while (j < i)
					free(token_array[j]), j++;
				free(token_array);
			}
			_strncpy(token_array[i], token, _strlen(token) + 1);
			token = strtok(NULL, _delim), i++;
		}
		token_array[i] = NULL;
		if (_strcmp(token_array[0], envi) == 0 ||
				_strcmp(token_array[0], "printenv") == 0)
			_env();
		if (_strcmp(token_array[0], exit) == 0)
			an_exit(token_array, num_tokens, comandl, exit_status);
		exit_status = _exec(token_array, num_tokens, comandl, count, argmt);
		while (l < num_tokens)
			free(token_array[l]), l++;
		free(token_array);
	}
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
	char *directory, *no_command = {"it is not a command"};

	switch (child_pid = fork())
	{
	case -1:
		perror("fork error");
		return (1);
	case 0:
		if (stat(comand_lst[0], &st) == 0 && st.st_mode & S_IXUSR)
		{
			if (execve(comand_lst[0], comand_lst, environ) == -1)
				perror(":) Error"), exit(exit_status);
			else
				exit(EXIT_SUCCESS);
		}
		else
		{
			directory = _path(comand_lst[0]);
			if (_strcmp(directory, not_command) == 0)
			{
				command_not_found(i, comand_lst, count, argmt), free(comandl);
				exit(EXIT_FAILURE);
			}
			else
			{
				if (execve(directory, comand_lst, environ) == -1)
					free(directory), perror(":( Error"), exit(exit_status);
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
		if (_strcmp(token, var) == 0)
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
		path = _calloc(_strlen(token) + _strlen(command) + 2, sizeof(char));
		_strcpy(path, token);
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
