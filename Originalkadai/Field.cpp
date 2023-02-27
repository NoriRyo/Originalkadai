#include "Field.h"
#include "DxLib.h"
#include "GameMain.h"
#include "Player.h"
#include "Game.h"
#include "Door.h"
#include "MovingEnemy.h"
#include "SceneTitle.h"
#include "GameOver.h"


#define kSize (48)

 //�f�o�b�N
//char m_field1[13][13] =
//{
//	{5, 5,5,5, 6,5,5,5, 5,5,5,5, 5},
//
//	{5, 0,0,0, 0,0,4,0, 0,0,0,0, 5},
//	{5, 0,0,0, 0,0,0,0, 0,0,0,0, 5},
//	{5, 0,0,0, 0,0,0,0, 0,0,0,0, 5},
//
//	{5, 0,0,0, 2,0,0,0, 0,0,0,0, 5},
//	{5, 0,0,3, 0,0,0,0, 0,0,0,0, 5},
//	{5, 0,0,0, 0,0,0,0, 0,0,0,0, 5},
//	{5, 0,1,0, 0,0,0,0, 0,0,0,0, 5},
//
//	{5, 0,0,0, 0,0,0,0, 0,0,0,0, 5},
//	{5, 0,1,0, 0,0,0,0, 0,0,0,0, 5},
//	{5, 0,0,0, 0,0,0,0, 0,0,0,0, 5},
//	{5, 0,0,0, 0,0,0,0, 0,0,0,0, 5},
//
//	{5, 5,5,5, 5,5,5,5, 5,5,5,5, 5}
//
//};

 //�X�e�[�W�P
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
	{5, 3,0,2, 0,5,0,0, 1,0,0,5, 5},

	{5, 5,5,5, 5,5,5,5, 5,5,5,5, 5}

};
// �X�e�[�W�Q
char m_field2[13][13] =
{
	{5, 5,5,5, 5,5,5,6, 5,5,5,5, 5},

	{5, 4,0,5, 0,0,0,1, 2,0,5,0, 5},
	{5, 0,0,5, 0,5,0,5, 5,0,2,0, 5},
	{5, 0,0,5, 0,0,1,0, 0,1,0,0, 5},

	{5, 1,5,5, 5,1,1,1, 5,0,0,0, 5},
	{5, 0,0,0, 1,0,1,0, 0,5,5,1, 5},
	{5, 0,0,1, 0,0,0,0, 0,0,0,0, 5},
	{5, 5,1,0, 1,5,5,5, 1,0,5,5, 5},

	{5, 0,0,0, 0,0,0,0, 0,0,1,0, 5},
	{5, 0,5,5, 0,5,0,5, 5,5,5,0, 5},
	{5, 0,0,0, 0,5,0,0, 0,0,0,0, 5},
	{5, 5,2,2, 2,5,0,0, 0,0,0,3, 5},

	{5, 5,5,5, 5,5,5,5, 5,5,5,5, 5}

};
// �X�e�[�W�R
char m_field3[13][13] =
{
	{5, 5,5,5, 6,5,5,5, 5,5,5,5, 5},

	{5, 0,0,0, 0,0,4,0, 0,0,0,0, 5},
	{5, 0,0,0, 0,0,0,0, 0,0,0,0, 5},
	{5, 0,0,0, 0,0,0,0, 0,0,0,0, 5},

	{5, 0,0,0, 2,0,0,0, 0,0,0,0, 5},
	{5, 0,0,0, 0,0,0,2, 2,0,0,0, 5},
	{5, 0,0,0, 0,0,0,0, 2,0,0,0, 5},
	{5, 0,1,0, 0,0,0,0, 0,0,0,0, 5},

	{5, 0,0,0, 0,0,0,0, 0,0,0,0, 5},
	{5, 0,1,0, 0,0,0,0, 0,0,0,0, 5},
	{5, 0,0,0, 0,0,0,0, 0,0,0,0, 5},
	{5, 0,0,0, 0,0,0,0, 0,0,0,3, 5},

	{5, 5,5,5, 5,5,5,5, 5,5,5,5, 5}

};
namespace
{
	constexpr int kEmpty = 0;		// �����
	constexpr int kMovingBlock = 1;	// ��������u���b�N
	constexpr int kHeart = 2;		// �n�[�g
	constexpr int kDoor = 6;		//�i���j
	constexpr int kTreasure = 4;	// ��
	constexpr int kTreasureOpen = 8;// �󔠁i�J���Ă���j 
	constexpr int kWall = 5;		// �������Ȃ���
	constexpr int kPlayer = 3;		// �v���C���[
	
	
	const char* const kPlayarGraphicFilename = "data/player3.png";
	const char* const kExplosionGraphicFilename = "data/Explosion.png";
	const char* const kDoorGraphicFilename = "data/door.png";

