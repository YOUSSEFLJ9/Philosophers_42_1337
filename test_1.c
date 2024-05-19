/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:31:53 by ymomen            #+#    #+#             */
/*   Updated: 2024/05/16 02:25:46 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void *thread_routine()
{
	printf("test from treads\n");
	sleep(3);
	printf("ending function\n");
	return 0;
}
int	main(void)
{
	pthread_t t1;
	pthread_t t2;
	
	pthread_create(&t1, NULL, &thread_routine, NULL);
	pthread_join(t1, NULL);
	pthread_create(&t2, NULL, &thread_routine, NULL);
	pthread_join(t2, NULL);
	return (0);
}