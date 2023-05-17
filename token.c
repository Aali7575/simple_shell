#include "main.h"

int main()
{
	char *token;
	char str[] = "hello world, i am using strtok";
	 char delimiters[] = " ,";

	  token = strtok(str, delimiters);

	   while( token != NULL ) {
      printf( " %s\n", token ); //print the token
      token = strtok(NULL, delimiters); //get next token
   }

   return 0;
}
