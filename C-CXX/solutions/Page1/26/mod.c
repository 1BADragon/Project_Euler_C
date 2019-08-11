#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

void go()
{
    int sequenceLength = 0;
    int num = 0;

    for (int i = 1000; i > 1; --i)
    {
        if (sequenceLength >= i)
        {
            break;
        }

        int *foundRemainders = calloc(i, sizeof(int));
        int value = 1;
        int position = 0;

        while (foundRemainders[value] == 0 && value != 0)
        {
            foundRemainders[value] = position;
            value = value * 10;
            value = value % i;
            position++;
        }

        if (position - foundRemainders[value] > sequenceLength)
        {
            num = i;
            sequenceLength = position - foundRemainders[value];
        }

        free(foundRemainders);
    }

    printf("Answer: %d(%d)\n", num, sequenceLength);
}
