#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <string.h>

typedef struct s_cowboy
{
	char	 	*name;
	pthread_t 	thread;
	int			rand;
}				t_cowboy;

pthread_mutex_t ugly_gun;
pthread_mutex_t bad_gun;

void *action(void *data)
{
	t_cowboy cowboy;
	cowboy = *(t_cowboy *)data;
	printf("rection time %s  %d\n", cowboy.name, cowboy.rand);
		usleep(cowboy.rand);
	if (!strcmp(cowboy.name, "ugly"))
		pthread_mutex_lock(&ugly_gun);
	else
		pthread_mutex_lock(&bad_gun);	
	printf("%s has take his own gun\n", cowboy.name);

	if (!strcmp(cowboy.name, "ugly"))
		pthread_mutex_lock(&bad_gun);
	else
		pthread_mutex_lock(&ugly_gun);
	printf("%s has take stol gun\n", cowboy.name);
	exit(0);
	return (NULL);
}
int main()
{
	t_cowboy ugly;
	t_cowboy bad ;
	bad.name = "bad";
	ugly.name= "ugly";
	srand(time(NULL));
	bad.rand = rand()%1000;
	ugly.rand = rand()%1000;
	pthread_mutex_init(&ugly_gun, NULL);
	pthread_mutex_init(&bad_gun, NULL);

	pthread_create(&ugly.thread, NULL, action, &ugly);
	pthread_create(&bad.thread, NULL, action, &bad);

	pthread_join(ugly.thread, NULL);
	pthread_join(bad.thread, NULL);

	return (0);
}
