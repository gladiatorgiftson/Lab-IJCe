#include<stdio.h>
#include<conio.h>
int first=5,second=5,thired=5;
struct node
{
    int ticketno;
    int phoneno;
    char name[100];
    char address[100];
}s[15];
int i=0;
void booking()
{
    printf("enter your details");
    printf("\nname:");
    scanf("%s",s[i].name);
    printf("\nphonenumber:");
    scanf("%d",&s[i].phoneno);
    printf("\naddress:");
    scanf("%s",s[i].address);
    printf("\nticketnumber only 1-10:");
    scanf("%d",&s[i].ticketno);
    i++;
}
void availability()
{
    int c;
    printf("availability cheking");
    printf("\n1.first class\n2.second class\n3.thired class\n");
    printf("enter the option");
    scanf("%d",&c);
    switch(c)
    {
        case 1:
            if(first>0)
            {
                printf("seat available\n");
                first--;
            }
            else
            {
                printf("seat not available");
            }
            break;
        case 2: 
            if(second>0)
            {
                printf("seat available\n");
                second--;
            }
            else
            {
                printf("seat not available");
            }
            break;
        case 3:
            if(thired>0)
            {
                printf("seat available\n");
                thired--;
            }
            else
            {
                printf("seat not available");
            }
            break;
        default:
            break;
    }
}
void cancel()
{
    int c;
    printf("cancel\n");
    printf("which class you want to cancel");
    printf("\n1.first class\n2.second class\n3.thired class\n");
    printf("enter the option");
    scanf("%d",c);
    switch(c)
    {
        case 1:
            first++;
            break;
        case 2:
            second++;
            break;
        case 3:
            thired++;
            break;
        default:
            break;
    }
    printf("ticket is canceled");
}

void chart()
{
    int c;
    for(c=0;c<I;c++)
    {
        printf(“\n Ticket No\t Name\n”);
        printf(“%d\t%s\n”,s[c].ticketno,s[c].name)
    }
}
main()
{
    int n;
    clrscr();
    printf("welcome to railway ticket reservation\n");
    while(1) 
    {
        printf("1.booking\n2.availability cheking\n3.cancel\n4.Chart \n5. Exit\nenter your option:");
        scanf("%d",&n);
        switch(n)
        {
            case 1: 
                booking();
                break;
            case 2: 
            availability();
            break;
            case 3: 
                cancel();
                break;
            case 4:
                chart();
                break;
            case 5:
                printf(“\n Thank you visit again!”);
                getch();
                exit(0);
            default:
                break;
        }
    }
    getch();
}