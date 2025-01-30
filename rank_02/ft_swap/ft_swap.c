#include <unistd.h>
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp = *a;
	*a = *b;
	*b = temp;
}

/*int	main(void)
{
	int	a = 5;

	int	b = 20;

	ft_swap(&a, &b);

	printf("a:%d\n", a);

}*/