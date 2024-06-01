/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 02:49:42 by ymomen            #+#    #+#             */
/*   Updated: 2024/06/01 23:48:49 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long get_time()
{
	struct timeval current_time;
	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

long get_time_milli(long start_time)
{
	struct timeval current_time;
	long time;

	if(gettimeofday(&current_time, NULL) == -1)
		return (-1);
	time = (current_time.tv_sec * 1000 + current_time.tv_usec / 1000) - start_time;
	return (time);
}

void wait_all_philos(t_philo *philo)
{
	while (get_variable_int(&(philo->data->all_ready_mtx), philo->data->all_ready)  != 1)
			;
}

void eat(t_philo *philo)
{
	if (get_variable_int((&philo->data->is_die_mtx) ,philo->data->is_die))
		return ;
	save_mutex(philo->first_fk, LOCK);
	save_mutex(philo->second_fk, LOCK);
	if (!get_variable_int((&philo->data->is_die_mtx) ,philo->data->is_die))
	{
		save_mutex(&philo->data->print, LOCK);
		printf("%ld %d philo has taken a fork\n",get_time() - philo->data->start_time ,philo->idx_philo);
		printf("%ld %d philo has taken a fork\n", get_time()- philo->data->start_time ,philo->idx_philo);
		printf("%ld %d philo is eating\n", get_time() - philo->data->start_time , philo->idx_philo);
		save_mutex(&philo->data->print, UNLOCK);
		philo->meals_cont++;
		my_usleep(get_variable_int((&philo->data->sleep_mtx), philo->data->time_to_eat));
		philo->last_meal_time = get_time();
	}
	save_mutex(philo->first_fk, UNLOCK);
	save_mutex(philo->second_fk, UNLOCK);
	
}

void *simulation_routine(void *args)
{
	t_philo *philo;
	
	philo = (t_philo *)args;
	wait_all_philos(philo);
	if (philo->idx_philo % 2 == 0)
		usleep(600);
	while(1)
	{
		if (get_variable_int(&(philo->data->all_ready_mtx ),philo->data->nb_meals)!= -1 && philo->meals_cont == get_variable_int(&(philo->data->all_ready_mtx) ,philo->data->nb_meals))
			break;
		if (get_variable_int(&(philo->data->is_die_mtx), philo->data->is_die))
			return (NULL);
		eat(philo);
		if (get_variable_int((&philo->data->is_die_mtx) ,philo->data->is_die))
		return (NULL) ;
		save_mutex(&philo->data->print, LOCK);
		printf("%ld %d philo is sleeping\n", get_time() - philo->data->start_time , philo->idx_philo);
		save_mutex(&philo->data->print, UNLOCK);
		my_usleep(philo->data->time_to_sleep);
		if (get_variable_int((&philo->data->is_die_mtx) ,philo->data->is_die))
		return (NULL) ;
		save_mutex(&philo->data->print, LOCK);
		printf("%ld %d philo is thinking\n", get_time() - philo->data->start_time , philo->idx_philo);
		save_mutex(&philo->data->print, UNLOCK);
		
	}
	return (NULL);
}
void start_simulation(t_data *data)
{
	int i;

	i = -1;
	if (data->nb_meals == 0)
		return ;
	data->start_time = get_time();
	if (data->nb_philo == 1)
	{
		printf("%ld %d philo has taken a fork\n",get_time() - data->start_time ,data->philo->idx_philo);
		my_usleep(data->time_to_die);
		printf("%ld %d philo is die\n", get_time() - data->start_time , data->philo->idx_philo);
	}
	else
	{
		while (++i < data->nb_philo)
			pthread_create(&data->philo[i].philo, NULL, simulation_routine, &data->philo[i]);
		set_variable_int((&data->all_ready_mtx), &data->all_ready, 1);
		i = -1;
		monitor(data);
		while (++i < data->nb_philo)
			pthread_join(data->philo[i].philo, NULL);

	}
}
