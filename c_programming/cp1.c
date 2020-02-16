/* 
*Sum the odd and even numbers respectively,from 1 to given upperbound
*compute its difference
*/
#include <stdio.h>
//need for IO  functions

int main()
{
    //variable initialization
    int sumOdd = 0 ;
    int sumEven = 0;
    int  number = 1;
    //starting from 1 as 0 has no addition
    int upperbound;
    int absdiff;
    //Getting input for upper bound
    printf("Enter the upper bound:");
    scanf("%d",&upperbound);
    //%d is for getting a integer input
    /* using the while loop we going to iterate
    till the upperbound
    condition : while(number<=upperbound)
    <= is used because to include the upperbound
    and the number is incremented by 1
    */
   while (number <=upperbound)
   {
       /*using if condition seperately add
       odd and even numbers*/
       if(number%2==0)//condition for even no else it is odd
       {
           sumEven+=number;
       }
       else
       {
           sumOdd+=number;
       }
       ++number;
   }
   //after exiting while loop we calulate the difference between odd and even no
   if(sumOdd>sumEven)
   {
       absdiff = sumOdd - sumEven;
   }
   else
   {
       absdiff = sumEven - sumOdd ;
   }
   //print the results
   printf("The sum of odd numbers is %d.\n",sumOdd);
   printf("The sum of Even numbers is %d.\n",sumEven);
   printf("The absolute difference is %d.\n",absdiff);
   
   return 0 ;

}