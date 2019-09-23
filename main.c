#include "src/dotenv.h"

int main()
{
    load_dotenv();

    printf("%s\n", get_env("SERVER_PORT"));
    printf("%s\n", get_env("SERVER_PORT"));
}