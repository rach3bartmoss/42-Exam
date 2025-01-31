#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	find_word_start(char *str, int i)
{
	while (isalpha(str[i]))
		i--;
}

void	rev_wstr(char *str, int first)
{
	int	start;
	int	i;

	i = 0;
	if (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (!str[i])
			return ;
		start = i;
		while (str[i] && str[i] != ' ' && str[i] != '\t')
			i++;
		rev_wstr(&str[i], 0);
		write(1, &str[start], i - start);
		if (!first)
			write(1, " ", 1);
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (write(1, "\n", 1));
	
	char	*str = av[1];

	rev_wstr(str, 1);
	write(1, "\n", 1);
}