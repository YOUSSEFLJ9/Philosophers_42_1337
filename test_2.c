/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:31:53 by ymomen            #+#    #+#             */
/*   Updated: 2024/05/19 09:42:59 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

unsigned long int x = 0;
pthread_mutex_t mutix;
void *rotine()
{
	long int i = 0;
	pthread_mutex_lock(&mutix);
	while(i++ < 1000000000)
		x++;
	pthread_mutex_unlock(&mutix);
	return (NULL);
}
int	main(void)
{
	pthread_t t1;
	pthread_t t2,t3,t4;
	pthread_mutex_init(&mutix, NULL);

	if (pthread_create(&t1, NULL, &rotine, NULL ) != 0)
		return (1);
	if (pthread_create(&t2, NULL, &rotine, NULL ) != 0)
		return (3);
	if (pthread_create(&t3, NULL, &rotine, NULL ) != 0)
		return (3);
	if (pthread_create(&t4, NULL, &rotine, NULL ) != 0)
		return (3);
	if ((pthread_join(t1, NULL)))
		return (2);
	if (pthread_join(t2, NULL))
		return (3);
	if (pthread_join(t3, NULL))
		return (3);
	if (pthread_join(t4, NULL))
		return (3);	
	pthread_mutex_destroy(&mutix);	
	printf("%lu\n", x);
	return (0);
}