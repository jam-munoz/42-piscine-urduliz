int	ft_floor_sqrt(int nb)
{
	int	sqrt;

	sqrt = 1;
	while ((sqrt * sqrt) <= nb)
		sqrt++;
	return (sqrt - 1);
}