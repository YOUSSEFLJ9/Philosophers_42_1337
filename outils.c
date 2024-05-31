/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:05:08 by ymomen            #+#    #+#             */
/*   Updated: 2024/05/31 17:56:58 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_strlen(char *str)
{
	int i;

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

void my_usleep(long time)
{
	long time_now;

	time_now = get_time();
	while((get_time()- time_now) < time)
	{
		usleep(10);
	}
}