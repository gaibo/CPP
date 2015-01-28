#include <iostream>

int celsius;
int fahrenheit;

int main()
{
    std::cout << "Input temperature in degrees Celsius: ";
    std::cin >> celsius;
    fahrenheit = celsius * 9 / 5 + 32;
    std::cout << "In Fahrenheit, it is " << fahrenheit << '\n';
    return (0);
}
