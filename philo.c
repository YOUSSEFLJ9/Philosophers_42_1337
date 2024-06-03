/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:20:07 by ymomen            #+#    #+#             */
/*   Updated: 2024/06/03 19:26:30 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	pars_input(char **av, int ac, t_data *data)
{
	data->nb_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->nb_meals = ft_atoi(av[5]);
	else
		data->nb_meals = -1;
	if (data->nb_philo < 1 || data->time_to_die < MINIM_INPUT \
	|| data->time_to_eat < MINIM_INPUT || data->time_to_sleep < MINIM_INPUT)
	{
		error("Error: wrong arguments\n");
		return (1);
	}
	return (0);
}

void	destroy_values(t_data *data)
{
	int	i;

	i = 0;
	save_mutex(&data->toprint, DESTROY);
	save_mutex(&data->isdiemtx, DESTROY);
	save_mutex(&data->nb_philomtx, DESTROY);
	save_mutex(&data->todie_mtx, DESTROY);
	save_mutex(&data->toeat_mtx, DESTROY);
	save_mutex(&data->tosleep_mtx, DESTROY);
	save_mutex(&data->nb_mealmtx, DESTROY);
	save_mutex(&data->readymtx, DESTROY);
	save_mutex(&data->starttimemtx, DESTROY);
	while (i < data->nb_philo)
	{
		save_mutex(&data->philo[i].save_mutex, DESTROY);
		i++;
	}
	free(data->philo);
	free(data->forks);
}

int	philo(char **av, int ac)
{
	t_data	data;

	if (pars_input(av, ac, &data))
		return (1);
	init_values(&data);
	start_simulation(&data);
	destroy_values(&data);
	return (0);
}
