#include "ConeSpawner.h"

// The number of milliseconds between meteor spawns.
const int SPAWN_DELAY = 1000;

void ConeSpawner::update(sf::Time& elapsed) {
	// Determine how much time has passed and adjust our timer
	int msElapsed = elapsed.asMilliseconds();
	timer_ -= msElapsed;

	// If our timer has elapsed, reset it and spawn a cone.
	if (timer_ <= 0)
	{
		int t = (rand() % 3) + 1;
		timer_ = SPAWN_DELAY * t;

		sf::Vector2u size = GAME.getRenderWindow().getSize();
		// Spawn the cone off the top of the screen.
		// We're assuming the cone isn't more than 100 pixels wide.
		int lane = (float)(rand() % 2) + 1;
		float coneX;
		if (lane == 1)
		{
			coneX = 240.0f;
		} 
		else {
			coneX = 440.0f;
		}

		// Spawn the cone somewhere on the road, randomly.
		float coneY = 0.0f - size.y;

		// Create a cone and add it to the scene
		ConePtr cone = std::make_shared<Cone>(sf::Vector2f(coneX, coneY));
		GAME.getCurrentScene().addGameObject(cone);
	}
}