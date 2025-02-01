#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	digit = 1;
	int	res = 0;
	int	i = ft_strlen(str) - 1;

	while (i >= 0)
	{
		res += ((str[i] - '0') * digit);
		digit = digit * 10;
		i--;
	}
	return (res);
}

void	print_hex(int	n)
{
	char	*base = "0123456789abcdef";
	char	buffer[9];
	int		i = 0;

	if (n == 0)
	{
		write(1, "0", 1);
	}
	while (n != 0)
	{
		buffer[i++] = base[n % 16];
		n /= 16;
	}
	while (i > 0)
		write(1, &buffer[--i], 1);
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	int	n = ft_atoi(av[1]);
	//printf("ft_atoi:%d\n", n);
	print_hex(n);
}