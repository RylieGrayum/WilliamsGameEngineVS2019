#pragma once

#include "Engine/GameEngine.h"
#include "Cone.h"

class ConeSpawner : public GameObject
{
public:
	void update(sf::Time& elapsed);
private:
	int timer_ = 0;
};

typedef std::shared_ptr<ConeSpawner> ConeSpawnerPtr;
