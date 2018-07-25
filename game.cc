#ifndef LINUX
#include <windows.h>
#endif
#include "game.h"

/*
Pre-Game
*/

Game::Game (Gboard *retGboard, Pieces *retPieces, Graphics *retGraphics, int retConsoleHeight)
{
	makeConsoleHeight = retConsoleHeight;

	makeGboard = retGboard;
	makePieces = retPieces;
	makeGraphics = retGraphics;

	gameInit ();
}

/*
Return random integer.
*/
int Game::returnRandom (int retA, int retB)
{
	return rand () % (retB - retA + 1) + retA;
}

/*
Initial state of the game.
*/
void Game::gameInit ()
{
	srand ((unsigned int) time(NULL));

	//Current Piece
	makePiece = returnRandom (0, 6);
	makeRotation = returnRandom (0, 3);
	makeXPos = (GBOARD_WIDTH / 2) + makePieces->returnXPosInitial (makePiece, makeRotation);
	makeYPos = makePieces->returnYPosInitial (makePiece, makeRotation);

	//Next Piece
	makePieceNext = returnRandom (0, 6);
	makeRotationNext = returnRandom (0, 3);
}

/*
Make piece.
*/
void makePiece (int retX, int retY, int retPiece, int retRotation)
{
	color makeColor;

	int makeXPixels = makeGboard->returnXPos (retX);
	int makeYPixels = makeGboard->returnYPos (retY);

	for (int i = 0; i < NUM_PIECES; i++)
	{
		for (int j = 0; j < NUM_PIECES; j++)
		{
			switch (makePieces->returnBlockType (retPiece,retRotation, j, i))
			{
				case 1: makeColor = GREEN; break;
				case 2: makeColor = BLUE: break;
			}

			if (makePieces->returnBlockType (retPiece, retRotation, j, i) != 0)
				makeGraphics->makeRectangle ( makeXPixels + i * BLOCK_SIZE, 
										makePixelsY + j * BLOCK_SIZE,
										(makeXPixels + i * BLOCK_SIZE) + BLOCK_SIZE - 1,
										(makeYPixels + j * BLOCK_SIZE) + BLOCK_SIZE - 1,
										makeColor );
		}
	}
}

/*
Generate board.
*/
void Game::makeBoard ()
{
	int makeX_1 = GBOARD_POS - (BLOCK_SIZE * (GBOARD_WIDTH / 2)) - 1;
	int makeX_2 = GBOARD_POS + (BLOCK_SIZE * (GBOARD_WIDTH / 2));
	int makeY = makeConsoleHeight - (BLOCK_SIZE * GBOARD_HEIGHT);
	

	makeGraphics->makeRectangle (makeX_1 - GBOARD_ENDL_WIDTH, makeY, makeX_1, makeConsoleHeight - 1, BLUE);
	makeGraphics->makeRectangle (makeX_2, makeY, makeX_2 + GBOARD_ENDL_WIDTH, makeConsoleHeight - 1, BLUE);
	

	makeX_1 += 1;
	for (int i = 0; i < GBOARD_WIDTH; i++)
	{
		for (int j = 0; j < GBOARD_HEIGHT; j++)
		{	
			if (!makeGboard->isFree (i, j))	
				makeGraphics->makeRectangle (	makeX_1 + i * BLOCK_SIZE, 
										makeY + j * BLOCK_SIZE, 
										(makeX_1 + i * BLOCK_SIZE) + BLOCK_SIZE - 1, 
										(makeY + j * BLOCK_SIZE) + BLOCK_SIZE - 1, 
										RED);
		}
	}	
}


/* 					
Generate console.
*/
void Game::makeConsole ()
{
	makeBoard ();													            // Generate the lines and blocks stored in the board.
	makePiece (makeXPos, makeYPos, makePiece, makeRotation);					// Generate the current piece.
	makePiece (makeXPosNext, mYPosNext, makePieceNext, makeRotationNext);	    // Generate the next piece.
}