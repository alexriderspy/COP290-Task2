#include <ltexture.hpp>

class Coin{
public:
	int value;
	int mPosX, mPosY;
	
	LTexture* coinTexture;

	Coin(int val,int posX,int posY,LTexture* coinTexture);

	~Coin();

	void render(int cameraX, int cameraY);
};