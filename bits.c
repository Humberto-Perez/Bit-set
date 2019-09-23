#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
/*
 * Humberto Perez PID: 3747565
 * I affirm that I wrote this program myself without the help of others or the internet
 * Description: This program grabs a number between 1 and 1000 from the user and either sets or clears a bit of the users choice
 */

//Method that prompts the user takes their number and bit and alters accordingly
//Using bitwise operations
void bitOperation()
{
   int n;
   int m;
   int l;
   printf("Enter a number between 1 and 1000 ");
   scanf("%d", &n);
   
   if (n <= 0 || n >= 1001)
   {
     printf("Outside of range\n");
     exit(1);
   }
   if(n >= 1 || n <= 1000)
   {
      uint32_t bn = n;	
      printf("Choose a bit from 0 to 31  to change to zero or one ");
      scanf("%d", &m);
     
      if(m >= 32)
      {
	printf("Outside of range\n");
 	exit(1);
      }

      if(m >= 0 || m <= 31)
      {
	 printf("Press 1 to set bit to 1 or press 0 to clear bit to 0 ");
         scanf("%d", &l);
	 if(l >= 2) 
	 {
	    printf("Outside of range\n");
	    exit(1);
         }
  	 bn ^= (-l ^ bn) & (1 << m);
	 printf("%u\n", bn);
      }
   } 
}
//Recursive method that relaunches bitOperation until the user is done
void doAgain()
{
   int k;
   printf("Would you like to do it again? If yes press 1 if no press 0 ");
   scanf("%d", &k);
   if(k == 1)
   {
     bitOperation();
     doAgain();
   }
   if(k == 0)
   {
     printf("Thank you goodbye.\n");
   } 
}

int main()
{	 
	
	bitOperation();
	doAgain();
}
