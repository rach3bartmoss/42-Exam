#include <ctype.h>
#include <stdio.h>
#include <unistd.h>

void	rstr_capitalizer(char *str)
{
	int	word_set = 0;
	int	i = 0;

	if (isalpha(str[0]) && (str[0 + 1] == ' ' || str[0+1] == '\0'))
	{
		str[i] = toupper(str[i]);
		write(1, &str[0], 1);
		i++;
	}

	while (str[i])
	{
		if (isalpha(str[i]) && isalpha(str[i-1]) && (str[i+1] == ' ' || str[i+1] == '\0'))
		{
			str[i] = toupper(str[i]);
			write(1, &str[i], 1);
			i++;
		}
		else if (isalpha(str[i]) && str[i-1] == ' ' && (str[i+1] == ' ' || str[i+1] == '\0'))
		{
			str[i] = toupper(str[i]);
			write(1, &str[i], 1);
			i++;
		}
		else
		{
			str[i] = tolower(str[i]);
			write (1, &str[i], 1);
			i++;
		}
	}
	write(1,"\n", 1);
}

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		write (1, "\n", 1);
		return (0);
	}
	int	i = 1;
	while (av[i] != NULL)
	{
		rstr_capitalizer(av[i]);
		i++;
	}
}
