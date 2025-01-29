#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_atoi(char *str)
{
	char	*base = "0123456789";
	int	i = strlen(str) - 1;
	int	digit = 1;
	int	result = 0;

	while (i >= 0)
	{
		result += ((str[i] - '0') * digit);
		digit = digit * 10;
		i--;
	}
	return (result);
}

void	print_hex(int n)
{
	char	*base = "0123456789abcdef";
	char	remainder;
	char	*to_print = malloc(8 * sizeof(char));
	int		result;
	int	i = 0;

	while (n > 0)
	{
		result = n / 16;
		remainder = n % 16;
		n = result;
		if (remainder <= 9)
		{
			to_print[i] = base[remainder];
		}
		else
		{
			to_print[i] = base[remainder];
		}
		i++;
	}
	i--;
	while (i >= 0)
	{
		write (1, &to_print[i], 1);
		i--;
	}
	write (1, "\n", 1);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		write (1, "\n", 1);
		return (0);
	}
	int	n = ft_atoi(av[1]);
	print_hex(n);
}