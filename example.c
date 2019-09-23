#include "src/dotenv.h"

void println(char * msg)
{
	printf("%s\n", msg);
}

int main()
{
    if(load_dotenv() < 0)
	{	
		println("No .env file could be found");
		println("Exiting...");
		return 1;
	}

    println(get_env("SERVER_PORT"));
    println(get_env("SERVER_URL"));

	return 0;
}
