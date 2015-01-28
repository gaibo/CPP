#include <iostream>
#include <iomanip>

double wage;
int hours;
double pay;

int main()
{
    std::cout << "Give hourly wage: ";
    std::cin >> wage;
    std::cout << "Number of hours worked: ";
    std::cin >> hours;
    if ((hours <= 40) && (hours > 0))
        pay = wage * hours;
    if (hours <= 0)
        std::cout << "NO" << '\n';
    if (hours > 40)
        pay = (hours - 40) * 1.5 * wage + wage * 40;
    std::cout << std::fixed << std::showpoint << std::setprecision(2) <<  "Pay is " << pay << " dollars" << '\n';
    return (0);
}
