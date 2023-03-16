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

	// �G�P�Ƃ̓����蔻��
	int Enemy1BlockHitCheck(float enemyX, float enemyY, float& enemyMoveX, float& enemyMoveY);
	// �G�Q�Ƃ̓����蔻��
	int Enemy2BlockHitCheck(float enemyX, float enemyY, float& enemyMoveX, float& enemyMoveY);

	// �}�b�v�`�b�v�̒l���擾����֐�
	int GetChipParam(float X, float Y);

	virtual void draw()override;

	// �X�e�[�W�̐�
	int StageNumber = 1;

private:
	int background0;
	int background1;
	int background2;
	int background3;
	int background4;
	int background5;
	// BGM�̃n���h��
	int BGMHandle;
	// �����T�E���h�̃n���h��
	int WalkSHandle;
	// �n�[�g�T�E���h�̃n���h��
	int HeartSHandle;
	// �L�[�T�E���h�̃n���h��
	int KeySHandle;
	// �����T�E���h�̃n���h��
	int attackSHandle;
	// �����T�E���h�̃n���h��
	int ExplosionSHandle;
	// ����
	int Volume;
	// �Ֆʂ̕\��������W
	int m_fieldX;
	int m_fieldY;
	// �n�[�g�̐�
	int HeartCount;
	// �󔠂̐�
	int TreasureCount;
	

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

	int HeartMax = 0;

	int PlayerCount = 0;
	
	int m_field[13][13];

	// �v���C���[�̃O���t�B�b�N�n���h��
	int m_hPlayerGraphic[Player::kPlayerGraphicDivNum];
	// �v���C���[�̔����O���t�B�b�N�n���h��
	int m_hExplosionGraphic[Player::kExplosionGraphicDivNum];
	// ���̃O���t�B�b�N�n���h��
	int m_hDoorGraphic[Door::kDoorGraphicDivNum];
	// �v���C���[
	Player player;
	//	�����Ă��邩�ǂ���
	int death = true;
	// ��
	Door door;

	// �����G
	MovingEnemy mEnemy1;

	MovingEnemy mEnemy2;
	
};