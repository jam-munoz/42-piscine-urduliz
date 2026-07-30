int is_alpha(char c)
{
	if ('a' <= c && c <= 'f')
		return 1;
	else
		return 0;
}

int is_numeric(char c)
{
	if ('0' <= c && c <= '9')
		return 1;
	else
		return 0;
}

int ft_atoi_base(const char *str, int str_base)
{
	if (str_base > 16)
		return 0;
	char base[] = "0123456789abcdef";

	int i = 0;
	int sum = 0;
	int sign = 1;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((is_numeric(str[i])) || (is_alpha(str[i]) && str_base > 10))
	{
		sum *= str_base;
		if (is_alpha(str[i]) && str_base > 10)
			sum += base[str[i]] - 'a' + 10;
		else
			sum += base[str[i]] - '0';
		i++;
	}
	return sum * sign;
}

#include <stdio.h>
int main(void)
{
	int n = ft_atoi_base("3ef", 16);
	printf("%d\n", n);
}
