#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <errno.h>

#define TRUE  1
#define FALSE 0
typedef unsigned char bool;
typedef long int32;
typedef long long int64;
typedef unsigned long uint32;
typedef unsigned long long uint64;

#define MAX_FACTORS 100

bool is_prime(uint64 value);

int main(int argc, char **argv)
{
   uint64 arg = 0;
   uint64 factors[MAX_FACTORS];

   char *str, *endptr;

   if (argc < 2)
   {
      printf("No argument.\n");
      exit(EXIT_FAILURE);
   }

   errno = 0;

   str = argv[1];
   arg = strtoull(str, &endptr, 0);

   if (errno == ERANGE || arg == ULLONG_MAX || arg == 0 && errno != 0)
   {
      printf("Value conversion failed (strtoull).\n");
      exit(EXIT_FAILURE);
   }

   printf("Argument value is %llu.\n", arg);

   uint64 work_arg = arg;
   uint64 root_arg = ((uint64)sqrtl((long double)arg)) + 1;
   uint64 i;
   uint64 factor_index = 0;

   printf("Factors: ");

   for (i = 2; i < root_arg; i++)
   {
      if (work_arg % i == 0 && is_prime(i))
      {
         factors[factor_index++] = work_arg;
         work_arg = work_arg / i;

         printf("%llu ", i);
      }

      if (factor_index == MAX_FACTORS)
      {
         printf("Number of factors exceeded %i. Quitting.\n", MAX_FACTORS);
         exit(EXIT_FAILURE);
      }
   }

   printf("\nThe largest factor of %llu is %llu.\n", arg, factors[factor_index-1]);

   exit(EXIT_SUCCESS);
}

bool is_prime(uint64 value)
{
   uint64 i, root_value_plus_one;
   root_value_plus_one = ((uint64)sqrtl((long double)value)) + 1;

   for (i = 2; i < root_value_plus_one; i++)
   {
      if (value % i == 0)
      {
         return FALSE;
      }
   }
   return TRUE;
}

