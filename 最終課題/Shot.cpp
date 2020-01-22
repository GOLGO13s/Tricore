#include "main.h"
#include "Shot.h"
#include "Player.h"
#include "Enemy.h"
#include "EnemyTracking.h"
#include "EnemyManager.h"

Shot::Shot()
{
	//初期化
	for (int i = 0; i < SHOT; i++)
	{
		shot[i].graph = LoadGraph("data/texture/shot.png");
		// 弾が画面上に存在しているか保持する変数に『存在していない』を意味するfalseを代入しておく
		shotFlag[i] = false;
		// 弾のグラフィックのサイズをえる
		GetGraphSize(shot[i].graph, &shot[i].w, &shot[i].h);
	}

	hitFlag = false;
	//プレイヤーとエネミーたちの生成
	player = new Player();
	normal = new Enemy();
	tracking = new EnemyTracking();
	//if (manager != NULL)manager = NULL;
	//if(manager == NULL)manager = new EnemyManager();
}


Shot::~Shot()
{
	delete(player);
	player = NULL;
	delete(normal);
	normal = NULL;
	delete(tracking);
	tracking = NULL;
	//delete(manager);
	//manager = NULL;
}


void Shot::Update()
{
	player->Move();
	normal->Update();
	tracking->Update(*player);
	//------------------------------//
	// 弾ルーチン
	//------------------------------//
	for (int i = 0; i < SHOT; i++)
	{
		// 自機の弾iの移動ルーチン( 存在状態を保持している変数の内容がtrue(存在する)の場合のみ行う )
		if (shotFlag[i] == true)
		{
			// 弾iを１６ドット上に移動させる
			shot[i].pos.y -= 16;

			// 画面外に出てしまった場合は存在状態を保持している変数にfalse(存在しない)を代入する
			if (shot[i].pos.y < -80)
			{
				shotFlag[i] = false;
			}

			// 画面に弾iを描画する
			DrawGraph(shot[i].pos.x, shot[i].pos.y, shot[i].graph, FALSE);
		}

		// 弾のあたり判定.
		// 弾iが存在している場合のみ次の処理に映る
		if (shotFlag[i] == 1)
		{
			//エネミーの当たり判定
			HitShotNormal(normal->GetterSprite().pos, normal->GetterSprite().w, normal->GetterSprite().h);
			//エネミートラッキングとの当たり判定
			HitShotTracking(tracking->GetterSprite().pos, tracking->GetterSprite().w, tracking->GetterSprite().h);
		}
	}
}

void Shot::HitShotNormal(VECTOR vec, int w, int h)
{
	for (int i = 0; i < SHOT; i++)
	{
		// エネミーとの当たり判定
		if (((shot[i].pos.x > vec.x&& shot[i].pos.x < vec.x + w) || (vec.x > shot[i].pos.x && vec.x < shot[i].pos.x + shot[i].w))
			&& ((shot[i].pos.y > vec.y && shot[i].pos.y < vec.y + h) || (vec.y > shot[i].pos.y && vec.y < shot[i].pos.y + shot[i].h)))
		{
			// 接触している場合は当たった弾の存在を消す
			shotFlag[i] = 0;
			//エネミーにヒットしたときの処理
			normal->OnHit();
		}
	}
}

void Shot::HitShotTracking(VECTOR vec, int w, int h)
{
	for (int i = 0; i < SHOT; i++)
	{
		// エネミーとの当たり判定
		if (((shot[i].pos.x > vec.x&& shot[i].pos.x < vec.x + w) || (vec.x > shot[i].pos.x && vec.x < shot[i].pos.x + shot[i].w))
			&& ((shot[i].pos.y > vec.y && shot[i].pos.y < vec.y + h) || (vec.y > shot[i].pos.y && vec.y < shot[i].pos.y + shot[i].h)))
		{
			// 接触している場合は当たった弾の存在を消す
			shotFlag[i] = 0;
			//エネミーにヒットしたときの処理
			tracking->OnHit();
		}
	}
}

