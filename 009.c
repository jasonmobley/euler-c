#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv)
{
   printf("Perfect squares up to 1000:\n");

   double current_number = 1;
   double current_square = 1;

   do
   {
      printf("%.0f\n", current_square);
      current_square = pow(++current_number, 2);
   }
   while (current_square < 1000);

   printf("\n");

   exit(EXIT_SUCCESS);
}
