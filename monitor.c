/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:41:20 by ymomen            #+#    #+#             */
/*   Updated: 2024/06/02 21:13:54 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*THE OBSERVER OTHER THAN GOD IS A PIMP*/

void	monitor(t_data *data)
{
	int	i;

	while (!get_variable_int(&(data->is_die_mtx), &(data->is_die)))
	{
		i = -1;
		while (++i < data->nb_philo)
		{
			if (get_time() - data->philo[i].last_meal_time > data->time_to_die \
			&& data->philo[i].meals_cont != get_variable_int(&data->all_ready_mtx, \
			&(data->nb_meals)) && !get_variable_int(&data->is_die_mtx, &(data->is_die)))
			{
				set_variable_int(&(data->is_die_mtx), &data->is_die, 1);
				save_mutex(&data->print, LOCK);
				display_msg(&data->philo[i], "philo is die");
			}
			else if (data->philo[i].meals_cont == get_variable_int(\
			&data->all_ready_mtx, &(data->nb_meals)))
				set_variable_int(&(data->all_ready_mtx),&(data->all_ready) ,1337);
		}
		if (get_variable_int(&(data->all_ready_mtx), &(data->all_ready)) == 1337)
			break ;
	}
}
