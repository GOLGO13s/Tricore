#pragma once

//プロトタイプ宣言
class EnemyBase;
class Player;

class EnemyManager
{
public:
	EnemyManager();
	~EnemyManager();
	void CreateEnemy();
	void Update();
private:
	Player * player;
	EnemyBase * normal;
	EnemyBase * tracking;
};

