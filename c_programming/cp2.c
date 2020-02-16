#include <stdio.h>
#include<conio.h>
void main ()
{
    float basic , da , salary ;
    int code ;
    char name[25];
    da=0.0;
    printf("Enter employee name\n");
    scanf("%[^\n]",name);
    printf("Enter basic salary\n");
    scanf("%f",&basic);
    printf("Enter code of the Employee\n");
    scanf("%d",&code);
    switch (code)
    {
        case 1:
            da = basic * 0.10;
            break;
        case 2:
            da = basic * 0.15;
            break;
        case 3:
            da = basic * 0.20; break;
        default :
            da = 0;
    }
    salary = basic + da;
    printf("Employee name is\n");
    printf("%s\n",name);
    printf ("DA is %f and Total salary is =%f\n",da, salary);
    getch();
}