#include "Field.h"
#include "DxLib.h"
#include "GameMain.h"
#include "Player.h"
#include "Game.h"


#define kSize (48)
#define SPEED (2.0f)

// �f�o�b�N
//char m_field1[13][13] =
//{
//	{5, 5,5,5, 6,5,5,5, 5,5,5,5, 5},
//
//	{5, 0,0,0, 0,0,4,0, 0,0,0,0, 5},
//	{5, 0,0,0, 0,0,0,0, 0,0,0,0, 5},
//	{5, 0,0,0, 0,0,0,0, 0,0,0,0, 5},
//
//	{5, 0,0,0, 2,0,0,0, 0,0,0,0, 5},
//	{5, 0,0,0, 0,0,0,0, 0,0,0,0, 5},
//	{5, 0,0,0, 0,0,0,0, 0,0,0,0, 5},
//	{5, 0,1,0, 0,0,0,0, 0,0,0,0, 5},
//
//	{5, 0,0,0, 0,0,0,0, 0,0,0,0, 5},
//	{5, 0,0,0, 0,0,0,0, 0,0,0,0, 5},
//	{5, 0,0,0, 0,0,0,0, 0,0,0,0, 5},
//	{5, 0,0,0, 0,0,0,0, 0,0,0,0, 5},
//
//	{5, 5,5,5, 5,5,5,5, 5,5,5,5, 5}
//
//};

// �X�e�[�W�P
char m_field1[13][13] =
{
	{5, 5,5,5, 6,5,5,5, 5,5,5,5, 5},

	{5, 5,0,1, 0,0,4,0, 0,1,0,0, 5},
	{5, 0,0,1, 0,0,5,0, 5,0,0,1, 5},
	{5, 0,5,5, 5,5,5,5, 5,5,5,0, 5},

	{5, 0,5,0, 2,1,0,0, 2,5,0,0, 5},
	{5, 0,0,0, 0,1,0,0, 0,1,0,0, 5},
	{5, 0,5,0, 2,1,0,0, 2,5,0,0, 5},
	{5, 0,5,1, 5,0,5,5, 5,5,5,0, 5},

	{5, 0,5,0, 0,0,0,0, 2,5,0,0, 5},
	{5, 1,5,5, 5,5,5,5, 5,5,0,5, 5},
	{5, 0,0,5, 0,0,0,1, 0,0,0,5, 5},
	{5, 0,0,2, 0,5,0,0, 1,0,0,5, 5},

	{5, 5,5,5, 5,5,5,5, 5,5,5,5, 5}

};
// �X�e�[�W�Q
char m_field2[13][13] =
{
	{5, 5,5,5, 6,5,5,5, 5,5,5,5, 5},

	{5, 0,0,1, 0,0,4,0, 0,1,0,0, 5},
	{5, 0,0,1, 0,0,0,0, 0,0,0,1, 5},
	{5, 0,0,0, 0,0,0,0, 0,0,0,0, 5},

	{5, 0,0,0, 2,1,0,0, 2,0,0,0, 5},
	{5, 0,0,0, 0,0,0,0, 0,1,0,0, 5},
	{5, 0,0,0, 0,1,0,0, 2,0,0,0, 5},
	{5, 0,0,0, 0,0,0,0, 0,0,0,0, 5},

	{5, 0,0,0, 0,0,0,0, 2,0,0,0, 5},
	{5, 1,0,0, 0,0,0,0, 0,0,0,0, 5},
	{5, 0,0,0, 0,0,0,0, 1,0,0,0, 5},
	{5, 0,0,2, 0,0,0,0, 1,0,0,0, 5},

	{5, 5,5,5, 5,5,5,5, 5,5,5,5, 5}

};
namespace
{
	constexpr int kEmpty = 0;		// �����
	constexpr int kMovingBlock = 1;	// ��������u���b�N
	constexpr int kHeart = 2;		// �n�[�g
	constexpr int kDoor = 6;		//�i���j
	constexpr int kGoal = 3;		// �S�[���i���j
	constexpr int kTreasure = 4;	// ��
	constexpr int kTreasureOpen = 8;// �󔠁i�J���Ă���j 
	constexpr int kWall = 5;		// �������Ȃ���
	
	const char* const kPlayarGraphicFilename = "data/player1.png";
	//const char* const kPlayarGraphicFilename = "data/titleBg.jpg";
}


Field::Field() :

	m_fieldX((Game::kScreenWidth/2)/2),
	m_fieldY(124)
	
{
	for (auto& handle : m_hPlayerGraphic)
	{
		handle = -1;
	}
}

Field::~Field()
{
	


	
}

