/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:41:20 by ymomen            #+#    #+#             */
/*   Updated: 2024/05/31 20:56:02 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*THE OBSERVER OTHER THAN GOD IS A PIMP*/

void monitor(t_data *data)
{
	int i;

	while(!get_variable_int(&(data->is_die_mtx), data->is_die))
	{
		i  = -1;
		while(++i < data->nb_philo)
		{
			if (get_time() - data->philo[i].last_meal_time > data->time_to_die)
			{
				set_variable_int(&(data->is_die_mtx), &data->is_die, 1);
				save_mutex(&data->print, LOCK);
				printf("%ld %d philo is die\n", get_time() - data->start_time , data->philo->idx_philo);
				save_mutex(&data->print, UNLOCK);
			}
		}
	}
}