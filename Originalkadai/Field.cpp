#include "Field.h"
#include "DxLib.h"
#include "GameMain.h"

namespace
{
	constexpr int kEmpty = 0;		// 空っぽ
	constexpr int kMovingBlock = 1;	// 動かせるブロック
	constexpr int kMovingEnemy = 2;	// 敵
	constexpr int kPlayer = 3;		// プレイヤー
	constexpr int kRightWall = 6;	// 右壁
	constexpr int kLeftWall = 7;	// 左壁
	constexpr int kUpWall = 8;		// 上壁
	constexpr int kDownWall = 9;	// 下壁
}

Field::Field() :
	m_fieldX(200),
	m_fieldY(64),
	m_playerX(1),			// プレイヤーの初期位置
	m_playerY(1),
	m_MovingEnemyX(3),		// 動く敵の初期位置
	m_MovingEnemyY(6),
	m_MovingBlockX(5),		// ブロックの初期位置
	m_MovingBlockY(4),
	m_PlayerFrameCount(0),	// プレイヤーのカウント
	m_EnemyFrameCount(0),	// エネミーのカウント
	m_ShotFrameCount(0),	// ショットのカウント

	m_PlayerWaitingTime(8),	// プレイヤー待機時間
	m_EnemyWaitingTime(8)	// エネミー待機時間
{
	m_shotX = m_MovingEnemyX;	// 球の初期位置
	m_shotY = m_MovingEnemyY;
}

Field::~Field()
{

}

void Field::init()
{
	for (int x = 0; x < kFieldX; x++)
	{
		for (int y = 0; y < kFieldY; y++)
		{
			// 盤面に何もおかれていない状態にする
			m_field[y][x] = kEmpty;

			// プレイヤー
			m_field[m_playerY][m_playerX] = kPlayer;

			// 動く敵
			m_field[m_MovingEnemyY][m_MovingEnemyX] = kMovingEnemy;

			// 動かせるブロック
			m_field[m_MovingBlockY][m_MovingBlockX] = kMovingBlock;

			// 右壁
			m_field[y][15] = kRightWall;
			// 左壁
			m_field[y][0] = kLeftWall;
			// 上壁
			m_field[0][x] = kUpWall;
			// 下壁
			m_field[11][x] = kDownWall;

			
		}
	}
}

