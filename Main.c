/*
Author : Goran Vujnovic
Project Name : X or O game
Date created : 23/09/2023
Description :This program is a game of X or O between two users
*/


/* Included the headers */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


/* Declaration of global variables */
char matrix [3][3];
int currentUser = 2;
int moves = 0;
int maxMoves = 9;


/* This function creates a table and fills it * */
void tableCreating(void)
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			matrix[i][j] = '*';

		}
	}
}


/* This function will print a table and fills it * */
void tablePrint()
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			printf("\t%c ",matrix[i][j]);
			fflush(stdout);
		}
		printf("\n");
	}
	printf("\n");
}


/* This function changes the user, the first user starts the game */
void switchUser()
{
	if(currentUser == 1)
	{
		currentUser = 2;
	}
	else
	{
		currentUser = 1;
	}
}


/*This function this function checks by rows, columns and diagonally
whether he entered three identical characters and won the game.*/
int winner()
{
	for(int i = 0; i < 3; i++)
	{
		if((matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2]) || (matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i]))
		{
			if(matrix[i][0] == 'X')
			{
				return 'X';
			}
			else if(matrix[i][0] == '0')
			{
				return '0';
			}
		}
	}
		if((matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2]) || (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0]))
		{
			/*Matrix[1][1] represents the center field of the matrix which is
			essential for checking the diagonals and deciding the winner of the game.*/
			if(matrix[1][1] == 'X')
			{
				return 'X';
			}
			else if(matrix[1][1] == '0')
			{
				return '0';
			}
		}

	return 0;
}


/*Check the winner*/
void checkTheWiner()
{
	int Winner = winner();

	if(Winner)
	{
		printf("\tPlayer %c wins!\n\n", (currentUser == 1) ? 'X' : 'O');
	}
	else if(moves == maxMoves)
	{
		printf("\tThere are no winners!\n");
	}
}


/* This function requires input from the user */
void makeMove(int currentUser)
{
	int choice = 2;

	printf("User %d can choose the number from 1 to 9 that make move: \n\n", currentUser);
	fflush(stdout);
	scanf("%d", &choice);

	/*After subtracting 1, the choice value is divided by 3 using the / operator.
	This is done to determine what type or row that position is in the game.*/
	int i = (choice - 1) / 3;
	/*After subtracting 1, the choice value is divided by 3 using the % operator (modulo operation).
	The modulo operation returns the remainder of dividing a number by another number.
	In this case, choice - 1 is divided by 3, and j will contain the remainder of that division.
	Example:
	The expressions 0 % 3 and 1 % 3 yield 0 and 1, because these numbers are partially divisible by 3 with no remainder.
    The expression 2 % 3 gives 2, because 2 is not divisible by 3 and the remainder is 2 itself.*/
	int j = (choice - 1) % 3;

	if (matrix[i][j] == '*')
	{
		matrix[i][j] = (currentUser == 1) ? 'X' : '0';
		tablePrint();
	}

	else
	{
		printf("The field is already occupied. Select a new value.\n\n");
		fflush(stdout);
	}
}


/* Main function */
int main()
{
	printf("\tThis is your board.\n\n");
	printf("You can start with moves and good luck!\n\n");
	tableCreating();
	tablePrint();

	while(moves < maxMoves)
	{
		switchUser();
		makeMove(currentUser);
		moves++;
		checkTheWiner();
	}
	return 0;
}

