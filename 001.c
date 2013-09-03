#include <stdio.h>

int main()
{
   int i, sum;
   i = 0;
   sum = 0;

   while (i < 1000)
   {
      if (i % 3 == 0 || i % 5 == 0)
      {
         sum += i;
      }
      i++;
   }

   printf("The sum is %i.\n", sum);

   return 0;
}

