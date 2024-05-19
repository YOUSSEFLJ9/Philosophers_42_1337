/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:31:53 by ymomen            #+#    #+#             */
/*   Updated: 2024/05/19 11:45:48 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

unsigned long int x = 0;
pthread_mutex_t mutix;
void *rotine()
{
	long int i = 0;
	pthread_mutex_lock(&mutix);
	while(i++ < 100000000)
		x++;
	pthread_mutex_unlock(&mutix);
	return (NULL);
}
int	main(int ac, char **av)
{
	(void)av;
	pthread_t t1[ac];
	srand(time(NULL));
	pthread_mutex_init(&mutix, NULL);
	
	int i = 0;
	while(i < ac)
	{
		if (pthread_create(&t1[i++], NULL, &rotine, NULL ) != 0)
			return (1);
		printf("the pthread %d start\n", i );
	}
	i = 0;
	while(i < ac)
	{
		if ((pthread_join(t1[i++], NULL)))
			return (6);
		printf("the pthread %d finish\n", i);
	}
	if(pthread_mutex_destroy(&mutix))
		return (5);
	printf("%lu\n", x);
	return (0);
}