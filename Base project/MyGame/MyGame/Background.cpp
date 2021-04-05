#include "Background.h"
#include "GameScene.h"

const float SPEED = 0.10f;

Background::Background(sf::Vector2f pos)
{
	initial_x = pos.x;
	sprite_.setTexture(GAME.getTexture("Resources/background.png"));
	sprite_.setPosition(pos);
}

void Background::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}

void Background::update(sf::Time& elapsed) {

	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();

	if (pos.x + WINDOW_WIDTH < initial_x)
	{
		sprite_.setPosition(initial_x, 0.0f);
	}
	else
	{
		sprite_.setPosition(sf::Vector2f(pos.x - SPEED * msElapsed, pos.y));
	}
}
