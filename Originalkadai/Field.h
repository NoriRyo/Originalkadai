#pragma once
#include "Player.h"
#include "MovingBlock.h"
class Field
{
public:
	
	// �}�X�̃T�C�Y
	//static constexpr int kSize = 48;

public:
	Field();
	virtual ~Field();
	void init();
	void update();

	// �}�b�v�Ƃ̓����蔻��
	int BlockHitCheck(float X, float Y, float& MoveX, float& MoveY);
	// �}�b�v�`�b�v�̒l���擾����֐�
	int GetChipParam(float X, float Y);

	void draw();
private:
	// �G�l�~�[�̈ʒu
	//int m_MovingEnemyX;
	//int m_MovingEnemyY;
	// ��������u���b�N�̈ʒu
	//int m_MovingBlockX;
	//int m_MovingBlockY;
	// �΂̈ʒu
	//int m_Stone1X;
	//int m_Stone1Y;
	// �ʒu��������.
	//int m_shotX;
	//int m_shotY;


	// �G�l�~�[���E�ړ����Ă��邩�ǂ����̃t���O�����Z�b�g
	bool enemyRightMove = true;
	// �e����ʏ�ɑ��݂��Ă��邩�ێ�����ϐ��Ɂw���݂��Ă��Ȃ��x���Ӗ�����false�������Ă���
	bool shotFlag = false;
	
	// �Ֆʂ̕\��������W
	int m_fieldX;
	int m_fieldY;
	// �v���C���[�t���[���J�E���g
	//int m_PlayerFrameCount;
	// �G�l�~�[�t���[���J�E���g
	//int m_EnemyFrameCount;
	// �V���b�g�t���[���J�E���g
	//int m_ShotFrameCount;

	// �v���C���[�ҋ@����
	//int m_PlayerWaitingTime;
	// �G�l�~�[�ҋ@����
	//int m_EnemyWaitingTime;

	//// �ՖʃT�C�Y
	//int m_FieldX;
	//int m_FieldY;

	// �ՖʃT�C�Y
	int kFieldX;
	int kFieldY;

	Player player;
	MovingBlock m_Block;
	
};

