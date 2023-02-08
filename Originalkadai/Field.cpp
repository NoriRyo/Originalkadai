#include "Field.h"
#include "DxLib.h"
#include "GameMain.h"
#include "Player.h"
#include "Game.h"


#define kSize (48)
#define SPEED (2.0f)

char m_field[13][13] =
{
	{5, 5,5,5, 3,5,5,5, 5,5,5,5, 5},

	{5, 5,0,1, 0,0,4,0, 0,1,0,0, 5},
	{5, 0,0,1, 0,0,5,0, 5,0,0,1, 5},
	{5, 0,5,5, 5,5,5,5, 5,5,5,0, 5},

	{5, 0,5,0, 2,1,0,0, 2,5,0,0, 5},
	{5, 0,0,0, 0,1,0,0, 0,1,0,0, 5},
	{5, 0,5,0, 2,1,0,0, 2,5,0,0, 5},
	{5, 0,5,1, 5,0,5,5, 5,5,5,0, 5},

	{5, 0,5,0, 0,0,0,0, 2,5,0,0, 5},
	{5, 1,5,5, 5,5,5,5, 5,5,0,5, 5},
	{5, 0,0,5, 0,0,0,0, 1,0,0,5, 5},
	{5, 0,0,2, 0,5,0,0, 1,0,0,5, 5},

	{5, 5,5,5, 5,5,5,5, 5,5,5,5, 5}

};


namespace
{
	constexpr int kEmpty = 0;		// �����
	constexpr int kMovingBlock = 1;	// ��������u���b�N
	constexpr int kHeart = 2;		// �n�[�g
	constexpr int kGoal = 3;		// �S�[���i���j
	constexpr int kTreasure = 4;	// ��
	constexpr int kWall = 5;		// �������Ȃ���
	
}