	int Key = true;		// �L�[�����݂��邩���Ȃ����B
}


Field::Field() :

	m_fieldX((Game::kScreenWidth/2)/2),
	m_fieldY(124)
	
{
	for (auto& playerHandle : m_hPlayerGraphic)
	{
		playerHandle = -1;
	}
	for (auto& ExplosionHandle : m_hExplosionGraphic)
	{
		ExplosionHandle = -1;
	}
	for (auto& doorHandle : m_hDoorGraphic)
	{
		doorHandle = -1;
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
			if (StageNumber == 3)
			{
				m_field[y][x] = m_field3[y][x];
			}
		}
	}
	// �v���C���[
	LoadDivGraph(kPlayarGraphicFilename, Player::kPlayerGraphicDivNum,
		Player::kPlayerGraphicDivX, Player::kPlayerGraphicDivY,
		Player::kPlayerGraphicSizeX, Player::kPlayerGraphicSizeY, m_hPlayerGraphic);

	for (int i = 0; i < Player::kPlayerGraphicDivNum; i++)
	{
		player.PlayerSetHandle(i, m_hPlayerGraphic[i]);
	}
	// ����
	LoadDivGraph(kExplosionGraphicFilename, Player::kExplosionGraphicDivNum,
		Player::kExplosionGraphicDivX, Player::kExplosionGraphicDivY,
		Player::kExplosionGraphicSizeX, Player::kExplosionGraphicSizeY, m_hExplosionGraphic);

	for (int i = 0; i < Player::kExplosionGraphicDivNum; i++)
	{
		player.ExplosionSetHandle(i, m_hExplosionGraphic[i]);
	}
	player.init();	

	// �h�A
	LoadDivGraph(kDoorGraphicFilename, Door::kDoorGraphicDivNum,
		Door::kGraphicDivX, Door::kGraphicDivY,
		Door::kGraphicSizeX, Door::kGraphicSizeY, m_hDoorGraphic);

	for (int i = 0; i < Door::kDoorGraphicDivNum; i++)
	{
		door.setHandle(i, m_hDoorGraphic[i]);
	}
	door.init();

	// �������݂��Ă���
	Key = true;

	// �G
	mEnemy.init();
	mEnemy2.init();

	//mEnemy.setPos(552.0f - 48.0f * 4,552.0f - 48.0f * 3);
	//mEnemy2.setPos(452.0f - 48.0f * 4, 452.0f - 48.0f * 3);
}

void Field::end()
{
	for (auto& handle : m_hPlayerGraphic)
	{
		DeleteGraph(m_hPlayerGraphic[4]);
	}

	for (auto& handle : m_hExplosionGraphic)
	{
		DeleteGraph(m_hExplosionGraphic[8]);
	}

	for (auto& handle : m_hDoorGraphic)
	{
		DeleteGraph(m_hDoorGraphic[2]);
	}
}

