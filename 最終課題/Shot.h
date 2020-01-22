//�V���b�g�Ǘ��N���X
#pragma once

//�v���g�^�C�v�錾
//struct Sprite;
class Player;
class EnemyBase;
class EnemyManager;
#include "Sprite.h"

// �V���b�g�̐�.
#define SHOT 20

class Shot
{
public:
	Shot();
	~Shot();
	void Update(/*Enemy& enemy*/);
	void HitShotNormal(VECTOR vec,int w ,int h);//�����蔻��֐�
	void HitShotTracking(VECTOR vec, int w, int h);//�����蔻��֐�

	bool shotFlag[SHOT];//�V���b�g�t���O
	Sprite shot[SHOT];
private:
	Player * player = NULL;
	EnemyBase * normal = NULL;
	EnemyBase * tracking = NULL;
	//EnemyManager * manager;

	bool hitFlag = false;
};