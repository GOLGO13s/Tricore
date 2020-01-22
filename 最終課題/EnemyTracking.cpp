#include "main.h"
#include "EnemyTracking.h"
#include "Player.h"

//エネミーのスピードの定義
constexpr float speed = 0.5;

EnemyTracking::EnemyTracking()
{
	//初期化
	//エネミーの表示座標初期化
	enemy.pos.x = 150;
	enemy.pos.y = SCREEN_SIZE_Y - SCREEN_SIZE_Y;
	//エネミーの画像読み込み
	enemy.graph = LoadGraph("data/texture/fugu.png");
	//エネミーのダメージ時の画像読み込み
	damageGraph = LoadGraph("data/texture/fuguDamage.png");
	//エネミースピード
	enemy.speed = speed;
	//エネミーのダメージフラグ
	damageFlag = false;
	// エネミーのグラフィックのサイズを得る
	GetGraphSize(enemy.graph, &enemy.h, &enemy.w);
}


EnemyTracking::~EnemyTracking()
{
}


void EnemyTracking::Update(const Player& player)
{
	// ベクトル移動
	VECTOR EP = VSub(player.player.pos, enemy.pos);//エネミーからプレイヤーの座標
	EP = VNorm(EP);//EPベクトル正規化
	EP = VScale(EP, speed);//EPにスピードをかける
	enemy.pos = VAdd(enemy.pos, EP);//エネミーの座標を補正

	// エネミーを描画
	// 顔を歪めているかどうかで処理を分岐
	if (damageFlag == true)
	{
		// 顔を歪めている場合はダメージ時のグラフィックを描画する
		DrawGraph(enemy.pos.x, enemy.pos.y, damageGraph, FALSE);

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
	else
	{
		DrawGraph(enemy.pos.x, enemy.pos.y, enemy.graph, FALSE);
	}
}

void EnemyTracking::OnHit()
{
	// エネミーの顔を歪めているかどうかを保持する変数に『歪めている』を表す１を代入
	damageFlag = true;
	// エネミーの顔を歪めている時間を測るカウンタ変数に０を代入
	damageCounter = 0;
}
