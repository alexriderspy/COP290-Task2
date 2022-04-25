#include <ltexture.hpp>

class Flag{
public:
	int mPosX,mPosY;
	LTexture* flagTexture;

	Flag(int mPosX,int mPosY,LTexture* tex);

	void render(int cameraX,int cameraY);
};