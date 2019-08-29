#include <unistd.h>
#include <stdio.h>

/**
 * main - print all args without ac
 * @ac: args count
 * @av: array of args
 *
 *Return: 0
 */
int main(__attribute__ ((unused)) int ac, char **av)
{
	char **av1 = av;

	while (*av1)
	{
		if (!(av1 == av))
			printf(", ");
		printf("%s", *av1);
		av1++;
	}
	printf("\n");
	return (0);
}
