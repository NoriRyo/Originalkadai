#include "Field.h"
#include "DxLib.h"
#include "Player.h"
#include "Game.h"
#include "Door.h"
#include "MovingEnemy.h"
#include "SceneTitle.h"
#include "GameOver.h"


#define kSize (48)

 //デバック
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

 //ステージ１
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
	{5, 10,0,2, 0,5,0,0, 1,0,0,5, 5},

	{5, 5,5,5, 5,5,5,5, 5,5,5,5, 5}
};
// ステージ２
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
	{5, 5,2,2, 2,5,0,0, 0,0,0,10, 5},

	{5, 5,5,5, 5,5,5,5, 5,5,5,5, 5}
};
// ステージ３
char m_field3[13][13] =
{
	{5, 5,5,5, 5,5,5,5, 6,5,5,5, 5},

	{5, 0,5,2, 0,5,1,5, 0,2,5,0, 5},
	{5, 0,0,0, 5,5,2,5, 5,0,0,0, 5},
	{5, 0,0,5, 1,0,0,0, 1,5,0,0, 5},

	{5, 0,5,5, 0,1,1,1, 0,5,5,0, 5},
	{5, 0,1,0, 1,0,0,0, 1,0,1,0, 5},
	{5, 0,1,0, 1,0,10,0, 1,0,1,0, 5},
	{5, 0,1,0, 1,0,0,0, 1,0,1,0, 5},

	{5, 0,5,5, 0,1,1,1, 0,5,5,0, 5},
	{5, 0,0,5, 1,0,0,0, 1,5,0,0, 5},
	{5, 0,0,0, 5,5,2,5, 5,0,0,0, 5},
	{5, 0,5,4, 0,5,1,5, 0,2,5,0, 5},

	{5, 5,5,5, 5,5,5,5, 5,5,5,5, 5}
};
// ステージ4
char m_field4[13][13] =
{
	{5, 5,5,5, 5,5,5,5, 5,5,5,5, 5},

	{5, 0,0,0, 0,0,0,0, 0,0,0,0, 5},
	{5, 0,0,0, 0,0,0,0, 0,0,0,0, 5},
	{5, 0,0,0, 0,0,0,0, 0,0,0,0, 5},

	{5, 0,0,0, 0,0,0,0, 0,0,0,0, 5},
	{5, 0,0,0, 0,0,0,0, 0,0,0,0, 5},
	{5, 0,0,0, 0,0,0,0, 0,0,0,0, 5},
	{5, 0,0,0, 6,0,0,0, 0,0,0,0, 5},

	{5, 0,0,0, 0,4,2,0, 0,0,0,0, 5},
	{5, 0,0,0, 0,0,10,0, 0,0,0,0, 5},
	{5, 0,0,0, 1,0,0,0, 0,0,0,0, 5},
	{5, 0,0,0, 0,0,0,0, 0,0,0,0, 5},

	{5, 5,5,5, 5,5,5,5, 5,5,5,5, 5}

};
namespace
{
	constexpr int kEmpty = 0;		// 空っぽ
	constexpr int kMovingBlock = 1;	// 動かせるブロック
	constexpr int kHeart = 2;		// ハート
	constexpr int kDoor = 6;		//（扉）
	constexpr int kTreasure = 4;	// 宝箱
	constexpr int kTreasureOpen = 8;// 宝箱（開いている） 
	constexpr int kWall = 5;		// 動かせない石
	constexpr int kPlayer = 10;		// プレイヤー
	
	
	const char* const kPlayarGraphicFilename = "data/player3.png";
	const char* const kExplosionGraphicFilename = "data/Explosion.png";
	const char* const kDoorGraphicFilename = "data/door.png";

	int Key = true;		// キーが存在するかしないか。
}


Field::Field() :

	m_fieldX((Game::kScreenWidth/2)/2),
	m_fieldY(124),
	m_hDoorGraphic(),
	m_hExplosionGraphic(),
	m_hPlayerGraphic(),
	m_field()

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
	HeartCount = 0;
	TreasureCount = 0;			
}

