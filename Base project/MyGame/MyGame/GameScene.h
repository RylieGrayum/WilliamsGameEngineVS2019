#pragma once

#include "Engine/GameEngine.h"

const int WINDOW_WIDTH = 1000;
const int WINDOW_HEIGHT = 800;

class GameScene : public Scene {
 public:
  // Creates our Scene.
  GameScene();

  // Get the gurrent score
  int getScore();

  // Increase the score
  void increaseScore();

  // Get the number of lives
  int getLives();
  
  //Decrease the number of lives
  void decreaseLives();

private:
	int score_ = 0;
	int lives_ = 3;
};

typedef std::shared_ptr<GameScene> GameScenePtr;
