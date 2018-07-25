#include "game.h"
#include "stlib.h"

int main ()
{
	Graphics makeGraphics;
	int makeConsoleHeight = makeGraphics.returnConsoleHeight ();

	Pieces makePieces;

	Gboard makeGboard ( &makePieces, makeConsoleHeight );

	Game makeGame ( &makeGboard, &makePieces, &makeGraphics, makeConsoleHeight);

	unisgned long makeTime_1 = SDL_GetTicks();

	while ( !makeGraphics.keyDown ( SDLK_ESCAPE ) )
	{

		makeGraphics.cls ();
		makeGame.makeConsole ();
		makeGraphics.updateCls ();

		int makeKey = makeGraphics.keyPoll ();

		switch (makeKey)
		{
			case (SDLK_RIGHT): 
			{
				if (makeGboard.isPossible (makeGame.makeXPos + 1, makeGame.makeYPos, makeGame.makePiece, makeGame.makeRotation))
					makeGame.makeXPos++;
					break;
			}

			case (SDLK_LEFT): 
			{
				if (makeGboard.isPossible (makeGame.makeXPos - 1, makeGame.makeYPos, makeGame.makePiece, makeGame.makeRotation))
					makeGame.makePosX--;	
				break;
			}

			case (SDLK_DOWN):
			{
				if (makeGboard.isPossible (makeGame.makeXPos, makeGame.makeYPos + 1, makeGame.makePiece, makeGame.makeRotation))
					makeGame.makeYPos++;	
				break;
			}

			case (SDLK_x):
			{
				// Check collision from up to down
				while (makeGboard.isPossible (makeGame.makeXPos, makeGame.makeYPos, makeGame.makePiece, makeGame.makeRotation)) { makeGame.makeYPos++; }
	
				makeGboard.savePiece (makeGame.makeXPos, makeGame.makeYPos - 1, makeGame.makePiece, makeGame.makeRotation);

				makeGboard.makeIfLines ();

				if ( makeGboard.gameStateOver () )
				{
					makeGraphics.keyGet();
					exit(0);
				}

				makeGame.generatePiece();

				break;
			}

			case (SDLK_z):
			{
				if (makeGboard.isPossible (makeGame.makeXPos, makeGame.makeYPos, makeGame.makePiece, (makeGame.makeRotation + 1) % 4))
					makeGame.makeRotation = (makeGame.makeRotation + 1) % 4;

				break;
			}
		}

		unsigned long makeTime_2 = SDL_GetTicks();

		if ( (makeTime_2 - makeTime_1) > HOVER_TIME)
		{
			if (makeGboard.isPossible (makeGame.makeXPos, makeGame.makeYPos + 1, makeGame.makePiece, makeGame.makeRotation))
			{
				makeGame.makeYPos++;
			}
			else
			{
				makeGboard.savePiece (makeGame.makeXPos, makeGame.makeYPos, makeGame.makePiece, makeGame.makeRotation);

				makeGboard.makeIfLines ();

				if ( makeGboard.gameStateOver () )
				{
					makeGraphics.keyGet();
					exit(0);
				}

				makeGame.generatePiece();
			}

			makeTime_1 = SDL_GetTicks();
		}
	}
}