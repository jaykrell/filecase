#include <stdio.h>

const char* file1();
const char* file2();

int main()
{
 printf("%s\n%s\n", file1(), file2());
}