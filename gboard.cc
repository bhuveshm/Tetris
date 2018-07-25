#include "gboard.h"

/*
Pre-Board
*/
Gboard::GBoard (Pieces *retPieces, int retConsoleHeight)
{
	makeConsoleHeight = retConsoleHeight;
	makePieces = retPieces;
	gboardInit ();
}

/*
Initialisation
*/
void Gboard::gboardInit ()
{
	for (int i = 0; i < GBOARD_WIDTH; i++)
		for (int j = 0; j < GBOARD_HEIGHT; j++)
			makeGboard[i][j] = FREE_POS;
}

/*
Storing a piece on the game board.
*/
void Gboard::savePiece (int retX, int retY, int retPiece, int retRotation)
{
	for (int i_1 = retX, i_2 = 0; i_1 < retX + NUM_PIECES; i_1++, i_2++)
	{
		for (int j_1 = retY, j_2 = 0; j_1 < retY + NUM_PIECES; j_1++, j_2++)
		{
			if (makePieces->returnBlockType (retPiece, retRotation, j_2, i_2) != 0)
				makeGboard[i_1][j_1] = FILL_POS;
		}
	}
}

/*
Check for game over.
*/
bool Gboard::gameStateOver ()
{
	for (int i = 0; i < GBOARD_WIDTH; i++)
	{
		if (makeGboard[i][0] == POS_FILLED) return true;
	}

	return false;
}

/*
Deleteing a full line
*/
void Gboard::makeLines (int retY)
{
	for (int j = retY; j > 0; j--)
	{
		for (int i = 0; i < GBOARD_WIDTH; i++)
		{
			makeGboard[i][j] = makeGboard[i][j-1];
		}
	}
}

/*
Deleting lines if any exist.
*/
void Gboard::makeIfLines ()
{
	for (int j = 0; j < GBOARD_HEIGHT; j++)
	{
		int i = 0;
		while (i < GBOARD_WIDTH)
		{
			if (makeGboard[i][j] != FILL_POS) break;
			i++;
		}

		if (i == GBOARD_WIDTH) makeLines (j);
	}
}

/*
Checks if block on board is empty.
*/
bool Gboard::isFree (int retX, int retY)
{
	if (makeGboard [retX][retY] == FREE_POS) return true;
}

/*
Get horizontal position of block in pixels.
*/
int Gboard::returnXPos (int retPos)
{
	return ( ( GBOARD_POS - (BLOCK_SIZE * GBOARD_HEIGHT)) + (retPos * BLOCK_SIZE) );
}

/*
Get vertical position of blocks in pixels.
*/
int Gboard::returnYPos (int retPos)
{
	return ( ( makeConsoleHeight - (BLOCK_SIZE * GBOARD_HEIGHT)) + (retPos * BLOCK_SIZE) );
}

/*
To check if a piece can be stored at current position.
*/
bool Gboard::isPossible (int retX, int retY, int retPiece, int retRotation)
{
	for (int i_1 = retX, i_2 = 0; i_1 < retX + NUM_PIECES; i_1++, i_2++)
	{
		for (int j_1 = retY, j2 = 0; j1 < retY + NUM_PIECES; j_1++, j_2++)
		{	
			if ( (i_1 < 0) || (i_1 > (GBOARD_WIDTH  - 1)) || (j_1 > (GBOARD_HEIGHT - 1)) )
			{
				if (makePieces->returnBlockType (retPiece, retRotation, j_2, i_2) != 0)
					return 0;		
			}

			if (j_1 >= 0)	
			{
				if ( (makePieces->returnBlockType (retPiece, retRotation, j_2, i_2) != 0) && (!isFree (i_1, j_1)) ) return false;
			}
		}
	}

	return true;
}