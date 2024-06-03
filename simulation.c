/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 02:49:42 by ymomen            #+#    #+#             */
/*   Updated: 2024/06/03 19:52:03 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

void	eat(t_philo *philo)
{
	if (get_var_int((&philo->data->isdiemtx), &(philo->data->is_die)))
		return ;
	save_mutex(philo->first_fk, LOCK);
	display_msg(philo, "philo has taken a fork");
	save_mutex(philo->second_fk, LOCK);
	display_msg(philo, "philo has taken a fork");
	if (!get_var_int((&philo->data->isdiemtx), &(philo->data->is_die)))
	{
		display_msg(philo, "philo is eating");
		increce_var((&philo->save_mutex), &(philo->meals_cont));
		my_usleep(get_var_int((&philo->data->toeat_mtx), \
		&(philo->data->time_to_eat)), philo->data);
		set_var((&philo->save_mutex), &(philo->last_meal_time), get_time());
	}
	save_mutex(philo->first_fk, UNLOCK);
	save_mutex(philo->second_fk, UNLOCK);
}

void	*simulation_routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	if (philo->idx % 2 == 0)
		my_usleep(40, philo->data);
	while (1)
	{
		if (get_var_int(&(philo->data->isdiemtx), &(philo->data->is_die)))
			return (NULL);
		eat(philo);
		if (get_var_int(&(philo->data->nb_mealmtx), &(philo->data->nb_meals)) \
		!= -1 && get_var(&(philo->save_mutex), &(philo->meals_cont)) == \
		get_var_int(&(philo->data->nb_mealmtx), &(philo->data->nb_meals)))
			break ;
		if (get_var_int(&(philo->data->isdiemtx), &(philo->data->is_die)))
			return (NULL);
		display_msg(philo, "philo is sleeping");
		my_usleep(get_var_int(&(philo->data->tosleep_mtx),
				&(philo->data->time_to_sleep)), philo->data);
		if (get_var_int(&(philo->data->isdiemtx), &(philo->data->is_die)))
			return (NULL);
		display_msg(philo, "philo is thinking");
	}
	return (NULL);
}

void	start_simulation(t_data *data)
{
	int	i;

	i = -1;
	if (get_var_int(&(data->nb_mealmtx), &(data->nb_meals)) == 0)
		return ;
	set_var(&(data->starttimemtx), &(data->start_time), get_time());
	if (get_var_int(&(data->nb_philomtx), &(data->nb_philo)) == 1)
	{
		display_msg(data->philo, "philo has taken a fork");
		my_usleep(get_var_int(&(data->todie_mtx), &(data->time_to_die)),
			data);
		display_msg(data->philo, "philo is die");
	}
	else
	{
		while (++i < data->nb_philo)
			pthread_create(&data->philo[i].philo, NULL, simulation_routine,
				&data->philo[i]);
		set_var_int((&data->readymtx), &(data->all_ready), 1);
		monitor(data, 0, 0);
		i = -1;
		while (++i < data->nb_philo)
			pthread_join(data->philo[i].philo, NULL);
	}
}
