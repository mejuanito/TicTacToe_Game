#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define row 3
#define col 3

//Winner and loser values

int winner = 0;
int loser = 0;


//this function prints the tictactoe board
void printBoard(char board[row][col])
{
    printf("  ");
    for (char c = '1'; c <= '3'; c++)
    {
    
        printf("   %c", c);

    }
    printf("\n");

    for (char i = 0; i < row; i++)
    {
        printf(" %c", 'a'+ i);
        for (char j = 0; j < col; j++)
        {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }
}

//Allows player to make a move

void makeMove(char board[row][col])
{
    char letter;
    int num;

    while(1)
    {
        printf("Your turn! Enter position. You are X. \nEx: a1\n: ");
        scanf(" %c%d", &letter, &num);

        if ((letter >= 'a' && letter <= 'c') && (num >= 1 && num <=3))
        {

            int rowIndex = letter - 'a';
            int colIndex = num - 1;

            if (board[rowIndex][colIndex] == ' ')
            {
                board[rowIndex][colIndex] = 'X';
                printBoard(board);
                break;
            }
            else
            {
                printf("This spot is already taken. Try again.\n");
            }
        }
        else
        {
            printf("Invalid input. Please try again: \n");
        }
    }
 
}

//Computers move
void computerMove(char board[row][col])
{
    
    if (winner == 0)
    {
        //setting up for the computer to pick a spot
        srand(time(0));
        int randomRow, randomCol;

        printf("Computers move...\n");

           do
           {
            randomRow = rand() % row;
            randomCol = rand() % col;
           } while (board[randomRow][randomCol] != ' ');

           board[randomRow][randomCol] = 'O';
           printBoard(board);
        }  
}

//checks if the player has won

void checkWin(char board[row][col])
{
    int win = 0;
    //printf("I'm checking if you've won\n");
    if (board[0][0] == 'X' && board[1][1] == 'X' && board [2][2] == 'X')
    {
        //*
        //  *
        //    *
        win = 1;
        //printf("I changed the win value\n");
    }
    if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
    {
        //      *
        //    *
        //  *
        win = 1;
    }
    if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X')
    {
        //    *
        //    *
        //    *
        win = 1;
    }
    if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')
    {
        //       *
        //       *
        //       *
        win = 1;
    }
    if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')
    {
        //*
        //*
        //*
        win = 1;
    }
    if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X')
    {
        //  *   *   *
        win = 1;
    }
    if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X')
    {
        // blank
        // *    *   *
        win = 1;
    }
    if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')
    {
        //blank
        //blank
        //  *   *   *
        win = 1;
    }


    switch (win)
    {
    case 1:
        printf("You win!!!\n");
        //I need to fix this
        winner = 1;
        break;
    
    default:
        break;
    }
}

//checks if the computer has won

void checkLose(char board[row][col])
{
    int lose = 0;
    if (board[0][0] == 'O' && board[1][1] == 'O' && board [2][2] == 'O')
    {
        //*
        //  *
        //    *
        lose = 1;
    }
    if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
    {
        //      *
        //    *
        //  *
        lose = 1;
    }
    if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O')
    {
        //    *
        //    *
        //    *
        lose = 1;
    }
    if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')
    {
        //       *
        //       *
        //       *
        lose = 1;
    }
    if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')
    {
        //*
        //*
        //*
        lose = 1;
    }
    if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O')
    {
        //  *   *   *
        lose = 1;
    }
    if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O')
    {
        // blank
        // *    *   *
        lose = 1;
    }
    if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O')
    {
        //blank
        //blank
        //  *   *   *
        lose = 1;
    }


    switch (lose)
    {
    case 1:
        printf("You lose!!!\n");
        loser = 1;
        break;
    
    default:
        break;
    }
}

//loops the game and sets the board
int main ()
{

    //sets the board
    char board[row][col];
    char choice;

    for (char i = 0; i < row; i++)
    {
        for (char j = 0; j < col; j++)
        {
            board[i][j] = ' ';
        }
    }
    printf("Would you like to play a game of tic tac toe with me?\n");
    printf("Y or n?: ");
    scanf(" %c", &choice);

    switch (choice)
    {
    case 'y' :
    case 'Y' :
        printf("\nLets start!\n");
        printBoard(board);
        while(1)
        {
            makeMove(board);
            checkWin(board);
            checkLose(board);
            computerMove(board);
            if (winner == 1)
            {
                break;
            }
            if (loser == 1)
            {
                break;
            }
        }
        break;

    case 'n' :
    case 'N' :
        printf("Okay, goodbye!\n");
        
        break;
    
    default:
        printf("Incorrect input\n");
        break;
    }
    return 0;
}
