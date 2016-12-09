#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char *argv[])
{
  if (argc != 2)
    {
      fprintf (stderr, "usage: cpu <string>\n");
      exit (1);
    }
  char *str = argv[1];

  char buffer[5];
  sprintf(buffer,"here is the message \n");

  printf("%s\n",buffer);
  return 0;
}
