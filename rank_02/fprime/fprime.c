#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	digit;

	i = ft_strlen(str) - 1 ;
	res = 0;
	digit = 1;

	while(i >= 0)
	{
		res += (str[i] - '0') * digit;
		digit *= 10;
		i--;
	}
	return (res);
}

void	fprime(int n)
{

	if (n == 1)
	{
		printf("1\n");
		return ;
	}
	if (n < 0)
	{
		printf("\n");
		return ;
	}
	while (n % 2 == 0)
	{
		printf("2*");
		n = n / 2;
	}
	int	 i = 3;
	while(i * i <= n)
	{
		while (n % i == 0)
		{
			printf("%d*", i);
			n = n / i;
		}
		i += 2;
	}
	if (n > 2)
		printf("%d", n);
	printf("\n");
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (write(1, "\n", 1));
	fprime(atoi(av[1]));
}
