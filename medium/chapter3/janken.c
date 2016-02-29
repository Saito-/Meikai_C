#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int player, cpu;
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
	cpu = rand() % 3;

	do {
		printf("Janken pon:\n");
		for (i = 0; i < 3; i++) 
			printf(" (%d) -> %s", i, te[i]);
		printf(": "); scanf("%d", &player);
		if (trial % 5) 
			cpu = (player + 2) % 3;
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
	int* cpus;
	int* judges;
	int* tmp;

	init();
	
	players = (int*)malloc(sizeof(int)*1);
	cpus = (int*)malloc(sizeof(int)*1);
	judges = (int*)malloc(sizeof(int)*1);

	printf("Number of trials (0 -> infinite): "); scanf("%d", &game);

	if (game == 0) {
		while (1) {
			printf("Game %d\n", trial);
			players = (int*)realloc(players, sizeof(int)*trial);
			cpus = (int*)realloc(cpus, sizeof(int)*trial);
			judges = (int*)realloc(judges, sizeof(int)*trial);
			janken();
			players[trial-1] = player;
			cpus[trial-1] = cpu;
			printf("Player: %s, CPU: %s\n", te[player], te[cpu]);
			judge = (player - cpu + 3) % 3;
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
			cpus = (int*)realloc(cpus, sizeof(int)*trial);
			judges = (int*)realloc(judges, sizeof(int)*trial);

			printf("Game %d\n", trial);
			janken();
			players[trial-1] = player;
			cpus[trial-1] = cpu;
			printf("Player: %s, CPU: %s\n", te[player], te[cpu]);
			judge = (player - cpu + 3) % 3;
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
		printf("CPU: %s, ", te[cpus[i]]);
		printf("Result: %s\n", results[judges[i]]);
	}

	free(players); free(cpus); free(judges);
	return 0;
}
