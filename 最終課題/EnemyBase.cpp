#include "EnemyBase.h"

EnemyBase::EnemyBase()
{
}

EnemyBase::~EnemyBase()
{
}

void EnemyBase::OnHit()
{
	// �G�l�~�[�̊��c�߂Ă��邩�ǂ�����ێ�����ϐ��Ɂw�c�߂Ă���x��\���P����
	damageFlag = true;
	// �G�l�~�[�̊��c�߂Ă��鎞�Ԃ𑪂�J�E���^�ϐ��ɂO����
	damageCounter = 0;
}

