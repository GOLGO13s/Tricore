//#include "Sprite.h"
#include "Enemy.h"
#include "main.h"

//ｽﾋﾟｰﾄﾞの定義
constexpr float speed = 3.5;

//初期化
Enemy::Enemy()
{
	//初期化
	//エネミーの表示座標初期化
	enemy.pos.x = SCREEN_SIZE_X / 2;
	enemy.pos.y = SCREEN_SIZE_Y - SCREEN_SIZE_Y;
	//エネミーの画像読み込み
	enemy.graph = LoadGraph("data/texture/anpanman.png");
	//エネミーのダメージ時の画像読み込み
	damageGraph = LoadGraph("data/texture/anpanmanDamage.png");
	//エネミースピード
	enemy.speed = speed;
	//エネミーのダメージフラグ
	damageFlag = false;
	// エネミーのグラフィックのサイズを得る
	GetGraphSize(enemy.graph, &enemy.h, &enemy.w);
	// エネミーが右移動しているかどうかのフラグをリセット
	enemyRightMove = true;
	//ヒットした回数を保持する変数
	hitCounter = 0;
}


Enemy::~Enemy()
{

}


//------------------------------//
// エネミールーチン
//------------------------------//
void Enemy::Update()
{
	// エネミーの座標を移動している方向に移動する
	if (enemyRightMove == true)
	{
		enemy.pos.x += enemy.speed;
	}
	else
	{
		enemy.pos.x -= enemy.speed;
	}

	// エネミーが画面端からでそうになっていたら画面内の座標に戻してあげ、移動する方向も反転する
	if (enemy.pos.x > SCREEN_SIZE_X - enemy.w)
	{
		enemy.pos.x = SCREEN_SIZE_X - enemy.w;
		enemyRightMove = false;
	}
	else if (enemy.pos.x < SCREEN_SIZE_X-SCREEN_SIZE_X)
	{
		enemy.pos.x = SCREEN_SIZE_X - SCREEN_SIZE_X;
		enemyRightMove = true;
	}

	// エネミーを描画
	// 顔を歪めているかどうかで処理を分岐
	if (damageFlag == true)
	{
		// 顔を歪めている場合はダメージ時のグラフィックを描画する
		DrawGraph(enemy.pos.x, enemy.pos.y,damageGraph, FALSE);

		// 顔を歪めている時間を測るカウンターに１を加算する
		damageCounter++;

		// もし顔を歪め初めて ３０ フレーム経過していたら顔の歪んだ状態から
		// 元に戻してあげる
		if (damageCounter == 30)
		{
			// 『歪んでいない』を表す０を代入
			damageFlag = 0;
		}
	}
	/*else if (hitCounter >= 20)
	{
		DrawGraph(enemy.pos.x, enemy.pos.y, , FALSE);
	}*/
	else
	{
		DrawGraph(enemy.pos.x, enemy.pos.y, enemy.graph, FALSE);
	}
}

void Enemy::OnHit()
{
	// エネミーの顔を歪めているかどうかを保持する変数に『歪めている』を表す１を代入
	damageFlag = true;
	// エネミーの顔を歪めている時間を測るカウンタ変数に０を代入
	damageCounter = 0;
	//ヒットした回数を１増やす
	hitCounter++;
}