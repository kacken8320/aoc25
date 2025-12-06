#include <stdio.h>
#include <stdlib.h>


/********************************************************************************/
/*										*/
/*	When does the counter increase?						*/
/*	- when sum == 0								*/
/*		(break here, we DONT want to check for the other cases now)	*/
/*	- when we do sum += 100							*/
/*		except: when sum was 0 in the run before. (only counts for	*/
/*			the first +100, afterwards, we increase)		*/
/*	- when we do sum -= 100							*/
/*										*/
/********************************************************************************/


int main() {
	int sum = 50;
	int prev_sum;
	int counter = 0;
	char input[8];
	int summand;

	/* open file */
	FILE* file;
	file = fopen("inputanh.txt", "r");

	/* read from file, output from file */
	while(fgets(input, 8, file)) {
		printf(input);

		/* convert all L31's to -31 and R43's to 43 */
		if(input[0] == 'L') {
			summand = -atoi(&input[1]);
		} else {
			summand = atoi(&input[1]);
		}

		/* basic operation */
		printf("sum = %d + %d = %d\n", sum, summand, sum + summand);
		sum = sum + summand;

		if(sum == 0) {
			counter++;
			prev_sum = sum;
			continue;
		}

		if(prev_sum == 0 && sum < 0 && sum > -100) {
			counter--;
		}
		while(sum < 0) {
			sum = sum + 100;
			counter++;
		}

		while(sum > 99) {
			sum = sum - 100;
			counter++;
		}

		prev_sum = sum;
	}

	fclose(file);

	printf("solution: %d\n", counter);

	return 0;
}