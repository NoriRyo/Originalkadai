#include "Field.h"
#include "DxLib.h"
#include "GameMain.h"
#include "Player.h"
#include "Game.h"

#define kFieldX (13)
#define kFieldY (13)
#define kSize (48)
#define SPEED (2.0f)

//#define kFieldX (Game::kScreenWidth / kSize)
//#define kFieldY (Game::kScreenHeight/ kSize)


//#define SPEED   (5.0f)   // �L�����̈ړ��X�s�[�h

 
char m_field[kFieldY][kFieldX] =
{
	5, 5,5,5, 5,5,5,5, 5,5,5,5, 5,

	5, 0,0,0, 0,0,0,0, 0,0,0,0, 5,
	5, 0,0,0, 0,0,0,0, 0,0,0,0, 5,
	5, 0,0,0, 0,0,0,0, 0,0,0,0, 5,

	5, 0,0,0, 0,0,5,5, 0,0,0,0, 5,
	5, 0,0,0, 0,0,0,0, 0,0,0,0, 5,
	5, 0,0,0, 0,0,0,0, 0,0,0,0, 5,
	5, 0,0,0, 0,0,0,0, 0,0,0,0, 5,

	5, 0,0,0, 0,0,0,0, 0,0,0,0, 5,
	5, 0,0,0, 0,0,0,0, 0,0,0,0, 5,
	5, 0,0,0, 0,0,0,0, 0,0,0,0, 5,
	5, 0,0,0, 0,0,0,0, 0,0,0,0, 5,

	5, 5,5,5, 5,5,5,5, 5,5,5,5, 5,

};
namespace
{
	constexpr int kEmpty = 0;		// �����
	constexpr int kMovingBlock = 1;	// ��������u���b�N
	constexpr int kMovingEnemy = 2;	// �����G
	constexpr int kPlayer = 3;		// �v���C���[
	constexpr int kShot = 4;		// �e
	constexpr int kWall = 5;		// �������Ȃ���
}

Field::Field() :

	m_fieldX(300),
	m_fieldY(64)
	//m_MovingEnemyX(3),		// �����G�̏����ʒu
	//m_MovingEnemyY(6),
	//m_MovingBlockY(4),
	//m_ShotFrameCount(0),	// �V���b�g  �̃J�E���g

	//m_PlayerWaitingTime(8),	// �v���C���[�ҋ@����
	//m_EnemyWaitingTime(8)	// �G�l�~�[  �ҋ@����
{
	//m_shotX = m_MovingEnemyX;	// ���̏����ʒu
	//m_shotY = m_MovingEnemyY;
	m_field[5][5] = kMovingBlock;

}

Field::~Field()
{
	
}

void Field::init()
{
	player.init();

}

