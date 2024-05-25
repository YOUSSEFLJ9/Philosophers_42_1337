/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 19:30:41 by ymomen            #+#    #+#             */
/*   Updated: 2024/05/25 19:59:21 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void save_mutex(pthread_mutex_t mutex, t_mutex type)
{
	if (type == INIT)
		pthread_mutex_init(&mutex, NULL);
	else if (type == DESTROY)
		pthread_mutex_destroy(&mutex);
	else if (type == LOCK)
		pthread_mutex_lock(&mutex);
	else if (type == UNLOCK)
		pthread_mutex_unlock(&mutex);
}
void assine_forks(t_philo *philo, int i)
{
	
}

int init_values(t_data *data)
{
	int i;
	data->philo = malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philo)
		return (1);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->forks)
	{
		free(data->philo);
		return (1);
	}
	i = 0;
	while (i < data->nb_philo)
	{
		save_mutex(data->forks[i], INIT);
		data->philo[i].idx_philo = i + 1;
		data->philo[i].meals_cont = 0;
		data->philo[i].is_full = 0;
		data->philo[i].last_meal_time = 0;
		assine_forks(data->philo, i);
		
	}
}
