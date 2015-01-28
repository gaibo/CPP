#include <iostream>

int counter;		// 3 counters for 3 layers of repeat
int counter1;
int counter2;
int horiz;		// horizontal and vertical dimensions
int verti;

void horizontal_line(void);		// declaring functions
void vertical_part(void);

int main()
{	
	std::cout << "Make a checkerboard by specifying horizontal and vertical dimensions\n";
	std::cout << "Horizontal: ";
	std::cin >> horiz;
	std::cout << "Vertical: ";
	std::cin >> verti;

/* Here begins the loops of construction (tucked away in the functions now) */

	// for repeating the first four unique lines
	for (counter2 = 0; counter2 < verti; ++counter2) {

		horizontal_line();		// for first line

		vertical_part();		// for the next three lines
	}
	
	// additional bottom line not possible with simple replication
	horizontal_line();

	return (0);
}


/* repeated function for +-----+ */
void horizontal_line(void)
{
	for (counter = 0; counter < horiz; ++counter) {
		std::cout << "+-----";
	}
	std::cout << "+\n";
}

/* repeatable function for |      */
void vertical_part(void)
{
	for (counter1 = 0; counter1 < 3; ++counter1) {		// for next three lines.  
/*************** NOTE: Modify the 3 right above to change vertical height of checkerboard blocks. ****************/
		for (counter = 0; counter < horiz; ++counter) {
			std::cout << "|     ";
		}
			std::cout << "|\n";
	}
}
