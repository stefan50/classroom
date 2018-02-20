#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void* num_primes(void* num)
{
	int n = *(int*)num;
	bool is_prime = true;
	int n_prime = 0;
	for(int i=2; i<n; i++)
	{
		is_prime = true;
		for(int j=2; j<i; j++)
		{
			if(i%j==0)
			{
				is_prime = false;
				break;
			}
		}
		if(is_prime)
		{
			n_prime++;
		}		
	}
	printf("Number of primes for N=%d is %d\n",n,n_prime);
	return NULL;
}

int main()
{
	char input[1024];
	char* in = input;
	size_t size = 1024;
	while(1)
	{
		pthread_t threads;
		getline(&in, &size, stdin);
		char* num = (input+2);
        int n = atoi(num);
		switch(input[0])
		{
			case 'p':
				printf("Prime calculation started for N=%d\n", n);
				pthread_create(&threads, NULL, num_primes, &n);
				break;
			case 'e':
				pthread_exit(NULL);
				break;
			default:
				printf("Commands that can be executed:\n\t* p\n\t* e\n");
				break;
		}
	}
	return 0;	
}
