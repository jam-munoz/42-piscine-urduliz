int ft_is_prime(int n)
{
	if (n < 2)
		return 1;
	int i = 2;

	while (i < n)
	{
		if (n % i == 0)
			return 0;
		i++;
	}
	return 1;

}

int ft_find_next_prime(int n)
{
	if (!ft_is_prime(n))
		n++;
	return n;
}

int add_prime_sum(int n)
{
	int i = 2;
	int sum = 0;

	while (i <= n)
	{
		if (ft_is_prime(i))
			sum += i;
		i++;
	}
	return sum;
}

#include <stdio.h>
int main(void)
{
	printf("%d\n", add_prime_sum(7));
}
