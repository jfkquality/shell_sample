#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork child example
 *
 * Return: Always 0.
 */
int main(void)
{
	/* pid_t my_pid; */
	pid_t child_pid;
	int i = 0;
	int status;

	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

	for (i = 0; i < 5; i++)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
			}
		}
		else
		{
			printf("%d %u\n", i, child_pid);
			wait(&status);
		}
	}
	return (0);
}
