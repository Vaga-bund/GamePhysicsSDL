#include "include/Target.h"

Target::Target(float x, float y)
{
	location = new Vector2D(x, y);
	velocity = new Vector2D(0.0f, 0.0f);
	acceleration = new Vector2D(0.0f, 0.0f);

	velocity->setX(1.0f);
	velocity->setY(1.0f);
	maxSpeed = 4;
	*velocity *= maxSpeed;
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

void Target::draw(SDL_Renderer* renderer)
{
	filledCircleColor(renderer, location->getX(), location->getY(), 10, 0xFFFF0000);
}