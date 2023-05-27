#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

#define r 3
#define c 3

int game_start=0;
    int opt,sp1=0,sp2=0,count=1,gamecount=1,poscheck,nameopt;
    char p1='X',p2='O',mark,p;
    char box[r][c],p1n[50]="PLAYER 1",p2n[50]="PLAYER 2",hist[1000];
    FILE *fp;

void start();
void pbox();
void marker();
int wincheck();
void poschecker();
void boardreset();
void fetchistory();


void main(){
if(gamecount==1){start();}
else{boardreset();pbox();}
//limiting to 9 moves and stopping if there is a win
while(1){
    int a=wincheck();
if(a==1){printf("Player \"%c\" Wins !\n",p);
     if(count%2==1){sp2++;break;}
     else{sp1++;break;}
        }
else if(count>9 && a==0){printf("IT IS A DRAW !\n");break;}
else if(a==0){marker();}
count++;
}
Sleep(2000);system("cls");
pbox();
gamecount++;
printf("ENTER \"1\" TO PLAY AGAIN AND PRESS ANY KEY TO END THE GAME\n");
if(getch()=='1'){main();}
else{printf("THANK YOU FOR PLAYING !\nENTER \"1\" TO CHECK HISTORY AND EXIT\nOR PRESS ANY KEY TO DIRECTLY EXIT THE GAME\n");
time_t t = time(NULL);
    fp=fopen("history.txt","a+");
    fprintf(fp,"%s==>%-20d | %s==>%-20d\t%s\n",p1n,sp1,p2n,sp2,ctime(&t));
    fclose(fp);

    if(getch()=='1'){fetchistory();}

}
}

void fetchistory(){
        fp=fopen("history.txt","r");
        printf("\n---HISTORY---\n");
         while (fgets(hist, sizeof(hist), fp)) { // read file line by line
        printf("%s", hist); // print the line to the console
    }
    fclose(fp);
}

void poschecker(){
    poscheck=0;
//Checking for invavlid move
for(int i=0;i<r;i++)
        {   for(int j=0;j<c;j++)
            { 
              if(box[i][j]==mark){poscheck=1;}
            }
        }
if(poscheck!=1){printf("POSITION ALREADY TAKEN / INVALID MOVE\nTry Again : ");
                scanf(" %c",&mark);
                poschecker();}
}


void marker(){
{
    if(count%2==1){
    p=p1;
    printf("Player 1 - Enter a position number to mark it with \"%c\"\n",p1);
    }

    else {
    p=p2;
    printf("Player 2 - Enter a position number to mark it with \"%c\"\n",p2);
    }

scanf(" %c",&mark);
    poschecker();//Checking invalid moves
    //ACTUAL MARKING OF THE POSTION
    for(int i=0;i<r;i++)
        {   for(int j=0;j<c;j++)
            { 
              if(box[i][j]==mark){box[i][j]=p;}
            }
        }
 system("cls");
 pbox();
}
}


void boardreset(){
    system("cls");
    count=1;
    int k=48;
        for(int i=0;i<r;i++)
    {   for(int j=0;j<c;j++)
        { 
             k++;
             box[i][j]=k; 
        }
    }
    }




void start(){
    printf("WELCOME TO TIC TAC TOE LEGENDS : \n");
printf("PRESS \"1\" TO CHECK HISTORY OR PRESS ANY KEY TO START THE GAME!...");
if(getch()=='1'){fetchistory();}
printf("\nENTER \"1\" TO ENTER NAMES AND SELECT ANY KEY TO SKIP..\n");
if(getch()=='1'){
 nameopt=1;
printf("Enter Player 1 name : ");
gets(p1n);
printf("Enter Player 2 name : ");
gets(p2n);
}
system("cls");
//starting the box
//printing 1-9 box
    printf("\nThis is the start of the game !\n");
    printf("%s\nPlease Enter 1 for \"X\" and 2 for \"O\" : ",p1n);
    scanf("%d",&opt);
    if(opt>2){printf("Invalid Input, Continuing with the Game Default Settings !\n");}
    if(opt==2){p1='O';p2='X';}
boardreset();
   pbox();printf("\n");
}


void pbox(){
    printf("TIC TAC TOE LEGENDS [GAME %d]\n",gamecount);
if(nameopt==1){printf("[%s]  VS  [%s]\n",p1n,p2n);}
printf("PLAYER 1 : \"%c\"\tPLAYER 2 : \"%c\"\n",p1,p2);
printf("SCORE    :  %d            :  %d\n\n",sp1,sp2);
        for(int i=0;i<r;i++)
    {   printf("-----|-----|----- \n");
        
         for(int j=0;j<c;j++)
        { 
            printf("  %c  ",box[i][j]);
            if(j==c-1){continue;}
            else{printf("|");}

        }printf("\n");
    }   printf("-----|-----|----- \n");
}


int wincheck(){
    for(int i=0,j=0;i<r;i++)
    {   
        if(box[i][j]==box[i][j+1] && box[i][j+1]==box[i][j+2]){return 1;}//row test
        else if(box[j][i]==box[j+1][i] && box[j+1][i]==box[j+2][i]){return 1;}//column test
        else if(box[j][j]==box[j+1][j+1] && box[j+1][j+1]==box[j+2][j+2]){return 1;}//diagonal 1 test
        else if(box[j+2][j]==box[j+1][j+1] && box[j+1][j+1]==box[j][j+2]){return 1;}//diagonal 2 test
        
      
    }
    return 0;

}