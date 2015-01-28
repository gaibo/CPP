/* Print - Format files for printing */

#include <iostream>
#include <cstdlib>

int verbose = 0;				// verbose mode (default = false)
char *out_file = "print.out";	// output file name
char *program_name;				// name of the program (for errors)
int line_max = 66;				// number of lines per page

// do_file -- dummy routine to handle file; Parameter: name -- name of the file to print
void do_file(char *name)
{
	std::cout << "Verbose " << verbose << " Lines " << line_max << " Input " << name << " Output " << out_file << '\n';
}
// usage -- instructions
void usage(void)
{
	std::cerr << "Usage is " << program_name << " [options] [file-list]\n";
	std::cerr << "Options\n";
	std::cerr << "	-v			verbose\n";
	std::cerr << "	-l<number>	Number of lines\n";
	std::cerr << "	-o<name>	Set output filename\n";
	exit (8);
}

int main(int argc, char *argv[])
{
	// save program name for future use
	program_name = argv[0];

	/*
	 * Loop for each option
	 *	Stop if we run out of arguments
	 *	or we get an argument without a dash
	 */
	while ((argc > 1) && (argv[1][0] == '-')) {
		switch (argv[1][1]) {
			// -v verbose
			case 'v':
				verbose = 1;
				break;
			// -o<name>	output file
			//		[0] is dash, [1] is o, [2] begins name
			case 'o':
				out_file = &argv[1][2];
				break;
			// -l<number> set max number of lines
			case 'l':
				line_max = atoi(&argv[1][2]);
				break;
			default:
				std::cerr << "Bad option " << argv[1] << '\n';
				usage();
		}
		// move argument list up one
		// move count down one
		++argv;
		--argc;
	}
	
	/*
	 * At this point all options have been processed.
	 * Check to see if we have no files in the list
	 * and, if so, we need to list just standard in
	 */
	if (argc == 1) {
		do_file("print.in");
	} else {
		while (argc > 1) {
			do_file(argv[1]);
			++argv;
			--argc;
		}
	}
	return (0);
}
