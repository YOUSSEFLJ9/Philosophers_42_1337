/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:20:07 by ymomen            #+#    #+#             */
/*   Updated: 2024/05/21 17:20:35 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void philo(char **av, int ac)
{
	int i;
	int nb;

	i = 1;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (nb == -1)
			error("Error: wrong argument\n");
		printf("%d\n", nb);
		i++;
	}
}