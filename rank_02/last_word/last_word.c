#include <unistd.h>
#include <stdio.h>
#include <ctype.h>


int	main(int ac, char **argv)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	int i = 0;
	int start = 0;

	while(argv[1][i])
	{
		if(argv[1][i] == ' ' && argv[1][i + 1] != ' ' && argv[1][i + 1] != '\0')
			start = i + 1;
		i++;
	}
	while(argv[1][start] != ' ' && argv[1][start] != '\0')
	{
		write(1, &argv[1][start], 1);
		start++;
	}
	write(1, "\n", 1);
	return 0;
}