Field::~Field()
{
	
}

void Field::init()
{
	//PlaySoundFile("BGM.wav", DX_PLAYTYPE_BACK+DX_PLAYTYPE_LOOP);
	// ステージ切り替え
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
			if (StageNumber == 4)
			{
				m_field[y][x] = m_field4[y][x];
			}
		}
	}
	// プレイヤー
	LoadDivGraph(kPlayarGraphicFilename, Player::kPlayerGraphicDivNum,
		Player::kPlayerGraphicDivX, Player::kPlayerGraphicDivY,
		Player::kPlayerGraphicSizeX, Player::kPlayerGraphicSizeY, m_hPlayerGraphic);

	for (int i = 0; i < Player::kPlayerGraphicDivNum; i++)
	{
		player.PlayerSetHandle(i, m_hPlayerGraphic[i]);
	}
	// 爆発
	LoadDivGraph(kExplosionGraphicFilename, Player::kExplosionGraphicDivNum,
		Player::kExplosionGraphicDivX, Player::kExplosionGraphicDivY,
		Player::kExplosionGraphicSizeX, Player::kExplosionGraphicSizeY, m_hExplosionGraphic);

	for (int i = 0; i < Player::kExplosionGraphicDivNum; i++)
	{
		player.ExplosionSetHandle(i, m_hExplosionGraphic[i]);
	}
	player.init();	

	// ドア
	LoadDivGraph(kDoorGraphicFilename, Door::kDoorGraphicDivNum,
		Door::kGraphicDivX, Door::kGraphicDivY,
		Door::kGraphicSizeX, Door::kGraphicSizeY, m_hDoorGraphic);

	for (int i = 0; i < Door::kDoorGraphicDivNum; i++)
	{
		door.setHandle(i, m_hDoorGraphic[i]);
	}
	door.init();

	// 鍵が存在している
	Key = true;

	// 敵
	mEnemy1.init();
	mEnemy2.init();
	if (StageNumber == 1 || StageNumber == 3)
	{
		mEnemy1.setPos(0, -200);
		mEnemy2.setPos(0, -200);
	}
	if (StageNumber == 2)
	{
		mEnemy1.setPos(552.0f - 48.0f * 4, 552.0f - 48.0f * 3);
		mEnemy2.setPos(0, -200);
	}
	if (StageNumber == 4)
	{
		mEnemy1.setPos(552.0f - 48.0f * 3, 552.0f - 48.0f * 1);
		mEnemy2.setPos(552.0f - 48.0f * 9, 552.0f - 48.0f * 1);
	}
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
	if (isFading())
	{
		bool isOut = isFadingOut();
		SceneBase::updateFade();
		// フェードアウト終了時にシーン切り替え
		
	}


	clsDx();
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

#ifdef _DEBUG
	//FprintfDx("1->リスタート　2->ステージ切り替え");
	if (CheckHitKey(KEY_INPUT_2))
	{
		
		StageNumber = 2;
	
		init(); // 次のステージへ！！！！！！
	}

	if (CheckHitKey(KEY_INPUT_1))
	{
		init();
	}
	if (CheckHitKey(KEY_INPUT_2))
	{

		StageNumber = 2;

		init(); // 次のステージへ！！！！！！
	}
	if (CheckHitKey(KEY_INPUT_3))
	{
		
	
	}
#else

