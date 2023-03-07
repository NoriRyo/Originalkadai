#include "MovingEnemy.h"
#include "Game.h"
#include "DxLib.h"
namespace
{
	// �G�̃T�C�Y
	constexpr int kSizeX = 48;
	constexpr int kSizeY = 48;


	constexpr int m_EnemyWaitingTime = 10;
	

	constexpr int m_fieldX((Game::kScreenWidth / 2) / 2);
	constexpr int m_fieldY(124);

}
MovingEnemy::MovingEnemy()
{
	LeftX = 0;	//�@�u���b�N�̍�
	TopY = 0;	//�@�u���b�N�̏�
	RightX = 0;	//�@�u���b�N�̉E
	BottomY = 0;	//�@�u���b�N�̂���
	Dummy = 0;
	MoveX = 0;
	MoveY = 0;
	Dummy = 0;
	EnemyX = 0;
	EnemyY = 0;
	afterX = 0;
	afterY = 0;
	hsize = 0;
	m_EnemyFrameCount = 0;
	size = 0;
	speed = 0;
}

MovingEnemy::~MovingEnemy()
{
}

void MovingEnemy::init()
{
	// �ړ��ʂ̏�����
	MoveX = 0.0f;
	MoveY = 0.0f;

	size = 45;
	speed = 4.0f;	// ����
	Dummy = 0.0f;
}

void MovingEnemy::Update()
{
	// �G�l�~�[�̈ړ�
	if (enemyRightMove == true)
	{
		MoveX  +=speed;;
	}
	else
	{
		MoveX  -=speed;
	}
}

void MovingEnemy::Draw()
{
	int kEnemyGraphic = LoadGraph("data/Enemy.png");

	//DrawBox((int)(m_fieldX + x - size * 0.5f), (int)(m_fieldY + y - size * 0.5f),
	//	(int)(m_fieldX + x + size * 0.5f), (int)(m_fieldY + y + size * 0.5f),
	//	GetColor(255, 255, 0), FALSE);
	
	DrawGraph(m_fieldX + EnemyX - 23, m_fieldY + EnemyY - 22, kEnemyGraphic, TRUE);
	
}

void MovingEnemy::setPos(float x, float y)
{
	EnemyX = x;
	EnemyY = y;
}
