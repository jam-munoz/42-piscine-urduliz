#include <unistd.h>

int is_sep(char c)
{
	if (c == ' ' || (9 <= c && c <= 13))
		return 1;
	else
		return 0;
}

int main(int argc, char *argv[])
{
	if (argc != 2 || !argv[1][0])
	{
		write(1, "\n", 1);
		return 0;
	}
	int i = 0;
	char *str = argv[1];
	while (str[i])
		i++;
	i--;
	while (is_sep(str[i]))
		i--;
	while (!is_sep(str[i]))
		i--;
	i++;
	while (str[i] && !is_sep(str[i]))
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}
