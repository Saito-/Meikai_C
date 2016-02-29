#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int answer_check(int input, int answer)
{
	if (input == answer) return 0;
	if (input > answer) return 1;
	else return -1;
}

void print_inputs(int* inputs, int ans, int max_trial)
{
	int i;
	for (i = 0; i < max_trial; i++) {
		printf("inputs[%d]: %d (ans - input = %d)\n", i, inputs[i], ans-inputs[i]);
	}
}

int main()
{
	int trial = 0;
	int input;
	int* inputs;
	int i;
	int rand_lower;
	int rand_upper;

	int mode;
	printf("Select mode:\n");
	printf("0: EASY 1: NORMAL, 2: HARD, 3: EXTREME ");
	scanf("%d", &mode);

	switch (mode) {
	case 0:
		rand_lower = 1;
		rand_upper = 9;
		break;
	case 1:
		rand_lower = 1;
		rand_upper = 99;
		break;
	case 2:
		rand_lower = 1;
		rand_upper = 999;
		break;
	case 3:
		srand(time(NULL));
		do {
		rand_lower = rand() % RAND_MAX;
		rand_upper = rand() % RAND_MAX;
		} while (rand_lower == rand_upper);
		
		if (rand_lower > rand_upper) {
			int tmp = rand_upper;
			rand_upper = rand_lower;
			rand_lower = tmp;
		}
	default:
		printf("バカ\n");
		rand_lower = 1;
		rand_upper = 9999999;
		break;
	}

	int rand_range = (rand_upper-1) - (rand_lower-1);
	int max_trial = (int)log2(rand_range);

	inputs = (int*)malloc(sizeof(int) * max_trial);

	srand(time(NULL));
	int ans = rand() % rand_range + rand_lower + 1;

	printf("What's the number? (between %d ~ %d)\n", rand_lower, rand_upper);

	do {
		printf("Trial %d (remains: %d)\n", trial, max_trial-trial);
		printf("Your answer: "); scanf("%d", &input);
		int chk = answer_check(input, ans);
		inputs[trial] = input;
		switch (chk) {
		case 0:
			printf("Correct!\n");
			print_inputs(inputs, ans, max_trial);
			return 0;
		case -1:
			printf("Incorrect... (too small)\n");
			break;
		case 1:
			printf("Incorrect... (too big)\n");
			break;
		default:
			break;
		}
		trial++;
	} while (trial < max_trial);

	printf("Game over\n");
	printf("Answer: %d\n", ans);
	print_inputs(inputs, ans, max_trial);
	
	return 0;
}
