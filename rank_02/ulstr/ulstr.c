/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopereir <dopereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:25:11 by dopereir          #+#    #+#             */
/*   Updated: 2024/11/03 15:40:30 by dopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i = 0;

	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

char	*reverse_case(char *str)
{
	int	i = 0;

	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
		else if (str[i] >= 97 && str[i] <= 122)
			str[i] -= 32;
		i++;
	}
	return (str);
}


int	main(int ac, char **av)
{
	char	*result;
	if (ac != 2)
		return (write(1, "\n", 1));
	else
		result = reverse_case(av[1]);
	ft_putstr(result);
	write(1, "\n", 1);
	return (0);
}