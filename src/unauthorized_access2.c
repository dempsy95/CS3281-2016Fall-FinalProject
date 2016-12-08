#include <stdio.h>
#include <stdlib.h> 

int main(void)
{
	char *p = malloc(1);
	*p = 'a'; 
	char c = *(p+1); 
	free(p);
	return 0;
}