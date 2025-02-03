#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	pgcd(int n1, int n2)
{
	if (n1 == 0)
		return n2;
	if (n2 == 0)
		return n1;
	if (n1 > n2)
		return pgcd(n1 % n2, n2);
	else
		return pgcd(n1, n2 % n1);
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	printf("%d\n", pgcd(atoi(av[1]), atoi(av[2])));
}
