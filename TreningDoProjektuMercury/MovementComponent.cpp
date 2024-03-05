#include "MovementComponent.h"

void MovementComponent::initVariables()
{
	velocity = sf::Vector2f(0, 0);
	acceleration = 0;
	deceleration = 0;
}

MovementComponent::MovementComponent(sf::Sprite& sprite,
	float maxVelocity, float acceleration, float deceleration):
	sprite(sprite),maxVelocity(maxVelocity),acceleration(acceleration),
	deceleration(deceleration)
{

}


MovementComponent::~MovementComponent()
{

}

const sf::Vector2f& MovementComponent::getVelocity() const
{
	return this->velocity;
}

void MovementComponent::move(const float dir_x, const float dir_y,const float& dt)
{
	//Acceleration
	this->velocity.x += this->acceleration * dir_x;
	this->velocity.y += this->acceleration * dir_y;
	
	
}

void MovementComponent::update(const float& dt)
{
	//Max check
	if (this->velocity.x > 0.f)
	{
		this->velocity.x = std::min(this->velocity.x, this->maxVelocity);
		this->velocity.x -= deceleration;
		if (this->velocity.x < 0.f)
			this->velocity.x = 0.f;
		
	}
	else if (this->velocity.x < 0.f)
	{
		this->velocity.x = std::max(this->velocity.x, -this->maxVelocity);
		this->velocity.x -= -deceleration;
		if (this->velocity.x > 0.f)
			this->velocity.x = 0.f;
	}
	if (this->velocity.y > 0.f)
	{
		this->velocity.y = std::min(this->velocity.y, this->maxVelocity);
		this->velocity.y -= deceleration;
		if (this->velocity.y < 0.f)
			this->velocity.y = 0.f;
	}
	else if (this->velocity.y < 0.f)
	{
		this->velocity.y = std::max(this->velocity.y, -this->maxVelocity);
		this->velocity.y -= -deceleration;
		if (this->velocity.y > 0.f)
			this->velocity.y = 0.f;
	}

	
	//Final move
	this->sprite.move(this->velocity * dt);
}
