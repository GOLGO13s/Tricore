//�G�l�~�[(�ʏ�)�Ǘ��N���X
#pragma once

//�v���g�^�C�v�錾
//struct Sprite;
#include "Sprite.h"
#include "EnemyBase.h"
class Player;

class Enemy : public EnemyBase
{
public:
	Enemy();
	~Enemy();
	void Update();
	void Update(Player& player) {};
	void OnHit();
private:
	int hitCounter;			//�q�b�g�J�E���g
	bool enemyRightMove;	//�E���������肷��N���X
};