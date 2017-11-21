#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
//argv[1] = times
//argv[2] = programme to be executed
	int times = atoi(argv[1]);
	const int l = strlen(argv[2]);
	char* file = (char*)malloc(l*sizeof(char));
	strcpy(file,argv[2]);
	for(int i=0; i<times; i++)
	{
		pid_t pid = fork();
		if(pid == 0)
		{
			execlp(file,file,NULL);
		}
		else
		{
			wait(NULL);
		}
	}
	free(file);
	return 0;
}
