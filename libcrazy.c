/* Copyright 2025 rock3tsprocket

Redistribution and use in source and binary forms, with or without modification, are permitted
provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and
the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions
and the following disclaimer in the documentation and/or other materials provided with the
distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to
endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS “AS IS”
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */

#include <stdio.h>
#include <stdbool.h>
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

long int crazy(long int tobecrazied1, long int tobecrazied2, bool areintstern, bool returntern) {
	if (areintstern != 1) {
		tobecrazied1 = dectotern(tobecrazied1);
		tobecrazied2 = dectotern(tobecrazied2);
	}
    
	char crazied1[21];
	char crazied2[21];
	snprintf(crazied1, 21, "%ld", tobecrazied1);
	snprintf(crazied2, 21, "%ld", tobecrazied2);

	/* Preparing result variables */
	int trit1 = 0;
	int trit2 = 0;
	int tritresult = 0;
	char tempresult[2];
	char resultstr[21];

	/* Performing the *crazy* operation per the table at
	 * https://en.wikipedia.org/wiki/Malbolge#Crazy_operation */
	size_t length = strlen(crazied1) > strlen(crazied2) ? strlen(crazied1) : strlen(crazied2);

	for (int i = 0; i < (int) length; i++) {
		trit1 = crazied1[i] - '0';
		trit2 = crazied2[i] - '0';
		int tritresult = 0;
		if ((trit1 == 1 && trit2 == 0) ||
		    (trit1 == 2 && trit2 == 0) ||
		    (trit1 == 1 && trit2 == 1)) tritresult = 0;

		else if ((trit1 == 0 && trit2 == 0) ||
		 (trit1 == 0 && trit2 == 1) ||
		 (trit1 == 2 && trit2 == 2)) tritresult = 1;

        else if ((trit1 == 2 && trit2 == 1) ||
		 (trit1 == 0 && trit2 == 2) ||
		(trit1 == 1 && trit2 == 2)) tritresult = 2;

		snprintf(tempresult, 2, "%ld", tritresult);
		strcat(resultstr, tempresult);
	}

	long int result = !returntern ? strtol(resultstr, NULL, 3) : strtol(resultstr, NULL, 10);
	return result;
}
