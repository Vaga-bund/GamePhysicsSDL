#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include "Vector2D.h"

class Vehicle
{
private:
  Vector2D* location;
  Vector2D* velocity;
  Vector2D* acceleration;
  Vector2D* force;

  Vector2D* tr_xy1;
  Vector2D* tr_xy2;
  Vector2D* tr_xy3;

  const int width = 600;
  const int height = 400;

  float maxSpeed;
  float maxForce;
  float radian;
  float r;
public :
  Vehicle(float x, float y);
  void seek(Vector2D* target);
  void applyForce(Vector2D* Force);
  void checkEdges();
  Vector2D rotation(float x, float y);
  void update();
  void draw(SDL_Renderer* renderer);
};