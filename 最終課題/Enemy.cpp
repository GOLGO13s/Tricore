//#include "Sprite.h"
#include "Enemy.h"
#include "main.h"

//��߰�ނ̒�`
constexpr float speed = 3.5;

//������
Enemy::Enemy()
{
	//������
	//�G�l�~�[�̕\�����W������
	enemy.pos.x = SCREEN_SIZE_X / 2;
	enemy.pos.y = SCREEN_SIZE_Y - SCREEN_SIZE_Y;
	//�G�l�~�[�̉摜�ǂݍ���
	enemy.graph = LoadGraph("data/texture/anpanman.png");
	//�G�l�~�[�̃_���[�W���̉摜�ǂݍ���
	damageGraph = LoadGraph("data/texture/anpanmanDamage.png");
	//�G�l�~�[�X�s�[�h
	enemy.speed = speed;
	//�G�l�~�[�̃_���[�W�t���O
	damageFlag = false;
	// �G�l�~�[�̃O���t�B�b�N�̃T�C�Y�𓾂�
	GetGraphSize(enemy.graph, &enemy.h, &enemy.w);
	// �G�l�~�[���E�ړ����Ă��邩�ǂ����̃t���O�����Z�b�g
	enemyRightMove = true;
	//�q�b�g�����񐔂�ێ�����ϐ�
	hitCounter = 0;
}


Enemy::~Enemy()
{

}


//------------------------------//
// �G�l�~�[���[�`��
//------------------------------//
void Enemy::Update()
{
	// �G�l�~�[�̍��W���ړ����Ă�������Ɉړ�����
	if (enemyRightMove == true)
	{
		enemy.pos.x += enemy.speed;
	}
	else
	{
		enemy.pos.x -= enemy.speed;
	}

	// �G�l�~�[����ʒ[����ł����ɂȂ��Ă������ʓ��̍��W�ɖ߂��Ă����A�ړ�������������]����
	if (enemy.pos.x > SCREEN_SIZE_X - enemy.w)
	{
		enemy.pos.x = SCREEN_SIZE_X - enemy.w;
		enemyRightMove = false;
	}
	else if (enemy.pos.x < SCREEN_SIZE_X-SCREEN_SIZE_X)
	{
		enemy.pos.x = SCREEN_SIZE_X - SCREEN_SIZE_X;
		enemyRightMove = true;
	}

	// �G�l�~�[��`��
	// ���c�߂Ă��邩�ǂ����ŏ����𕪊�
	if (damageFlag == true)
	{
		// ���c�߂Ă���ꍇ�̓_���[�W���̃O���t�B�b�N��`�悷��
		DrawGraph(enemy.pos.x, enemy.pos.y,damageGraph, FALSE);

		// ���c�߂Ă��鎞�Ԃ𑪂�J�E���^�[�ɂP�����Z����
		damageCounter++;

		// �������c�ߏ��߂� �R�O �t���[���o�߂��Ă������̘c�񂾏�Ԃ���
		// ���ɖ߂��Ă�����
		if (damageCounter == 30)
		{
			// �w�c��ł��Ȃ��x��\���O����
			damageFlag = 0;
		}
	}
	/*else if (hitCounter >= 20)
	{
		DrawGraph(enemy.pos.x, enemy.pos.y, , FALSE);
	}*/
	else
	{
		DrawGraph(enemy.pos.x, enemy.pos.y, enemy.graph, FALSE);
	}
}

void Enemy::OnHit()
{
	// �G�l�~�[�̊��c�߂Ă��邩�ǂ�����ێ�����ϐ��Ɂw�c�߂Ă���x��\���P����
	damageFlag = true;
	// �G�l�~�[�̊��c�߂Ă��鎞�Ԃ𑪂�J�E���^�ϐ��ɂO����
	damageCounter = 0;
	//�q�b�g�����񐔂��P���₷
	hitCounter++;
}