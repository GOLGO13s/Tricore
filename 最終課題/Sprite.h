//画像管理クラス
#pragma once
#include "DxLib.h"

struct Sprite
{
	VECTOR pos;			//座標
	int graph;			//画像ハンドル
	int h;				//高さ
	int w;				//幅
	int speed;			//移動ｽﾋﾟｰﾄﾞ
};