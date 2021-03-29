#include "Ship.h"
#include "Laser.h"

const float SPEED = 0.3f;
const int FIRE_DELAY = 200;

Ship::Ship()
{
	sprite_.setTexture(GAME.getTexture("Resources/ship.png"));
	sprite_.setPosition(sf::Vector2f(100, 100));
}

void Ship::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}

void Ship::update(sf::Time& elapsed) {
	sf::Vector2f pos = sprite_.getPosition();
	float x = pos.x;
	float y = pos.y;

	int msElapsed = elapsed.asMilliseconds();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))      y -= SPEED * msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))    y += SPEED * msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))    x -= SPEED * msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))   x += SPEED * msElapsed;

	sprite_.setPosition(sf::Vector2f(x, y));

	if (fireTimer_ > 0)
	{
		fireTimer_ -= msElapsed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && fireTimer_ <= 0)
	{
		fireTimer_ = FIRE_DELAY;

		sf::FloatRect bounds = sprite_.getGlobalBounds();

		// Top Laser
		float laserXtop = x + (bounds.width / 2.0f);
		float laserYtop = y + 0;

		// Middle Laser
		float laserXmiddle = x + bounds.width;
		float laserYmiddle = y + (bounds.height / 2.0f);

		// Bottom Laser
		float laserXbottom = x + (bounds.width / 2);
		float laserYbottom = y + bounds.height;

		LaserPtr topLaser = std::make_shared<Laser>(sf::Vector2f(laserXtop, laserYtop));
		GAME.getCurrentScene().addGameObject(topLaser);

		LaserPtr middleLaser = std::make_shared<Laser>(sf::Vector2f(laserXmiddle, laserYmiddle));
		GAME.getCurrentScene().addGameObject(middleLaser);

		LaserPtr bottomLaser = std::make_shared<Laser>(sf::Vector2f(laserXbottom, laserYbottom));
		GAME.getCurrentScene().addGameObject(bottomLaser);

	}



}



