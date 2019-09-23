#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#include "dotenv.h"



char * get_env(const char * name)
{
    char * value = (char*)malloc(sizeof(char));
	value = getenv(name);
	return value;
}

static bool is_commented(char * line)
{
    if (line[0] == '#')
    {
        return true;
    }

    int i = 0;
    while (line[i] == ' ')
    {
        if (line[0] == '#')
        {
            return true;
        }
    }


    return false;
}

static char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}

int load_dotenv()
{
	FILE *file;
	size_t nread = 0;

	char *line = NULL, *value;
	char** tokens;

	file = fopen(".env", "r");
	if (file)
	{
		while(getline(&line, &nread, file) > 0)
		{
			tokens=str_split(line, '=');
			if (tokens && !is_commented(line))
			{
                value = strtok_r(NULL, "\n", (tokens + 1));
				setenv(*(tokens + 0), value, 1);
				free(tokens);
			}
		}
		if (ferror(file))
			return -1;
		fclose(file);
	}
	else
	{
		printf("No file provided");
	}
	return 0;
}

