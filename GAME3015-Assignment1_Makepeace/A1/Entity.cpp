#include "Entity.h"

Entity::Entity()
{   
}

Entity::~Entity()
{
}





XMFLOAT2 Entity::getVelocity()
{
    return XMFLOAT2();
}

void Entity::setVelocity(float x, float y)
{
    Velocity.x = x;
    Velocity.y = y;

}

void Entity::updateVelocity(const GameTimer& gt)
{
    MoveTo(
        Velocity.x * gt.DeltaTime(),
        Velocity.y * gt.DeltaTime(),
        0
    );

}

