#pragma once

#include "Engine/GameEngine.h"

class GoodLuck : public GameObject
{
public:
	// Creates the score instance.
	GoodLuck(sf::Vector2f pos);
	int messageCount = 100;

	// Functions overridden from GameObject:
	void draw();
	void update(sf::Time& elapsed);

private:
	sf::Text text_;
};

typedef std::shared_ptr<GoodLuck> GoodLuckPtr;
