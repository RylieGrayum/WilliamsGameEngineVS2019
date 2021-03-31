#include "GoodLuckMessage.h"
#include "GameScene.h"
#include <sstream>

GoodLuck::GoodLuck(sf::Vector2f pos)
{
	text_.setFont(GAME.getFont("Resources/Courneuf-Regular.ttf"));
	text_.setPosition(pos);
	text_.setCharacterSize(100);
#pragma warning(suppress : 4996)
	text_.setColor(sf::Color::Blue);
	assignTag("goodluck");
}

void GoodLuck::draw()
{
	GAME.getRenderWindow().draw(text_);
}

void GoodLuck::update(sf::Time& elapsed) {
	GameScene& scene = (GameScene&)GAME.getCurrentScene();

	std::stringstream stream;
	stream << "GOOD LUCK!!!";

	text_.setString(stream.str());

	if (messageCount-- <= 0) {
		makeDead();
		messageCount = 100;
	}
}