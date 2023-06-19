#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


char *_getenv(const char *name);
extern char **environ;

int main(void)
{
        char *value = _getenv("SHELL"); // Retrieve the value of the "PATH" environment variable
        if (value != NULL)
                {
                printf("The value of SHELL using _getenv is: %s\n", value);
            }
                else
                {
                        printf("SHELL environment variable not found.\n");
                }

        char *value2 = getenv("SHELL"); // Retrieve the value of the "PATH" environment variable
        if (value2 != NULL)
                {
                printf("\n\nThe value of SHELL using getenv is: %s\n", value2);
        }
                else
                {
                printf("SHELL environment variable not found.\n");
        }

    return (0);
}




char *_getenv(const char *name)

{
        int i = 0;
        int len = strlen(name);

        while(environ[i] != NULL)
        {
                char *check;


                check = strstr(environ[i], name); //strstr will return a pointer to the first occurence of the string environ[i] in string name
                        if (check != NULL)
                        {
                                return (check + len + 1); //since env var as usually of the format var=value, hence, we need to return a pointer to v in value so it can be printed
                        }
                        i++;
        }
        return NULL;

}
