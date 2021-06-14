#include "Background.h"
#include "GameScene.h"

const float SPEED = 0.25f;
const float GAP = 165.0f; // this gap is needed to push the road to the center of the screen.

Background::Background(sf::Vector2f pos)
{
	initial_y = pos.y;
	pos.x = GAP;
	sprite_.setTexture(GAME.getTexture("Resources/roadpicture.jpg")); // Use the road picture as the background
	sprite_.setPosition(pos);
}

void Background::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}

void Background::update(sf::Time& elapsed) {

	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();

	if (pos.y - WINDOW_HEIGHT > initial_y)
	{
		sprite_.setPosition(GAP, initial_y);
	}
	else
	{
		// Reposition the road to scroll vertically.
		sprite_.setPosition(sf::Vector2f(pos.x, pos.y + SPEED * msElapsed));
	}
}
