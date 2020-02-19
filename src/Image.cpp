#include "Image.h"
#include "TextureManager.h"
#include "Game.h"

Image::Image(std::string imagePath, std::string n) : name(n)
{
	TheTextureManager::Instance()->load(imagePath,
		name, TheGame::Instance()->getRenderer());
}

Image::~Image()
{
}

void Image::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw(name, xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Image::clean()
{
}

void Image::update()
{
}
