#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i = 0;
	while(str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int	size = ft_strlen(src);
	int	i = 0;

	char	*new = malloc(sizeof(char) * size);

	while (src[i] != '\0')
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

/*int	main(void)
{
	char	*str = "raf simmons";

	char	*dup = ft_strdup(str);

	printf("%s\n", dup);

	free(dup);
	}*/
