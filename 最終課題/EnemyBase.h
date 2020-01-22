#pragma once
#include "Sprite.h"
//プロトタイプ宣言
class Player;

class EnemyBase
{
public:
	EnemyBase();
	~EnemyBase();
	virtual void Update() = 0;
	virtual void Update(const Player& player){};
	void OnHit();
	Sprite GetterSprite() { return enemy; }
private:

protected:
	Sprite enemy;
	int damageGraph;
	int damageCounter;	//ダメージカウント
	bool damageFlag;	//ダメージフラグ
};

