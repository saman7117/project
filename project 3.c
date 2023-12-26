#include<stdio.h>
#include <stdlib.h>
#include <time.h>

struct board{
	int Map[20][20];
	int visit[20][20]; 
}gameBoard;

struct mouse{
	int point;
	int tedad;
	int x,y;
	int type;
};
struct dog{
	int power, energy , speed ,x ,y;
};
struct cat{
	int power , energy , x , y , lock;
};
struct fish{
	int energy,x,y;
};


void printgameboard(){
	for(int i=0;i<20;i++){
		for(int j=0;j<20;j++){
			if((gameBoard.Map[i][j]/100)%10 == 1)
				printf("----");
			else
				printf("====");
		}
		printf("\n");
		for(int j=0;j<20;j++){
			if(gameBoard.Map[i][j]/1000 == 1)
				printf("|");
			else
				printf("*");
			if(gameBoard.Map[i][j]%100 == 0){
				printf("   ");
			}
			else if(gameBoard.Map[i][j]%100 == 1){
				printf(" M ");
			}
			else if(gameBoard.Map[i][j]%100 == 2){
				printf(" m ");
			}
			else if(gameBoard.Map[i][j]%100 == 3){
				printf(" n ");
			}
			else if(gameBoard.Map[i][j]%100 == 4){
				printf(" f ");
			}
			else if(gameBoard.Map[i][j]%100 == 5){
				printf(" B ");
			}
			else if(gameBoard.Map[i][j]%100 == 6){
				printf(" P ");
			}
			else if(gameBoard.Map[i][j]%100 == 7){
				printf(" S ");
			}
			else if(gameBoard.Map[i][j]%100 == 8){
				printf(" J ");
			}
			else if(gameBoard.Map[i][j]%100 == 9){
				printf(" 1 ");
			}
			else if(gameBoard.Map[i][j]%100 == 10){
				printf(" 2 ");
			}
			else if(gameBoard.Map[i][j]%100 == 11){
				printf(" 3 ");
			}
			else if(gameBoard.Map[i][j]%100 == 12){
				printf(" 4 ");
			}
		}
		printf("\n");
	}
}

void setMouseLoc(struct mouse mouse[]){
	int x,y;
	for(int i=0;i<mouse[0].tedad;i++){
		x = (rand() % 20);
		y = (rand() % 20);
		if(gameBoard.visit[x][y] == 0){
			gameBoard.Map[x][y] = gameBoard.Map[x][y] + mouse[0].type;
			mouse[i].point = mouse[0].point;
			mouse[i].x = x;
			mouse[i].y = y;
			gameBoard.visit[x][y]=1;
		}
		else
			i--;
	}
}

void setFishLoc(struct fish fishes[]){
	int x,y;
	for(int i=0;i<10;i++){
		x = (rand() % 20);
		y = (rand() % 20);
		if(gameBoard.visit[x][y] == 0){
			gameBoard.Map[x][y] += 4;
			fishes[i].x = x;
			fishes[i].y = y;
			fishes[i].energy = (rand()%3)+2;
			gameBoard.visit[x][y]=1;
		}
		else
			i--;
	}
}

void setDogLoc(struct dog dogs[]){
	int x,y;
	for(int i=0;i<4;i++){
		x = (rand() % 20);
		y = (rand() % 20);
		if(gameBoard.visit[x][y] == 0){
			gameBoard.Map[x][y] += (5+i);
			dogs[i].x = x;
			dogs[i].y = y;
			if(i==0){
				dogs[i].energy = 30;
				dogs[i].power = 5;
				dogs[i].speed = 5;
			}
			else if(i==1){
				dogs[i].energy = 15;
				dogs[i].power = 2;
				dogs[i].speed = 2;
			}
			else if(i==2){
				dogs[i].energy = 20;
				dogs[i].power = 2;
				dogs[i].speed = 3;
			}
			else{
				dogs[i].energy = 5;
				dogs[i].power = 1;
				dogs[i].speed = 1;
			}
			gameBoard.visit[x][y]=1;
		}
		else
			i--;
	}
}

int main(){
	int i,j;
	//struct board gameBoard;
	for(int i=0;i<20;i++){
		for(int j=0;j<20;j++){
			gameBoard.Map[i][j]=1100;
			gameBoard.visit[i][j] = 0;
		}
	}
	srand(time(0));
	struct cat player[4];
	for(int i=0;i<4;i++){
		player[i].energy=5;
		player[i].power=2;
		player[i].lock=0;
	}
	gameBoard.Map[7][7]=1109;
	gameBoard.Map[7][8]=1110;
	gameBoard.Map[8][7]=1111;
	gameBoard.Map[8][8]=1112;
	gameBoard.visit[7][7]=1;
	gameBoard.visit[7][8]=1;
	gameBoard.visit[8][7]=1;
	gameBoard.visit[8][8]=1;
	struct mouse mouse1[8];
	mouse1[0].tedad=4;
	mouse1[0].type= 1;
	mouse1[0].point=1;
	struct mouse mouse2[6];
	mouse2[0].tedad=6;
	mouse2[0].type= 2;
	mouse2[0].point=2;
	struct mouse mouse3[4];
	mouse3[0].tedad=8;
	mouse3[0].type= 3;
	mouse3[0].point=3;
	struct fish fishes[10];
	struct dog dogs[4];
	setFishLoc(fishes);
	setMouseLoc(mouse1);
	setMouseLoc(mouse2);
	setMouseLoc(mouse3);
	setDogLoc(dogs);
    printgameboard();
	
}
