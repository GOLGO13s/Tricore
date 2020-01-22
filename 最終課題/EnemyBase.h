#pragma once
#include "Sprite.h"
//�v���g�^�C�v�錾
class Player;

class EnemyBase
{
public:
	EnemyBase();
	~EnemyBase();
	virtual void Update() = 0;
	virtual void Update(const Player& player){};
	void OnHit();
	Sprite GetterSprite() { return enemy; }
private:

protected:
	Sprite enemy;
	int damageGraph;
	int damageCounter;	//�_���[�W�J�E���g
	bool damageFlag;	//�_���[�W�t���O
};

