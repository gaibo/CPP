#include <iostream>
#include <string.h>

int word_count(char input[]);
char words[10000];

int main()
{
	std::cout << "Input words to count: ";
	std::cin.getline(words, sizeof(words));
	std::cout << word_count(words) << " word(s)\n";
	return (0);
}


// defining a word as a group of one or more letters, either with spaces in front, behind, or on both sides
int word_count(char input[])
{
	int index;
	int counter;
	int length;

	counter = 0;		// set up counter
	length = strlen(input);		// use alternate designated variable to save time
	for (index = 0; index < length; ++index) {		// for loop for evaluating each character as to whether it is a space
		if (input[index] == ' ')
			++counter;
	}
	return (counter + 1);		// number of spaces correlates roughly to number of words
}
