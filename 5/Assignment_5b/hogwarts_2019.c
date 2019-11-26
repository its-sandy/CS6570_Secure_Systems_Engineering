#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEAMSIZE 10
#define GRYFFINDOR       1
#define RAVENCLAW        2
#define HUFFLEPUFF    	 3
#define SLYTHERIN  		 4

struct _players_t{
	char *name;
	int house;
} players[TEAMSIZE];

unsigned char secret_player[32];

void addplayer()
{
	int i=0, housei;
	char *p = (char *) malloc(16);
	char house[2];

	printf("Enter student name\n");
	gets(p);

	printf("Enter house type\n");
	printf("(Enter 1 for Gryffindor, 2 for Ravenclaw, 3 Hufflepuff or 4 for Slytherin\n");

	gets(house);
	housei = atoi(house);
	if (housei < 1 || housei > 4){
		printf("Invalid house... are you from Durmstrang?\n");
	}

	while(i != TEAMSIZE){
		if(players[i].house == 0){
			players[i].name = p;
			players[i].house = housei;
			p = NULL;
			break;
		}
		i++;
	}
	if (p != NULL){
		printf("Team full... Try Next Year!\n");
	}
}

void printplayers()
{
	int i, j=1;
	char house_type[16];

	for(i=0; i<TEAMSIZE; ++i){
		switch(players[i].house){
		case GRYFFINDOR:      strcpy(house_type, "Gryffindor"); break;
		case RAVENCLAW:       strcpy(house_type, "Ravenclaw");  break;
		case HUFFLEPUFF:   strcpy(house_type, "Hufflepuff"); break;
		case SLYTHERIN: strcpy(house_type, "Slytherin"); break;
		default: players[i].house = 0;
		}
		if (players[i].house != 0){
			printf("%d %s (%s) %p\n", j++, players[i].name, house_type, players[i].name);	
		}
	}
}

void removeplayer()
{
	char n[2];
	int ni;

	printf("Enter player number to remove : ");
	gets(&n);
	ni = atoi(n)-1;
	if (ni >= TEAMSIZE){
		printf("Invalid number\n");
		return;	
	}

	free(players[ni].name);
	players[ni].house = 0;
}

char mainmenu()
{
	char end=0;
	char option;

	while(!end){
		printf("....................\n");
		printf("[a]dd a player\n");
		printf("[r]emove a player\n");
		printf("[p]rint team\n");
		printf("e[x]it program\n");
		gets(&option);


		switch(option){
		case 'a': addplayer(); break;
		case 'r': removeplayer(); break;
		case 'p': printplayers("p\n"); break;
		case 'x': printf("That's all folks!\n"); end=1; break;
		default : printf("Invalid option\n"); break;
		}
	}
	return option;
}


int main(int argc, char **argv)
{
	char name[10];
	printf("-----------------------------------\n");
	printf("   Build your Hogwarts Quidditch team\n\n");
	printf("-----------------------------------\n");
	printf("Enter the name of your team\n");
	gets(name);
	printf("%s\n", name);


	mainmenu();
	printf("My Secret Player is %s\n", secret_player);
}

