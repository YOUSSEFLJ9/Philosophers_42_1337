/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:20:07 by ymomen            #+#    #+#             */
/*   Updated: 2024/05/23 23:31:24 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void philo(char **av, int ac)
{
	int i;
	t_philo philo;
	init_values(&philo, av, ac);
	
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