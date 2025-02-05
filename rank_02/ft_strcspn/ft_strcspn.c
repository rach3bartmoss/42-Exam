#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	int	reject_len = strlen(reject);
	int	i = 0;
	int	j = 0;
	while (s[i] != '\0')
	{
		reject_len = strlen(reject) - 1;
		j = 0;
		while (reject_len >= 0)
		{
			if (s[i] == reject[j])
				return (i);
			reject_len--;
			j++;
		}
		i++;
	}
	return (i);
}

/*int	main(int ac, char **av)
{
	if (ac != 2)
		return (write(1, "\n", 1));

	char	*str = av[1];
	int	res = ft_strcspn(str, "rache");
	size_t	orig = strcspn(str, "rache");

	printf("ft_:%d\noriginal:%ld\n", res, orig);
	}*/
