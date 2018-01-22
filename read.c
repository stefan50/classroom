#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fifo = open("lala", O_RDONLY);
	char message;
	while(read(fifo, &message, 1))
	{
		write(STDOUT_FILENO, &message, 1);
	}
	return 0;
}
