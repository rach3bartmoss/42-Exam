#include <ctype.h>
#include <stdio.h>
#include <unistd.h>

int	ft_isalpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

void	str_capitalizer(char *str)
{
	int	i = 0;

	while (str[i] != '\0')
	{
		if (ft_isalpha(str[0]) && i == 0)
		{
			str[i] = toupper(str[i]);
			write(1, &str[i], 1);
			i++;
		}
		else if (ft_isalpha(str[i]) && (i == 0 || str[i-1] == ' ') && (str[i+1] == ' ' || str[i+1] == '\0'))
		{
			str[i] = toupper(str[i]);
			write(1, &str[i], 1);
			i++;
		}
		else if (ft_isalpha(str[i]) && str[i-1] == ' ' && ft_isalpha(str[i+1]))
		{
			str[i] = toupper(str[i]);
			write(1, &str[i], 1);
			i++;
		}
		else
		{
			if (ft_isalpha(str[i]))
			{
				str[i] = tolower(str[i]);
			}
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	if (ac == 1)
		return (write(1, "\n", 1));
	int	i = 1;

	while (i < ac)
	{
		str_capitalizer(av[i]);
		i++;
	}
}
