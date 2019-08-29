/**
 * _memset - prints buffer in hexa
 * @s: the address of memory to print
 * @n: the size of the memory to print
 * @b: char to print
 *
 * Return: Nothing.
 */
char *_memset(char *s, char b, unsigned int n)
{
	char *s1 = s;
	char b1 = b;
	int n1 = n;

	while (n1)
	{
		*s1 = b1;
		s1++;
		n1--;
	}
	return (s);
}
