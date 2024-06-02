/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_vrbls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:30:48 by ymomen            #+#    #+#             */
/*   Updated: 2024/06/02 20:36:18 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_variable(pthread_mutex_t *mutex, long *var, long value)
{
	int	ret;

	ret = save_mutex(mutex, LOCK);
	*var = value;
	ret = save_mutex(mutex, UNLOCK);
	return (ret);
}

long	get_variable(pthread_mutex_t *mutex, long *var)
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

int	increce_variable(pthread_mutex_t *mutex, long *var)
{
	int	ret;

	ret = save_mutex(mutex, LOCK);
	*var += 1;
	ret = save_mutex(mutex, UNLOCK);
	return (ret);
}

int	set_variable_int(pthread_mutex_t *mutex, int *var, int value)
{
	int	ret;

	ret = save_mutex(mutex, LOCK);
	*var = value;
	ret = save_mutex(mutex, UNLOCK);
	return (ret);
}

int	get_variable_int(pthread_mutex_t *mutex, int *var)
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
