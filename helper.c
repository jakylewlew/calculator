#include <stdint.h>
#define INT_DIGITS 11

/****
*	This function will return the null terminated string
*	equivalent of the given integer
*	Input registers:
*		r0 = val
*	Output registers:
*		r0 = first char of string
*****/
char *toStr(int val) {
	static char ret[INT_DIGITS+2];		// +2 for - and '\0'
	char *pend = ret + INT_DIGITS + 1;	// point at '\0'
	// Ensure null termination
	*pend = '\0';
	if( val < 0 ) {
		do {
			pend--;
			*pend = '0' - (val % 10);
			val = val/10;
		} while( val != 0 );
		*--pend = '-';		// negative so add '-'
	} else {
		do {
			pend--;
			*pend = '0' + (val % 10);
			val = val/10;
		} while( val != 0 );
	}
	return pend;
}

/****
*	This function will return an integer equivalent of
*	a given null terminated string
*	Input registers:
*		r0 = first char of string
*	Output registers:
*		r0 = integer equivalent of str
*****/
int toInt(char *str) {
	int res = 0;  // Initialize result
	int sign = 1;  // Initialize sign as positive
	int i = 0;  // Initialize index of first digit

	// If number is negative, then update sign
	if (str[0] == '-') {
		sign = -1;
		i++;  // Also update index of first digit
	}

	// Iterate through all digits and update the result
	for (; str[i] != '\0'; ++i) {
		res = res*10 + str[i] - '0';
	}

	// Return result with sign
	return sign*res;
}

