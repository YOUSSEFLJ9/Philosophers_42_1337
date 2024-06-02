/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_vrbls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:30:48 by ymomen            #+#    #+#             */
/*   Updated: 2024/06/02 23:20:30 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_var(pthread_mutex_t *mutex, long *var, long value)
{
	int	ret;

	ret = save_mutex(mutex, LOCK);
	*var = value;
	ret = save_mutex(mutex, UNLOCK);
	return (ret);
}

long	get_var(pthread_mutex_t *mutex, long *var)
{
	long	ret;
	long	value;

	ret = save_mutex(mutex, LOCK);
	value = *var;
	ret = save_mutex(mutex, UNLOCK);
	if (ret)
		return (-1);
	return (value);
}

int	increce_var(pthread_mutex_t *mutex, long *var)
{
	int	ret;

	ret = save_mutex(mutex, LOCK);
	*var += 1;
	ret = save_mutex(mutex, UNLOCK);
	return (ret);
}

int	set_var_int(pthread_mutex_t *mutex, int *var, int value)
{
	int	ret;

	ret = save_mutex(mutex, LOCK);
	*var = value;
	ret = save_mutex(mutex, UNLOCK);
	return (ret);
}

int	get_var_int(pthread_mutex_t *mutex, int *var)
{
	int	ret;
	int	value;

	ret = save_mutex(mutex, LOCK);
	value = *var;
	ret = save_mutex(mutex, UNLOCK);
	if (ret)
		return (-1);
	return (value);
}
