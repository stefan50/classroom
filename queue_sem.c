#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>

typedef sem_t Semaphore;
Semaphore dance_sem;
Semaphore lead_sem;

void* dancer_come()
{
	sem_post(&dance_sem);
	sem_wait(&lead_sem);
}

void* leader_come()
{
	sem_post(&lead_sem);
	sem_wait(&dance_sem);
}

int main()
{
	int dancers;
	int leaders; 
	pthread_t threads[100];
	sem_init(&dance_sem, 0, 0);
	sem_init(&lead_sem, 0, 0);

	for(int i=0; i<5; i++)
	{
		pthread_create(threads+i, NULL, dancer_come, NULL);
		pthread_create(threads+i+5, NULL, leader_come, NULL);
	}
	for(int i=0; i<5; i++)
	{
		pthread_join(threads[i], NULL);
		pthread_join(threads[i+5], NULL);
	}

	sem_getvalue(&dance_sem, &dancers);
	sem_getvalue(&lead_sem, &leaders);
	printf("Dancers: %d, Leaders: %d\n", dancers, leaders);

	sem_destroy(&dance_sem);
	sem_destroy(&lead_sem);
	return 0;
}
