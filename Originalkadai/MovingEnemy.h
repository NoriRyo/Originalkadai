#pragma once
//#include "Field.h"
//class Field;
class MovingEnemy
{
public:
	MovingEnemy();
	virtual ~MovingEnemy();
	virtual void init();
	virtual void Update();
	virtual void Draw();

	//�@�G�̍��W(���S���W)
	virtual void setPos(float x, float y);

	// �G�̃T�C�Y
	int size;

	// �G�̈ړ�����
	float MoveX;
	float MoveY;

	// �G�̈ʒu
	int EnemyX;
	int EnemyY;

	// �G�̑��x
	float speed;

	// �X�e�[�W�̔ԍ�
	float Number = 1;

	// �G�̌���
	float enemyRightMove = false;

	// �����̃T�C�Y���Z�o
	float Dummy;
	float hsize;

	// �G�̎��̓���
	float afterX;
	float afterY;

	float LeftX;	//�@�u���b�N�̍�
	float TopY;	//�@�u���b�N�̏�
	float RightX;	//�@�u���b�N�̉E
	float BottomY;	//�@�u���b�N�̂���

private:
	// �t���[���J�E���g
	int m_EnemyFrameCount;

	//Field* m_pField;
};

