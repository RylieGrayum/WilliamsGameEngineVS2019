#include "GameScene.h"
#include "Ship.h"
#include "MeteorSpawner.h"
#include "Score.h"
#include "GameOverScene.h"
#include "GoodLuckMessage.h"
#include "Background.h"

GameScene::GameScene()
{

	// Create background here.
	BackgroundPtr background1 = std::make_shared<Background>(sf::Vector2f(0.0f, 0.0f));
	addGameObject(background1);

	BackgroundPtr background2 = std::make_shared<Background>(sf::Vector2f(WINDOW_WIDTH, 0.0f));
	addGameObject(background2);

	ShipPtr ship = std::make_shared<Ship>();
	addGameObject(ship);

	MeteorSpawnerPtr meteorSpawner = std::make_shared<MeteorSpawner>();
	addGameObject(meteorSpawner);

	ScorePtr score = std::make_shared<Score>(sf::Vector2f(10.0f, 10.0f));
	addGameObject(score);

	int height = WINDOW_HEIGHT / 2;
	int width = WINDOW_WIDTH / 2;

	GoodLuckPtr goodLuck = std::make_shared<GoodLuck>(sf::Vector2f(width - 300, height - 100));
	addGameObject(goodLuck);
}

int GameScene::getScore()
{
	return score_;
}

void GameScene::increaseScore()
{
	++score_;
}

int GameScene::getLives()
{
	return lives_;
}

void GameScene::decreaseLives()
{
	--lives_;

	if (lives_ == 0)
	{
		GameOverScenePtr gameOverScene = std::make_shared<GameOverScene>(score_);
		GAME.setScene(gameOverScene);
	}
}





