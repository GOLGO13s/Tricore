#include "main.h"
#include "EnemyTracking.h"
#include "Player.h"

//�G�l�~�[�̃X�s�[�h�̒�`
constexpr float speed = 0.5;

EnemyTracking::EnemyTracking()
{
	//������
	//�G�l�~�[�̕\�����W������
	enemy.pos.x = 150;
	enemy.pos.y = SCREEN_SIZE_Y - SCREEN_SIZE_Y;
	//�G�l�~�[�̉摜�ǂݍ���
	enemy.graph = LoadGraph("data/texture/fugu.png");
	//�G�l�~�[�̃_���[�W���̉摜�ǂݍ���
	damageGraph = LoadGraph("data/texture/fuguDamage.png");
	//�G�l�~�[�X�s�[�h
	enemy.speed = speed;
	//�G�l�~�[�̃_���[�W�t���O
	damageFlag = false;
	// �G�l�~�[�̃O���t�B�b�N�̃T�C�Y�𓾂�
	GetGraphSize(enemy.graph, &enemy.h, &enemy.w);
}


EnemyTracking::~EnemyTracking()
{
}


void EnemyTracking::Update(const Player& player)
{
	// �x�N�g���ړ�
	VECTOR EP = VSub(player.player.pos, enemy.pos);//�G�l�~�[����v���C���[�̍��W
	EP = VNorm(EP);//EP�x�N�g�����K��
	EP = VScale(EP, speed);//EP�ɃX�s�[�h��������
	enemy.pos = VAdd(enemy.pos, EP);//�G�l�~�[�̍��W��␳

	// �G�l�~�[��`��
	// ���c�߂Ă��邩�ǂ����ŏ����𕪊�
	if (damageFlag == true)
	{
		// ���c�߂Ă���ꍇ�̓_���[�W���̃O���t�B�b�N��`�悷��
		DrawGraph(enemy.pos.x, enemy.pos.y, damageGraph, FALSE);

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
	else
	{
		DrawGraph(enemy.pos.x, enemy.pos.y, enemy.graph, FALSE);
	}
}

void EnemyTracking::OnHit()
{
	// �G�l�~�[�̊��c�߂Ă��邩�ǂ�����ێ�����ϐ��Ɂw�c�߂Ă���x��\���P����
	damageFlag = true;
	// �G�l�~�[�̊��c�߂Ă��鎞�Ԃ𑪂�J�E���^�ϐ��ɂO����
	damageCounter = 0;
}
