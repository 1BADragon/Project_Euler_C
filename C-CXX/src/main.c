#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)
{
    //Check to make sure usage is correct
    if(argc < 2)
    {
        printf("Usage:\n\t%s [test number]\n", argv[0]);
        exit(1);
    }

    clock_t start, stop;
    char buf[100];
    memset(buf, 0, 100);

#if __unix
    snprintf(buf, 100, "solutions/libtest%d.so", atoi(argv[1]));
#else
    snprintf(buf, 100, "solutions/libtest%d.dll", atoi(argv[1]));
#endif

    //Load the library
    void *sym = dlopen(buf, RTLD_NOW);
    if(sym == NULL)
    {
        printf("dlopen: %s\n", dlerror());
        exit(1);
    }

    //Find go and run it
    void (*go)(void) = (void(*)(void))dlsym(sym, "go");
    if(go == NULL)
    {
        printf("dlsym: %s\n", dlerror());
        exit(1);
    }
    start = clock();
    go();
    stop = clock();

    printf("Solution took %6.3fms.\n", ((double)(stop - start) / CLOCKS_PER_SEC) * 1000.);

    return 0;
}
