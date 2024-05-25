/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:34:23 by ymomen            #+#    #+#             */
/*   Updated: 2024/05/25 19:58:35 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h> 
# include <sys/time.h>
#include <limits.h>
# define MAX_DOUBLE 922337203685477580

typedef enum e_mutex
{
	INIT,
	DESTROY,
	LOCK,
	UNLOCK
}	t_mutex;
typedef struct s_philo
{
	int		idx_philo; // start from 1
	long	meals_cont;
	int		is_full;
	long	last_meal_time;
	long	start_time;//checkafter
	pthread_mutex_t	*first_fk;
	pthread_mutex_t	*second_fk;
	pthread_t	philo;
}	t_philo;

typedef struct s_data
{
	int		nb_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		nb_meals;
	t_philo *philo;
	pthread_mutex_t *forks; // array of forks start from 0 to nb_philo - 1
	int		is_die;
		

}	t_data;

/* FUNCTIONS */
int		philo(char **av, int ac);
int		ft_atoi(const char *str);
void	error(char *str);

#endif /*PHILO_H*/