#ifndef GAME
#define GAME

#include "gboard.h"
#include "pieces.h"
#include "graphics.h"
#include <time.h>

#define HOVER_TIME 750                     // Milliseconds spent by block on each line.

class Game
{
public:

	Game (Gboard *retGboard, Pieces *retPieces, Graphics *retGraphics, int retConsoleHeight);

	void generatePiece ();
	void makeConsole ();

	int makeXPos, makeYPos;               // Position of the current piece.
	int makePiece, makeRotation;          // Type and orientation of current piece.

private:

	int makeConsoleHeight;                // Height of console in pixels.
	int makeXPosNext, makeYPosNext;       // Position of the next piece.
	int makePieceNext, makeRotationNext;  // Type and orientation of next piece.

	Gboard *makeGboard;
	Pieces *makePieces;
	Graphics *makeGraphics;

	int returnRandom (int retA, int retB);
	void gameInit ();
	void makePiece (int retX, int retY, int retPiece, int retRotation);
	void makeBoard ();
};

#endif 