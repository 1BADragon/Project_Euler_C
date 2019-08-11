#include <stdio.h>

void go()
{
  int n1_9 = 3+3+5+4+4+3+5+5+4; //letters from 1 to 9
  int n10_19 = 3+6+6+8+8+7+7+9+8+8; //letters from 10 to 19
  int n20_99 = 10*(6+6+5+5+5+7+6+6) + 8*n1_9; //letters from 20 to 99
  int n1_99 = n1_9+n10_19+n20_99; //All letters from 1 to 99

  int n1_9_100 = n1_9*100; //Letter for the beginning of each number
  int n100_999q = 9*n1_99; //Letters for each number after 'and'
  int hundreds = 7*9; //Hundred occurs 9 times for each 100*n
  int hundred_ands = 9*99*10; //"hundred and" occures 99*9 times

  int n100_999 = n1_9_100 + n100_999q + hundreds + hundred_ands; //all letters between 100 and 999

  int total = n1_99 + n100_999 + 11; //11 for 'one thousand'

  printf("Total: %d\n", total);
}
