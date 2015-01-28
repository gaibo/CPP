#include <iostream>
int result;		// the result of the calculations
char oper_char;	// the user-specified operator
int value;		//value specified after the operator
int main()
{
    result = 0;	// initialize the result

    // loop forever (or until break reached)
    while (1) {
        std::cout << "Result: " << result << '\n';
		std::cout << "Enter operator and number: ";

		std::cin >> oper_char;

		if ((oper_char == 'q') || (oper_char == 'Q'))
			break;

		std::cin >> value;
		if (oper_char == '+') {
			result += value;
		} else if (oper_char == '-') {
			result -= value;
		} else if (oper_char == '*') {
			result *= value;
		} else if (oper_char == '/') {
			if (value == 0) {
				std::cout << "Error: Divide by zero\n";
				std::cout << "	operation ignored\n";
			} else
				result /= value;
		} else {
			std::cout << "Unknown operator " << oper_char << '\n';
		}
	}
	return (0);
}
