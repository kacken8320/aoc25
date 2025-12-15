#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_max_1(char*);
int find_max_2(char*, int);

int main(int argc, char* argv[]) {
	char buffer[256];
	int max_1;
	int max_2;
	int max;
	int sum = 0;
	FILE* file = fopen(argv[1], "r");

	while(fgets(buffer, 256, file)) {
		/* 2873489734923\n\0 */
		if(buffer[strlen(buffer) - 1] == '\n') {
			buffer[strlen(buffer) - 1] = '\0';
		}
		for(int i = 0; i < strlen(buffer); i++) {
			/* ultra smarter way of ascii -> int  weil '0' ist automatisch der ascii wert den man abziehen kann */
			printf("%d", buffer[i] - '0');
		}

		max_1 = find_max_1(buffer);
		max_2 = find_max_2(buffer, max_1);
		max = 10 * (buffer[max_1] - '0') + buffer[max_2] - '0';
		sum += max;

		printf(" max1 index: %d zahl: %d", max_1, buffer[max_1] - '0');
		printf(" max2 index: %d zahl: %d", max_2, buffer[max_2] - '0');
		printf(" also zahl: %d%d\n", buffer[max_1] - '0', buffer[max_2] - '0');

	}

	printf("%d\n", sum);
	fclose(file);

    return 0;
}


int find_max_1(char* input) {
	int temp;
	for(int i = 0; i < strlen(input) - 1; i++) {
		temp = i;
		for(int j = 0; j < strlen(input) - 1; j++) {
			if((input[j] - '0') > input[temp] - '0') {
				temp = j;
			}
		}
	}
	return temp;
}

int find_max_2(char* input, int indx) {
	int temp;
	for(int i = indx; i < strlen(input); i++) {
		temp = i;
		if(i == indx) {
			temp = i++;
		}
		for(int j = indx; j < strlen(input); j++) {
			if((input[j] - '0') > input[temp] - '0' && j != indx) {
				temp = j;
			}
		}
	}
	return temp;
}

