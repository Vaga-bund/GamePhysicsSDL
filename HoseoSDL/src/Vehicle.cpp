#include "Vehicle.h"

Vehicle::Vehicle(float x, float y)
{
  location = new Vector2D(x, y);
  velocity = new Vector2D(0.0f, 0.0f);
  acceleration = new Vector2D(0.0f, 0.0f);
  //초기화
  force = new Vector2D(0.0f, 0.0f);
  target = new Vector2D(0.0f, 0.0f);
  prediction = new Vector2D(0.0f, 0.0f);
  
  maxSpeed = 4.0f;
  maxForce = 0.25f;
  r = 16.0f;
  
  tr_xy1 = new Vector2D(0, 0);
  tr_xy2 = new Vector2D(0, 0);
  tr_xy3 = new Vector2D(0, 0);
}

Vector2D* Vehicle::seek(Vector2D* target)
{
  *force = *target - *location;
  //setMag(maxSpeed)
  force->normalize();
  *force *= maxSpeed;
  
  *force -= *velocity;
  force->limit(maxForce);

  return force;
}

Vector2D* Vehicle::evade(Vehicle* vehicle)
{
    Vector2D* pursuit = pursue(vehicle);
    *pursuit *= -1;
    return pursuit;
}
Vector2D* Vehicle::pursue(Vehicle* vehicle)
{
    target = vehicle->getLocation();
    prediction = vehicle->getVelocity();
    *prediction *= 2.0f;
    *target += *prediction;

    return seek(target);
}
Vector2D* Vehicle::flee(Vector2D* target)
{
    target = seek(target);
    *target *= -1;
    return target;
}

void Vehicle::applyForce(Vector2D* Force)
{
  *acceleration += *Force;
}

Vector2D Vehicle::rotation(float x, float y)
{
  // 영상 참고 - 메모리 누수 제거
  Vector2D tmp(0, 0);
  // x' = cos(rad)x - sin(rad)y
  tmp.setX(cos(radian) * x - sin(radian) * y);
  // y' = sin(rad)x + cos(rad)y
  tmp.setY(sin(radian) * x + cos(radian) * y);
  
  return tmp;
}

void Vehicle::checkEdges()
{
  if(location->getX() > width + r)
    location->setX(-r);
  else if(location->getX() < -r)
    location->setX(width + r);
  if(location->getY() > height + r)
    location->setY(-r);
  else if(location->getY() < -r)
    location->setY(height + r);
}

void Vehicle::update()
{
  radian = atan2(velocity->getY(), velocity->getX());

  *tr_xy1 = rotation(-r, -r/2);
  *tr_xy2 = rotation(-r, r/2);
  *tr_xy3 = rotation(r, 0);
  
  *velocity += *acceleration;
  velocity->limit(maxSpeed);
  *location += *velocity;
  *acceleration *= 0;
}

void Vehicle::draw(SDL_Renderer* renderer)
{
  filledTrigonColor(renderer, 
    location->getX() + tr_xy1->getX(),
    location->getY() + tr_xy1->getY(),
    location->getX() + tr_xy2->getX(),
    location->getY() + tr_xy2->getY(),
    location->getX() + tr_xy3->getX(),
    location->getY() + tr_xy3->getY(), 0xFFFFFFFF);
}