#include <unistd.h>
#include <stdio.h>

int	max(int *tab, unsigned int len)
{
	int				max = 0;
	unsigned int	i = 0;

	if (!tab)
		return (max);
	max = tab[0];
	while (i < len)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}
/*
int	main(void)
{
	int	tab[] = {20, 77, 5, -89, 77, 63, -0, 0, -1, -2147483648};
	int	size = sizeof(tab) / sizeof(tab[0]);

	printf("%d\n", max(NULL, size));
}
*/
