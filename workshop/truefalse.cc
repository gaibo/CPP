#include <iostream>
#define MOD10(x) \
	{if (x % 10 == 0) std::cout << "true\n"; else std::cout << "false\n";}

int main()
{
    int input;
    std::cin >> input;
    MOD10(input);
    return (0);
}
