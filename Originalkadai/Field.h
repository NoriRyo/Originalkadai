#pragma once
#include "Player.h"
class Field
{
private:
	static constexpr int kFieldX = 13;
	static constexpr int kFieldY = 13;

public:
	Field();
	virtual ~Field();
	virtual void init();
	// �I������
	void end();

	virtual void update();

	// �}�b�v�Ƃ̓����蔻��
	int BlockHitCheck(float X, float Y, float& MoveX, float& MoveY);
	// �}�b�v�`�b�v�̒l���擾����֐�
	int GetChipParam(float X, float Y);

	virtual void draw();
	

private:
	// �Ֆʂ̕\��������W
	int m_fieldX;
	int m_fieldY;
	// �n�[�g�̐�
	int HeartCount;
	// �X�e�[�W�̐�
	int StageNumber = 1;

	// ���������Ă邩�ǂ���
	int KeyGet;
	
	char m_field[13][13];

	// �v���C���[�̃O���t�B�b�N�n���h��
	int m_hPlayerGraphic[Player::kGraphicDivNum];
	// �v���C���[
	Player player;
	
};