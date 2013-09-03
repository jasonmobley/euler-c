#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
   int value = 20;
   int found = 0;

   while (!found)
   {
      if (value % 10 == 0 && value % 11 == 0 && value % 12 == 0 && value % 13 == 0 && 
            value % 14 == 0 && value % 15 == 0 && value % 16 == 0 && value % 17 == 0 && 
            value % 18 == 0 && value % 19 == 0 && value % 20 == 0)
      {
         found = 1;
      }
      else
      {
         value++;
      }
   }


   printf("The smallest number divisible by 1-20 is %i.\n", value);

   exit(EXIT_SUCCESS);
}

