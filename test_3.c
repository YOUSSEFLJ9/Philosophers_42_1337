/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:31:53 by ymomen            #+#    #+#             */
/*   Updated: 2024/05/21 18:37:09 by ymomen           ###   ########.fr       */
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
	double k = 0.5;
	sleep(k);
	int i = *(int *)arg;
	printf("%d\n",d[i]);
	free(arg);
	return (NULL);
}
int	main(int ac, char **av)
{
	(void)av;
	pthread_t t1[ac];
	if(fork() != -1)
	{
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
		main(ac, av);
		sleep(5);
	}
	else
	{
		printf("fork failed\n");
		return (1);
	}
	return (0);
}