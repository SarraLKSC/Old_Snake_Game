#include<stdio.h>
#include <windows.h>
#include <time.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include <unistd.h>





#define N 60
#define M 30
int i,j,Field[M][N],x,y,head,tail,Gy,game,Frog,a,b,var,dir,score;
COORD FROG;
void SnakeStart(){
     score=0;  
	for(i=1;i<=M;i++){
		for(j=1;j<=N;j++){
			Field[i][j]=0;
		}
	}x=M/2; y=N/2; head=5; tail=1; Gy=y;
	 for(i=0;i<head;i++){
	 	Gy++; Field[x][Gy-head]=i+1;
	 }
	game=0; Frog=0;
}
void print(){
   
	printf("\n\nWELCOME TO THE SNAKE GAME\n\n");
	for(i=1;i<=M;i++){
		if(i==1){printf("%c",201); for(j=2;j<=N-1;j++){printf("%c",205);} printf("%c",187);}
		if(i==M){printf("%c",200); for(j=2;j<=N-1;j++){printf("%c",205);} printf("%c",188);}
		if((i<M)&&(i>1)) { printf("%c",186);for(j=2;j<=N-1;j++){if (Field[i][j]==0)printf(" ");
		                                              if(Field[i][j]>0 && Field[i][j]!=head){printf("%c",177);}
													    if(Field[i][j]==head)printf("%c",178);
														if(Field[i][j]==-1)printf("%c",206);}  
		printf("%c",186);	} printf("\n");
		}
		printf("       DEVELOPED BY SARRA");
}
void reset(){
	  HANDLE  hConsole;
	  COORD Position; Position.X=0; Position.Y=0;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleCursorPosition(hConsole,Position);
}
void Random(){
	srand(time(0));
	a=1+rand()%28;
	b=1+rand()%58;
	if(Frog==0 && Field[a][b]==0){Field[a][b]=-1; FROG.X=a; FROG.Y=b; Frog=1; }
	
}
int getch_noblock() {
    if (_kbhit())
        return _getch();
    else 
        return -1;
}
void mouvement(){
	var= getch_noblock(); var= tolower(var);
	if(var=='x') game=1;
	if(((var=='g'||var=='f')||(var=='t'||var=='v'))&&(abs(dir-var)>5))
	dir=var;
	if(dir=='g'){y++; if(Field[x][y]>0){game=1;} if(y==N){game=1;} head++; Field[x][y]=head;}
		if(dir=='f'){y--; if(Field[x][y]>0){game=1;}if(y==1){game=1;} head++; Field[x][y]=head;}
	      if(dir=='v'){x++; if(Field[x][y]>0){game=1;} if(x==M){game=1;} head++; Field[x][y]=head;}
          	if(dir=='t'){x--; if(Field[x][y]>0){game=1;} if(x==1){game=1;} head++; Field[x][y]=head;}
   	
}
void tailupdate(){
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			if(Field[i][j]==tail)	Field[i][j]=0;
          }
	} 	if(Field[FROG.X][FROG.Y]!=head){tail++;}
	if(Field[FROG.X][FROG.Y]==head) {Frog=0; score++;}
}


void clearScreen()
{
  const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
  write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}
int main(){
	   int i;
	   printf("PRESS ANY KEY TO START DE GAME:");
	   getch();
	   
	  SnakeStart();
	  dir='g';
	  HANDLE  hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

 	while(game==0){print(); reset(); Random();  mouvement(); tailupdate(); }

	printf("\n\n END, THANKS FOR PLAYING !"); printf("\nyour score=%d",score);
	
	printf("\n\n want to play again ?"); printf("\n1-Yes\n2-No");
	    

	scanf("%d",&i); 
	if(i==1){bool b=true;}
	while(b){
	  
	   printf("PRESS ANY KEY TO START DE GAME:");
	   getch();
	   
	  SnakeStart();
	  dir='g';
	  HANDLE  hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole,2);
	SetConsoleTextAttribute(hConsole,7);
	while(game==0){print(); reset(); Random();  mouvement(); tailupdate(); }	
	printf("\n\n want to play again ?"); printf("\n1-Yes\n2-No");
	scanf("%d",&i); 
	if(i==1){bool b=false;}
}
	}
