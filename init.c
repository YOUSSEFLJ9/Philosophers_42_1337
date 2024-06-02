/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 19:30:41 by ymomen            #+#    #+#             */
/*   Updated: 2024/06/03 00:43:09 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	save_mutex(pthread_mutex_t *mutex, t_mutex type)
{
	int	ret;

	ret = 0;
	if (type == INIT)
		ret = pthread_mutex_init(mutex, NULL);
	else if (type == DESTROY)
		ret = pthread_mutex_destroy(mutex);
	else if (type == LOCK)
		ret = pthread_mutex_lock(mutex);
	else if (type == UNLOCK)
		ret = pthread_mutex_unlock(mutex);
	if (ret != 0)
		error("Error in mutex\n");
	return (ret);
}

static	void	assign_forks(t_data *data, int i)
{
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;

	left = &data->forks[i];
	right = &data->forks[(i + 1) % data->nb_philo];
	if (i % 2 == 0)
	{
		data->philo[i].first_fk = left;
		data->philo[i].second_fk = right;
	}
	else
	{
		data->philo[i].first_fk = right;
		data->philo[i].second_fk = left;
	}
}

static int	init_philos(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		philo[i].idx = i + 1;
		philo[i].meals_cont = 0;
		philo[i].is_full = 0;
		philo[i].last_meal_time = get_time();
		philo[i].data = data;
		if (save_mutex(&philo[i].save_mutex, INIT))
			return (1);
		assign_forks(data, i);
		i++;
	}
	return (0);
}

int	init_mutexs(t_data *data)
{
	int	ret;

	ret = 0;
	ret += save_mutex(&data->nb_philomtx, INIT);
	ret += save_mutex(&data->todie_mtx, INIT);
	ret += save_mutex(&data->toeat_mtx, INIT);
	ret += save_mutex(&data->tosleep_mtx, INIT);
	ret += save_mutex(&data->nb_mealmtx, INIT);
	ret += save_mutex(&data->readymtx, INIT);
	ret += save_mutex(&data->starttimemtx, INIT);
	ret += save_mutex(&data->isdiemtx, INIT);
	ret += save_mutex(&data->toprint, INIT);
	return (ret);
}

int	init_values(t_data *data)
{
	int	i;

	data->philo = malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philo)
		return (1);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->forks)
		return (free(data->philo), 1);
	i = -1;
	data->all_ready = 0;
	data->is_die = 0;
	if (init_mutexs(data))
		return (1);
	while (++i < data->nb_philo)
	{
		if (save_mutex(&(data->forks[i]), INIT))
			return (1);
	}
	init_philos(data->philo, data);
	return (0);
}
