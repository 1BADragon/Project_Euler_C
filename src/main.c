#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>


int main(int argc, char **argv)
{
  //Check to make sure usage is correct
  if(argc < 2)
  {
    printf("Usage:\n\t%s [test number]\n", argv[0]);
    exit(1);
  }

  //Load the library
  void *sym = dlopen(argv[1], RTLD_NOW);
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

  go();
  return 0;
}
