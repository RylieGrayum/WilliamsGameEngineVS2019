#include "Cone.h"
#include "Explosion.h"
#include "GameScene.h"


const float SPEED = 0.25f; // Speed is same as road so they look fixed to the road.

Cone::Cone(sf::Vector2f pos)
{
	sprite_.setTexture(GAME.getTexture("Resources/cone3.png")); // Changed picture.
	sprite_.setPosition(pos);
	assignTag("cone");
	setCollisionCheckEnabled(true);
}

void Cone::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}

void Cone::update(sf::Time& elapsed) {
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();
	sprite_.setPosition(sf::Vector2f(pos.x, pos.y + SPEED * msElapsed)); // Makes the cones fall vertically.
}

void Cone::handleCollision(GameObject& otherGameObject)
{
	if (otherGameObject.hasTag("laser"))
	{
		sf::FloatRect rect = otherGameObject.getCollisionRect();
		sf::Vector2f pos = {rect.left, rect.top};

		// Create a meteor and add it to the scene
		ExplosionPtr explosion = std::make_shared<Explosion>(pos);
		GAME.getCurrentScene().addGameObject(explosion);

		otherGameObject.makeDead();
		GameScene& scene = (GameScene&)GAME.getCurrentScene();

		scene.increaseScore();
	}

	makeDead();
}

sf::FloatRect Cone::getCollisionRect()
{
	return sprite_.getGlobalBounds();
}
