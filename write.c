#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 50

int main()
{
	int fifo = open("lala", O_WRONLY);
	char** message;
	scanf("%ms", message);
	write(fifo, message, strlen(message));
	free(message);
	return 0;
}
