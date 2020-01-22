#include "EnemyManager.h"
#include "EnemyBase.h"
#include "Enemy.h"
#include "EnemyTracking.h"
#include "Player.h"


EnemyManager::EnemyManager()
{
	player - NULL;
	normal = NULL;
	tracking = NULL;
}


EnemyManager::~EnemyManager()
{

}

void EnemyManager::CreateEnemy()
{
	player = new Player();
	normal = new Enemy();
	tracking = new EnemyTracking();
}

void EnemyManager::Update()
{
	player->Move();
	normal->Update();
	tracking->Update(*player);
}
