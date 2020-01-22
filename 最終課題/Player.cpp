
#include "main.h"
#include "Player.h"
#include "Shot.h"

//ｽﾋﾟｰﾄﾞの定義
constexpr int speed = 3;

Player::Player()
{
	//初期化
	//プレイヤーの表示座標初期化
	player.pos.x = SCREEN_SIZE_X / 2;
	player.pos.y = SCREEN_SIZE_Y / 2;
	//画像の読み込み
	player.graph = LoadGraph("data/texture/player.png");
	//プレイヤースピード
	player.speed = speed;
}

Player::~Player()
{

}

void Player::Move()
{
	//------------------------------//
	// プレイヤールーチン
	//------------------------------//
	// 矢印キーを押していたらプレイヤーを移動させる
	if (CheckHitKey(KEY_INPUT_UP) == 1)
	{
		player.pos.y -= speed;
	}
	if (CheckHitKey(KEY_INPUT_DOWN) == 1)
	{
		player.pos.y += speed;
	}
	if (CheckHitKey(KEY_INPUT_LEFT) == 1)
	{
		player.pos.x -= speed;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
	{
		player.pos.x += speed;
	}

	// プレイヤーが画面左端からはみ出そうになっていたら画面内の座標に戻してあげる
	if (player.pos.x < SCREEN_SIZE_X - SCREEN_SIZE_X)
	{
		player.pos.x = SCREEN_SIZE_X - SCREEN_SIZE_X;
	}
	if (player.pos.x > SCREEN_SIZE_X - 64)
	{
		player.pos.x = SCREEN_SIZE_X - 64;
	}
	if (player.pos.y < SCREEN_SIZE_Y - SCREEN_SIZE_Y)
	{
		player.pos.y = SCREEN_SIZE_Y - SCREEN_SIZE_Y;
	}
	if (player.pos.y > SCREEN_SIZE_Y - 64)
	{
		player.pos.y = SCREEN_SIZE_Y - 64;
	}
}

//プレイヤールーチン
void Player::FiringShot(Shot * shot)
{
	//弾の発射処理
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		// 前フレームでショットボタンを押したかが保存されている変数がfalseだったら弾を発射
		if (prevshotFlag == false)
		{
			// 画面上にでていない弾があるか、弾の数だけ繰り返して調べる
			for (int i = 0; i < SHOT; i++)
			{
				// 弾iが画面上にでていない場合はその弾を画面に出す
				if (shot->shotFlag[i] == false)
				{
					int Bw, Bh, Sw, Sh;

					// プレイヤーと弾の画像のサイズを得る
					GetGraphSize(player.graph, &Bw, &Bh);
					GetGraphSize(shot->shot[i].graph, &Sw, &Sh);

					// 弾iの位置をセット、位置はプレイヤーの中心にする
					shot->shot[i].pos.x = (Bw - Sw) / 2 + player.pos.x;
					shot->shot[i].pos.y = (Bh - Sh) / 2 + player.pos.y;

					// 弾iは現時点を持って存在するので、存在状態を保持する変数にtrueを代入する
					shot->shotFlag[i] = true;

					// 一つ弾を出したので弾を出すループから抜けます
					break;
				}
			}
		}

		// 前フレームでショットボタンを押されていたかを保存する変数にtrue(おされていた)を代入
		prevshotFlag = true;
	}
	else
	{
		// ショットボタンが押されていなかった場合は
		// 前フレームでショットボタンが押されていたかを保存する変数にfalse(おされていない)を代入
		prevshotFlag = false;
	}
}
	
void Player::Draw()
{

	// プレイヤーを描画
	DrawGraph(player.pos.x, player.pos.y, player.graph, FALSE);
}