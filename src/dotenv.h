#include <stdio.h>
#include <stdlib.h>

/*
*   load_dotenv() loads the .env file in the current directory
*   returns 0 if ok and -1 if there is an error
*/
int load_dotenv();
/*
*   @param name: str -> the name of the environment variable
*   get_env() returns the value of the set environment variable
*/
char * get_env(const char *);
