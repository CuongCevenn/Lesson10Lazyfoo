#ifndef GET_TEXTURE_H_
#define GET_TEXTURE_H_

#include "CommonFunc.h"

class LTexture
{
public:
    LTexture();
    ~LTexture();

    bool loadFromFile(std::string path);
    void free();
    void render(int x, int y);
    int getWidth();
    int getHeight();

private:
    SDL_Texture* mTexture;

    int mWidth;
    int mHeight;
};




#endif // GET_TEXTURE_H_
