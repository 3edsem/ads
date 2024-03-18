#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Day {
char *name;
int date;
char *activity;
};
void create(struct Day calendar[7])
{
for (int i = 0; i < 7; i++)
{
calendar[i].name = (char *)malloc(20 * sizeof(char));
printf("Enter day name: ");
scanf("%s", calendar[i].name);
printf("Enter date: ");
scanf("%d", &calendar[i].date);
calendar[i].activity = (char *)malloc(100 * sizeof(char));
}
}
void read(struct Day calendar[7])
{
printf("Enter the activity for each day of the week:\n");
for (int i = 0; i < 7; i++)
{
printf("Day %s: %d - ", calendar[i].name, calendar[i].date);
//gets(calendar[i].activity);
scanf(" %[^\n]s", calendar[i].activity);
}
}
void display(struct Day calendar[7])
{
printf("Week Activity Details:\n");
for (int i = 0; i < 7; i++)
{
printf("Day: %s, Date: %d, Activity: %s\n", calendar[i].name, calendar[i].date, calendar[i].activity);
}
}
int main()
{
struct Day *calendar = (struct Day *) malloc(7 * sizeof(struct Day));
if (calendar == NULL)
{
printf("Memory allocation failed.\n");
return 1;
}
create(calendar);
read(calendar);
display(calendar);
for (int i = 0; i < 7; i++)
{
free(calendar[i].name);
free(calendar[i].activity);
}
free(calendar);
return 0;
}