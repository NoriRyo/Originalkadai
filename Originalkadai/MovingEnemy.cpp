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
}

MovingEnemy::~MovingEnemy()
{
}

void MovingEnemy::init()
{
	// �ʒu��������
	if (Number == 2 || Number == 3)
	{
		EnemyX = 552.0f - 48.0f * 4;
		EnemyY = 552.0f - 48.0f * 3;
	}
	else
	{
		EnemyX = -100;
		EnemyY = -100;
		
	}
	// �ړ��ʂ̏�����
	MoveX = 0.0f;
	MoveY = 0.0f;

	size = 45;
	speed = 5.0f;	// ����
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
	
	//// ��ɍ��E�ړ����������Ń`�F�b�N
	//// �����̃`�F�b�N
	//m_pField->EnemyBlockHitCheck( EnemyX -  hsize,  EnemyY +  hsize,  MoveX,  Dummy);

	//// �E���̃`�F�b�N
	//m_pField->EnemyBlockHitCheck( EnemyX +  hsize,  EnemyY +  hsize,  MoveX,  Dummy);

	//// ����̃`�F�b�N
	//m_pField->EnemyBlockHitCheck( EnemyX -  hsize,  EnemyY -  hsize,  MoveX,  Dummy);

	//// �E��̃`�F�b�N
	//m_pField->EnemyBlockHitCheck( EnemyX +  hsize,  EnemyY -  hsize,  MoveX,  Dummy);

	//// �㉺���E�ړ����������Z
	// EnemyX +=  MoveX;
	// EnemyY +=  MoveY;
}

void MovingEnemy::Draw()
{
	int kEnemyGraphic = LoadGraph("data/Enemy.png");

	//DrawBox((int)(m_fieldX + x - size * 0.5f), (int)(m_fieldY + y - size * 0.5f),
	//	(int)(m_fieldX + x + size * 0.5f), (int)(m_fieldY + y + size * 0.5f),
	//	GetColor(255, 255, 0), FALSE);
	if (Number == 1)
	{
		
	}
	else
	{
		DrawGraph(m_fieldX + EnemyX - 23, m_fieldY + EnemyY - 22, kEnemyGraphic, TRUE);
	}
}

void MovingEnemy::setPos(float x, float y)
{
	EnemyX = x;
	EnemyY = y;
}
