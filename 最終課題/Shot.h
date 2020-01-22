//ショット管理クラス
#pragma once

//プロトタイプ宣言
//struct Sprite;
class Player;
class EnemyBase;
class EnemyManager;
#include "Sprite.h"

// ショットの数.
#define SHOT 20

class Shot
{
public:
	Shot();
	~Shot();
	void Update(/*Enemy& enemy*/);
	void HitShotNormal(VECTOR vec,int w ,int h);//当たり判定関数
	void HitShotTracking(VECTOR vec, int w, int h);//当たり判定関数

	bool shotFlag[SHOT];//ショットフラグ
	Sprite shot[SHOT];
private:
	Player * player = NULL;
	EnemyBase * normal = NULL;
	EnemyBase * tracking = NULL;
	//EnemyManager * manager;

	bool hitFlag = false;
};