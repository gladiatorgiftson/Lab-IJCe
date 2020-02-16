#include <stdio.h>
#include <math.h>
void main()
{
    int nArray[50],wArray[50],nelem,i,j,t;
    clrscr();
    printf("\nEnter the number of elements in an array : ");
    scanf("%d",&nelem);
    printf("\nEnter %d elements\n",nelem);
    for(i=0;i<nelem;i++)
        scanf("%d",&nArray[i]);
    //Calculate the weight
    for(i=0; i<nelem; i++)
    {
        wArray[i] = 0;
        if(percube(nArray[i]))
            wArray[i] = wArray[i] + 5;
        if(nArray[i]%4==0 && nArray[i]%6==0)
            wArray[i] = wArray[i] + 4;
        if(prime(nArray[i]))
            wArray[i] = wArray[i] + 3;
    }
    // Sorting an array
    for(i=0;i<nelem;i++)
        for(j=i+1;j<nelem;j++)
        if(wArray[i] > wArray[j])
        {
            t = wArray[i];
            wArray[i] = wArray[j];
            wArray[j] = t;
        }
        for(i=0; i<nelem; i++)
            printf("<%d,%d>\n", nArray[i],wArray[i]);
            getch();
}
int prime(int num)
{
    int flag=1,i;
    for(i=2;i<=num/2;i++)
    if(num%i==0)
    {
        flag=0;
        break;
    }
    return flag;
}
int percube(int num)
{
    int i,flag=0;
    for(i=2;i<=num/2;i++)
    if((i*i*i)==num)
    {
        flag=1;
        break;
    }
return flag;
}