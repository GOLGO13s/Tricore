#include "EnemyBase.h"

EnemyBase::EnemyBase()
{
}

EnemyBase::~EnemyBase()
{
}

void EnemyBase::OnHit()
{
	// エネミーの顔を歪めているかどうかを保持する変数に『歪めている』を表す１を代入
	damageFlag = true;
	// エネミーの顔を歪めている時間を測るカウンタ変数に０を代入
	damageCounter = 0;
}

