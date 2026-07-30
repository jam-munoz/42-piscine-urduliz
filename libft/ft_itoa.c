#include <stdlib.h>

int digit_count(int nb)
{
	long n = nb;
	int digits = 0;
	if (n < 0)
	{
		digits++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		digits++;
	}
	return digits;
}

char *ft_itoa(int nb)
{
	long n = nb;
	int digits = digit_count(nb);
	char *out = malloc((digits + 1) * sizeof(char));
	int i = 0;
	if (n < 0)
	{
		n *= -1;
		out[i] = '-';
		i++;
	}
	out[digits] = '\0';
	digits--;
	while (digits > 0)
	{
		out[digits] = (n % 10) + '0';
		n /= 10;
		digits--;
	}
	return out;
}
