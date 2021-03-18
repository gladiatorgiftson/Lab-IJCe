/*
* C Program for Addition, Subtraction, Multiplication, Division
* and square of two numbers
*/
#include <stdio.h>
#include <conio.h>
int main()
{
    /* Variable declation */
    int firstNumber, secondNumber;
    int sum, difference, product;
    long square;
    float quotient;
    /* Taking input from user and storing it in firstNumber and secondNumber */
    printf("Enter First Number: ");
    scanf("%d", &amp;firstNumber);
    printf("Enter Second Number: ");
    scanf("%d", &amp;secondNumber);
    /* Adding two numbers */
    sum = firstNumber + secondNumber;
    /* Subtracting two numbers */
    difference = firstNumber - secondNumber;
    /* Multiplying two numbers*/
    product = firstNumber * secondNumber;
    /* Dividing two numbers by typecasting one operand to float*/
    quotient = (float)firstNumber / secondNumber;
    /* returns remainder of after an integer division */
    square = firstNumber *firstNumber;
    printf("\nSum = %d", sum);
    printf("\nDifference = %d", difference);
    printf("\nMultiplication = %d", product);
    printf("\nDivision = %.3f", quotient);
    printf("\n Square= %ld", square);
    getch();
    return 0;
}