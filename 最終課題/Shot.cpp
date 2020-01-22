#include "main.h"
#include "Shot.h"
#include "Player.h"
#include "Enemy.h"
#include "EnemyTracking.h"
#include "EnemyManager.h"

Shot::Shot()
{
	//������
	for (int i = 0; i < SHOT; i++)
	{
		shot[i].graph = LoadGraph("data/texture/shot.png");
		// �e����ʏ�ɑ��݂��Ă��邩�ێ�����ϐ��Ɂw���݂��Ă��Ȃ��x���Ӗ�����false�������Ă���
		shotFlag[i] = false;
		// �e�̃O���t�B�b�N�̃T�C�Y������
		GetGraphSize(shot[i].graph, &shot[i].w, &shot[i].h);
	}

	hitFlag = false;
	//�v���C���[�ƃG�l�~�[�����̐���
	player = new Player();
	normal = new Enemy();
	tracking = new EnemyTracking();
	//if (manager != NULL)manager = NULL;
	//if(manager == NULL)manager = new EnemyManager();
}


Shot::~Shot()
{
	delete(player);
	player = NULL;
	delete(normal);
	normal = NULL;
	delete(tracking);
	tracking = NULL;
	//delete(manager);
	//manager = NULL;
}


void Shot::Update()
{
	player->Move();
	normal->Update();
	tracking->Update(*player);
	//------------------------------//
	// �e���[�`��
	//------------------------------//
	for (int i = 0; i < SHOT; i++)
	{
		// ���@�̒ei�̈ړ����[�`��( ���ݏ�Ԃ�ێ����Ă���ϐ��̓��e��true(���݂���)�̏ꍇ�̂ݍs�� )
		if (shotFlag[i] == true)
		{
			// �ei���P�U�h�b�g��Ɉړ�������
			shot[i].pos.y -= 16;

			// ��ʊO�ɏo�Ă��܂����ꍇ�͑��ݏ�Ԃ�ێ����Ă���ϐ���false(���݂��Ȃ�)��������
			if (shot[i].pos.y < -80)
			{
				shotFlag[i] = false;
			}

			// ��ʂɒei��`�悷��
			DrawGraph(shot[i].pos.x, shot[i].pos.y, shot[i].graph, FALSE);
		}

		// �e�̂����蔻��.
		// �ei�����݂��Ă���ꍇ�̂ݎ��̏����ɉf��
		if (shotFlag[i] == 1)
		{
			//�G�l�~�[�̓����蔻��
			HitShotNormal(normal->GetterSprite().pos, normal->GetterSprite().w, normal->GetterSprite().h);
			//�G�l�~�[�g���b�L���O�Ƃ̓����蔻��
			HitShotTracking(tracking->GetterSprite().pos, tracking->GetterSprite().w, tracking->GetterSprite().h);
		}
	}
}

void Shot::HitShotNormal(VECTOR vec, int w, int h)
{
	for (int i = 0; i < SHOT; i++)
	{
		// �G�l�~�[�Ƃ̓����蔻��
		if (((shot[i].pos.x > vec.x&& shot[i].pos.x < vec.x + w) || (vec.x > shot[i].pos.x && vec.x < shot[i].pos.x + shot[i].w))
			&& ((shot[i].pos.y > vec.y && shot[i].pos.y < vec.y + h) || (vec.y > shot[i].pos.y && vec.y < shot[i].pos.y + shot[i].h)))
		{
			// �ڐG���Ă���ꍇ�͓��������e�̑��݂�����
			shotFlag[i] = 0;
			//�G�l�~�[�Ƀq�b�g�����Ƃ��̏���
			normal->OnHit();
		}
	}
}

void Shot::HitShotTracking(VECTOR vec, int w, int h)
{
	for (int i = 0; i < SHOT; i++)
	{
		// �G�l�~�[�Ƃ̓����蔻��
		if (((shot[i].pos.x > vec.x&& shot[i].pos.x < vec.x + w) || (vec.x > shot[i].pos.x && vec.x < shot[i].pos.x + shot[i].w))
			&& ((shot[i].pos.y > vec.y && shot[i].pos.y < vec.y + h) || (vec.y > shot[i].pos.y && vec.y < shot[i].pos.y + shot[i].h)))
		{
			// �ڐG���Ă���ꍇ�͓��������e�̑��݂�����
			shotFlag[i] = 0;
			//�G�l�~�[�Ƀq�b�g�����Ƃ��̏���
			tracking->OnHit();
		}
	}
}

