#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	count_digit(int n)
{
	int	count = 0;
	if (n < 0)
		n *= -1;

	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int nbr)
{
	int	sign = 0;
	int	indexes = 0;

	if (0 > nbr)
	{
		nbr *= -1;
		sign = 1;
		indexes = count_digit(nbr) + 1;
	}
	else
		indexes = count_digit(nbr);
	char	*result = malloc(indexes * sizeof(char));
	if (nbr == 0)
	{
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	int	save = nbr;

	indexes--;
	while (indexes >= 0)
	{
		result[indexes] = (nbr % 10) + '0';
		nbr = nbr / 10;
		if (indexes == 0 && sign == 1)
			result[indexes] = '-';
		indexes--;
	}
	result[save] = '\0';
	return (result);
}

/*int	main(void)
{
	char	*str = ft_itoa(156);
	printf("%s\n", str);
}*/