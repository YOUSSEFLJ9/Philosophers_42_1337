/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:31:53 by ymomen            #+#    #+#             */
/*   Updated: 2024/06/03 20:49:04 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	leaks(void)
{
	system("leaks philo");
}
	// atexit(leaks);

int	main(int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		error("Error: wrong number of arguments\n");
		return (1);
	}
	if (philo(av, ac))
		return (1);
	return (0);
}
