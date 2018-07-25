#ifndef PIECES
#define PIECES

class Pieces
{
public:

	int returnBlockType        (int retPiece, int retRotation, int retX, int retY);
	int returnXPosInitial      (int retPiece, int retRotation);
	int returnYPosInitial      (int retPiece, int retRotation);
};

#endif 