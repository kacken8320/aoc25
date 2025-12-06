#include <stdio.h>
#include <stdlib.h>

/********************************/
/*				*/
/* L -> minus			*/
/* R -> plus			*/
/* Base: 99			*/
/* Answer: Amounts of time the	*/
/* 	calculation equals 0	*/
/*				*/
/********************************/

int main() {
	int sum = 50;
	int counter = 0;
	char input[8];

	/* open file */
	FILE* file;
	file = fopen("input.txt", "r");

	/* read from file, output from file */
	while(fgets(input, 8, file)) {
		printf(input);

		/* decide for plus or minus */
		if(input[0] == 'L') {
			/* subtract */
			printf("sum = %d - %d\n", sum, atoi(&input[1]));
			sum = sum - atoi(&input[1]);
		} else {
			/* add */
			printf("sum = %d + %d\n", sum, atoi(&input[1]));
			sum = sum + atoi(&input[1]);
		}

		/* keep sum between 0 and 99 */
		if(sum < 0) {
			sum = 100 + sum;
		}
		sum = sum % 100;
		printf("sum: %d\n", sum);

		/* if sum equals 0, increase counter */
		/* what an informative comment */
		if(sum == 0) {
			counter++;
			printf("counter: %d\n", counter);
		}
	}

	fclose(file);

	printf("solution: %d\n", counter);

	return 0;
}
