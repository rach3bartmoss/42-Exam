#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	fill(char c, int *alpha)
{
	c -= 97;
	if (alpha[c] == 1)
		return ;
	else
		alpha[c] = 1;
}

int	ft_strlen(char *str)
{
	int	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_union(char *str1, char *str2)
{
	int		alphaL[26] = {0};
	//char	alphaU[26] = {0};
	int		output_size = ft_strlen(str1) + ft_strlen(str2) + 1;

	char	*output = malloc(output_size * sizeof(char));

	int	i = 0, j = 0, k = 0;

	while (1)
	{
		while (str1[i] != '\0')
		{
			output[k] = str1[i];
			k++;
			i++;
		}
		while (str2[j] != '\0')
		{
			output[k] = str2[j];
			j++;
			k++;
		}
		output[output_size] = '\0';
		break;
	}
	//for (int i = 0; i < 26; i++)
	//	printf("%d ", alphaL[i]);
	
	//write(1, "\n", 1);
	i = 0;
	int	alpha_index = 0;
	while (output[i] != '\0')
	{
		alpha_index = output[i] - 97;
		//printf("%d\n", alpha_index);
		if (alphaL[alpha_index] == 1)
			i++;
		else
		{
			write(1, &output[i], 1);
			fill(output[i], alphaL);
			i++;
		}
	}
	write(1, "\n", 1);
	free (output);
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		write (1, "\n", 1);
		return (0);
	}
	char	*s1 = av[1];
	char	*s2 = av[2];

	ft_union(s1, s2);
}