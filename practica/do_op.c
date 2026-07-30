#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int nb)
{
	long n = nb;
	char c;

	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr(n/10);
	}
	c = (n % 10) + '0';
	ft_putchar(c);
}

int ft_atoi(char *s)
{
	int sum = 0;
	int sign = 1;
	int i = 0;

	while(s[i] == ' ' && (9 <= s[i] && s[i] <= 13))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
		{
			sign = -1;
		}
		i++;
	}
	while ('0' <= s[i] && s[i] <= '9')
	{
		sum *= 10;
		sum += s[i] - '0';
		i++;
	}
	return sum * sign;
}
int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		ft_putchar('\n');
		return 0;
	}

	int x = ft_atoi(argv[1]);
	int y = ft_atoi(argv[3]);
	char op = argv[2][0];
	int result;
	if (op == '+')
		result = x + y;
	else if (op == '-')
		result = x - y;
	else if (op == '*')
		result = x * y;
	else if (op == '/')
	{
		if (y == 0)
			return 0;
		else
			result = x / y;
	}
	else if (op == '%')
	{
		if (y == 0)
			return 0;
		else
			result = x % y;
	}
	else
		return 0;
	ft_putnbr(result);
	ft_putchar('\n');
	return 0;
}
