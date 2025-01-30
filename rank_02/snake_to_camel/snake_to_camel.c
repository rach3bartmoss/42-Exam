#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_toupper(char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	else if (c >= 'A' && c <= 'Z')
		c += 32;
	return c;
}

char	*snake_to_camel(char *str)
{
	int	i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '_')
		{
			i++;
			str[i] = ft_toupper(str[i]);
			write(1, &str[i], 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (str);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	char *str = snake_to_camel(av[1]);
}