//�v���C���[�Ǘ��N���X
#pragma once

//�v���g�^�C�v�錾
//struct Sprite;
class Shot;
#include "Sprite.h"

class Player
{
public:
	Player();
	~Player();
	void Move();//�v���C���[�̓���
	void FiringShot(Shot * shot);//�e���ˏ���
	void Draw();//�`��
	Sprite player;
private:
	// �V���b�g�{�^�����O�̃t���[���ŉ����ꂽ���ǂ�����ۑ�����ϐ���false(�����ꂢ�Ȃ�)����
	bool prevshotFlag = false;
};

