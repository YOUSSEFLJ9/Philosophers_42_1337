/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:31:53 by ymomen            #+#    #+#             */
/*   Updated: 2024/05/20 19:37:50 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

pthread_mutex_t mutix;
int d[]= {1,2,3,4,5,6,7,8,9,10};
void *rotine(void *arg)
{
	sleep(1);
	int i = *(int *)arg;
	printf("%d\n",d[i]);
	free(arg);
	return (NULL);
}
int	main(int ac, char **av)
{
	(void)av;
	pthread_t t1[ac];
	pthread_mutex_init(&mutix, NULL);
	int i = 0;
	while(i < ac)
	{
		int *ptr = malloc(4);
		*ptr = i;
		if (pthread_create(&t1[i], NULL, &rotine, ptr) != 0)
			return (1);
		i++;
	}
	i = 0;
	while(i < ac)
	{
		if ((pthread_join(t1[i++], NULL)))
			return (6);
	}
	if(pthread_mutex_destroy(&mutix))
		return (5);
	return (0);
}