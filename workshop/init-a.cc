const int MAX = 10;

// zero out an array with a function
void init_array_1(int data[])
{
	int index;
	for (index = 0; index < MAX; ++index)
		data[index] = 0;
}

// zero out an array another way, with a pointer
void init_array_2(int *data_ptr)
{
	int index;
	for (index = 0; index < MAX; ++index)
		*(data_ptr + index) = 0;
}

#

int main()
{
	int array[MAX];

	// one way of initializing the array
	init_array_1(array);

	// another way of initializing the array
	init_array_1(&array[0]);

	// similar to the first method but with different function
	init_array_2(array);

	return (0);
}
