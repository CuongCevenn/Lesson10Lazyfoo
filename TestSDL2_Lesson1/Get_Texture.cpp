#include "Get_Texture.h"
#include <iostream>

LTexture::LTexture()
{
    mTexture = NULL;
    mWidth = 0;
    mHeight = 0;
}
LTexture::~LTexture()
{
    free();
}

bool LTexture::loadFromFile(std::string path)
{
    free();

    SDL_Texture* newTexture = NULL;

    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if(loadedSurface == NULL)
    {
        std::cout << "Fail to get surface!" << std::endl;
    }
    else
    {
        //Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
        if(newTexture == NULL)
        {
            std::cout << "Fail to load texture!" << std::endl;
        }
        else
        {
            mWidth = loadedSurface->w;
            mHeight = loadedSurface->h;
        }
        SDL_FreeSurface(loadedSurface);
    }
    mTexture = newTexture;
    return mTexture!=NULL;
}

void LTexture::free()
{
    if(mTexture!=NULL)
    {
        SDL_DestroyTexture(mTexture);
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
    }
}

void LTexture::render(int x, int y)
{
    SDL_Rect renderSquad = {x,y,mWidth,mHeight};
    SDL_RenderCopy(gRenderer, mTexture, NULL, &renderSquad);
}

int LTexture::getWidth()
{
    return mWidth;
}
int LTexture::getHeight()
{
    return mHeight;
}
