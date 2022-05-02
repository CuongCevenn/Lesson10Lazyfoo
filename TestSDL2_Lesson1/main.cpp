#include <iostream>
#include "CommonFunc.h"
#include "Get_Texture.h"

using namespace std;

LTexture gFooTexture;
LTexture gBackgroundTexture;

int main(int argc, char* argv[])
{
    bool quit = false;
    if(!init())
        return -1;
    if(!loadMedia())
        return -1;
    while(!quit)
    {
        while(SDL_PollEvent(&e) != 0)
        {
            if(e.type == SDL_QUIT)
            {
                quit = true;
            }
        }
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(gRenderer);
        gBackgroundTexture.render(0,0);
        gFooTexture.render(240,190);

        SDL_RenderPresent(gRenderer);
    }


    close();

    return 0;
}



bool init()
{
	bool success = true;

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "Initialize false!" << endl;
        success = false;
    }
    else
    {
        if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"1"))
        {

        }

        gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(gWindow == NULL)
        {
            cout << "Fail to create window!" << endl;
            success = false;
        }
        else
        {
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
            if(gRenderer == NULL)
            {
                cout << "Renderer could not be created!" << endl;
                success = false;
            }
            else
            {
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                int imgFlags = IMG_INIT_PNG;
                if(!(IMG_Init(imgFlags)&imgFlags))
                {
                    cout << "SDL_image could not initialize!" << endl;
                    success = false;
                }
            }
        }
    }
    return success;
}

bool loadMedia()
{
	bool success = true;

    if(!gFooTexture.loadFromFile("img/foo.png"))
    {
        cout << "Fail to load foo image" << endl;
        success = false;
    }

    if(!gBackgroundTexture.loadFromFile("img/background.png"))
    {
        cout << "Fail to load background image" << endl;
        success = false;
    }

    return success;
}

void close()
{
    gFooTexture.free();
    gBackgroundTexture.free();

    SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

    IMG_Quit();
	SDL_Quit();
}
