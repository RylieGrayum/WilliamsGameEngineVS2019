#pragma once

#include "Engine/GameEngine.h"

class Car : public GameObject
{
public:
	// Creates our ship.
	Car();

	// Functions overridden from GameObject:
	void draw();
	void update(sf::Time& elapsed);
private:
	sf::Sprite sprite_;
	int fireTimer_ = 0;
};

typedef std::shared_ptr<Car> CarPtr;