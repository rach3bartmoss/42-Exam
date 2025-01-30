#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>

int	ft_strlen_nospace(char *str)
{
	int	i = 0;
	int	count = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else
		{
			i++;
			count++;
		}
	}
	return (count);
}

int	ft_isblank(char c)
{
	return (c == ' ' || c == '\t');
}

int	count_first_word(char *str)
{
	int	i = 0;
	int	word_len = 0;

	while (str[i])
	{
		while (ft_isblank(str[i]))
			i++;
		while (str[i] && !ft_isblank(str[i]))
		{
			i++;
			word_len++;
		}
		return (word_len);
	}
}

void	rostring(char *str)
{
	int		f_word_size = 0;
	int		i = 0;
	
	f_word_size = count_first_word(str);
	char	*first_word = malloc(f_word_size * sizeof(char));

	//copy first word
	int	index_src = 0;
	while (i < f_word_size)
	{
		while (str[index_src] == ' ')
			index_src++;
		first_word[i] = str[index_src];
		i++;
		index_src++;
	}
	first_word[i] = '\0';

	while (str[index_src] && str[index_src] == ' ')
		index_src++;
	while (str[index_src] != '\0')
	{
		if (str[index_src] == ' ' && str[index_src + 1] == ' ')
			index_src++;
		else if (str[index_src] == ' ' && str[index_src + 1] == '\0')
			index_src++;
		else
		{
			write(1, &str[index_src], 1);
			index_src++;
		}
	}
	if (ft_strlen_nospace(str) != ft_strlen_nospace(first_word))
		write(1, " ", 1);
	i = 0;
	while (i < count_first_word(str))
	{
		write (1, &first_word[i], 1);
		i++;
	}
	write(1, "\n", 1);

	free(first_word);
}

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		write (1, "\n", 1);
		return (0);
	}
	rostring(av[1]);
}