//エネミー(追いかけてくる)管理クラス
#pragma once
//#include "Sprite.h"
#include "EnemyBase.h"

//プロトタイプ宣言
class Player;

class EnemyTracking : public EnemyBase
{
public:
	EnemyTracking();
	~EnemyTracking();
	void Update() {}
	void Update(const Player& player);
	void OnHit();
private:
	
};

