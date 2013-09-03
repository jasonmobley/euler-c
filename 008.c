#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#define NUM_DIGITS 1000

int main(int argc, char **argv)
{
   FILE* number_file;
   char* filename;
   char buffer[NUM_DIGITS+1];

   if (argc > 1)
   {
      filename = argv[1];
   }
   else
   {
      printf("No filename given.\n");
      exit(EXIT_FAILURE);
   }

   number_file = fopen(filename, "r");

   if (NULL == number_file)
   {
      printf("The file %s does not exist.\n", filename);
      exit(EXIT_FAILURE);
   }

   if (NULL != fgets(buffer, NUM_DIGITS+1, number_file))
   {
      printf("My buffer is full.\n");
   }
   else
   {
      printf("Could not read from the file!\n");
   }

   fclose(number_file);

   int index = 4;
   int d1, d2, d3, d4, d5;
   int currentProduct = 0;
   int maxProduct = 0;

   do
   {
      d1 = buffer[index-4] - '0';
      d2 = buffer[index-3] - '0';
      d3 = buffer[index-2] - '0';
      d4 = buffer[index-1] - '0';
      d5 = buffer[index] - '0';

      if (d1 == 0 || d2 == 0 || d3 == 0 || d4 == 0 || d5 == 0)
      {
         continue;
      }

      currentProduct = d1 * d2 * d3 * d4 * d5;

      if (currentProduct > maxProduct)
      {
         maxProduct = currentProduct;
      }
   }
   while (++index < NUM_DIGITS);

   printf("Max product of 5 consecutive digits: %d\n", maxProduct);

   exit(EXIT_SUCCESS);
}