Field::Field() :

	m_fieldX((Game::kScreenWidth/2)/2),
	m_fieldY(124)
	//m_MovingEnemyX(3),		// �����G�̏����ʒu
	//m_MovingEnemyY(6),
	//m_MovingBlockY(4),
	//m_ShotFrameCount(0),	// �V���b�g  �̃J�E���g

	//m_PlayerWaitingTime(8),	// �v���C���[�ҋ@����
	//m_EnemyWaitingTime(8)	// �G�l�~�[  �ҋ@����
{
	

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

	HeartCount = 0;
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
	if (GetChipParam(player.afterX, player.afterY) == 5)
	{
		// �������Ă�����ǂ��痣���������s��
		// �u���b�N�̏㉺���E�̍��W���Z�o
		// ���ӂ� X ���W
		player.LeftX = (float)((int)player.afterX / kSize) * kSize;
		// �E�ӂ� X ���W
		player.RightX = (float)((int)player.afterX / kSize + 1) * kSize;
		// ��ӂ� Y ���W
		player.TopY = (float)((int)player.afterY / kSize ) * kSize ;
		// ���ӂ� Y ���W
		player.BottomY = (float)((int)player.afterY / kSize + 1) * kSize;
		
		// ��ӂɓ������Ă����ꍇ
		if (CheckHitKey(KEY_INPUT_UP))
		{
			// �ړ��ʂ�␳����
			player.MoveY = player.BottomY - Y + 1.0f;

			//��ӂɓ��������ƕԂ�
			return 3;
		}

		// ���ӂɓ������Ă����ꍇ
		if (CheckHitKey(KEY_INPUT_DOWN))
		{
			// �ړ��ʂ�␳����
			player.MoveY = player.TopY - Y - 1.0f;

			// ���ӂɓ��������ƕԂ�
			return 4;
		}
		
		// ���ӂɓ������Ă����ꍇ
		if (player.MoveX < 0.0f)
		{
			// �ړ��ʂ�␳����
			player.MoveX = player.RightX - X + 1.0f;

			// ���ӂɓ��������ƕԂ�
			return 1;
		}
		// �E�ӂɓ������Ă����ꍇ
		if (player.MoveX > 0.0f)
		{
			// �ړ��ʂ�␳����
			player.MoveX = player.LeftX - X - 1.0f;

			// �E�ӂɓ��������ƕԂ�
			return 2;
		}
		return 5;
	}

	int i, j;
	// �����l�֕ϊ�
	i = (int)X / kSize;
	j = (int)Y / kSize;
	// �v���C���[�Ɠ�������u���b�N���������Ă邩�`�F�b�N
	if (GetChipParam(player.afterX, player.afterY) == 0)
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
						if (m_field[y - 1][x] == 0 && y + 1 == j && x == i)
						{
							m_field[y][x] = 0;
							m_field[y - 1][x] = kMovingBlock;
							return 1;
						}
						else
						{
							player.MoveY = 0;
						}
					}

					// ���ӂɓ������Ă����ꍇ
					if (CheckHitKey(KEY_INPUT_DOWN))
					{
						if (m_field[y + 1][x] == 0 && y - 1 == j && x == i)
						{
							m_field[y][x] = 0;
							m_field[y + 1][x] = kMovingBlock;
							return 1;
						}
						else
						{
							player.MoveY = 0;
						}
					}

					// ���ӂɓ������Ă����ꍇ
					if (CheckHitKey(KEY_INPUT_LEFT))
					{
						if (m_field[y][x - 1] == 0 && y == j && x + 1 == i)
						{
							m_field[y][x] = 0;
							m_field[y][x - 1] = kMovingBlock;
							return 1;
						}
						else
						{
							player.MoveX = 0;
						}
					}
					// �E�ӂɓ������Ă����ꍇ
					if (CheckHitKey(KEY_INPUT_RIGHT))
					{
						if (m_field[y][x + 1] == 0 && y == j && x - 1 == i)
						{
							m_field[y][x] = 0;
							m_field[y][x + 1] = kMovingBlock;
							return 1;
						}
						else
						{
							player.MoveX = 0;
						}
					}
				}
				
			}
		}
	}

	// �Ֆʂɂ���n�[�g�̐��𐔂���
	for (int y = 0; y < kFieldY; y++)
	{
		for (int x = 0; x < kFieldX; x++)
		{
			if (m_field[y][x] == kHeart)
			{
				HeartCount++;
			}
		}
	}
	
	// �n�[�g�̐����O�ɂȂ�����A�󔠂��J����
	for (int y = 0; y < kFieldY; y++)
	{
		for (int x = 0; x < kFieldX; x++)
		{
			if (HeartCount == 0)
			{
				if (m_field[y][x] == 3)
				{
					m_field[y][x] = 0;
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

	if (m_field[y][x] == 5)
	{
		printfDx("�ǂɓ������� \n");
		return 5;
	}
	if (m_field[y][x] == 1)
	{
		printfDx("�u���b�N�ɓ������� \n");
		return 0;
	}
	if (m_field[y][x] == kHeart)
	{
		m_field[y][x] = 0;
		printfDx("�n�[�g�ɓ������� \n");
		return 2;
	}
	
}


void Field::draw()
{

	// �}�b�v�̕`��
	for (int y = 0; y < kFieldY; y++)
	{
		for (int x = 0; x < kFieldX; x++)
		{
			//�@�ǂ̕`��
			if (m_field[y][x] == 5)
			{
				DrawBox(m_fieldX + x * kSize, m_fieldY + y * kSize,
					m_fieldX + x * kSize + kSize, m_fieldY + y * kSize + kSize,
					GetColor(255, 255, 255), TRUE);
			}
			//�@�u���b�N�̕`��
			if (m_field[y][x] == 1)
			{
				DrawBox(m_fieldX + x * kSize, m_fieldY + y * kSize,
					m_fieldX + x * kSize + kSize, m_fieldY + y * kSize + kSize,
					GetColor(0, 255, 0), TRUE);
			}
			//�@�n�[�g�̕`��
			if (m_field[y][x] == 2)
			{
				DrawBox(m_fieldX + x * kSize, m_fieldY + y * kSize,
					m_fieldX + x * kSize + kSize, m_fieldY + y * kSize + kSize,
					GetColor(255, 155, 155), TRUE);
			}
			//�@�f�n�`�k�̕`��
			if (m_field[y][x] == 3)
			{
				DrawBox(m_fieldX + x * kSize, m_fieldY + y * kSize,
					m_fieldX + x * kSize + kSize, m_fieldY + y * kSize + kSize,
					GetColor(0, 0, 255), TRUE);
			}
			//�@�󔠂̕`��
			if (m_field[y][x] == 4)
			{
				DrawBox(m_fieldX + x * kSize, m_fieldY + y * kSize,
					m_fieldX + x * kSize + kSize, m_fieldY + y * kSize + kSize,
					GetColor(218,165,32), TRUE);
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