void Field::init()
{
	// �X�e�[�W�؂�ւ�
	for (int y = 0; y < kFieldY; y++)
	{
		for (int x = 0; x < kFieldX; x++)
		{
			if (StageNumber == 1)
			{
				m_field[y][x] = m_field1[y][x];
			}
			if (StageNumber == 2)
			{
				m_field[y][x] = m_field2[y][x];
			}
		}
	}
	LoadDivGraph(kPlayarGraphicFilename, Player::kGraphicDivNum,
		Player::kGraphicDivX, Player::kGraphicDivY,
		Player::kGraphicSizeX, Player::kGraphicSizeY, m_hPlayerGraphic);

	for (int i = 0; i < Player::kGraphicDivNum; i++)
	{
		player.setHandle(i, m_hPlayerGraphic[i]);
	}
	player.init();	
}

void Field::end()
{
	for (auto& handle : m_hPlayerGraphic)
	{
		DeleteGraph(m_hPlayerGraphic[4]);
	}
}

void Field::update()
{
	clsDx();

	player.Update();
	
	if (CheckHitKey(KEY_INPUT_1))
	{
		init();
	}
	
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


	// �����蔻��̂���ǂɓ������Ă��邩�`�F�b�N
	if (GetChipParam(player.afterX, player.afterY) == 0.5)
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
				for (int y = 0; y < kFieldY; y++)
				{
					for (int x = 0; x < kFieldX; x++)
					{
						if (m_field[y][x] == kTreasure)
						{
							// �󔠃I�[�v��
							m_field[y][x] = kTreasureOpen;
						}
					}
				}
			}
		}
	}

	// ���Q�b�g
	if (GetChipParam(player.afterX, player.afterY) == KeyGet)
	{
		for (int y = 0; y < kFieldY; y++)
		{
			for (int x = 0; x < kFieldX; x++)
			{
				if (m_field[y][x] == kDoor)
				{
					//printfDx("���J���܂�\n");
					// ���I�[�v��
					m_field[y][x] = kGoal;
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

	if (m_field[y][x] == kWall || m_field[y][x] == kDoor || m_field[y][x] == kTreasure)
	{
		//printfDx("�ǂɓ������� \n");
		return 0.5;
	}
	if (m_field[y][x] == kMovingBlock)
	{
		//printfDx("�u���b�N�ɓ������� \n");
		return 0;
	}
	if (m_field[y][x] == kHeart)
	{
		m_field[y][x] = 0;
		//printfDx("�n�[�g�ɓ������� \n");
		return 2;
	}
	if (m_field[y][x] == kGoal)
	{
		//printfDx("GOAL \n");
		if (StageNumber == 1)
		{
			StageNumber = 2;
		}
		init(); // ���̃X�e�[�W�ցI�I�I�I�I�I
	}
	if (m_field[y][x] == kTreasureOpen)
	{
		//printfDx("���Q�b�g \n");
		return KeyGet;
	}
}


void Field::draw()
{
	player.Draw();
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
			if (m_field[y][x] == kGoal)
			{
				DrawBox(m_fieldX + x * kSize, m_fieldY + y * kSize,
					m_fieldX + x * kSize + kSize, m_fieldY + y * kSize + kSize,
					GetColor(0, 0, 255), FALSE);
			}// ���̕`��
			if (m_field[y][x] == kDoor)
			{
				DrawBox(m_fieldX + x * kSize, m_fieldY + y * kSize,
					m_fieldX + x * kSize + kSize, m_fieldY + y * kSize + kSize,
					GetColor(0, 0, 255), TRUE);
			}
			//�@�󔠂̕`��
			if (m_field[y][x] == kTreasure)
			{
				DrawBox(m_fieldX + x * kSize, m_fieldY + y * kSize,
					m_fieldX + x * kSize + kSize, m_fieldY + y * kSize + kSize,
					GetColor(218,165,32), TRUE);
			}
			//�@�J�����󔠂̕`��
			if (m_field[y][x] == kTreasureOpen)
			{
				DrawBox(m_fieldX + x * kSize, m_fieldY + y * kSize,
					m_fieldX + x * kSize + kSize, m_fieldY + y * kSize + kSize,
					GetColor(218, 165, 32), FALSE);
			}
		}
	}
	
	//// �L�����N�^�̕`��
	//DrawBox((int)(m_fieldX + player.x - player.size * 0.5f), (int)(m_fieldY + player.y - player.size * 0.5f),
	//	(int)(m_fieldX + player.x + player.size * 0.5f) + 1, (int)(m_fieldY + player.y + player.size * 0.5f) + 1,
	//	GetColor(255, 0, 0), TRUE);

	
		
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
