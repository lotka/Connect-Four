#include <stdio.h>

int board[100][100];
int gamemode;
/*
   -1 ERROR
    0 Game in progress
    1 Game quit by user
    2 Game over
*/

/*Game functions*/
int mainmenu(void);

/*Board functions*/
void gameover(int player);
void resetboard(void);
void printboard(void);
void intformat(int number);


/* Move functions */
int getint(int options);
int player(int p);


main()
{
    system("color 3");
    int turn=1, lastmove;

   resetboard();

    while(1)
    {
         switch(mainmenu())
    {
        case 65:
           return 0;
        case 0:
                system("cls");
                while(1)
                {
                  ++turn;
                  printboard();
                  player((turn%2)+1);
                  if(gamemode==65)
                     break;
                  system("cls");
                  gameover((turn%2)+1);
               }
        case 1:
                while(1)
                {
                  ++turn;
                  system("cls");
                  gameover(1);
                  gameover(2);
                  printboard();
                  player(1);
                  if(gamemode==65)
                     break;
                  ai_move();
               }

    }
    resetboard();
    }

}


int getint(int options)
{
   int i, c=125, move, userinput[1000]={0};


   while(1)
   {
   for(i=0; (c=getchar()) != '\n'; ++i)
   {
      userinput[i]=c - '0';
   }

   gamemode=userinput[0];

   if(c=='\n' && i==0)
      return getint(options);


   if(userinput[0]>-1 && userinput[0]<=options)
      return userinput[0];

   if(userinput[0]==65)
   {
       gamemode=65;
       return 65;
   }

   printf("\nunrecognised option %d \n", userinput[0]);
   }
}

int mainmenu(void)
{
    int gametype;
    char userinput[10];
    char *modes[2]={"Human vs Human", "Human vs AI"};
    printf("\nC4\n Choose game mode: \n 0. Human vs Human \n 1. Human vs AI \n(Press q to exit at anytime)\n:");

    gametype=getint(2);
    if(gametype==65)
       return 65;

    printf("\nYOU CHOSE %d %s\n",gametype, modes[gametype]);

    return gametype;
}

int player(int player)
{
    int move=0, i;

    move=getint(7);




    for(i=6; i>0 && board[i][move] == 0 ; --i)
       ;

    ++i;

    board[i][move]=player;


    return 0;
}


void resetboard(void)
{
    int i, j;

    for(i=0; i<100; ++i)
       for(j=0; j<100; ++j)
          board[i][j]=0;


//   board[2][2]=board[3][3]=board[4][4]=board[4][5]=1;

    for(i=0; i<100; ++i)
       board[0][i]=100;
    for(i=0; i<100; ++i)
       board[i][0]=100;
    for(i=0; i<100; ++i)
       board[i][8]=100;

}

void printboard(void)
{
    int i, j;

    for(i=6; i>0; --i)
    {
       printf("\n_____________________\n");
       for(j=1;j<8; ++j)
          intformat(board[i][j]);
    }
    printf("\n_____________________\n");
    printf("\n\n 1  2  3  4  5  6  7\n");

}

void intformat(int p)
{
    if(p==1)
      printf(" #|");
    if(p==2)
      printf(" $|");
    if(p==0)
      printf("  |");
}


void gameover(int player)
{
    int i, j;

    for(i=0;i<10;++i)
    {
        for(j=0;j<10;++j)
        {
            if(board[i][j]==player && board[i][j+1]==player && board[i][j+2]==player && board[i][j+3]==player)
               printf("HORIZONTAL WIN PLAYER %d ", player);
            if(board[i][j]==player && board[i+1][j]==player && board[i+2][j]==player && board[i+3][j]==player)
               printf("VERTICAL WIN PLAYER %d ", player);
            if(board[i][j]==player && board[i+1][j+1]==player && board[i+2][j+2]==player && board[i+3][j+3]==player)
               printf("DIAGONAL WIN PLAYER %d ", player);
            if(board[i][j]==player && board[i-1][j+1]==player && board[i-2][j+2]==player && board[i-3][j+3]==player)
               printf("ANTIDIAGONAL WIN PLAYER %d ", player);
        }
    }
}
