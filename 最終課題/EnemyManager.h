#pragma once

//�v���g�^�C�v�錾
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

