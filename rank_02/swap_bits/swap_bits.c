#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

unsigned char	swap_bits(unsigned char octet)
{
	int	i = 0;

	unsigned char	right = (octet & 0b00001111);
	right = (right<<4);

	unsigned char	left = (octet & 0b11110000);
	left = (left>>4);

	return (right | left);
}

/*int main()
{
	int res = swap_bits(42);
	printf("Result = %d\n", res);
	return 0;
	}*/
