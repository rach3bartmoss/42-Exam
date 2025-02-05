#include <unistd.h>

void	ulstr(char *str)
{
	int	i = 0;

	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
			write(1, &str[i], 1);
		}
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
			write(1, &str[i], 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	write (1, "\n", 1);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (write(1, "\n", 1));
	ulstr(av[1]);
	return (0);
}
