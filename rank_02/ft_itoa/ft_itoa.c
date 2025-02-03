#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	count_digits(int n)
{
	int	count = 0;
	if (n == -2147483648)
		return (10);
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

void	ft_strcpy(char *dest, char *src)
{
	int	i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_itoa(int nbr)
{
	char	*str;
	int		digits;
	int		neg;

	str = malloc(sizeof(char) * 12);
	digits = count_digits(nbr) - 1;
	neg = 0;
	char	*base = "0123456789";
	if (nbr == 0)
	{
		ft_strcpy(str, "0");
		return (str);
	}
	if (nbr == -2147483648)
	{
		ft_strcpy(str, "-2147483648");
		return (str);
	}
	if (nbr < 0)
	{
		neg = 1;
		nbr *= -1;
		digits++;
	}
	while (nbr > 0)
	{
		str[digits] = base[nbr % 10];
		nbr /= 10;
		digits--;
	}
	if (neg)
	{
		str[digits] = '-';
	}
	return (str);
}

/*int	main(int ac, char **av)
{
	if (ac != 2)
		return (write(1, "\n", 1));

	int	n = atoi(av[1]);
	char	*res = ft_itoa(n);

	printf("%s\n", res);
	free(res);
	}*/
