//�G�l�~�[(�ǂ������Ă���)�Ǘ��N���X
#pragma once
//#include "Sprite.h"
#include "EnemyBase.h"

//�v���g�^�C�v�錾
class Player;

class EnemyTracking : public EnemyBase
{
public:
	EnemyTracking();
	~EnemyTracking();
	void Update() {}
	void Update(const Player& player);
	void OnHit();
private:
	
};

