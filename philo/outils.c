/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:05:08 by ymomen            #+#    #+#             */
/*   Updated: 2024/06/03 23:10:50 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	error(char *str)
{
	write(2, str, ft_strlen(str));
	return ;
}

void	my_usleep(long time, t_data *data)
{
	long	time_now;

	time_now = get_time();
	while ((get_time() - time_now) < time && !get_var_int(&(data->isdiemtx), \
	&(data->is_die)))
		usleep(10);
}

void	display_msg(t_philo *philo, char *str)
{
	save_mutex(&philo->data->toprint, LOCK);
	if (get_var_int(&(philo->data->isdiemtx), &(philo->data->is_die)) == 0)
	{
		printf("%ld %d %s\n", get_time() - get_var(&(philo->data->starttimemtx),
				&(philo->data->start_time)), \
		philo->idx, str);
	}
	save_mutex(&philo->data->toprint, UNLOCK);
}

void	philo_die(t_philo *philo, char *str)
{
	save_mutex(&philo->data->toprint, LOCK);
	printf("%ld %d %s\n", get_time() - get_var(&(philo->data->starttimemtx), \
		&(philo->data->start_time)), philo->idx, str);
	save_mutex(&philo->data->toprint, UNLOCK);
}
