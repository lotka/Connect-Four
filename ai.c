#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int ai_move(void);
int ai_block_three(void);
int ai_win_three(void);
int ai_block_special(void);
int ai_make_three(void);
int ai_lastresort(void);
extern board[100][100];

int ai_move(void)
{
    int move=0, i;

    move=ai_block_three();
    if(move==0)
       move=ai_win_three();
    if(move==0)
       move=ai_make_three();
    if(move==0)
       move=ai_lastresort();


     if(board[6][1]>0 && board[6][2]>0 && board[6][3]>0 && board[6][4]>0 && board[6][5]>0 && board[6][6]>0 && board[6][7]>0)
       resetboard();



    while(1)
    {
      for(i=6; i>0 && board[i][move] == 0 ; --i)
         ;

      ++i;

      if(i==7 || move>7)
        move=ai_lastresort();
      else
        break;
    }

    board[i][move]=2;

    return 0;
}



int ai_block_three(void)
{
    int i, j, left, right;

    for(i=1;i<10;++i)
    {
        for(j=1;j<10;++j)
        {
            /* XXX */
            if(board[i][j]==1 && board[i][j+1]==1 && board[i][j+2]==1)
               {
                   left=j-1;
                   right=j+3;
                   if(board[i-1][left]>0 && board[i][left]==0)
                      return left;
                   if(board[i-1][right]>0 && board[i][right]==0)
                      return right;

               }


            /* X XX */
            if(board[i][j]==1 && board[i][j+2]==1 && board[i][j+3]==1)
                   if(board[i-1][j+1]>0 && board[i][j+1]==0)
                      return j+1;
            /* XX X */
            if(board[i][j]==1 && board[i][j+1]==1 && board[i][j+3]==1)
                   if(board[i-1][j+2]>0 && board[i][j+2]==0)
                      return j+2;


            /* X
               X
               X   */
            if(board[i][j]==1 && board[i+1][j]==1 && board[i+2][j]==1)
               {
                if(board[i+3][j]==0)
                   return j;
               }
            /*   X
                X
               X   */
            if(board[i][j]==1 && board[i+1][j+1]==1 && board[i+2][j+2]==1)
               {
                if(   board[i-2][j-1]>0 && board[i-1][j-1]==0   )
                   return j-1;
                if(   board[i+2][j+3]>0 && board[i+3][j+3]==0   )
                   return j+3;
               }

            /*    X

                X
               X   */
            if(board[i][j]==1 && board[i+1][j+1]==1 && board[i+3][j+3]==1)
                if(   board[i+1][j+2]>0 && board[i+2][j+2]==0   )
                   return j+2;

            /*    X
                 X

               X   */
            if(board[i][j]==1 && board[i+2][j+2]==1 && board[i+3][j+3]==1)
                if(   board[i][j+1]>0 && board[i+1][j+1]==0   )
                   return j+1;

            /*X
               X
                X */
            if(board[i][j]==1 && board[i-1][j+1]==1 && board[i-2][j+2]==1)
               {
                if(   board[i][j-1]>0 && board[i+1][j-1]==0   )
                  return j-1;
                if(   board[i-4][j+3]>0 && board[i-3][j+3]==0   )
                  return j+3;
               }


            /* X
                X

                  X   */
            if(board[i][j]==1 && board[i-1][j+1]==1 && board[i-3][j+3]==1)
                if(   board[i-3][j+2]>0 && board[i-2][j+2]==0   )
                   return j+2;

            /* X

                 X
                  X   */
            if(board[i][j]==1 && board[i-2][j+2]==1 && board[i-3][j+3]==1)
                if(   board[i-2][j+1]>0 && board[i-1][j+1]==0   )
                   return j+1;

        }
    }
}



int ai_win_three(void)
{
    int i, j, left, right;

    for(i=1;i<10;++i)
    {
        for(j=1;j<10;++j)
        {
            /* XXX */
            if(board[i][j]==2 && board[i][j+1]==2 && board[i][j+2]==2)
               {
                   left=j-1;
                   right=j+3;
                   if(board[i-1][left]>0 && board[i][left]==0)
                      return left;
                   if(board[i-1][right]>0 && board[i][right]==0)
                      return right;

               }


            /* X XX */
            if(board[i][j]==2 && board[i][j+2]==2 && board[i][j+3]==2)
                   if(board[i-1][j+1]>0 && board[i][j+1]==0)
                      return j+1;
            /* XX X */
            if(board[i][j]==2 && board[i][j+1]==2 && board[i][j+3]==2)
                   if(board[i-1][j+2]>0 && board[i][j+2]==0)
                      return j+2;


            /* X
               X
               X   */
            if(board[i][j]==2 && board[i+1][j]==2 && board[i+2][j]==2)
               {
                if(board[i+3][j]==0)
                   return j;
               }
            /*   X
                X
               X   */
            if(board[i][j]==2 && board[i+1][j+1]==2 && board[i+2][j+2]==2)
               {
                if(   board[i-2][j-1]>0 && board[i-1][j-1]==0   )
                   return j-1;
                if(   board[i+2][j+3]>0 && board[i+3][j+3]==0   )
                   return j+3;
               }

            /*    X

                X
               X   */
            if(board[i][j]==2 && board[i+1][j+1]==2 && board[i+3][j+3]==2)
                if(   board[i+1][j+2]>0 && board[i+2][j+2]==0   )
                   return j+2;

            /*    X
                 X

               X   */
            if(board[i][j]==2 && board[i+2][j+2]==2 && board[i+3][j+3]==2)
                if(   board[i][j+1]>0 && board[i+1][j+1]==0   )
                   return j+1;

            /*X
               X
                X */
            if(board[i][j]==2 && board[i-1][j+1]==2 && board[i-2][j+2]==2)
               {
                if(   board[i][j-1]>0 && board[i+1][j-1]==0   )
                  return j-1;
                if(   board[i-4][j+3]>0 && board[i-3][j+3]==0   )
                  return j+3;
               }


            /* X
                X

                  X   */
            if(board[i][j]==2 && board[i-1][j+1]==2 && board[i-3][j+3]==2)
                if(   board[i-3][j+2]>0 && board[i-2][j+2]==0   )
                   return j+2;

            /* X

                 X
                  X   */
            if(board[i][j]==2 && board[i-2][j+2]==2 && board[i-3][j+3]==2)
                if(   board[i-2][j+1]>0 && board[i-1][j+1]==0   )
                   return j+1;

        }
    }
}



int ai_block_special(void)
{
    int i,j;

    for(i=1;i<10;++i)
    {
       for(j=1;j<10;++j)
          {
           /* 00XX00
              333333 */
            return 0;

          }
    }
    return 0;
}
int ai_make_three(void)
{
    return 0;
}

int ai_lastresort(void)
{
    int move;
    printf("THAT WAS RANDOM");
     return (7*((double)rand()/RAND_MAX)  ) + 1;
}

