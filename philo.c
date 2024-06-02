/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:20:07 by ymomen            #+#    #+#             */
/*   Updated: 2024/06/03 00:38:00 by ymomen           ###   ########.fr       */
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

int	philo(char **av, int ac)
{
	t_data	data;

	if (pars_input(av, ac, &data))
		return (1);
	init_values(&data);
	start_simulation(&data);
	return (0);
}
