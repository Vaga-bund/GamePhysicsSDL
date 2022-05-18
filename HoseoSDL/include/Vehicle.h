#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include "Vector2D.h"

class Vehicle
{
protected:
	Vector2D* location;
	Vector2D* velocity;
	Vector2D* acceleration;
	Vector2D* force;

	Vector2D* target;
	Vector2D* prediction;

	Vector2D* tr_xy1;
	Vector2D* tr_xy2;
	Vector2D* tr_xy3;

	const int width = 600;
	const int height = 400;

	float maxSpeed;
	float maxForce;
	float radian;
	float r;
public:
	Vehicle() {}
	Vehicle(float x, float y);
	Vector2D* seek(Vector2D* target);
	Vector2D* evade(Vehicle* vehicle);
	Vector2D* pursue(Vehicle* vehicle);
	Vector2D* flee(Vector2D* target);
	void applyForce(Vector2D* Force);
	void checkEdges();
	Vector2D rotation(float x, float y);
	void update();
	void draw(SDL_Renderer* renderer);
	Vector2D* getLocation() { return location; }
	Vector2D* getVelocity() { return velocity; }
	float getR() { return r; }
	void setLocation(float x, float y)
	{ 
		location->setX(x);
		location->setY(y);
	}
};