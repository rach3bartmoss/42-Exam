#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac != 2)
		return (write(1, "\n", 1));
	char	*str = av[1];
	int	i = 0;
	if (str[0] == ' ')
		i = 1;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' && str[i + 1] == ' ')
			i++;
		else
		{
			if (str[i] == ' ' && str[i + 1] == '\0')
				break ;
			write(1, &str[i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
}