#endif
	

	for (int y = 0; y < kFieldY; y++)
	{
		for (int x = 0; x < kFieldX; x++)
		{
			if (m_field[y][x] == kPlayer)
			{
				PlayerCount++;
				
				player.isKey = false;
				m_field[y][x] = kEmpty;
				// パッド(もしくはキーボード)からの入力を取得する
				if (padState & PAD_INPUT_UP)
				{
					if (PlayerCount >= 10)
					{
						if (m_field[y - 1][x] == kMovingBlock)
						{
							if (!(m_field[y - 2][x] == kMovingBlock || m_field[y - 2][x] == kWall || m_field[y - 2][x] == kTreasure 
								|| m_field[y - 2][x] == kTreasureOpen || m_field[y - 2][x] == kDoor || m_field[y - 2][x] == kHeart))
							{
								m_field[y - 1][x] = kEmpty;
								m_field[y - 2][x] = kMovingBlock;
							}
						}
						if (!(m_field[y - 1][x] == kWall || m_field[y - 1][x] == kMovingBlock 
							|| m_field[y - 1][x] == kDoor || m_field[y - 1][x] == kTreasure ))
						{
							y --;
						}
						player.m_dirNo = 3;
						player.isKey = true;
						PlayerCount = 0;
					}
				}
				else if (padState & PAD_INPUT_DOWN)
				{
					if (PlayerCount >= 10)
					{
						if (m_field[y + 1][x] == kMovingBlock)
						{
							if (!(m_field[y + 2][x] == kMovingBlock || m_field[y + 2][x] == kWall 
								|| m_field[y + 2][x] == kHeart || m_field[y + 2][x] == kTreasureOpen || m_field[y + 2][x] == kTreasure))
							{
								m_field[y + 1][x] = kEmpty;
								m_field[y + 2][x] = kMovingBlock;
							}
						}
						if (!(m_field[y + 1][x] == kWall || m_field[y + 1][x] == kMovingBlock 
							|| m_field[y + 1][x] == kTreasure ))
						{
							y++;
						}
						player.m_dirNo = 0;
						player.isKey = true;
						PlayerCount = 0;
					}
				}
				else if (padState & PAD_INPUT_LEFT)
				{
					if (PlayerCount >= 10)
					{
						if (m_field[y][x - 1] == kMovingBlock)
						{
							if (!(m_field[y][x - 2] == kMovingBlock || m_field[y][x - 2] == kWall || m_field[y][x - 2] == kHeart
								|| m_field[y][x - 2] == kTreasure || m_field[y][x - 2] == kTreasureOpen))
							{
								m_field[y][x - 1] = kEmpty;
								m_field[y][x - 2] = kMovingBlock;
							}
							
						}
						if (!(m_field[y][x - 1] == kWall || m_field[y][x - 1] == kMovingBlock 
							|| m_field[y][x - 1] == kTreasure ))
						{
							x--;
						}
						player.m_dirNo = 1;
						player.isKey = true;
						PlayerCount = 0;
					}
				}
				else if (padState & PAD_INPUT_RIGHT)
				{
					if (PlayerCount >= 10)
					{
						if (m_field[y][x + 1] == kMovingBlock)
						{
							if (!(m_field[y][x + 2] == kMovingBlock || m_field[y][x + 2] == kWall || m_field[y][x + 2] == kHeart
								|| m_field[y][x + 2] == kTreasure || m_field[y][x + 2] == kTreasureOpen))
							{
								m_field[y][x + 1] = kEmpty;
								m_field[y][x + 2] = kMovingBlock;
							}
						}
						if (!(m_field[y][x + 1] == kWall || m_field[y][x + 1] == kMovingBlock 
							|| m_field[y][x + 1] == kTreasure ))
						{
							x++;
						}
						player.m_dirNo = 2;
						PlayerCount = 0;
						player.isKey = true;
					}
				}
				m_field[y][x] = kPlayer;
			}
		}
	}

	player.Update();

	door.Update();

	mEnemy1.MoveX = 0.0f;
	mEnemy1.MoveY = 0.0f;
	
	mEnemy1.Update();

	mEnemy2.MoveX = 0.0f;
	mEnemy2.MoveY = 0.0f;

	mEnemy2.Update();
	
	if (player.m_ExplosionAnimeNo == 7)
	{
		return(new GameOver);
	}
	
	HeartCount = 0;
	TreasureCount = 0;
	// 半分のサイズを算出
	mEnemy1.hsize = mEnemy1.size * 0.5f;
	mEnemy2.hsize = mEnemy2.size * 0.5f;

	

	//////////////////////////////////////
	// プレイヤーの当たり判定
	//////////////////////////////////////
	// 盤面にあるハートの数を数える
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
	//printfDx("%d\n", HeartCount);
	//printfDx("%d\n", HeartMax);

	if (HeartMax > HeartCount)
	{
		PlaySoundFile("sound/Heart.wav",DX_PLAYTYPE_BACK);
	}

	HeartMax = HeartCount;

	// ハートの数が０になったら、宝箱を開ける
	if (HeartCount == 0)
	{
		for (int y = 0; y < kFieldY; y++)
		{
			for (int x = 0; x < kFieldX; x++)
			{
				if (m_field[y][x] == kTreasure)
				{
					// 宝箱オープン
					m_field[y][x] = kTreasureOpen;
				}
			}
		}
	}
	if (TreasureCount == 0)
	{
		// 扉を開ける
		if (door.OpenCount == 0)
		{
			door.OpenDoor = false;
			Key == false;
		}
	}
	// 扉に当たった時
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
						// 扉が開いている時
						if (door.m_animeNo == 13)
						{
							door.m_animeNo = 0;
							if (StageNumber == 1)
							{
								StageNumber = 2;
							}
							else if (StageNumber == 2)
							{
								StageNumber = 3;
							}
							else if (StageNumber == 3)
							{
								StageNumber = 4;
							}
							init(); // 次のステージへ！！！！！！
						}
					}
				}
			}
		}
	}


	//////////////////////////////////////
	// 敵1の当たり判定
	//////////////////////////////////////

	// 後に左右移動成分だけでチェック
	// 左下のチェック
	Enemy1BlockHitCheck(mEnemy1.EnemyX - mEnemy1.hsize, mEnemy1.EnemyY + mEnemy1.hsize, mEnemy1.MoveX, mEnemy1.Dummy);

	// 右下のチェック
	Enemy1BlockHitCheck(mEnemy1.EnemyX + mEnemy1.hsize, mEnemy1.EnemyY + mEnemy1.hsize, mEnemy1.MoveX, mEnemy1.Dummy);

	// 左上のチェック
	Enemy1BlockHitCheck(mEnemy1.EnemyX - mEnemy1.hsize, mEnemy1.EnemyY - mEnemy1.hsize, mEnemy1.MoveX, mEnemy1.Dummy);

	// 右上のチェック
	Enemy1BlockHitCheck(mEnemy1.EnemyX + mEnemy1.hsize, mEnemy1.EnemyY - mEnemy1.hsize, mEnemy1.MoveX, mEnemy1.Dummy);

	// 上下左右移動成分を加算
	mEnemy1.EnemyX += mEnemy1.MoveX;
	mEnemy1.EnemyY += mEnemy1.MoveY;

	//////////////////////////////////////
	// 敵2の当たり判定
	//////////////////////////////////////

	// 後に左右移動成分だけでチェック
	// 左下のチェック
	Enemy2BlockHitCheck(mEnemy2.EnemyX - mEnemy2.hsize, mEnemy2.EnemyY + mEnemy2.hsize, mEnemy2.MoveX, mEnemy2.Dummy);

	// 右下のチェック
	Enemy2BlockHitCheck(mEnemy2.EnemyX + mEnemy2.hsize, mEnemy2.EnemyY + mEnemy2.hsize, mEnemy2.MoveX, mEnemy2.Dummy);

	// 左上のチェック
	Enemy2BlockHitCheck(mEnemy2.EnemyX - mEnemy2.hsize, mEnemy2.EnemyY - mEnemy2.hsize, mEnemy2.MoveX, mEnemy2.Dummy);

	// 右上のチェック
	Enemy2BlockHitCheck(mEnemy2.EnemyX + mEnemy2.hsize, mEnemy2.EnemyY - mEnemy2.hsize, mEnemy2.MoveX, mEnemy2.Dummy);

	// 上下左右移動成分を加算
	mEnemy2.EnemyX += mEnemy2.MoveX;
	mEnemy2.EnemyY += mEnemy2.MoveY;


	return this;
}



