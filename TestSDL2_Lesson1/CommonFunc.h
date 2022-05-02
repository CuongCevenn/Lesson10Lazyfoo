#ifndef COMMONFUNCTION_H_
#define COMMONFUNCTION_H_

#include <SDL.h>
#include <SDL_image.h>
#include <string>


static SDL_Window* gWindow = NULL;
static SDL_Renderer* gRenderer = NULL;
static SDL_Event e;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;



bool init();
bool loadMedia();
void close();



#endif // COMMONFUNCTION_H_
