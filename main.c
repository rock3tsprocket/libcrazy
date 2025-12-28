#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long int dectotern(long int tobeterned) {
	/* Conversion to ternary */
	int remainder;
	char resultstr[21];
	char tempresult[2];
	
	while (1L) {
		remainder = tobeterned % 3;
		tobeterned = tobeterned / 3;
		snprintf(tempresult, 2, "%ld", remainder);
		strcat(resultstr, tempresult);
		if (tobeterned == 0) break;
	}
	
	/* Reversing the string result
	 * (taken from GeeksForGeeks as
	 * I am too stupid to do it myself)  */
	int l = 0;
	int r = strlen(resultstr) - 1;
	char t;

	/* Swap characters till l and r meet */
	while (l < r) {
		/* Swap characters */
		t = resultstr[l];
		resultstr[l] = resultstr[r];
		resultstr[r] = t;

		/* Move pointers towards each other */
		l++;
		r--;
	}
	
	return strtol(resultstr, NULL, 10);

}

int main(int argc, char *argv[]) {
	long int tern = dectotern(strtol(argv[1], NULL, 10));
	printf("%ld\n", tern);
}
