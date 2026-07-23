#include <unistd.h>

int is_lower(char c)
{
	if ('a' <= c && c <= 'z')
		return 1;
	else
		return 0;
}

int is_upper(char c)
{
	if ('A' <= c && c <= 'Z')
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
	int i = 0;
	char *str = argv[1];
	unsigned char c;
	while (str[i])
	{
		if(is_lower(str[i]))
		{
			c = 'z' - str[i] + 'a';
			write(1, &c, 1);
		}
		else if(is_upper(str[i]))
		{
			c = 'Z' - str[i] + 'A';
			write(1, &c, 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}