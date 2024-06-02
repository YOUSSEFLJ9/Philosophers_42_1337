/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:34:23 by ymomen            #+#    #+#             */
/*   Updated: 2024/06/02 00:54:06 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h> 
# include <sys/time.h>
# include <limits.h>
# define MAX_DOUBLE 922337203685477580
# define MINIM_INPUT 1

typedef enum e_mutex
{
	INIT,
	DESTROY,
	LOCK,
	UNLOCK
}	t_mutex;
typedef struct s_philo
{
	int				idx; // start from 1
	int				is_full;
	long			meals_cont;
	long			last_meal_time;
	pthread_mutex_t	*first_fk;
	pthread_mutex_t	*second_fk;
	pthread_t		philo;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_meals;
	int				all_ready;
	long			start_time;//check after
	t_philo			*philo;
	int				is_die;
	pthread_mutex_t	sleep_mtx;
	pthread_mutex_t	last_meal_mtx;
	pthread_mutex_t	is_die_mtx;
	pthread_mutex_t	all_ready_mtx;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks; // array of forks start from 0 to nb_philo - 1
}	t_data;

/* FUNCTIONS */
void	display_msg(t_philo *philo, char *str);
long	get_time(void);
void	monitor(t_data *data);
void	my_usleep(long time);
long	get_time_milli(long start_time);
void	start_simulation(t_data *data);
int		save_mutex(pthread_mutex_t *mutex, t_mutex type);
int		init_values(t_data *data);
int		philo(char **av, int ac);
int		ft_atoi(const char *str);
void	error(char *str);
/*DATA_FROM_VAR_PROTECT_WITH_MUTEX*/
int		get_variable_int(pthread_mutex_t *mutex, int var);
int		set_variable_int(pthread_mutex_t *mutex, int *var, int value);
int		increce_variable(pthread_mutex_t *mutex, long *var);
long	get_variable(pthread_mutex_t *mutex, long var);
int		set_variable(pthread_mutex_t *mutex, long *var, long value);

#endif /*PHILO_H*/