#pragma once
#include "Player.h"
#include "MovingEnemy.h"
#include "Door.h"
#include "SceneBase.h"
class Field : public SceneBase
{
private:
	static constexpr int kFieldX = 13;
	static constexpr int kFieldY = 13;

public:
	Field();
	virtual ~Field();
	virtual void init()override;
	// �I������
	void end()override;

	virtual SceneBase* update()override;

	// �}�b�v�Ƃ̓����蔻��
	int EnemyBlockHitCheck(float enemyX, float enemyY, float& enemyMoveX, float& enemyMoveY);
	// �}�b�v�`�b�v�̒l���擾����֐�
	int GetChipParam(float X, float Y);

	virtual void draw()override;

	

private:
	// �Ֆʂ̕\��������W
	int m_fieldX;
	int m_fieldY;
	// �n�[�g�̐�
	int HeartCount;
	// �󔠂̐�
	int TreasureCount;
	// �X�e�[�W�̐�
	int StageNumber = 1;

	// ���������Ă邩�ǂ���
	int KeyGet = 12;
	// �v���C���[�ɓ������Ă��邩�ǂ���
	int playerHit = 13;
	// �ǂɓ������Ă��邩�ǂ���
	int WallHit = 15;
	// �G���������Ă��邩�ǂ���
	int EnemyHit = 16;
	// ���ɓ������Ă��邩�ǂ���
	int BooxHit = 17;

	int PlayerCount = 0;
	
	char m_field[13][13];

	// �v���C���[�̃O���t�B�b�N�n���h��
	int m_hPlayerGraphic[Player::kPlayerGraphicDivNum];
	// �v���C���[�̔����O���t�B�b�N�n���h��
	int m_hExplosionGraphic[Player::kExplosionGraphicDivNum];
	// �v���C���[
	Player player;
	//	�����Ă��邩�ǂ���
	int death = true;
	// ���̃O���t�B�b�N�n���h��
	int m_hDoorGraphic[Door::kDoorGraphicDivNum];
	// ��
	Door door;

	// �����G
	MovingEnemy mEnemy;

	MovingEnemy mEnemy2;
	
};