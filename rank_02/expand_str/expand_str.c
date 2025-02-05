#include <unistd.h>

void	expand_str(char *str)
{
	int	i = 0;
	int	space_count = 3;

	while (str[i] == ' ')
		i++;
	while(str[i])
	{
		space_count = 3;
		if (str[i] != ' ' && str[i+1] == ' ')
		{
			write(1, &str[i], 1);
			i++;
			while (str[i] == ' ' && str[i] != '\0')
				i++;
			while (space_count > 0 && str[i] != '\0')
			{
				write(1, " ", 1);
				space_count--;
			}
		}
		else if (str[i] != '\0')
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (write(1, "\n", 1));
	expand_str(av[1]);
}
