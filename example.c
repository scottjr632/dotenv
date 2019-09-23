#include "src/dotenv.h"

int main()
{
    if (load_dotenv() < 0)
    {
        return 1;
    }

    printf("%s\n", get_env("SERVER_PORT"));
    printf("%s\n", get_env("SERVER_PORT"));
    
    return 0;
}
