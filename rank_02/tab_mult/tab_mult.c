#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	result;
	int	i;
	int	digit = 1;

	i = ft_strlen(str) - 1;
	result = 0;
	while (i >= 0)
	{
		result += (str[i] - '0') * digit;
		digit *= 10;
		i--;
	}
	return (result);
}

void	ft_putnbr(int n)
{
	char	*base = "0123456789";
	char	result[20];

	int	i = 0;
	while (n > 0)
	{
		result[i] = base[n % 10];
		i++;
		n /= 10;
	}
	result[i] = '\0';
	while (i >= 0)
	{
		write (1, &result[i], 1);
		i--;
	}
	//write (1, "\n", 1);
}

void	tab_mult(int n)
{
	int	q = 1;
	while (q <= 9)
	{
		ft_putnbr(q);
		write(1, " * ", 3);
		ft_putnbr(n);
		write(1, " = ", 3);
		ft_putnbr((q * n));
		write(1, "\n", 1);
		q++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	tab_mult(ft_atoi(av[1]));
}
