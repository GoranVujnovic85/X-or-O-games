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


/* This function this function checks by rows, columns and diagonally
    whether he entered three identical characters and won the game    */
int winner()
{
	for (int i = 0; i < 3; i++)
	{
		if (matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2] && matrix[i][0]  == 'X')
		{
			return 'X';
		}
		if (matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2] && matrix[i][0] == '0')
		{
			return '0';
		}
		if (matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i] && matrix[0][i] == 'X')
		{
			return 'X';
		}
		if (matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i] && matrix[0][i] == '0')
		{
			return '0';
		}
	}
	if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2] && matrix[0][0] == 'X')
	{
		return 'X';
	}
	if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2] && matrix[0][0] == '0')
	{
		return '0';
	}
	if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0] && matrix[0][2] == 'X')
	{
		return 'X';
	}
	if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0] && matrix[0][2] == '0')
	{
		return '0';
	}

	return 0;
}


/* This function requires input from the user */
void makeMove(int player)
{
	int choice;

	printf("User %d can choose the number from 1 to 9 that make move: \n\n", player);
	fflush(stdout);
	scanf("%d", &choice);

	/*https://www.youtube.com/watch?v=zH_omFPqMO4*/
	int i = (choice - 1) / 3;
	int j = (choice - 1) % 3;

	if (matrix[i][j] == '*')
	{
		matrix[i][j] = (currentUser == 1) ? 'X' : '0';
	}

	else
	{
		printf("The field is already occupied. Select a new value.\n\n");
		fflush(stdout);
		makeMove(player);
	}
		tablePrint();

		int Winner = winner();

		if (Winner)
		{
		    printf("\tPlayer %c wins!\n\n", (currentUser == 1) ? 'X' : 'O');
		    return;
		}
}

/* Main function */
int main()
{
	printf("\tThis is your board.\n\n");
	tableCreating();
	tablePrint();
	printf("\n");
	printf("\tYou can start with moves and good luck!\n\n");

	int moves = 0;
	int maxMoves = 9;

	while(moves < maxMoves)
	{
		switchUser();
		makeMove(currentUser);
		moves++;

		if (moves == maxMoves)
		{
			printf("\tThere are no winners!\n");
		}
	}

	return 0;
}

