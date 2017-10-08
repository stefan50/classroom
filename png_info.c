//Stefan Angelov, 11a, N24
#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>
#include "read.h"

void png_info(uint8_t*);
void png_or_not(uint8_t*);

int main(int argc,char* argv[])
{
	uint8_t* png_file=read_image(argv[1]);
	png_or_not(png_file);
	return 0;
}

void png_info(uint8_t* png_file)
{
	uint8_t png_start[8] = {0x89,0x50,0x4E,0x47,0x0D,0x0A,0x1A,0x0A}; //how a png should start
	uint8_t ihdr[4] = {0x49,0x48,0x44,0x52}; //hexadecimals indicating ihdr chunk
	uint8_t iend[4] = {0x49,0x45,0x4E,0x44}; //hexadecimals indicating iend chunk
	uint32_t i=0,j=0;
	uint32_t width=0,height=0,size=0,flag;
	for(i=0;i<8;i++)
	{
		if(*(png_file+i)!=png_start[i])
		{
			printf("Unable to parse file\n");
			return;
		}
	}
	while(1)
	{
		flag=1;
		for(j=i;j<i+4;j++)
		{
			if(*(png_file+j)!=ihdr[j-i])
			{
				flag--;
				break;
			}
		}
		if(flag==1)
		{
			width = *(uint32_t*)(png_file+i+4);
			width = ntohl(width);
			height = *(uint32_t*)(png_file+i+8);
			height = ntohl(height);
			i++;
			break;
		}
		i++;
	}
	while(1)
	{
		flag=1;
		for(j=i;j<i+4;j++)
		{
			if(*(png_file+j)!=iend[j-i])
			{
				//printf("%x\n",*(png_file+j));
				flag--;
				break;
			}
		}
		if(flag==1)
		{
			size=j+4;
			break;	
		}
		i++;
	}
	printf("PNG image width: %d\nPNG image height: %d\nPNG file size: %d\n",width,height,size);	
}
void png_or_not(uint8_t* png_file)
{
	if(png_file != NULL)
	{
		png_info(png_file);
	}
	else
	{
		printf("Unable to open file\n");
	}
}
