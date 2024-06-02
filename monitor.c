/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:41:20 by ymomen            #+#    #+#             */
/*   Updated: 2024/06/03 00:30:20 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*THE OBSERVER OTHER THAN GOD IS A PIMP*/

void	monitor(t_data *data)
{
	int	i;

	while (!get_var_int(&(data->isdiemtx), &(data->is_die)))
	{
		i = -1;
		while (++i < get_var_int(&(data->nb_philomtx), &(data->nb_philo)))
		{
			if (get_time() - get_var(&(data->philo[i].save_mutex) ,&(data->philo[i].last_meal_time)) > get_var_int(&(data->todie_mtx),&(data->time_to_die)) && get_var(&(data->philo[i].save_mutex),&(data->philo[i].meals_cont)) != get_var_int(&(data->nb_mealmtx), &(data->nb_meals)) && !get_var_int(&(data->isdiemtx), &(data->is_die)))
			{
				set_var_int(&(data->isdiemtx), &(data->is_die), 1);
				save_mutex(&data->toprint, LOCK);
				printf("%ld %d philo is die\n", get_time() - get_var(&(data->starttimemtx), &(data->start_time)), \
				data->philo[i].idx);
			}
			else if (get_var(&(data->philo[i].save_mutex), &(data->philo[i].meals_cont)) == get_var_int( &data->nb_mealmtx, &(data->nb_meals)))
				set_var_int(&(data->readymtx), &(data->all_ready), 1337);
		}
		if (get_var_int(&(data->readymtx), &(data->all_ready)) == 1337)
			break ;
	}
}
