#pragma once

#include "Engine/GameEngine.h"

class Background : public GameObject
{
public:
	// Creates our Background.
	Background(sf::Vector2f pos);

	// Functions overridden from GameObject:
	void draw();
	void update(sf::Time& elapsed);
private:
	sf::Sprite sprite_;

	float initial_x;
};

typedef std::shared_ptr<Background> BackgroundPtr;