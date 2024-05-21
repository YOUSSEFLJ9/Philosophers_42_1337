/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:34:23 by ymomen            #+#    #+#             */
/*   Updated: 2024/05/21 18:24:54 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <time.h>
# define MAX_DOUBLE 922337203685477580

/*STRUCTS*/
typedef struct s_philo
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_eat;
	int				*forks;
	pthread_mutex_t	*forks_mutex;
	pthread_mutex_t	mutex;
	pthread_t		*philo;
}	t_philo;
typedef struct s_args
{
	t_philo	*philo;
	int		i;
}	t_args;

/*FUNCTIONS*/
int		ft_atoi(const char *str);
void	error(char *str);
#endif /*PHILO_H*/