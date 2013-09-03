#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
   unsigned long long sum = 0;
   unsigned long long sum_of_squares = 0;
   unsigned long long square_of_sum = 0;
   unsigned long long difference = 0;
   unsigned long long i;

   for (i = 1; i <= 100; i++)
   {
      sum += i;
      sum_of_squares += (i*i);
   }

   square_of_sum = sum*sum;
   difference = square_of_sum - sum_of_squares;

   printf("The sum of the squares is %llu.\n", sum_of_squares);
   printf("The square of the sum is %llu.\n", square_of_sum);
   printf("The difference is %llu.\n", difference);

   exit(EXIT_SUCCESS);
}

