/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:20:07 by ymomen            #+#    #+#             */
/*   Updated: 2024/05/31 17:14:03 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int pars_input(char **av, int ac, t_data *data)
{
	data->nb_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->nb_meals = ft_atoi(av[5]);
	else
		data->nb_meals = -1;
	if(data->nb_philo < 1 || data->time_to_die < MINIM_INPUT || data->time_to_eat < MINIM_INPUT || data->time_to_sleep < MINIM_INPUT)
	{
		if (data->nb_philo < 1)
			error("Error: wrong number of philosophers\n");
		else if (data->time_to_die < MINIM_INPUT)
			error("Error: wrong time to die\n");
		else if (data->time_to_eat < MINIM_INPUT)
			error("Error: wrong time to eat\n");
		else if (data->time_to_sleep < MINIM_INPUT)
			error("Error: wrong time to sleep\n");
		else if (ac == 6 && data->nb_meals < 1)
			error("Error: wrong number of meals\n");
		else
			error("Error: wrong arguments\n");
		return (1);
	}	
	return (0);
}

int philo(char **av, int ac)
{
	t_data data;
	if (pars_input(av, ac, &data))
		return (1);
	init_values(&data);
	start_simulation(&data);
	// monitor(&data);
	return (0);
}











// void *routine(void *args)
// {
// 	t_args *arg = (t_args *)args;
// 	t_philo *philo = arg->philo;
// 	int i = arg->i;
// 	int left;
// 	int right;
// 	while (1)
// 	{
// 		pthread_mutex_lock(&philo->mutex);
// 		left = i;
// 		right = (i + 1) % philo->nb_philo;
// 		pthread_mutex_unlock(&philo->mutex);
// 		pthread_mutex_lock(&philo->forks_mutex[left]);
// 		pthread_mutex_lock(&philo->forks_mutex[right]);
// 		printf("%d has taken a fork\n", i);
// 		printf("%d has taken a fork\n", i);
// 		pthread_mutex_unlock(&philo->forks_mutex[left]);
// 		pthread_mutex_unlock(&philo->forks_mutex[right]);
// 		printf("%d is eating\n", i);
// 		printf("%d is sleeping\n", i);
// 		printf("%d is thinking\n", i);
// 	}
// }

// void philo(char **av, int ac)
// {
// 	int i;
// 	t_philo philo;
// 	init_values(&philo, av, ac);
// 	philo.philo = malloc(sizeof(pthread_t) * philo.nb_philo);
// 	philo.forks = malloc(sizeof(int) * philo.nb_philo);
// 	philo.forks_mutex = malloc(sizeof(pthread_mutex_t) * philo.nb_philo);
// 	i = 0;
// 	while (i < philo.nb_philo)
// 	{
// 		philo.forks[i] = 1;
// 		pthread_mutex_init(&philo.forks_mutex[i], NULL);
// 		i++;
// 	}
// 	pthread_mutex_init(&philo.mutex, NULL);
// 	i = 0;
// 	while (i < philo.nb_philo)
// 	{
// 		t_args *args = malloc(sizeof(t_args));
// 		args->philo = &philo;
// 		args->i = i;
// 		pthread_create(&philo.philo[i], NULL, &routine, args);
// 		i++;
// 	}
	
// }