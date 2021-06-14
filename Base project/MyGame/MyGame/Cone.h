#pragma once

#include "Engine/GameEngine.h"

class Cone : public GameObject
{
public:
	// Creates our Meteor.
	Cone(sf::Vector2f pos);

	// Functions overridden from GameObject:
	void draw();
	void update(sf::Time& elapsed);
	sf::FloatRect getCollisionRect();
	void handleCollision(GameObject& otherGameObject);
private:
	sf::Sprite sprite_;
};

typedef std::shared_ptr<Cone> ConePtr;