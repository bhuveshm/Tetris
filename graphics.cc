#include "graphics.h"


static SDL_Surface *makeConsole;
static Uint32 makeColor [COLOR_END] = {0xff0000ff, 0x00ff00ff, 0x0000ffff,0x000000ff, 0xffff00ff, 0xffffffff};

/*
Initialisation
*/
Graphics::graphics ()
{
	graphicsInit ();
}

/*
Clear Screen
*/
void Graphics::cls ()
{
	boxColor (makeConsole, 0, 0, makeConsole->w -1, makeConsole->h-1,makeColor[BLACK]);
}

/*
Generating a rectangle of given co-oridnates and color.
*/

void Graphics::makeRectangle (int retX_1, int retY_1, int retX_2, int retY_2, enum color retCOL)
{
	boxColor (makeConsole, retX_1, retY_1, retX_2,retY_2 -1, makeColor[retCOL]);
}

int Graphics::returnConsoleHeight ()
{
	return makeConsole->h;
}

void Graphics::updateCls ()
{
	SDL_Flip(makeConsole);
}


int Graphics::keyPoll ()
{
	SDL_Event press;
	while ( SDL_PollEvent(&press) )
	{
		if ( press.type == SDL_KEYDOWN ) return press.key.keysym.sym;
		if ( press.type == SDL_QUIT ) exit(3);
	}
	return -1;
}

int Graphics::keyGet ()
{
	SDL_Event press;
	while (1)
	{
		SDL_WaitEvent(&press);
		if ( press.type == SDL_KEYDOWN ) break;
		if ( press.type == SDL_QUIT ) exit(3);
	};
	return press.key.keysym.sym;
}

int Graphics::keyDown (int retKey)
{
	int makeKeys;
	Unit8* makeTable;
	SDL_PumpEvents ();
	makeTable = SDL_GetKeyState(&makeKeys);
	return makeTable [retKey];
}

int Graphics::graphicsInit ()
{
	const SDL_VideoInfo *meta;
	Unit8 bpp_vid;
	Uint32 flags_vid;

	if ( SDL_Init(SDL_INIT_VIDEO) < 0 ) {
		fprintf(stderr, "Unable to initialize SDL: %s\n",SDL_GetError());
		return 1;
	}
	atexit(SDL_Quit);

	meta = SDL_GetVideoInof();
	if ( meta->vfmt->BitsPerPixel > 8) bpp_vid = meta->vfmt->BitsPerPixel;
	else bpp_vid = 16;

	flags_vid = SDL_SWSURFACE | SDL_DOUBLEBUF;

	if ( (makeConsole=SDL_SetVideoMode(640,480,bpp_vid,flags_vid)) == NULL ) {
		fprintf(stderr, "Unable to set %ix%i video mode: %s\n",640,480,SDL_GetError());
		return 2;
	}
	return 0;
}



