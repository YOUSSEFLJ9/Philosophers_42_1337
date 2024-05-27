/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 02:49:42 by ymomen            #+#    #+#             */
/*   Updated: 2024/05/27 02:32:32 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long get_time_micro(long start_time)
{
	struct timeval current_time;
	long time;

	if(gettimeofday(&current_time, NULL) == -1)
		return (-1);
	time = (current_time.tv_sec * 1000 + current_time.tv_usec / 1000) - start_time;
	return (time);
} 

void *simulation_routine(void *args)
{
	
}
void start_simulation(t_data *data)
{
	int i;

	i = -1;
	if (data->nb_meals == 0)
		return ;
	data->start_time = get_time(0);
	if (data->nb_philo == 1)
	{

	}
	else
	{
		while (++i < data->nb_philo)
			pthread_create(&data->philo[i].philo, NULL, simulation_routine, &data->philo[i]);
	}
}
