#include <unistd.h>
#include <stdio.h>
#include <ctype.h>

int	check_if_null_is_next(char *str, int i)
{
	while (str[i])
	{
		if (isalpha(str[i]) || str[i] == '.')
			return (0);
		i++;
	}
	return (1);
}

int	next_word_index(char *str, int i)
{
	while ((str[i] == ' ' || str[i] == '\t') && str[i])
	{
		i++;
	}
	return (i);
}

void	expand_str(char *str)
{
	int	i = 0;
	int	check = 0;
	int	blank_counter = 3;

	while (str[i] != 0)
	{
		blank_counter = 3;
		if (str[check] == ' ' && check == 0)
		{
			while (str[i] == ' ')
				i++;
			check = 1;
		}
		if (str[i] == ' ' || str[i] == '\t')
		{
			if (check_if_null_is_next(str, i) == 1)
				blank_counter = 0;
			while (blank_counter > 0)
			{
				write(1, " ", 1);
				blank_counter--;
			}
			i = next_word_index(str, i) - 1;
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
	{
		return (write(1, "\n", 1));
	}
	char	*str = av[1];
	expand_str(str);
}