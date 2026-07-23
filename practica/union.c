#include <unistd.h>

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return 0;
	}
	int repeat[256] = { 0 };
	int i = 0;
	while (argv[1][i])
	{
		if (!repeat[(unsigned char)argv[1][i]])
		{
			repeat[(unsigned char)argv[1][i]] = 1;
			write(1, &argv[1][i], 1);
		}
		i++;
	}
	i = 0;
	while (argv[2][i])
	{
		if (!repeat[(unsigned char)argv[2][i]])
		{
			repeat[(unsigned char)argv[2][i]] = 1;
			write(1, &argv[2][i], 1);
		}
		i++;
	}
	write(1, "\n", 1);
}
