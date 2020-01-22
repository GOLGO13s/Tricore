
#include "main.h"
#include "Player.h"
#include "Shot.h"

//��߰�ނ̒�`
constexpr int speed = 3;

Player::Player()
{
	//������
	//�v���C���[�̕\�����W������
	player.pos.x = SCREEN_SIZE_X / 2;
	player.pos.y = SCREEN_SIZE_Y / 2;
	//�摜�̓ǂݍ���
	player.graph = LoadGraph("data/texture/player.png");
	//�v���C���[�X�s�[�h
	player.speed = speed;
}

Player::~Player()
{

}

void Player::Move()
{
	//------------------------------//
	// �v���C���[���[�`��
	//------------------------------//
	// ���L�[�������Ă�����v���C���[���ړ�������
	if (CheckHitKey(KEY_INPUT_UP) == 1)
	{
		player.pos.y -= speed;
	}
	if (CheckHitKey(KEY_INPUT_DOWN) == 1)
	{
		player.pos.y += speed;
	}
	if (CheckHitKey(KEY_INPUT_LEFT) == 1)
	{
		player.pos.x -= speed;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
	{
		player.pos.x += speed;
	}

	// �v���C���[����ʍ��[����͂ݏo�����ɂȂ��Ă������ʓ��̍��W�ɖ߂��Ă�����
	if (player.pos.x < SCREEN_SIZE_X - SCREEN_SIZE_X)
	{
		player.pos.x = SCREEN_SIZE_X - SCREEN_SIZE_X;
	}
	if (player.pos.x > SCREEN_SIZE_X - 64)
	{
		player.pos.x = SCREEN_SIZE_X - 64;
	}
	if (player.pos.y < SCREEN_SIZE_Y - SCREEN_SIZE_Y)
	{
		player.pos.y = SCREEN_SIZE_Y - SCREEN_SIZE_Y;
	}
	if (player.pos.y > SCREEN_SIZE_Y - 64)
	{
		player.pos.y = SCREEN_SIZE_Y - 64;
	}
}

//�v���C���[���[�`��
void Player::FiringShot(Shot * shot)
{
	//�e�̔��ˏ���
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		// �O�t���[���ŃV���b�g�{�^���������������ۑ�����Ă���ϐ���false��������e�𔭎�
		if (prevshotFlag == false)
		{
			// ��ʏ�ɂłĂ��Ȃ��e�����邩�A�e�̐������J��Ԃ��Ē��ׂ�
			for (int i = 0; i < SHOT; i++)
			{
				// �ei����ʏ�ɂłĂ��Ȃ��ꍇ�͂��̒e����ʂɏo��
				if (shot->shotFlag[i] == false)
				{
					int Bw, Bh, Sw, Sh;

					// �v���C���[�ƒe�̉摜�̃T�C�Y�𓾂�
					GetGraphSize(player.graph, &Bw, &Bh);
					GetGraphSize(shot->shot[i].graph, &Sw, &Sh);

					// �ei�̈ʒu���Z�b�g�A�ʒu�̓v���C���[�̒��S�ɂ���
					shot->shot[i].pos.x = (Bw - Sw) / 2 + player.pos.x;
					shot->shot[i].pos.y = (Bh - Sh) / 2 + player.pos.y;

					// �ei�͌����_�������đ��݂���̂ŁA���ݏ�Ԃ�ێ�����ϐ���true��������
					shot->shotFlag[i] = true;

					// ��e���o�����̂Œe���o�����[�v���甲���܂�
					break;
				}
			}
		}

		// �O�t���[���ŃV���b�g�{�^����������Ă�������ۑ�����ϐ���true(������Ă���)����
		prevshotFlag = true;
	}
	else
	{
		// �V���b�g�{�^����������Ă��Ȃ������ꍇ��
		// �O�t���[���ŃV���b�g�{�^����������Ă�������ۑ�����ϐ���false(������Ă��Ȃ�)����
		prevshotFlag = false;
	}
}
	
void Player::Draw()
{

	// �v���C���[��`��
	DrawGraph(player.pos.x, player.pos.y, player.graph, FALSE);
}