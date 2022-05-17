#pragma once
#include "Vehicle.h"

class Target : public Vehicle
{
private :
public :
	Target(float x, float y);
	void checkEdges();
	void draw(SDL_Renderer* renderer);
};