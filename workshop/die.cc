#include <iostream>
#include <stdlib.h>

int main()
{
    int value;

    value = 1;
    if (value < 0) {
        std::cout << "Fatal Error: Abort\n";
        exit(8);
    }

    std::cout << "We did not die\n";
    return (0);
}
