//エネミー(通常)管理クラス
#pragma once

//プロトタイプ宣言
//struct Sprite;
#include "Sprite.h"
#include "EnemyBase.h"
class Player;

class Enemy : public EnemyBase
{
public:
	Enemy();
	~Enemy();
	void Update();
	void Update(Player& player) {};
	void OnHit();
private:
	int hitCounter;			//ヒットカウント
	bool enemyRightMove;	//右向きか判定するクラス
};