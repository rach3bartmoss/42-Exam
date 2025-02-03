#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp = 0;

	temp = *a;
	*a = *b;
	*b = temp;
}

/*int	main(void)
{
	int	a = 10;
	int	b = 80;

	ft_swap(&a, &b);
	printf("A:%d\nB:%d\n", a, b);
	}*/
