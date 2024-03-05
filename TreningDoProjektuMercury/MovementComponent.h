#ifndef MOVEMENTCOMPONENT_H
#define MOVEMENTCOMPONENT_H


#include <iostream>
#include <ctime>
#include <cstdlib>

#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\Audio.hpp"
#include "SFML\Network.hpp"
#include <fstream>
#include <sstream>
#include <stack>
#include <map>

class MovementComponent
{
private:
	sf::Sprite& sprite;

	float maxVelocity;
	float acceleration;
	float deceleration;

	sf::Vector2f velocity;
	

	//initializer functions
	void initVariables();
public:
	MovementComponent(sf::Sprite& sprite, float maxVelocity, const float acceleration, const float deceleration);
	virtual ~MovementComponent();


	//Accessors
	const sf::Vector2f& getVelocity() const;
	//functions
	void move(const float dir_x, const float dir_y, const float& dt);
	void update(const float &dt);
};

#endif // !MOVEMENTCOMPONENT_H