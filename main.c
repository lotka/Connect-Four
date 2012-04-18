#include <stdio.h>
#include <stdlib.h>
   int board[10][10]; //Seven entries will be used horizontally, six vertically. I might use other entries for data.
   int player;
   int turn;

   void resetboard(); //Fills it with 0's and 9'
   void printboard(); //Prints the board
   void printer(int n); // Auxilary function for printboard, just converts zeros into ASCII
   void domove();       //Asks for input from console
   void ai_domove();    //The AI executes a move
   int gameover();       //Looks for four in a row
   int random(int max);  // Gives a random number between 1 and INPUT

main () {
    int x = 1; //Funky player ticker
    char s;

    resetboard();



    while(1) {
    if(!gameover()) {
       system("cls");

       player = (1 +((++x) % 2));

       printboard();


       if(player==1)
       domove();

       if(player==2)
       ai_domove();


    ++turn;
    }
    else
    {
        system("cls");
        printboard();
        printf("PLAYER %d WINS!\n", gameover());
        printf("Play again? (y/n)");
        scanf("%c", &s);
        if(s=='n')
           return 0;
        if(s=='y')
           resetboard();
    }
    }


}

int gameover() {


   // Horizontal win
   int i, j, k;
   for (k=1; k<5; ++k) {
   for (j=1; j<8; ++j) {
   for (i=k; i<8; ++i) {
      if (board[i][j]==1 && board[i+1][j]==1 && board[i+2][j]==1  && board[i+3][j]==1)
         return 1;
      if (board[i][j]==2 && board[i+1][j]==2 && board[i+2][j]==2  && board[i+3][j]==2)
         return 2;
   }
   }
   }

   // Vertical win
   for (k=1; k<5; ++k) {
   for (i=1; i<8; ++i) {
   for (j=k; j<8; ++j) {
      if (board[i][j]==1 && board[i][j+1]==1 && board[i][j+2]==1  && board[i][j+3]==1)
         return 1;
      if (board[i][j]==2 && board[i][j+1]==2 && board[i][j+2]==2  && board[i][j+3]==2)
         return 2;
   }
   }
   }
   //Positive Diagonal win
   for (k=1; k<8; ++k) {
   for (j=1; j<8; ++j) {
   for (i=k; i<8; ++i) {
   if (board[i][j]==1 && board[i+1][j+1]==1 & board[i+2][j+2]==1 && board[i+3][j+3]==1)
      return 1;
   if (board[i][j]==2 && board[i+1][j+1]==2 & board[i+2][j+2]==2 && board[i+3][j+3]==2)
      return 2;
   }
   }
   }
   //Negative Diagonal win
   for (k=1; k<8; ++k) {
   for (j=4; j<8; ++j) {
   for (i=k; i<8; ++i) {
   if (board[i][j]==1 && board[i+1][j-1]==1 & board[i+2][j-2]==1 && board[i+3][j-3]==1)
      return 1;
   if (board[i][j]==2 && board[i+1][j-1]==2 & board[i+2][j-2]==2 && board[i+3][j-3]==2)
      return 2;
   }
   }
   }


   return 0;
}

void printer(int n) {
   if (n==0)
      printf("º ");
   if (n==1)
      printf("º.");
   if (n==2)
      printf("º›");
}

void domove(){
   int move=0;
   int i=0;
   int marker;


   if (player == 1)
      marker = 1;
   if (player == 2)
      marker = 2;
  printf("\n  Enter your move player %d:\n>", player);

   scanf("%d", &move);

//Awesome

   i=7;
   while(board[move][i]==0)
       --i;
    ++i;
    board[move][i]=marker;

}

void printboard(){
   int i, j;

   printf("    1 2 3 4 5 6 7 \n");
   printf("   ÉÍËÍËÍËÍËÍËÍËÍ»\n");


   for (i=6; i>0; --i) {


       if(i<6)
       printf("   ÌÍÎÍÎÍÎÍÎÍÎÍÎÍ¹\n");


       printf("   ");



       for (j=1; j<8; ++j){
          printer(board[j][i]);


          if(j==7)
            printf("º");




          }

    printf("\n");
       }
      printf("   ÈÍÊÍÊÍÊÍÊÍÊÍÊÍ¼");

         printf("\n    1 2 3 4 5 6 7 \n");
                 printf("    It is turn: %d\n", turn);
}

void resetboard(){
   int i, j;
   turn=1;
       player = 1;


   for (i=0; i<10; ++i) {

      for (j=0; j<10; ++j)
         board[i][j]=0;
   }

   //board[1][1]=1;
   //board[7][1]=2;
   //board[7][6]=3;
   //board[1][6]=4;

   for(i=0; i<10;++i) {
   board[0][i]=9;
   board[i][0]=9;
   board[8][i]=9;
}
}

void ai_domove() {

   int i, j, k;
   int move;
   int marker=2;

   //first 2 turns are random

   if(turn<5)
      move=random(7);

   /* Big if statement*/
   if(turn>= 5) {
   //blocking horizontal
      for (k=1; k<8; ++k) {
      for (j=1; j<8; ++j) {
      for (i=k; i<8; ++i) {
         if (board[i][j]==1 && board[i+1][j]==1) {
            if(random(2)-1)
               move=i-1;
            else
               move=i+2;
            i=j=k=10;

   }
   }
   }
   }
   }


   if(move==0)
   ++move;
   if(move==8)
   --move;


   //Does the move, all this needs is a move input

   i=7;
   while(board[move][i]==0)
       --i;
    ++i;
    board[move][i]=marker;
}

int random(int max){
   //Random number between 1 and INPUT
   int number;
   while(1) {
      number=rand();
      if (number <= max && number >= 1)
         return number;
   }


}
