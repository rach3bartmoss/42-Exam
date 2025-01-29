#include <unistd.h>

int	is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

void	rotone(char *str)
{
	int		i = 0;
	char	c = 0;


	while (str[i] != '\0')
	{
		if (is_alpha(str[i]) == 1)
		{
			if (str[i] == 'z')
				c = 'a';
			else if (str[i] == 'Z')
				c = 'A';
			else
				c = str[i] + 1;
			write (1, &c, 1);
		}
		else
		{
			c = str[i];
			write (1, &c, 1);
		}
		i++;
	}
	write (1, "\n", 1);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		write (1, "\n", 1);
		return (0);
	}
	rotone(av[1]);
}