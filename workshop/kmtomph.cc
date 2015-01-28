#include <iostream>

long double kmph;
long double mph;

int main() {
    std::cout << "Input speed in kilometers per hour: ";
    std::cin >> kmph;
    mph = kmph * 0.6213712;
    std::cout << "In miles per hour, that is " << mph << '\n';
    return (0); }
