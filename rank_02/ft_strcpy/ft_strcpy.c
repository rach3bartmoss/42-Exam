#include <unistd.h>
#include <stdio.h>

char	*ft_strcpy(char *s1, char *s2)
{
	int	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	return (s1);
}

/*int	main(void)
{
	char	dest[4096];
	char	*src = "rache bartmoss";

	ft_strcpy(dest, src);
	printf("%s\n", dest);
	}*/
