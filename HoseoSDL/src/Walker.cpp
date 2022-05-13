#include "Walker.h"
#include "InputHandler.h"
#include <random>

Walker::Walker(int x, int y) 
{
  vehicle = new Vehicle(x, y);
  target = new Vector2D(0, 0);
}

void Walker::update() 
{
  target = InputHandler::Instance()->getMousePosition();
  vehicle->seek(target);
  vehicle->checkEdges();
  vehicle->update();
}

void Walker::draw(SDL_Renderer* renderer)
{
  filledCircleColor(renderer, target->getX(), target->getY(), 10, 0xFFFF0000);
  vehicle->draw(renderer);
}