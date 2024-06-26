/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:41:20 by ymomen            #+#    #+#             */
/*   Updated: 2024/06/04 02:31:12 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitor(t_data *data, int i, int all_ready)
{
	while (!get_var_int(&(data->isdiemtx), &(data->is_die)))
	{
		i = -1;
		all_ready = 0;
		while (++i < get_var_int(&(data->nb_philomtx), &(data->nb_philo)))
		{
			if (get_time() - get_var(&(data->philo[i].save_mutex), \
&(data->philo[i].last_meal_time)) > get_var_int(&(data->todie_mtx), \
&(data->time_to_die)) && get_var(&(data->philo[i].save_mutex), \
&(data->philo[i].meals_cont)) != get_var_int(&(data->nb_mealmtx), \
&(data->nb_meals)) && !get_var_int(&(data->isdiemtx), &(data->is_die)))
			{
				set_var_int(&(data->isdiemtx), &(data->is_die), 1);
				philo_die(&data->philo[i], "is died");
				return ;
			}
			else if (get_var(&(data->philo[i].save_mutex), &(data->\
	philo[i].meals_cont)) == get_var_int(&data->nb_mealmtx, &(data->nb_meals)))
				all_ready++;
		}
		if (all_ready == get_var_int(&(data->nb_philomtx), &(data->nb_philo)))
			break ;
	}
}