SceneBase* Field::update()
{
	clsDx();
	

	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	for (int y = 0; y < kFieldY; y++)
	{
		for (int x = 0; x < kFieldX; x++)
		{
			if (m_field[y][x] == kPlayer)
			{
				PlayerCount++;
				if (PlayerCount >= 10)
				{
					player.isKey = false;
					m_field[y][x] = kEmpty;
					// �p�b�h(�������̓L�[�{�[�h)����̓��͂��擾����
					if (padState & PAD_INPUT_UP)
					{
						if (m_field[y - 1][x] == kMovingBlock)
						{
							if (!(m_field[y - 2][x] == kMovingBlock || m_field[y - 2][x] == kWall || m_field[y - 2][x] == kTreasure || m_field[y - 2][x] == kDoor))
							{
								m_field[y - 1][x] = kEmpty;
								m_field[y - 2][x] = kMovingBlock;
							}
						}
						if (!(m_field[y - 1][x] == kWall || m_field[y - 1][x] == kMovingBlock || m_field[y - 1][x] == kDoor || m_field[y - 1][x] == kTreasure))
						{
							y --;
						}
						player.m_dirNo = 3;
						player.isKey = true;
					}
					else if (padState & PAD_INPUT_DOWN)
					{
						if (m_field[y + 1][x] == kMovingBlock)
						{
							if (!(m_field[y + 2][x] == kMovingBlock || m_field[y + 2][x] == kWall))
							{
								m_field[y + 1][x] = kEmpty;
								m_field[y + 2][x] = kMovingBlock;
							}
						}
						if (!(m_field[y + 1][x] == kWall || m_field[y + 1][x] == kMovingBlock || m_field[y + 1][x] == kTreasure))
						{
							y++;
						}
						player.m_dirNo = 0;
						player.isKey = true;
					}
					else if (padState & PAD_INPUT_LEFT)
					{
						if (m_field[y][x - 1] == kMovingBlock)
						{
							if (!(m_field[y][x - 2] == kMovingBlock || m_field[y][x - 2] == kWall))
							{
								m_field[y][x - 1] = kEmpty;
								m_field[y][x - 2] = kMovingBlock;
							}
							
						}
						if (!(m_field[y][x - 1] == kWall || m_field[y][x - 1] == kMovingBlock || m_field[y][x - 1] == kTreasure))
						{
							x--;
						}
						player.m_dirNo = 1;
						player.isKey = true;
					}
					else if (padState & PAD_INPUT_RIGHT)
					{
						if (m_field[y][x + 1] == kMovingBlock)
						{
							if (!(m_field[y][x + 2] == kMovingBlock || m_field[y][x + 2] == kWall))
							{
								m_field[y][x + 1] = kEmpty;
								m_field[y][x + 2] = kMovingBlock;
							}
						}
						if (!(m_field[y][x + 1] == kWall || m_field[y][x + 1] == kMovingBlock || m_field[y][x + 1] == kTreasure))
						{
							x++;
						}
						player.m_dirNo = 2;
						player.isKey = true;
					}
					m_field[y][x] = kPlayer;
					PlayerCount = 0;
				}
			}
		}
	}

	player.Update();

	door.Update();

	mEnemy.MoveX = 0.0f;
	mEnemy.MoveY = 0.0f;
	
	mEnemy.Update();

	mEnemy2.MoveX = 0.0f;
	mEnemy2.MoveY = 0.0f;

	mEnemy2.Update();
	
	if (CheckHitKey(KEY_INPUT_1))
	{
		init();
		return (new SceneTitle);
	}
	if (player.m_ExplosionAnimeNo == 7)
	{
		return(new GameOver);
	}
	
	HeartCount = 0;
	TreasureCount = 0;
	// �����̃T�C�Y���Z�o
	mEnemy.hsize = mEnemy.size * 0.5f;


	//////////////////////////////////////
	// �v���C���[�̓����蔻��
	//////////////////////////////////////
	// �Ֆʂɂ���n�[�g�̐��𐔂���
	for (int y = 0; y < kFieldY; y++)
	{
		for (int x = 0; x < kFieldX; x++)
		{
			if (m_field[y][x] == kHeart)
			{
				HeartCount++;
			}
			if (m_field[y][x] == kTreasureOpen || m_field[y][x] == kTreasure)
			{
				TreasureCount++;
			}
		}
	}

	// �n�[�g�̐����O�ɂȂ�����A�󔠂��J����
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
	if (TreasureCount == 0)
	{
		// �����J����
		if (door.OpenCount == 0)
		{
			door.OpenDoor = false;
			Key == false;
		}
	}
	// ���ɓ���������
	for (int y = 0; y < kFieldY; y++)
	{
		for (int x = 0; x < kFieldX; x++)
		{
			if (m_field[y][x] == kPlayer)
			{
				if (m_field[y - 1][x] == kDoor)
				{
					if (padState & PAD_INPUT_UP)
					{
						// �����J���Ă��鎞
						if (door.m_animeNo == 13)
						{
							door.m_animeNo = 0;
							if (StageNumber == 1)
							{
								mEnemy.Number = 2;
								StageNumber = 2;
							}
							else if (StageNumber == 2)
							{
								mEnemy.Number = 3;
								StageNumber = 3;
							}
							init(); // ���̃X�e�[�W�ցI�I�I�I�I�I
						}
					}
				}
			}
		}
	}


	//////////////////////////////////////
	// �G�̓����蔻��
	//////////////////////////////////////

	// ��ɍ��E�ړ����������Ń`�F�b�N
	// �����̃`�F�b�N
	EnemyBlockHitCheck(mEnemy.EnemyX - mEnemy.hsize, mEnemy.EnemyY + mEnemy.hsize, mEnemy.MoveX, mEnemy.Dummy);

	// �E���̃`�F�b�N
	EnemyBlockHitCheck(mEnemy.EnemyX + mEnemy.hsize, mEnemy.EnemyY + mEnemy.hsize, mEnemy.MoveX, mEnemy.Dummy);

	// ����̃`�F�b�N
	EnemyBlockHitCheck(mEnemy.EnemyX - mEnemy.hsize, mEnemy.EnemyY - mEnemy.hsize, mEnemy.MoveX, mEnemy.Dummy);

	// �E��̃`�F�b�N
	EnemyBlockHitCheck(mEnemy.EnemyX + mEnemy.hsize, mEnemy.EnemyY - mEnemy.hsize, mEnemy.MoveX, mEnemy.Dummy);

	// �㉺���E�ړ����������Z
	mEnemy.EnemyX += mEnemy.MoveX;
	mEnemy.EnemyY += mEnemy.MoveY;
}



