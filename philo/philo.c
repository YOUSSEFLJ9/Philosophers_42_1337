/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:20:07 by ymomen            #+#    #+#             */
/*   Updated: 2024/06/04 08:50:11 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_nbr(char c)
{
	if (c >= 48 && c <= 59)
		return (1);
	return (0);
}

static int	check_input(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = 0;
		if (av[i][j] == '+' && !is_nbr(av[i][j + 1]))
			return (1);
		while (av[i][j])
		{
			if (j > 0 && av[i][j] == '+' && av[i][j - 1] != ' '
				&& av[i][j - 1] != '\t')
				return (1);
			if (!is_nbr(av[i][j]) && av[i][j] != ' ' && av[i][j] != '+'
				&& av[i][j] != '\t')
				return (1);
			j++;
		}
	}
	return (0);
}

static int	pars_input(char **av, int ac, t_data *data)
{
	if (check_input(av))
		return (error("Error: wrong input\n"), 1);
	data->nb_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->nb_meals = ft_atoi(av[5]);
	else
		data->nb_meals = -1;
	if (data->nb_philo < 0 || data->time_to_die < MINIM_INPUT \
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
	save_mutex(&data->starttimemtx, DESTROY);
	while (i < data->nb_philo)
	{
		if (save_mutex(&data->philo[i].save_mutex, DESTROY))
			return (error("Error: mutex destroy\n"));
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
