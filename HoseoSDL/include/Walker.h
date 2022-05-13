#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include "Vehicle.h"
#include "Vector2D.h"

class Walker 
{
  Vector2D* target;
  Vehicle* vehicle;
public:
  Walker(int x, int y);
  void draw(SDL_Renderer* renderer);
  void update();
};