#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int	i = 256;

	while (i >>= 1)
		(octet & i)	? write (1, "1", 1) : write (1, "0", 1);
}

int	main(void)
{
	unsigned char	n = 54;
	print_bits(n);
	write(1, "\n", 1);
}