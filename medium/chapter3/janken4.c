#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int player, cpu1, cpu2, cpu3;
int trial;
int win, lose, draw;

char* te[] = { "Gu", "Choki", "Pa" };

char* results[] = { "Draw", "Lose", "Win" };

void init()
{
	win = 0; lose = 0; draw = 0; trial = 1;
	srand((unsigned)time(NULL));

	printf("Janken start\n");
}

void janken()
{
	int i;
	cpu1 = rand() % 3;
	cpu2 = rand() % 3;
	cpu3 = rand() % 3;

	do {
		printf("Janken pon:\n");
		for (i = 0; i < 3; i++) 
			printf(" (%d) -> %s", i, te[i]);
		printf(": "); scanf("%d", &player);
	} while (player < 0 || player > 2);
}

void update(int judge)
{
	switch(judge) {
	case 0:
		draw++; printf("Draw\n"); break;
	case 1:
		lose++; printf("You Lose\n"); break;
	case 2:
		win++; printf("You win\n"); break;
	}
	trial++;
}

int main()
{
	int judge;
	int game;
	int* players;
	int* cpus1;
	int* cpus2;
	int* cpus3;
	int* judges;
	int* tmp;

	init();
	
	players = (int*)malloc(sizeof(int)*1);
	cpus1 = (int*)malloc(sizeof(int)*1);
	cpus2 = (int*)malloc(sizeof(int)*1);
	cpus3 = (int*)malloc(sizeof(int)*1);
	judges = (int*)malloc(sizeof(int)*1);

	printf("Number of trials (0 -> infinite): "); scanf("%d", &game);

	if (game == 0) {
		while (1) {
			printf("Game %d\n", trial);
			players = (int*)realloc(players, sizeof(int)*trial);
			cpus1 = (int*)realloc(cpus1, sizeof(int)*trial);
			cpus2 = (int*)realloc(cpus2, sizeof(int)*trial);
			cpus3 = (int*)realloc(cpus3, sizeof(int)*trial);
			judges = (int*)realloc(judges, sizeof(int)*trial);
			janken();
			players[trial-1] = player;
			cpus1[trial-1] = cpu1;
			cpus2[trial-1] = cpu2;
			cpus3[trial-1] = cpu3;
			printf("Player: %s, CPU1: %s, CPU2: %s, CPU3: %s\n",
				te[player],te[cpu1],te[cpu2],te[cpu3]);
			int j1 = player + cpu1 + cpu2;
			int j2 = player + cpu2 + cpu3;
			int j3 = player + cpu1 + cpu3;
			int j4 = cpu1 + cpu2 + cpu3;
			if ((j1%3==0) || (j2%3==0) || (j3%3==0) || (j4%3==0))
				judge = 0;
			else if (player == 0) {
				if (cpu1 == 1 || cpu2 == 1 || cpu3 == 1) 
					judge = 2;
				else
					judge = 1;
			} else if (player == 1) {
				if (cpu1 == 2 || cpu2 == 2 || cpu3 == 2)
					judge = 2;
				else
					judge = 1;
			} else {
				if (cpu1 == 0 || cpu2 == 0 || cpu3 == 0)
					judge = 2;
				else
					judge = 1;
			}
			judges[trial-1] = judge;
			update(judge);
			int flg;
			printf("Continue? (yes: 0, no: 1)"); scanf("%d", &flg);
			if (flg == 0) 
				continue;
			else
				break;
		}
		if (win == lose) 
			printf("Draw (END)\n");
		else if (win > lose)
			printf("You win (END)\n");
		else
			printf("You lose (END)\n");
	} else {
		do {
			players = (int*)realloc(players, sizeof(int)*trial);
			cpus1 = (int*)realloc(cpus1, sizeof(int)*trial);
			cpus2 = (int*)realloc(cpus2, sizeof(int)*trial);
			cpus3 = (int*)realloc(cpus3, sizeof(int)*trial);
			judges = (int*)realloc(judges, sizeof(int)*trial);

			printf("Game %d\n", trial);
			janken();
			players[trial-1] = player;
			cpus1[trial-1] = cpu1;
			cpus2[trial-1] = cpu2;
			cpus3[trial-1] = cpu3;

			printf("Player: %s, CPU1: %s, CPU2: %s, CPU3: %s\n",
				te[player],te[cpu1],te[cpu2],te[cpu3]);
			int j1 = player + cpu1 + cpu2;
			int j2 = player + cpu2 + cpu3;
			int j3 = player + cpu1 + cpu3;
			int j4 = cpu1 + cpu2 + cpu3;
			if ((j1%3==0) || (j2%3==0) || (j3%3==0) || (j4%3==0)) 
				judge = 0;
			else if (player == 0) {
				if (cpu1 == 1 || cpu2 == 1 || cpu3 == 1) 
					judge = 2;
				else
					judge = 1;
			} else if (player == 1) {
				if (cpu1 == 2 || cpu2 == 2 || cpu3 == 2)
					judge = 2;
				else
					judge = 1;
			} else {
				if (cpu1 == 0 || cpu2 == 0 || cpu3 == 0)
					judge = 2;
				else
					judge = 1;
			}
			judges[trial-1] = judge;
			update(judge);
		} while (win < game && lose < game);

		if (win == game) 
			printf("You win (END)\n");
		else 
			printf("You lose (END)\n");
	}

	int i;
	printf("Game records:\n");
	for (i = 0; i < trial-1; i++) {
		printf("Game %d\n", i+1);
		printf("Player: %s, ", te[players[i]]);
		printf("CPU1: %s, ", te[cpus1[i]]);
		printf("CPU2: %s, ", te[cpus2[i]]);
		printf("CPU3: %s, ", te[cpus3[i]]);
		printf("Result: %s\n", results[judges[i]]);
	}

	free(players); free(cpus1); free(cpus2); free(cpus3); free(judges);
	return 0;
}
