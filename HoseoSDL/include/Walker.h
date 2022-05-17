#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include "Vehicle.h"
#include "Target.h"
#include "Vector2D.h"

class Walker 
{
	Target* target;
	Vehicle* vehicle;
	Vector2D* steering;

  float d;
public:
  Walker(int x, int y);
  void draw(SDL_Renderer* renderer);
  float dist(Vector2D* location_a, Vector2D* location_b);
  void update();
};