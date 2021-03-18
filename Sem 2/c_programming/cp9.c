#include <stdio.h>
#include <string.h>
#include <conio.h>
void swap(char *a, char *b)
{
    char t;
    t = *a;
    *a = *b;
    *b = t;
}
// Main program
void main()
{
    char str[100];
    // Function Prototype
    void reverse(char *);
    int isAlpha(char);
    void swap(char *a ,char *b);
    clrscr();
    printf("Enter the Given String : ");
    // scanf("%[^\n]s",str);
    gets(str);
    reverse(str);
    printf("\nReverse String : %s",str);
    getch();
}
void reverse(char str[100])
{
    // Initialize left and right pointers
    int r = strlen(str) - 1, l = 0;
    // Traverse string from both ends until
    // 'l' and 'r'
    while (l < r)
    {
    // Ignore special characters
        if (!isAlpha(str[l]))
            l++;
        else if(!isAlpha(str[r]))
            r--;
        else
        {
            swap(&str[l], &str[r]);
            l++;
            r--;
        }
    }
}
// To check x is alphabet or not if it an alphabet then return 0 else 1
int isAlpha(char x)
{
    return ( (x >= 'A' && x <= 'Z') ||(x >= 'a' && x <= 'z') );
}