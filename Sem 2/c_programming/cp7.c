/* Get a Height of Different Persons and find how many of them
are are above average */
#include <stdio.h>
#include <conio.h>
void main()
{
    int i,n,sum=0,count=0,height[100];
    float avg;
    clrscr();
    //Read Number of persons
    printf("Enter the Number of Persons : ");
    scanf("%d",&n);
    //Read the height of n persons
    printf("\nEnter the Height of each person in centimeter\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&height[i]);
        sum = sum + height[i];
    }
    avg = (float)sum/n;
    //Counting
    for(i=0;i<n;i++)
        if(height[i]>avg)
            count++;
    //display
    printf("\nAverage Height of %d persons is : %.2f\n",n,avg);
    printf("\nThe number of persons above average : %d ",count);
    getch();
}