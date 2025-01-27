/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parasum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopereir <dopereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:08:46 by rache             #+#    #+#             */
/*   Updated: 2024/11/03 17:41:02 by dopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	count_digits(int n)
{
	int	count = 0;

	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int	digits = count_digits(n);
	char	*str = malloc(digits * sizeof(char) + 1);

	int i = digits - 1;
	while (i >= 0)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	return (str);
}

void	ft_putstr(char *str)
{
	int i = 0;

	while(str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 1)
		return(write(1, "0\n", 2));

	int	result = ac - 1;

	char	*a = ft_itoa(result);

	ft_putstr(a);
	write (1, "\n", 1);
	free (a);
	return (0);
}

