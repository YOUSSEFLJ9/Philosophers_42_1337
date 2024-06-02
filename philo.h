/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:34:23 by ymomen            #+#    #+#             */
/*   Updated: 2024/06/02 23:31:55 by ymomen           ###   ########.fr       */
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
	int				idx;
	int				is_full;
	long			meals_cont;
	long			last_meal_time;
	pthread_mutex_t	save_mutex;
	pthread_mutex_t	*first_fk;
	pthread_mutex_t	*second_fk;
	pthread_t		philo;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				nb_philo;
	pthread_mutex_t nb_philomtx;
	int				time_to_die;
	pthread_mutex_t todie_mtx;
	int				time_to_eat;
	pthread_mutex_t toeat_mtx;
	int				time_to_sleep;
	pthread_mutex_t tosleep_mtx;
	int				nb_meals;
	pthread_mutex_t nb_mealmtx;
	int				all_ready;
	pthread_mutex_t readymtx;
	long			start_time;
	pthread_mutex_t starttimemtx;
	t_philo			*philo;
	int				is_die;
	pthread_mutex_t isdiemtx;
	pthread_mutex_t	toprint;
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
int		get_var_int(pthread_mutex_t *mutex, int *var);
int		set_var_int(pthread_mutex_t *mutex, int *var, int value);
int		increce_var(pthread_mutex_t *mutex, long *var);
long	get_var(pthread_mutex_t *mutex, long *var);
int		set_var(pthread_mutex_t *mutex, long *var, long value);

#endif /*PHILO_H*/