void Field::update()
{

	clsDx();


	//// �G�l�~�[�̈ړ�
	//if (enemyRightMove == true)
	//{
	//	m_EnemyFrameCount++;
	//	if (m_EnemyFrameCount >= m_EnemyWaitingTime)
	//	{
	//		m_MovingEnemyX ++;
	//		m_EnemyFrameCount = 0;
	//	}
	//}
	//else
	//{
	//	m_EnemyFrameCount++;
	//	if (m_EnemyFrameCount >= m_EnemyWaitingTime)
	//	{
	//		m_MovingEnemyX--;
	//		m_EnemyFrameCount = 0;
	//	}
	//}
	//// �����G���ǂɂԂ�������ړ���������𔽓]����
	//// ->
	//if (enemyRightMove == true)
	//{
	//	
	//	if (m_MovingEnemyX > kFieldX - 2)
	//	{
	//		m_MovingEnemyX = kFieldX - 3;
	//		enemyRightMove = false;
	//	}
	//	if (m_MovingEnemyX == m_MovingBlockX && m_MovingEnemyY == m_MovingBlockY)
	//	{
	//		m_MovingEnemyX = m_MovingBlockX - 1;
	//		enemyRightMove = false;
	//	}
	//				//printfDx("%d\n", );
	//if (m_field[m_MovingEnemyY][m_MovingEnemyY] == kStone)
	//{
	//	printfDx("�΂ɂԂ�����\n");
	//	m_MovingEnemyX = m_MovingEnemyX;
	//	enemyRightMove = false;
	//}
	//
	//// <-
	//if (enemyRightMove == false)
	//{
	//	if (m_MovingEnemyX < 1)
	//	{
	//		m_MovingEnemyX = 1;
	//		enemyRightMove = true;
	//	}
	//	if (m_MovingEnemyX == m_MovingBlockX && m_MovingEnemyY == m_MovingBlockY)
	//	{
	//		m_MovingEnemyX = m_MovingBlockX  + 1;
	//		enemyRightMove = true;
	//	}
	//}

	player.MoveX = 0.0f;
	player.MoveY = 0.0f;

	if (CheckHitKey(KEY_INPUT_UP))
	{
		player.MoveY -= SPEED;
	}
	else if (CheckHitKey(KEY_INPUT_DOWN))
	{
		player.MoveY += SPEED;
	}
	else if (CheckHitKey(KEY_INPUT_LEFT))
	{
		player.MoveX -= SPEED;
	}
	else if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		player.MoveX += SPEED;
	}

	// �����̃T�C�Y���Z�o
	player.hsize = player.size * 0.5f;

	// �����̃`�F�b�N
	if (BlockHitCheck(player.x - player.hsize, player.y + player.hsize, player.Dummy, player.MoveY) == 3)
	{
		player.y = 0.0f;
	}

	// �E���̃`�F�b�N
	if (BlockHitCheck(player.x + player.hsize, player.y + player.hsize, player.Dummy, player.MoveY) == 3)
	{
		player.y = 0.0f;
	}

	// ����̃`�F�b�N
	if (BlockHitCheck(player.x - player.hsize, player.y - player.hsize, player.Dummy, player.MoveY) == 4)
	{
		player.y *= -1.0f;
	}

	// �E��̃`�F�b�N
	if (BlockHitCheck(player.x + player.hsize, player.y - player.hsize, player.Dummy, player.MoveY) == 4)
	{
		player.y *= -1.0f;
	}
	


	// ��ɍ��E�ړ����������Ń`�F�b�N
	// �����̃`�F�b�N
	BlockHitCheck(player.x - player.hsize, player.y + player.hsize, player.MoveX, player.Dummy);

	// �E���̃`�F�b�N
	BlockHitCheck(player.x + player.hsize, player.y + player.hsize, player.MoveX, player.Dummy);

	// ����̃`�F�b�N
	BlockHitCheck(player.x - player.hsize, player.y - player.hsize, player.MoveX, player.Dummy);

	// �E��̃`�F�b�N
	BlockHitCheck(player.x + player.hsize, player.y - player.hsize, player.MoveX, player.Dummy);

	// �㉺���E�ړ����������Z
	player.x += player.MoveX;
	player.y += player.MoveY;

	//printfDx("%f\n", player.MoveX);
	//// �G�ƃv���C���[
	//if (player.x == m_MovingEnemyX || player.y == m_MovingEnemyY)
	//{
	//	if (shotFlag == false)
	//	{
	//		m_shotX = m_MovingEnemyX;
	//		m_shotY = m_MovingEnemyY;
	//	}
	//	
	//	shotFlag = true;
	//	// �G������Ƀv���C���[�������ꍇ
	//	if (player.y < m_MovingEnemyY)
	//	{
	//		m_shotX = m_MovingEnemyX;
	//		m_ShotFrameCount++;
	//		if (m_ShotFrameCount >= 300)
	//		{
	//			m_shotY--;
	//			m_ShotFrameCount = 0;
	//		}	
	//	}
	//	// �G�������Ƀv���C���[�������ꍇ
	//	else if (player.y > m_MovingEnemyY)
	//	{
	//		//clsDx();
	//		//printfDx("���ɂ���\n");
	//		m_shotX = m_MovingEnemyX;
	//		m_ShotFrameCount++;
	//		if (m_ShotFrameCount >= 300)
	//		{
	//			m_shotY++;
	//			m_ShotFrameCount = 0;
	//		}
	//	}
	//	// �G�������Ƀv���C���[�������ꍇ
	//	if (player.x < m_MovingEnemyX)
	//	{
	//		//clsDx();
	//		//printfDx("���ɂ���\n");
	//		m_shotY = m_MovingEnemyY;
	//		m_ShotFrameCount++;
	//		if (m_ShotFrameCount >= 300)
	//		{
	//			m_shotX--;
	//			m_ShotFrameCount = 0;
	//		}
	//	}
	//	// �G�����E�Ƀv���C���[�������ꍇ
	//	else if (player.x > m_MovingEnemyX)
	//	{
	//		//clsDx();
	//		//printfDx("�E�ɂ���\n");
	//		m_shotY = m_MovingEnemyY;
	//		m_ShotFrameCount++;
	//		if (m_ShotFrameCount >= 300)
	//		{
	//			m_shotX++;
	//			m_ShotFrameCount = 0;
	//		}
	//	}
	//}
	//// �����u���b�N�ɓ���������A�Z�[�t
	//if (m_shotY == m_MovingBlockY && m_shotX == m_MovingBlockX)
	//{
	//	//printfDx("�Z�[�t\n");
	//	m_shotX = 0;
	//	m_shotY = 0;
	//	shotFlag = false;
	//	return;
	//}
	//// �����v���C���[�ɓ���������A�A�E�g
	//// �v���C���[�͏����ʒu�ɖ߂����
	//if (m_shotY == player.y && m_shotX == player.x)
	//{
	//	//printfDx("�Q�[���I�[�o�[\n");
	//	m_shotX = 0;
	//	m_shotY = 0;
	//	shotFlag = false;
	//	player.x = 1;
	//	player.y = 11;
	//	return;
	//}
	//		
}

