#include <iostream>
#include <math.h>

int x_1;
int x_2;
int y_1;
int y_2;
int distance;

int main() {
    std::cout << "First ordered pair in form x y: ";
    std::cin >> x_1 >> y_1;
    std::cout << "Second ordered pair: ";
    std::cin >> x_2 >> y_2;
    distance = pow((x_1 - x_2),2) + pow((y_1 - y_2),2);
    std::cout << "The square of the distance between points is " << distance << '\n';
    return (0);  }
