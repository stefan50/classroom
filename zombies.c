#include "ui.h"
#include <stdio.h>
#include <curses.h>
#include <pthread.h>
#include <unistd.h>

int gold = 100;
int soldiers = 15;

void* mine()
{
	//insert mutex
	if(gold >= 100)
	{
		gold -= 100;
	}
	else
	{
		print_fail("Not enough gold!\n");
		//clrtoeol();
	}
	//insert mutex out
	while(1)
	{
		print_gold(gold);
		//insert mutex
		gold += 10;
		//insert mutex out
		sleep(1);
	}
}

//void

int main() 
{
	init();
	print_gold(gold);
	print_soldiers(soldiers);
	print_zombies(5, 13);
	print_health(100);
	pthread_t threads[100];
	int peeps = 0;

	while(1) 
	{
		int ch = get_input();
		switch(ch) 
		{
			case 'm':
				peeps++;	
				pthread_create(threads+peeps, NULL, mine, NULL);				
				break;
			case 's':
				move(10, 10);
				//clrtoeol();		
				printw("af");

				break;
			case 'x':
				
				break;
			
			case 'q':
				game_end(1);
				break;
		}
	}
}