int Field::BlockHitCheck(float X, float Y, float& PlayerMoveX, float& PlayerMoveY)
{
	// �ړ��ʂ𑫂�

	player.afterX = X + PlayerMoveX;
	player.afterY = Y + PlayerMoveY;
	
	

	// �����蔻��̂���u���b�N�ɓ������Ă��邩�`�F�b�N
	if (GetChipParam(player.afterX, player.afterY) == 1)
	{
		// �������Ă�����ǂ��痣���������s��
		// �u���b�N�̏㉺���E�̍��W���Z�o
		// ���ӂ� X ���W
		m_Block.LeftX = (float)((int)player.afterX / kSize) * kSize;
		// �E�ӂ� X ���W
		m_Block.RightX = (float)((int)player.afterX / kSize + 1) * kSize;
		// ��ӂ� Y ���W
		m_Block.TopY = (float)((int)player.afterY / kSize ) * kSize ;
		// ���ӂ� Y ���W
		m_Block.BottomY = (float)((int)player.afterY / kSize + 1) * kSize;
		
		// ��ӂɓ������Ă����ꍇ
		if (CheckHitKey(KEY_INPUT_UP))
		{
			//player.y +=5.0f;
			// �ړ��ʂ�␳����
			player.MoveY = m_Block.BottomY - Y + 1.0f;

			//��ӂɓ��������ƕԂ�
			return 3;
		}

		// ���ӂɓ������Ă����ꍇ
		if (CheckHitKey(KEY_INPUT_DOWN))
		{
			// �ړ��ʂ�␳����
			player.MoveY = m_Block.TopY - Y - 1.0f;

			// ���ӂɓ��������ƕԂ�
			return 4;
		}
		
		// ���ӂɓ������Ă����ꍇ
		if (player.MoveX < 0.0f)
		{
			// �ړ��ʂ�␳����
			player.MoveX = m_Block.RightX - X + 1.0f;

			// ���ӂɓ��������ƕԂ�
			return 1;
		}
		// �E�ӂɓ������Ă����ꍇ
		if (player.MoveX > 0.0f)
		{
			// �ړ��ʂ�␳����
			player.MoveX = m_Block.LeftX - X - 1.0f;

			// �E�ӂɓ��������ƕԂ�
			return 2;
		}

		return 5;
	}

	// �v���C���[�Ɠ�������u���b�N���������Ă邩�`�F�b�N
	if (GetChipParam(player.afterX, player.afterY) == 2)
	{
		for (int y = 0; y < kFieldY; y++)
		{
			for (int x = 0; x < kFieldX; x++)
			{
				if (m_field[y][x] == kMovingBlock)
				{
					// ��ӂɓ������Ă����ꍇ
					if (CheckHitKey(KEY_INPUT_UP))
					{
						if (m_field[y - 1][x] == 0)
						{
							m_field[y][x] = 0;
							m_field[y - 1][x] = 1;
							return 1;
						}
					}

					// ���ӂɓ������Ă����ꍇ
					if (CheckHitKey(KEY_INPUT_DOWN))
					{
						if (m_field[y + 1][x] == 0)
						{
							m_field[y][x] = 0;
							m_field[y + 1][x] = 1;
							return 1;
						}
					}

					// ���ӂɓ������Ă����ꍇ
					if (CheckHitKey(KEY_INPUT_LEFT))
					{
						if (m_field[y][x - 1] == 0)
						{
							m_field[y][x] = 0;
							m_field[y][x - 1] = 1;
							return 1;
						}
					}
					// �E�ӂɓ������Ă����ꍇ
					if (CheckHitKey(KEY_INPUT_RIGHT))
					{
						if (m_field[y][x + 1] == 0)
						{
							m_field[y][x] = 0;
							m_field[y][x + 1] = 1;
							return 1;
						}
					}
				}
				
			}
		}
	}
	return 0;
}

