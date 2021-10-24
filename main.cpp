#include <stdio.h>

int main(int argc, char* argv[])
{
    if (2 != argc)
    {
        printf ("usage: %s <path-to-chip-8-rom>\n", argv[0]);
        return 0;
    }

    return 0;
}