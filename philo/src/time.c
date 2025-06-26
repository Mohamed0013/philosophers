/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:53:30 by mohdahma          #+#    #+#             */
/*   Updated: 2025/06/15 16:33:39 by mohdahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_usleep(size_t time_to_sleep)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < time_to_sleep)
		usleep(500);
}

size_t	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return ((tv.tv_sec * (size_t)1000) + (tv.tv_usec / 1000));
}