int Field::EnemyBlockHitCheck(float enemyX, float enemyY, float& enemyMoveX, float& enemyMoveY)
{
	/////////////////////////////////
	// �G
	/////////////////////////////////
	// �ړ��ʂ𑫂�
	mEnemy.afterX = enemyX + enemyMoveX;
	mEnemy.afterY = enemyY + enemyMoveY;

	// �����蔻��̂���ǂɓ������Ă��邩�`�F�b�N
	if (GetChipParam(mEnemy.afterX, mEnemy.afterY) == WallHit || GetChipParam(mEnemy.afterX, mEnemy.afterY) == BooxHit)
	{
		// �������Ă�����ǂ��痣���������s��
		// �u���b�N�̏㉺���E�̍��W���Z�o
		// ���ӂ� X ���W
		mEnemy.LeftX = (float)((int)mEnemy.afterX / kSize) * kSize;
		// �E�ӂ� X ���W
		mEnemy.RightX = (float)((int)mEnemy.afterX / kSize + 1) * kSize;
		// ��ӂ� Y ���W
		mEnemy.TopY = (float)((int)mEnemy.afterY / kSize) * kSize;
		// ���ӂ� Y ���W
		mEnemy.BottomY = (float)((int)mEnemy.afterY / kSize + 1) * kSize;

		// ���ӂɓ������Ă����ꍇ
		if (mEnemy.enemyRightMove == false)
		{
			// �ړ��ʂ�␳����
			mEnemy.MoveX = mEnemy.RightX - enemyX + 1.0f;
			mEnemy.enemyRightMove = true;
			// ���ӂɓ��������ƕԂ�
			return 11;
		}
		// �E�ӂɓ������Ă����ꍇ
		if (mEnemy.enemyRightMove == true)
		{
			// �ړ��ʂ�␳����
			mEnemy.MoveX = mEnemy.LeftX - enemyX - 1.0f;
			mEnemy.enemyRightMove = false;
			// �E�ӂɓ��������ƕԂ�
			return 12;
		}
		return 5;
	}
	//�@�v���C���[�ƓG�̓����蔻��
	if (GetChipParam(mEnemy.afterX, mEnemy.afterY) == playerHit)
	{
		// �v���C���[����������
		if (player.ExplosionCount == 0)
		{
			player.Explosion = false;
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

	//�@�G���ǂɓ���������
	if (m_field[y][x] == kWall ||  m_field[y][x] == kTreasure)
	{
		return WallHit;
	}
	//�@�G����������u���b�N�ɂ�������
	if (m_field[y][x] == kMovingBlock)
	{
		return BooxHit;
	}

	// �G���v���C���[�ɓ���������
	if (m_field[y][x] == kPlayer)
	{
		death = false;
		return playerHit;
	}
}


void Field::draw()
{
	printfDx("%d\n", player.ExplosionCount);


	int kWallGraphic = LoadGraph("data/Wall.png");
	int kBooxGraphic = LoadGraph("data/Boox.png");
	int kHeartGraphic = LoadGraph("data/Heart.png");
	int kFloorGraphic = LoadGraph("data/floor.png");
	int kTreasureGraphic = LoadGraph("data/Treasure.png");
	int kTreasureOpenGraphic = LoadGraph("data/TreasureOpen.png");
	int kTreasureOpenEmptyGraphic = LoadGraph("data/TreasureOpenEmpty.png");


	// �}�b�v�̕`��
	for (int y = 0; y < kFieldY; y++)
	{
		for (int x = 0; x < kFieldX; x++)
		{
			//�@�ǂ̕`��
			if (m_field[y][x] == 5)
			{
				DrawGraph(m_fieldX + x * kSize, m_fieldY + y * kSize,  kWallGraphic,TRUE);
			}
			//�@���̕`��
			if (m_field[y][x] == 0)
			{
				DrawGraph(m_fieldX + x * kSize, m_fieldY + y * kSize, kFloorGraphic, TRUE);
			}
			//�@�u���b�N�̕`��
			if (m_field[y][x] == 1)
			{
				DrawExtendGraph(m_fieldX + x * kSize, m_fieldY + y * kSize,
					m_fieldX + x * kSize + 48, m_fieldY + y * kSize + 48, kBooxGraphic, TRUE);
			}
			//�@�n�[�g�̕`��
			if (m_field[y][x] == 2)
			{
				DrawGraph(m_fieldX + x * kSize, m_fieldY + y * kSize, kHeartGraphic, TRUE);
			}
			// ���̕`��
			if (m_field[y][x] == kDoor)
			{
				DrawGraph(m_fieldX + x * kSize, m_fieldY + y * kSize, door.m_handle[door.m_animeNo], true);
			}
			//�@�󔠂̕`��
			if (m_field[y][x] == kTreasure)
			{
				DrawExtendGraph(m_fieldX + x * kSize, m_fieldY + y * kSize, 
					m_fieldX + x * kSize + 48, m_fieldY + y * kSize + 48, kTreasureGraphic, TRUE);
			}
			//�@�J�����󔠂̕`��
			if (m_field[y][x] == kTreasureOpen)
			{
				DrawExtendGraph(m_fieldX + x * kSize, m_fieldY + y * kSize,
					m_fieldX + x * kSize + 48, m_fieldY + y * kSize + 48, kTreasureOpenGraphic, TRUE);
				if (Key == false)
				{
					DrawExtendGraph(m_fieldX + x * kSize, m_fieldY + y * kSize,
						m_fieldX + x * kSize + 48, m_fieldY + y * kSize + 48, kTreasureOpenEmptyGraphic, TRUE);
				}
			}

			if (m_field[y][x] == kPlayer)
			{
				DrawGraph(m_fieldX + x * kSize, m_fieldY + y * kSize, kFloorGraphic, TRUE);
				
				if (death == false)
				{
					DrawExtendGraph(m_fieldX + x * kSize, m_fieldY + y * kSize,
						m_fieldX + x * kSize + 50, m_fieldY + y * kSize + 50,
						player.m_ExplosionHandle[player.m_ExplosionAnimeNo], TRUE);
				}
				else
				{
					DrawExtendGraph(m_fieldX + x * kSize, m_fieldY + y * kSize,
						m_fieldX + x * kSize + 50, m_fieldY + y * kSize + 50,
						player.m_PlayerHandle[player.m_PlayerAnimeNo], TRUE);
				}

			}
		}
	}
	
	//// �L�����N�^�̕`��
	//player.Draw();
	
	// �����G�̕`��
	mEnemy.Draw();

			
}