int Field::Enemy1BlockHitCheck(float enemyX, float enemyY, float& enemyMoveX, float& enemyMoveY)
{
	/////////////////////////////////
	// 敵
	/////////////////////////////////
	// 移動量を足す
	mEnemy1.afterX = enemyX + enemyMoveX;
	mEnemy1.afterY = enemyY + enemyMoveY;

	// 当たり判定のある壁に当たっているかチェック
	if (GetChipParam(mEnemy1.afterX, mEnemy1.afterY) == WallHit || GetChipParam(mEnemy1.afterX, mEnemy1.afterY) == BooxHit)
	{
		// 当たっていたら壁から離す処理を行う
		// ブロックの上下左右の座標を算出
		// 左辺の X 座標
		mEnemy1.LeftX = (float)((int)mEnemy1.afterX / kSize) * kSize;
		// 右辺の X 座標
		mEnemy1.RightX = (float)((int)mEnemy1.afterX / kSize + 1) * kSize;
		// 上辺の Y 座標
		mEnemy1.TopY = (float)((int)mEnemy1.afterY / kSize) * kSize;
		// 下辺の Y 座標
		mEnemy1.BottomY = (float)((int)mEnemy1.afterY / kSize + 1) * kSize;

		// 左辺に当たっていた場合
		if (mEnemy1.enemyRightMove == false)
		{
			// 移動量を補正する
			mEnemy1.MoveX = mEnemy1.RightX - enemyX + 1.0f;
			mEnemy1.enemyRightMove = true;
			// 左辺に当たったと返す
			return 11;
		}
		// 右辺に当たっていた場合
		if (mEnemy1.enemyRightMove == true)
		{
			// 移動量を補正する
			mEnemy1.MoveX = mEnemy1.LeftX - enemyX - 1.0f;
			mEnemy1.enemyRightMove = false;
			// 右辺に当たったと返す
			return 12;
		}
		return 5;
	}
	//　プレイヤーと敵の当たり判定
	if (GetChipParam(mEnemy1.afterX, mEnemy1.afterY) == playerHit)
	{
		// プレイヤーが爆発する
		if (player.ExplosionCount == 0)
		{
			player.Explosion = false;
		}
	}
	return 0;
}
int Field::Enemy2BlockHitCheck(float enemyX, float enemyY, float& enemyMoveX, float& enemyMoveY)
{
	/////////////////////////////////
	// 敵
	/////////////////////////////////
	// 移動量を足す
	mEnemy2.afterX = enemyX + enemyMoveX;
	mEnemy2.afterY = enemyY + enemyMoveY;

	// 当たり判定のある壁に当たっているかチェック
	if (GetChipParam(mEnemy2.afterX, mEnemy2.afterY) == WallHit || GetChipParam(mEnemy2.afterX, mEnemy2.afterY) == BooxHit)
	{
		// 当たっていたら壁から離す処理を行う
		// ブロックの上下左右の座標を算出
		// 左辺の X 座標
		mEnemy2.LeftX = (float)((int)mEnemy2.afterX / kSize) * kSize;
		// 右辺の X 座標
		mEnemy2.RightX = (float)((int)mEnemy2.afterX / kSize + 1) * kSize;
		// 上辺の Y 座標
		mEnemy2.TopY = (float)((int)mEnemy2.afterY / kSize) * kSize;
		// 下辺の Y 座標
		mEnemy2.BottomY = (float)((int)mEnemy2.afterY / kSize + 1) * kSize;

		// 左辺に当たっていた場合
		if (mEnemy2.enemyRightMove == false)
		{
			// 移動量を補正する
			mEnemy2.MoveX = mEnemy2.RightX - enemyX + 1.0f;
			mEnemy2.enemyRightMove = true;
			// 左辺に当たったと返す
			return 11;
		}
		// 右辺に当たっていた場合
		if (mEnemy2.enemyRightMove == true)
		{
			// 移動量を補正する
			mEnemy2.MoveX = mEnemy2.LeftX - enemyX - 1.0f;
			mEnemy2.enemyRightMove = false;
			// 右辺に当たったと返す
			return 12;
		}
		return 5;
	}
	//　プレイヤーと敵の当たり判定
	if (GetChipParam(mEnemy2.afterX, mEnemy2.afterY) == playerHit)
	{
		// プレイヤーが爆発する
		if (player.ExplosionCount == 0)
		{
			player.Explosion = false;
		}
	}
	return 0;
}

