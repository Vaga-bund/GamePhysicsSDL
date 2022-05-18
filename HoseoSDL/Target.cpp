#include "include/Target.h"
#include <stdio.h>

Target::Target(float x, float y)
{
	location = new Vector2D(x, y);
	velocity = new Vector2D(1.0f, 1.0f);
	acceleration = new Vector2D(0.0f, 0.0f);

	maxSpeed = 1;
}

void Target::checkEdges()
{
	if (location->getX() > width - r)
	{
		velocity->setX(velocity->getX() * -1);
		location->setX(width - r);
	}
	else if (location->getX() < r)
	{
		velocity->setX(velocity->getX() * -1);
		location->setX(r);
	}
	if (location->getY() > height - r)
	{
		velocity->setY(velocity->getY() * -1);
		location->setY(height - r);
	}
	else if (location->getY() < r)
	{
		velocity->setY(velocity->getY() * -1);
		location->setY(r);
	}
}

void Target::update()
{
	*velocity += *acceleration;
	velocity->limit(maxSpeed);
	*location += *velocity;
	*acceleration *= 0;
}

void Target::draw(SDL_Renderer* renderer)
{
	filledCircleColor(renderer, location->getX(), location->getY(), 10, 0xFFFF0000);
}