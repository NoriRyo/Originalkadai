#pragma once
class Field
{
public:
	// �ՖʃT�C�Y
	static constexpr int kFieldX = 16;
	static constexpr int kFieldY = 12;
	// �}�X�̃T�C�Y
	static constexpr int kSize = 48;
public:
	Field();
	virtual ~Field();
	void init();
	void update();
	void draw();
private:
	// �v���C���[�̈ʒu
	int m_playerX;	
	int m_playerY;
	// �G�l�~�[�̈ʒu
	int m_MovingEnemyX;
	int m_MovingEnemyY;
	// ��������u���b�N�̈ʒu
	int m_MovingBlockX;
	int m_MovingBlockY;
	// �΂̈ʒu
	int m_StoneX;
	int m_StoneY;
	// �ʒu��������.
	int m_shotX;
	int m_shotY;

	// �G�l�~�[���E�ړ����Ă��邩�ǂ����̃t���O�����Z�b�g
	bool enemyRightMove = true;
	// �e����ʏ�ɑ��݂��Ă��邩�ێ�����ϐ��Ɂw���݂��Ă��Ȃ��x���Ӗ�����false�������Ă���
	bool shotFlag = false;
	// ���݂̔Ֆʃf�[�^
	int m_field[kFieldY][kFieldX];
	// �Ֆʂ̕\��������W
	int m_fieldX;
	int m_fieldY;
	// �v���C���[�t���[���J�E���g
	int m_PlayerFrameCount;
	// �G�l�~�[�t���[���J�E���g
	int m_EnemyFrameCount;
	// �V���b�g�t���[���J�E���g
	int m_ShotFrameCount;

	// �v���C���[�ҋ@����
	int m_PlayerWaitingTime;
	// �G�l�~�[�ҋ@����
	int m_EnemyWaitingTime;

	// �ՖʃT�C�Y
	int m_FieldX;
	int m_FieldY;
};

