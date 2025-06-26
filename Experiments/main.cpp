
#include <stdio.h>
#include <string.h>
#include <cstring>
using namespace std;

void main()
{
    char str[] = "- This, a sample string.";
    char* pch;
    printf("Splitting string \"%s\" into tokens:\n", str);
    pch = std::strtok(str, " ,.-");
    while (pch != NULL)
    {
        printf("%s\n", pch);
        pch = std::strtok(NULL, " ,.-");
    }
    
}