void Field::update()
{
	int Up = 0;
	int Do = 0;
	int Ri = 0;
	int Le = 0;

	if (enemyRightMove == true)
	{
		m_EnemyFrameCount++;
		if (m_EnemyFrameCount >= m_EnemyWaitingTime)
		{
			m_MovingEnemyX ++;
			
			m_EnemyFrameCount = 0;
		}
	}
	else
	{
		m_EnemyFrameCount++;
		if (m_EnemyFrameCount >= m_EnemyWaitingTime)
		{
			m_MovingEnemyX--;

			m_EnemyFrameCount = 0;
		}
	}

	// 動く敵が壁にぶつかったら移動する方向を反転する
	// ->
	if (enemyRightMove == true)
	{
		if (m_MovingEnemyX > kFieldX - 2)
		{
			m_MovingEnemyX = kFieldX - 3;
			enemyRightMove = false;
		}
		if (m_MovingEnemyX == m_MovingBlockX && m_MovingEnemyY == m_MovingBlockY)
		{
			m_MovingEnemyX = m_MovingBlockX - 1;
			enemyRightMove = false;
		}
	}
	
	
	// <-
	if (enemyRightMove == false)
	{
		if (m_MovingEnemyX < 1)
		{
			m_MovingEnemyX = 1;
			enemyRightMove = true;
		}

		if (m_MovingEnemyX == m_MovingBlockX && m_MovingEnemyY == m_MovingBlockY)
		{
			m_MovingEnemyX = m_MovingBlockX  + 1;
			enemyRightMove = true;
		}
	}

	if (CheckHitKey(KEY_INPUT_UP))
	{
		m_PlayerFrameCount++;
		if (m_PlayerFrameCount >= m_PlayerWaitingTime)
		{
			Up = + 1;
			m_playerY--;
			m_PlayerFrameCount = 0;
		}

	}
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		m_PlayerFrameCount++;
		if (m_PlayerFrameCount >= m_PlayerWaitingTime)
		{
			Do = + 1;
			m_playerY++;
			m_PlayerFrameCount = 0;
		}
	}
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		m_PlayerFrameCount++;
		if (m_PlayerFrameCount >= m_PlayerWaitingTime)
		{
			Ri = +1;
			m_playerX++;
			m_PlayerFrameCount = 0;
		}
	}
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		m_PlayerFrameCount++;
		if (m_PlayerFrameCount >= m_PlayerWaitingTime)
		{
			Le = +1;
			m_playerX--;
			m_PlayerFrameCount = 0;
		}
	}
	for (int x = 0; x < kFieldX; x++)
	{
		for (int y = 0; y < kFieldY; y++)
		{
			// プレイヤーとブロックがぶつかったら
			if (m_playerX == m_MovingBlockX && m_playerY == m_MovingBlockY )
			{
				if (m_field[y][x] == kMovingBlock)
				{
					m_field[y][x] = kEmpty;
					if (Up == 1)
					{
						//m_playerY++;
						m_MovingBlockY--;
					}
					if (Do == 1)
					{
						//m_playerY--;
						m_MovingBlockY++;
					}
					if (Ri == 1)
					{
						//m_playerX--;
						m_MovingBlockX++;
					}
					if (Le == 1)
					{
					//	m_playerX++;
						m_MovingBlockX--;
					}
					if (m_field[y][x] == kRightWall)
					{
						m_MovingBlockX--;
					}
					if (m_field[y][x] == kLeftWall)
					{
						m_MovingBlockX++;
					}
					if (m_field[y][x] == kUpWall)
					{
						m_MovingBlockY++;
					}
					if (m_field[y][x] == kDownWall)
					{
						m_MovingBlockY--;
					}
					m_field[y][x] = kMovingBlock;
				}
			}
			// プレイヤーと壁が当たった場合
			if (m_field[m_playerY][m_playerX] == kRightWall)
			{
				m_playerX--;
			}
			if (m_field[m_playerY][m_playerX] == kLeftWall)
			{
				m_playerX++;
			}
			if (m_field[m_playerY][m_playerX] == kUpWall)
			{
				m_playerY++;
			}
			if (m_field[m_playerY][m_playerX] == kDownWall)
			{
				m_playerY--;
			}


			


			// 敵とプレイヤー
			if (m_playerX == m_MovingEnemyX || m_playerY == m_MovingEnemyY)
			{
				if (shotFlag == false)
				{
					m_shotX = m_MovingEnemyX;
					m_shotY = m_MovingEnemyY;
				}
				
				shotFlag = true;
				// 敵よりも上にプレイヤーがいた場合
				if (m_playerY < m_MovingEnemyY)
				{
					clsDx();
					printfDx("上にいた\n");
					m_shotX = m_MovingEnemyX;
					m_ShotFrameCount++;
					if (m_ShotFrameCount >= 300)
					{
						m_shotY--;
						m_ShotFrameCount = 0;
					}	
				}
				// 敵よりも下にプレイヤーがいた場合
				else if (m_playerY > m_MovingEnemyY)
				{
					clsDx();
					printfDx("下にいた\n");
					m_shotX = m_MovingEnemyX;
					m_ShotFrameCount++;
					if (m_ShotFrameCount >= 300)
					{
						m_shotY++;
						m_ShotFrameCount = 0;
					}
				}
				// 敵よりも左にプレイヤーがいた場合
				if (m_playerX < m_MovingEnemyX)
				{
					clsDx();
					printfDx("左にいた\n");
					m_shotY = m_MovingEnemyY;
					m_ShotFrameCount++;
					if (m_ShotFrameCount >= 300)
					{
						m_shotX--;
						m_ShotFrameCount = 0;
					}
				}
				// 敵よりも右にプレイヤーがいた場合
				else if (m_playerX > m_MovingEnemyX)
				{
					clsDx();
					printfDx("右にいた\n");
					m_shotY = m_MovingEnemyY;
					m_ShotFrameCount++;
					if (m_ShotFrameCount >= 300)
					{
						m_shotX++;
						m_ShotFrameCount = 0;
					}
				}
			}
			
			// 球がブロックに当たったら、セーフ
			if (m_shotY == m_MovingBlockY && m_shotX == m_MovingBlockX)
			{
				printfDx("セーフ\n");

				m_shotX = 0;
				m_shotY = 0;
				shotFlag = false;
				return;
			}

			// 球がプレイヤーに当たったら、アウト
			// プレイヤーは初期位置に戻される
			if (m_shotY == m_playerY && m_shotX == m_playerX)
			{
				printfDx("ゲームオーバー\n");

				m_shotX = 0;
				m_shotY = 0;

				shotFlag = false;

				m_playerX = 1;
				m_playerY = 1;
				return;
			}
		}
	}
}

void Field::draw()
{
	//printfDx("pX=%d  pY=%d  eX=%d  eY=%d\n", m_playerX, m_playerY,m_enemyX,m_enemyY);

	//printfDx("bX=%d    eX=%d   \n", m_blockX,m_enemyX);

	//clsDx();
	for (int x = 0; x < kFieldX; x++)
	{
		for (int y = 0; y < kFieldY; y++)
		{
			int posX = x * kSize + m_fieldX;
			int posY = y * kSize + m_fieldY;

			int plyerX = m_playerX * kSize + m_fieldX;
			int plyerY = m_playerY * kSize + m_fieldY;

			int MovingEnemyX = m_MovingEnemyX * kSize + m_fieldX;
			int MovingEnemyY = m_MovingEnemyY * kSize + m_fieldY;

			int blockX = m_MovingBlockX * kSize + m_fieldX;
			int blockY = m_MovingBlockY * kSize + m_fieldY;

			int shotX = m_shotX * kSize + m_fieldX;
			int shotY = m_shotY * kSize + m_fieldY;


			// フィールドの描写
			DrawBox(posX, posY,
				posX + kSize, posY + kSize,
				0xffffff, false);
			// 動く敵の描写
			DrawBox(MovingEnemyX, MovingEnemyY,
				MovingEnemyX + kSize, MovingEnemyY + kSize,
				0xff00ff, true);
			// プレイヤーの描写
			DrawBox(plyerX, plyerY,
				plyerX + kSize, plyerY + kSize,
				0xff0000, true);

			if (shotFlag == true)
			{
				// 弾の描写
				DrawBox(shotX, shotY,
					shotX + kSize, shotY + kSize,
					0xffffff, true);
			}
			
			// ブロックの描写
			DrawBox(blockX, blockY,
				blockX + kSize, blockY + kSize,
				0xffff00, true);

			if (m_field[y][x] == kRightWall || m_field[y][x] == kLeftWall ||
				m_field[y][x] == kUpWall || m_field[y][x] == kDownWall)
			{
				DrawBox(posX, posY,
					posX + kSize, posY + kSize,
					0xffffff, true);
			}

			//printfDx("%d ", m_field[y][x]);
		}
	//	printfDx("\n");
	}
}
