//プレイヤー管理クラス
#pragma once

//プロトタイプ宣言
//struct Sprite;
class Shot;
#include "Sprite.h"

class Player
{
public:
	Player();
	~Player();
	void Move();//プレイヤーの動き
	void FiringShot(Shot * shot);//弾発射処理
	void Draw();//描画
	Sprite player;
private:
	// ショットボタンが前のフレームで押されたかどうかを保存する変数にfalse(押されいない)を代入
	bool prevshotFlag = false;
};

