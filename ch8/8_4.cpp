#include <stdio.h>
#include <math.h>
#include <iostream>


void printPowerSet(char *set, int set_size)
{
    /*set_size of power set of a set with set_size
      n is 2**n, empty set included*/
    unsigned int pow_set_size = pow(2, set_size);
    int counter, j;

    /*Run from counter 000..0 to 111..1*/
    for(counter = 0; counter < pow_set_size; counter++)
    {
      for(j = 0; j < set_size; j++)
       {
          /* Check if jth bit in the counter is set
             If set then print jth element from set */
          if(counter & (1<<j))             //shift 1 to the jth position,
                                           //counter & (1<<j) extracts the jth element of this binary number
            printf("%c", set[j]);
       }
       printf("\n");
    }
}

/*Driver program to test printPowerSet*/
int main()
{
    char set[] = {'a','b','c','d'};
    printPowerSet(set, 4);
    return 0;
}
