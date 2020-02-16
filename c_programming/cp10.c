#include <stdio.h>
#include <conio.h>
void swap(char *s1, char *s2)
{
    char temp;
    temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}
void reverse(char *str, int length)
{
    int start = 0;
    int end = length -1;
    while (start < end)
    {
        swap(&str[start], &str[end]);
        start++;
        end--;
    }
}
char* convert(int num, char str[100], int base)
{
    int i = 0;
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }
    str[i] = '\0'; // Append string terminator
    // Reverse the string
    reverse(str, i);
    return str;
}
void main()
{
    char str[100];
    int n;
    clrscr();
    printf("Enter the given decimal number : ");
    scanf("%d",&n);
    printf("\nThe Binary value : %s\n",convert(n,str,2));
    printf("\nThe Octal value : %s\n",convert(n,str,8));
    printf("\nThe Hexa value : %s\n",convert(n,str,16));
    getch();
}