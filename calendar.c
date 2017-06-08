#include <stdio.h>
#include <stdlib.h>

struct calendar_t
{
	int events_count[52];
};
struct events_month_t
{
	int events[13];
};
struct events_month_t events_per_month(struct calendar_t);

int main()
{
	int i;
	struct calendar_t calendar;
	for(i=0;i<52;i++) calendar.events_count[i] = 2;
	struct events_month_t year = events_per_month(calendar);
	for(i=0;i<13;i++)
		printf("%d\n",year.events[i]);
	return 0;
}
struct events_month_t events_per_month(struct calendar_t calendar)
{
	int i,j=0,k=0;
	struct events_month_t result;
	for(i=0;i<13;i++) result.events[i] = 0;
	for(i=0;i<13;i++)
	{
		k+=4;
		while(j<k)
		{
			result.events[i] += calendar.events_count[j];
			j++;
		}
	}
	return result;
}
