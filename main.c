#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // To use booleans

#define SIZE 16 // Constant to define memory size

/*
Description:
  Function to print a initial description
Parameters:
  N/A
Output:
  N/A (print in console)
*/
void greet() {
	printf("Welcome");
	printf("\nDescription: Convert a 16-bits decimal integer to a binary, using one's and two's complement");
}

/*
Description:
  Function to print the content of an array
Parameters:
  int * binary -> This is the reference to the array with integers (memory)
Output:
  N/A (print in console)
*/
void print_result(int * binary) {
	int i; // Iteration variable
	printf("\n16-bits Binary Number: "); // Message
	// Loop over the array to print its elements
	for(i=SIZE-1; i>=0; i--)  
	{  
		printf("%u", binary[i]);  
	}
}

/*
Description:
  Function to convert a 16-bits integer to binary, using one's and two's complement
Parameters:
  int number -> This is the 16-bits number that the user input using keyboard
Output:
   binary -> This is the integer array with binary numbers in 16-bits memory
*/
int * convert_decimal_binary(int number) {
	// Variables list
	static int binary[SIZE]; // Represent the array
	int x; // Used for iterations
	int carry = 1; // Used for two's complement
	bool negative = false; // Identify negative numbers
	
	// If the number is negative then it is converted into a positive number, the flag is validated and initialize the array with 1
	if (number < 0)
	{
		number = abs(number); // Convert to a positive number
		negative = true; // Validate the negative number flag
	}
	
	// Initial conversion from decimal to binary
	for(x=0; number>0; x++)
	{
		binary[x]=number%2;
		number=number/2;
	}
	
	// If the flag is active, then apply one's and two's complement
	if (negative == true) {
		// Execution of one's complement
		for(x=0; x<SIZE; x++)
		{
			binary[x] = abs(binary[x]-1);
		}
		
		// Execution of two's complement
		for(x=0; x<SIZE; x++)
		{
			if (binary[x]==1 && carry==1)
			{
				binary[x] = 0;
			}
			else if (binary[x]==0 && carry==1)
			{
				binary[x] = 1;
				carry = 0;
			}
			else
			{
				binary[x] = binary[x];
			}
		}
		
		// Return final array
		return binary;
	} 
	// If the number is positive, then it returns the final array (not applying one's and two's complement)
	else {
		return binary;	
	}
}

/*
Description:
  Main function of the program where we ask for the 16-bits integer decimal number then we call convert_decimal_binary
Parameters:
  N/A (only console-default)
Output:
   0 -> Successful exit 
*/
int main(int argc, char *argv[]) {
	// Variable definition (decimal integer number and binary array)
	int number, *binary;
	// Variable to keep the cycle
	char answer;
	
	// Show initial message
	greet();

	do
	{
		// 16-bits integer number input
		printf("\n16-bits Integer Number: "); // Message for user
		scanf("%d", &number); // Lectura de variable
		
		// Validate that the number is between the valid 16-bits integer value range
		if (number >= -32767 && number <= 32767)
		{
			binary = convert_decimal_binary(number); // Function call
			print_result(binary); // Function call
		}
		else
		{
			printf("\nERROR::The number is out the range of 16-bits numbers"); // Error message for invalid numbers
		}
		
		fflush(stdin);
		printf("\n\nWant to try with another number? Y o N: \n");
        scanf(" %c", &answer);
	} while (answer == 'Y' || answer == 'y');
	
	printf("\nThank for trusting us. Good-bye!\n");
	return 0; // Successful exit of the program
}
