#include <iostream>

int counter;		// 3 counters for 3 layers of repeat and horizontal and vertical dimensions
int counter1;
int counter2;
int horiz;
int verti;

int main()
{	
	std::cout << "Make a checkerboard by specifying horizontal and vertical dimensions\n";
	std::cout << "Horizontal: ";
	std::cin >> horiz;
	std::cout << "Vertical: ";
	std::cin >> verti;

/* Here begins the loops of construction */

	for (counter2 = 0; counter2 < verti; ++counter2) {		// for repeating the first four unique lines
		for (counter = 0; counter < horiz; ++counter) {		// for first line
			std::cout << "+-----";
		}
		std::cout << "+\n";

		for (counter1 = 0; counter1 < 3; ++counter1) {		// for next three lines.  
/******************* NOTE: Modify the 3 right above to change vertical height of checkerboard blocks. ************************/
			for (counter = 0; counter < horiz; ++counter) {
				std::cout << "|     ";
			}
				std::cout << "|\n";
		}
	}
	
	for (counter = 0; counter < horiz; ++counter) {
		std::cout << "+-----";
	}
	std::cout << "+\n";

	return (0);
}
