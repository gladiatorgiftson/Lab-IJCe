#include<stdio.h>
#include<math.h>
int main(void)
{
    int n,i,j;
    printf("How many people's BMI do you want to calculate?\n");
    scanf("%d",&n);
    float massheight[n][2];
    float bmi[n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<2;j++)
        {
            switch(j)
            {
                case 0:
                    printf("\nPlease enter the mass of the person %d in kg: ",i+1);
                    scanf("%f",&massheight[i][0]);
                    break;
                case 1:
                    printf("\nPlease enter the height of the person %d in meter: ",i+1);
                    scanf("%f",&massheight[i][1]);
                    break;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        bmi[i]=massheight[i][0]/pow(massheight[i][1],2.0);
        printf("Person %d's BMI is %f\n",i+1,bmi[i]);
    }
    return 0;
}