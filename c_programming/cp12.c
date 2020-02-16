#include <stdio.h>
#include <conio.h>
void towerofhanoi(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        printf("\n Move disk 1 from peg %c to peg %c", from, to);
        return;
    }
    towerofhanoi(n-1, from, aux, to);
    printf("\n Move disk %d from peg %c to peg %c", n, from, to);
    towerofhanoi(n-1, aux, to, from);
}
int main()
{
    int n;
    clrscr();
    printf("Enter the number of disks : ");
    scanf("%d",&n); // Number of disks
    towerofhanoi(n, 'A', 'C', 'B'); // A, B and C are names of peg
    getch();
    return 0;
}