#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct note_t
{
	char message[20];
};
struct board_t
{
	struct note_t note[10];
	int count;
};
struct board_t copy_board(struct board_t);

int main()
{
	int i;
	struct board_t board;
	board.count = 10;
	for(i=0;i<10;i++)
	{
		strcat(board.note[i].message,"Hello");
	}
	struct board_t copy = copy_board(board);
	printf("%s",copy.note[1].message);
	return 0;
}
struct board_t copy_board(struct board_t reference)
{
	int i;
	struct board_t copy;
	copy.count = reference.count;
	for(i=0;i<copy.count;i++)
	{
		strcpy(copy.note[i].message,reference.note[i].message);
	}
	return copy;
}
