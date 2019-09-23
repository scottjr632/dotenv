# DOTENV - C
A dotenv implementation for the C programming language

## Getting started
### Load .env file
```C
if (load_dotenv() < 0)
{
  exit(1);
}
```

Returns 0 if ok and -1 if there was an error.
