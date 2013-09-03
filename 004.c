#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_palindrome(char* string);

int main(int argc, char **argv)
{
   char buffer[7];
   int i, j, product;
   int max_palindrome = 0;

   for (i = 100; i < 1000; i++)
   {
      for (j = 100; j < 1000; j++)
      {
         product = i * j;
         sprintf(buffer, "%i", product);
         if (is_palindrome(buffer) && product > max_palindrome)
         {
            max_palindrome = product;
         }
      }
   }

   printf("The largest palindrome is %i.\n", max_palindrome);

   exit(EXIT_SUCCESS);
}

int is_palindrome(char* string)
{
   int same_forward_and_backward = 0;
   size_t length = strlen(string);
   char *reverse = malloc(length + 1);

   size_t i = 0;

   while (string[i] != '\0')
   {
      reverse[length-1-i] = string[i];
      i++;
   }

   reverse[length] = '\0';

   if (0 == strcmp(string, reverse))
   {
      same_forward_and_backward = 1;
   }

   free(reverse);

   return same_forward_and_backward;
}

