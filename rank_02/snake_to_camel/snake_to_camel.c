#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char	*snake_to_camel(char *str)
{
	int	i = 0;
	int	j = 0;
	char	*res = malloc(sizeof(char) * 4096);


	while (str[i] != '_')
	{
		res[j] = str[i];
		i++;
		j++;
	}
	while (str[i])
	{
		if (str[i] == '_')
		{
			i++;
			res[j] = toupper(str[i]);
			j++;
			i++;
		}
		else
		{
			res[j] = str[i];
			i++;
			j++;
		}
	}
	res[j] = '\0';
	for (int i = 0; res[i] != '\0'; i++)
	{
		write(1, &res[i], 1);
	}
	write(1, "\n", 1);
	return res;
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (write (1, "\n", 1));
	char	*res = snake_to_camel(av[1]);

	free(res);
}
