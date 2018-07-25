#ifndef GRAPHICS
#define GRAPHICS


#include "SDL/SDL_GfxPrimitives/SDL_gfxPrimitives.h"
#include <SDL/SDL.h>

#pragma comment (lib, "SDL/lib/SDL/lib")
#pragma comment (lib, "SDL/SDL_GfxPrimitives/SDL_GfxPrimitives_Static.lib")

enum color {RED, GREEN, BLUE, BLACK, YELLOW, WHITE, COLOR_END};

class Graphics
{
public:
	graphics ();

	void makeRectangle (int retX_1, int retY_1, int retX_2, int retY_2, enum color retCOL);
	void cls ();
	int returnConsoleHeight ();
	int graphicsInit ();
	int keyPoll ();
	int keyGet ();
	int keyDown (int retKey);
	int updateCls ();
};

#endif