//-----------------------------------------
// �}�b�v�`�b�v�̒l���擾����֐�
//-----------------------------------------
int Field::GetChipParam(float X, float Y)
{
	int x, y;
	// �����l�֕ϊ�
	x = (int)X / kSize;
	y = (int)Y / kSize;

	//printfDx("%d\n", m_field[y][x]);
	if (m_field[y][x] == 5)
	{
		printfDx("�ǂɓ������� \n");
		return 1;
	}
	if (m_field[y][x] == 1)
	{
		printfDx("�u���b�N�ɓ������� \n");
		return 2;
	}
	
}


void Field::draw()
{
	//printfDx("pX=%d  pY=%d  eX=%d  eY=%d\n", player.x, player.y,m_enemyX,m_enemyY);

	//printfDx("bX=%d    eX=%d   \n", m_blockX,m_enemyX);

	// �}�b�v�̕`��
	for (int y = 0; y < kFieldY; y++)
	{
		for (int x = 0; x < kFieldX; x++)
		{
			// �P�͓����蔻��`�b�v��\���Ă���̂łP�̂Ƃ��낾���`��
			if (m_field[y][x] == 5)
			{
				DrawBox(m_fieldX + x * kSize, m_fieldY + y * kSize,
					m_fieldX + x * kSize + kSize, m_fieldY + y * kSize + kSize,
					GetColor(255, 255, 255), FALSE);
			}
			if (m_field[y][x] == 1)
			{
				DrawBox(m_fieldX + x * kSize, m_fieldY + y * kSize,
					m_fieldX + x * kSize + kSize, m_fieldY + y * kSize + kSize,
					GetColor(255, 0, 255), TRUE);
			}
		}
	}
	
	// �L�����N�^�̕`��
	DrawBox((int)(m_fieldX + player.x - player.size * 0.5f), (int)(m_fieldY + player.y - player.size * 0.5f),
		(int)(m_fieldX + player.x + player.size * 0.5f) + 1, (int)(m_fieldY + player.y + player.size * 0.5f) + 1,
		GetColor(255, 0, 0), TRUE);
	
		
	//if (shotFlag == true)
			//{
			//	if (m_field[y][x] == kShot)
			//	{
			//	}
			//	//// �e�̕`��
			//	//DrawBox(shotX, shotY,
			//	//	shotX + kSize, shotY + kSize,
			//	//	0xffffff, true);
			//}
			//if (m_field[y][x] == kRightWall || m_field[y][x] == kLeftWall ||
			//	m_field[y][x] == kUpWall || m_field[y][x] == kDownWall)
			//{
			//	DrawBox(posX, posY,
			//		posX + kSize, posY + kSize,
			//		0xffffff, true);
			//}
			//for (int y = 0; y < kFieldY; y++)
			//{
			//	for (int x = 0; x < kFieldX; x++)
			//	{
			//		printfDx("%d", m_field[y][x]);
			//	}
			//	printfDx("\n");
			//}
		
			
}