//-----------------------------------------
// マップチップの値を取得する関数
//-----------------------------------------
int Field::GetChipParam(float X, float Y)
{
	int x, y;
	// 整数値へ変換
	x = (int)X / kSize;
	y = (int)Y / kSize;

	//　敵が壁に当たった時
	if (m_field[y][x] == kWall ||  m_field[y][x] == kTreasure)
	{
		return WallHit;
	}
	//　敵が動かせるブロックにあった時
	if (m_field[y][x] == kMovingBlock)
	{
		return BooxHit;
	}

	// 敵がプレイヤーに当たった時
	if (m_field[y][x] == kPlayer)
	{
		death = false;
		return playerHit;
	}
}


void Field::draw()
{
	int kWallGraphic = LoadGraph("data/Wall.png");
	int kBooxGraphic = LoadGraph("data/Boox.png");
	int kHeartGraphic = LoadGraph("data/Heart.png");
	int kFloorGraphic = LoadGraph("data/floor.png");
	int kTreasureGraphic = LoadGraph("data/Treasure.png");
	int kTreasureOpenGraphic = LoadGraph("data/TreasureOpen.png");
	int kTreasureOpenEmptyGraphic = LoadGraph("data/TreasureOpenEmpty.png");

	// マップの描画
	for (int y = 0; y < kFieldY; y++)
	{
		for (int x = 0; x < kFieldX; x++)
		{
			//　壁の描画
			if (m_field[y][x] == 5)
			{
				DrawGraph(m_fieldX + x * kSize, m_fieldY + y * kSize,  kWallGraphic,TRUE);
			}
			//　床の描画
			if (m_field[y][x] == 0)
			{
				DrawGraph(m_fieldX + x * kSize, m_fieldY + y * kSize, kFloorGraphic, TRUE);
			}
			//　ブロックの描画
			if (m_field[y][x] == 1)
			{
				DrawExtendGraph(m_fieldX + x * kSize, m_fieldY + y * kSize,
					m_fieldX + x * kSize + 48, m_fieldY + y * kSize + 48, kBooxGraphic, TRUE);
			}
			//　ハートの描画
			if (m_field[y][x] == 2)
			{
				DrawGraph(m_fieldX + x * kSize, m_fieldY + y * kSize, kHeartGraphic, TRUE);
			}
			// 扉の描画
			if (m_field[y][x] == kDoor)
			{
				DrawGraph(m_fieldX + x * kSize, m_fieldY + y * kSize, door.m_handle[door.m_animeNo], true);
			}
			//　宝箱の描画
			if (m_field[y][x] == kTreasure)
			{
				DrawExtendGraph(m_fieldX + x * kSize, m_fieldY + y * kSize, 
					m_fieldX + x * kSize + 48, m_fieldY + y * kSize + 48, kTreasureGraphic, TRUE);
			}
			//　開いた宝箱の描画
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
			// キャラクタの描画
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
	// 動く敵の描画
	mEnemy1.Draw();

	mEnemy2.Draw();


	SceneBase::drawFade();
}
