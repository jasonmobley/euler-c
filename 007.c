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

bool is_prime(uint64 value);

int main(int argc, char **argv)
{
   uint64 current_value = 3;
   uint64 primes_found = 2;

   while (primes_found < 10001)
   {
      current_value += 2;
      if (is_prime(current_value))
      {
         primes_found++;
      }
   }

   printf("The 10001st prime is %llu.\n", current_value);

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

