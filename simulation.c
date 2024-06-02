/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 02:49:42 by ymomen            #+#    #+#             */
/*   Updated: 2024/06/03 00:45:45 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

void	wait_all_philos(t_philo *philo)
{
	while (get_var_int(&(philo->data->readymtx),
			&(philo->data->all_ready)) != 1)
		;
}

void	eat(t_philo *philo)
{
	if (get_var_int((&philo->data->isdiemtx), &(philo->data->is_die)))
		return ;
	save_mutex(philo->first_fk, LOCK);
	save_mutex(philo->second_fk, LOCK);
	if (!get_var_int((&philo->data->isdiemtx), &(philo->data->is_die)))
	{
		display_msg(philo, "philo has taken a fork");
		display_msg(philo, "philo has taken a fork");
		display_msg(philo, "philo is eating");
		increce_var((&philo->save_mutex), &(philo->meals_cont));
		my_usleep(get_var_int((&philo->data->toeat_mtx), \
		&(philo->data->time_to_eat)));
		set_var((&philo->save_mutex), &(philo->last_meal_time), get_time());
	}
	save_mutex(philo->first_fk, UNLOCK);
	save_mutex(philo->second_fk, UNLOCK);
}

void	*simulation_routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	wait_all_philos(philo);
	if (philo->idx % 2 == 0)
		usleep(600);
	while (1)
	{
		if (get_var_int(&(philo->data->nb_mealmtx), &(philo->data->nb_meals)) \
		!= -1 && get_var(&(philo->save_mutex), &(philo->meals_cont)) == \
		get_var_int(&(philo->data->nb_mealmtx), &(philo->data->nb_meals)))
			break ;
		if (get_var_int(&(philo->data->isdiemtx), &(philo->data->is_die)))
			return (NULL);
		eat(philo);
		if (get_var_int(&(philo->data->isdiemtx), &(philo->data->is_die)))
			return (NULL);
		display_msg(philo, "philo is sleeping");
		my_usleep(get_var_int(&(philo->data->tosleep_mtx),
				&(philo->data->time_to_sleep)));
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
		my_usleep(get_var_int(&(data->todie_mtx), &(data->time_to_die)));
		display_msg(data->philo, "philo is die");
	}
	else
	{
		while (++i < data->nb_philo)
			pthread_create(&data->philo[i].philo, NULL, simulation_routine,
				&data->philo[i]);
		set_var_int((&data->readymtx), &(data->all_ready), 1);
		i = -1;
		monitor(data);
		while (++i < data->nb_philo)
			pthread_join(data->philo[i].philo, NULL);
	}
}
