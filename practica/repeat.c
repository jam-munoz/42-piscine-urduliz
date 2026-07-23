#include <unistd.h>

int is_upper(char c)
{
	if ('A' <= c && c <= 'Z')
		return 1;
	else
		return 0;
}

int is_lower(char c)
{
	if ('a' <= c && c <= 'z')
		return 1;
	else
		return 0;
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	char *str = argv[1];
	int i = 0;
	int j = 0;
	while(str[i])
	{
		if (is_lower(str[i]))
		{
			char c = str[i];
			while (c >= 'a')
			{
				write(1, &str[i], 1);
				c--;
			}
		}
		else if (is_upper(str[i]))
		{
			char c = str[i];
			while (c >= 'A')
			{
				write(1, &str[i], 1);
				c--;
			}
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}