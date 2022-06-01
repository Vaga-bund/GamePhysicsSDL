#include "Walker.h"
#include "InputHandler.h"
#include <random>
#include <iostream>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<float> dis_width(0, 600);
std::uniform_real_distribution<float> dis_height(0, 400);

Walker::Walker(int x, int y) 
{
  vehicle = new Vehicle(dis_width(gen), dis_height(gen));
  target = new Target(dis_width(gen), dis_height(gen));
  steering = new Vector2D(0, 0);
  d = 0.0f;
}

void Walker::update() 
{
	steering = vehicle->arrive(target->getLocation(), vehicle->slow);
	vehicle->applyForce(steering);

	/*
	d = dist(vehicle->getLocation(), target->getLocation());
	if (d < vehicle->getR() + target->getR())
	{
		target = new Target(dis_width(gen), dis_height(gen));
		vehicle->setLocation(dis_width(gen), dis_height(gen));
	}
	*/
	printf("%f, %f\n", steering->getX(), steering->getY());
	vehicle->checkEdges();
	vehicle->update();
	target->checkEdges();
	target->update();
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