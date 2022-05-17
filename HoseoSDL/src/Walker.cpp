#include "Walker.h"
#include "InputHandler.h"
#include <random>

Walker::Walker(int x, int y) 
{
  vehicle = new Vehicle(x, y);
  target = new Target(300, 300);
  steering = new Vector2D(0, 0);

  d = 0.0f;
}

void Walker::update() 
{
	steering = vehicle->pursue(target);
	vehicle->applyForce(steering);

	d = dist(vehicle->getLocation(), target->getLocation());
	if (d < vehicle->getR() + target->getR())
	{
		target = new Target(300, 300);
		vehicle->setLocation(100, 100);
	}
	target->update();
	vehicle->checkEdges();
	vehicle->update();
}

float Walker::dist(Vector2D* location_a, Vector2D* location_b)
{
	return sqrt((location_b->getX() - location_a->getX()) * (location_b->getX() - location_a->getX()) + (location_b->getY() - location_a->getY()) * (location_b->getY() - location_a->getY()));
}

void Walker::draw(SDL_Renderer* renderer)
{
	target->draw(renderer);
	vehicle->draw(renderer);
}