#ifndef GBOARD
#define GBOARD

#include "pieces.h"

#define GBOARD_ENDL_WIDTH 6    // Width of board ending lines.
#define BLOCK_SIZE 16          // Width and height of each piece block.
#define GBOARD_POS 300         // Position of board from left of console.
#define GBOARD_HEIGHT 30       // Game board height in blocks.
#define GBOARD_WIDTH 15        // Game board width in blocks.
#define MIN_MARGIN_V 20        // Minimum vertical margin for the game board.
#define MIN_MARGIN_H 5         // Minimum horizontal margin for the game board.
#define NUM_PIECES 5           // Number of blocks in each piece vertically and horizontally.

class GBoard
{
public:

	GBoard (Pieces *retPieces, int retConsoleHeight);

	int returnXPos     (int retPos);
	int returnYPos     (int retPos);
	bool isFree        (int retX, int retY);
	bool isPossible    (int retX, int retY, int retPiece, int retRotation);
	void savePiece     (int retX, int retY, int retPiece, int retRotation);
	void makeIfLines   ();
	bool gameStateOver ();

private:

	enum { FREE_POS, FILL_POS };
	Pieces *makePieces;
	int makeGboard [GBOARD_WIDTH][GBOARD_HEIGHT];  // Game board.
	int makeConsoleHeight;

	void gboardInit    ();
	void makeLines     (int retY);
};

#endif 