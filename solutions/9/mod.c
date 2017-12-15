#include <stdio.h>


void go()
{
  int a,b,c;

  for(a = 1; a <= 1000; a++)
  {
    for(b = a + 1; b <= 1000; b++)
    {
      for(c = b + 1; c <= 1000; c++)
      {
        if(((a*a + b*b) == c*c) && ((a + b + c) == 1000))
        {
          goto finish;
        }
      }
    }
  }
finish:
  printf("A: %d, B: %d, C: %d, SUM: %d\n", a, b, c, a+b+c);
  printf("Answer: %d\n", a*b*c);
}
