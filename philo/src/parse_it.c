/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:58:37 by mohdahma          #+#    #+#             */
/*   Updated: 2025/06/21 18:51:47 by mohdahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	wrong_input_check(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 6 && ft_atoi(av[5]) <= 0)
		return (1);
	return (0);
}

int	is_input_digit(int ac, char **av)
{
	int	i;
	int	k;

	i = 1;
	while (i < ac)
	{
		k = 0;
		while (av[i][k] != '\0')
		{
			if (av[i][k] < '0' || av[i][k] > '9')
				return (1);
			k++;
		}
		i++;
	}
	return (0);
}

int	check_input(int ac, char **av)
{
	if (is_input_digit(ac, av) != 0 || wrong_input_check(ac, av))
		return (1);
	return (0);
}
