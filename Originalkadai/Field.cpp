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


//#define SPEED   (5.0f)   // キャラの移動スピード

 
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
	constexpr int kEmpty = 0;		// 空っぽ
	constexpr int kMovingBlock = 1;	// 動かせるブロック
	constexpr int kMovingEnemy = 2;	// 動く敵
	constexpr int kPlayer = 3;		// プレイヤー
	constexpr int kShot = 4;		// 弾
	constexpr int kWall = 5;		// 動かせない石
}

Field::Field() :

	m_fieldX(300),
	m_fieldY(64)
	//m_MovingEnemyX(3),		// 動く敵の初期位置
	//m_MovingEnemyY(6),
	//m_MovingBlockY(4),
	//m_ShotFrameCount(0),	// ショット  のカウント

	//m_PlayerWaitingTime(8),	// プレイヤー待機時間
	//m_EnemyWaitingTime(8)	// エネミー  待機時間
{
	//m_shotX = m_MovingEnemyX;	// 球の初期位置
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


	//// エネミーの移動
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
	//// 動く敵が壁にぶつかったら移動する方向を反転する
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
	//	printfDx("石にぶつかった\n");
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

	// 半分のサイズを算出
	player.hsize = player.size * 0.5f;

	// 左下のチェック
	if (BlockHitCheck(player.x - player.hsize, player.y + player.hsize, player.Dummy, player.MoveY) == 3)
	{
		player.y = 0.0f;
	}

	// 右下のチェック
	if (BlockHitCheck(player.x + player.hsize, player.y + player.hsize, player.Dummy, player.MoveY) == 3)
	{
		player.y = 0.0f;
	}

	// 左上のチェック
	if (BlockHitCheck(player.x - player.hsize, player.y - player.hsize, player.Dummy, player.MoveY) == 4)
	{
		player.y *= -1.0f;
	}

	// 右上のチェック
	if (BlockHitCheck(player.x + player.hsize, player.y - player.hsize, player.Dummy, player.MoveY) == 4)
	{
		player.y *= -1.0f;
	}
	


	// 後に左右移動成分だけでチェック
	// 左下のチェック
	BlockHitCheck(player.x - player.hsize, player.y + player.hsize, player.MoveX, player.Dummy);

	// 右下のチェック
	BlockHitCheck(player.x + player.hsize, player.y + player.hsize, player.MoveX, player.Dummy);

	// 左上のチェック
	BlockHitCheck(player.x - player.hsize, player.y - player.hsize, player.MoveX, player.Dummy);

	// 右上のチェック
	BlockHitCheck(player.x + player.hsize, player.y - player.hsize, player.MoveX, player.Dummy);

	// 上下左右移動成分を加算
	player.x += player.MoveX;
	player.y += player.MoveY;

	//printfDx("%f\n", player.MoveX);
	//// 敵とプレイヤー
	//if (player.x == m_MovingEnemyX || player.y == m_MovingEnemyY)
	//{
	//	if (shotFlag == false)
	//	{
	//		m_shotX = m_MovingEnemyX;
	//		m_shotY = m_MovingEnemyY;
	//	}
	//	
	//	shotFlag = true;
	//	// 敵よりも上にプレイヤーがいた場合
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
	//	// 敵よりも下にプレイヤーがいた場合
	//	else if (player.y > m_MovingEnemyY)
	//	{
	//		//clsDx();
	//		//printfDx("下にいた\n");
	//		m_shotX = m_MovingEnemyX;
	//		m_ShotFrameCount++;
	//		if (m_ShotFrameCount >= 300)
	//		{
	//			m_shotY++;
	//			m_ShotFrameCount = 0;
	//		}
	//	}
	//	// 敵よりも左にプレイヤーがいた場合
	//	if (player.x < m_MovingEnemyX)
	//	{
	//		//clsDx();
	//		//printfDx("左にいた\n");
	//		m_shotY = m_MovingEnemyY;
	//		m_ShotFrameCount++;
	//		if (m_ShotFrameCount >= 300)
	//		{
	//			m_shotX--;
	//			m_ShotFrameCount = 0;
	//		}
	//	}
	//	// 敵よりも右にプレイヤーがいた場合
	//	else if (player.x > m_MovingEnemyX)
	//	{
	//		//clsDx();
	//		//printfDx("右にいた\n");
	//		m_shotY = m_MovingEnemyY;
	//		m_ShotFrameCount++;
	//		if (m_ShotFrameCount >= 300)
	//		{
	//			m_shotX++;
	//			m_ShotFrameCount = 0;
	//		}
	//	}
	//}
	//// 球がブロックに当たったら、セーフ
	//if (m_shotY == m_MovingBlockY && m_shotX == m_MovingBlockX)
	//{
	//	//printfDx("セーフ\n");
	//	m_shotX = 0;
	//	m_shotY = 0;
	//	shotFlag = false;
	//	return;
	//}
	//// 球がプレイヤーに当たったら、アウト
	//// プレイヤーは初期位置に戻される
	//if (m_shotY == player.y && m_shotX == player.x)
	//{
	//	//printfDx("ゲームオーバー\n");
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
	// 移動量を足す

	player.afterX = X + PlayerMoveX;
	player.afterY = Y + PlayerMoveY;
	
	

	// 当たり判定のあるブロックに当たっているかチェック
	if (GetChipParam(player.afterX, player.afterY) == 1)
	{
		// 当たっていたら壁から離す処理を行う
		// ブロックの上下左右の座標を算出
		// 左辺の X 座標
		m_Block.LeftX = (float)((int)player.afterX / kSize) * kSize;
		// 右辺の X 座標
		m_Block.RightX = (float)((int)player.afterX / kSize + 1) * kSize;
		// 上辺の Y 座標
		m_Block.TopY = (float)((int)player.afterY / kSize ) * kSize ;
		// 下辺の Y 座標
		m_Block.BottomY = (float)((int)player.afterY / kSize + 1) * kSize;
		
		// 上辺に当たっていた場合
		if (CheckHitKey(KEY_INPUT_UP))
		{
			//player.y +=5.0f;
			// 移動量を補正する
			player.MoveY = m_Block.BottomY - Y + 1.0f;

			//上辺に当たったと返す
			return 3;
		}

		// 下辺に当たっていた場合
		if (CheckHitKey(KEY_INPUT_DOWN))
		{
			// 移動量を補正する
			player.MoveY = m_Block.TopY - Y - 1.0f;

			// 下辺に当たったと返す
			return 4;
		}
		
		// 左辺に当たっていた場合
		if (player.MoveX < 0.0f)
		{
			// 移動量を補正する
			player.MoveX = m_Block.RightX - X + 1.0f;

			// 左辺に当たったと返す
			return 1;
		}
		// 右辺に当たっていた場合
		if (player.MoveX > 0.0f)
		{
			// 移動量を補正する
			player.MoveX = m_Block.LeftX - X - 1.0f;

			// 右辺に当たったと返す
			return 2;
		}

		return 5;
	}

	// プレイヤーと動かせるブロックが当たってるかチェック
	if (GetChipParam(player.afterX, player.afterY) == 2)
	{
		for (int y = 0; y < kFieldY; y++)
		{
			for (int x = 0; x < kFieldX; x++)
			{
				if (m_field[y][x] == kMovingBlock)
				{
					// 上辺に当たっていた場合
					if (CheckHitKey(KEY_INPUT_UP))
					{
						if (m_field[y - 1][x] == 0)
						{
							m_field[y][x] = 0;
							m_field[y - 1][x] = 1;
							return 1;
						}
					}

					// 下辺に当たっていた場合
					if (CheckHitKey(KEY_INPUT_DOWN))
					{
						if (m_field[y + 1][x] == 0)
						{
							m_field[y][x] = 0;
							m_field[y + 1][x] = 1;
							return 1;
						}
					}

					// 左辺に当たっていた場合
					if (CheckHitKey(KEY_INPUT_LEFT))
					{
						if (m_field[y][x - 1] == 0)
						{
							m_field[y][x] = 0;
							m_field[y][x - 1] = 1;
							return 1;
						}
					}
					// 右辺に当たっていた場合
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
// マップチップの値を取得する関数
//-----------------------------------------
int Field::GetChipParam(float X, float Y)
{
	int x, y;
	// 整数値へ変換
	x = (int)X / kSize;
	y = (int)Y / kSize;

	//printfDx("%d\n", m_field[y][x]);
	if (m_field[y][x] == 5)
	{
		printfDx("壁に当たった \n");
		return 1;
	}
	if (m_field[y][x] == 1)
	{
		printfDx("ブロックに当たった \n");
		return 2;
	}
	
}


void Field::draw()
{
	//printfDx("pX=%d  pY=%d  eX=%d  eY=%d\n", player.x, player.y,m_enemyX,m_enemyY);

	//printfDx("bX=%d    eX=%d   \n", m_blockX,m_enemyX);

	// マップの描画
	for (int y = 0; y < kFieldY; y++)
	{
		for (int x = 0; x < kFieldX; x++)
		{
			// １は当たり判定チップを表しているので１のところだけ描画
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
	
	// キャラクタの描画
	DrawBox((int)(m_fieldX + player.x - player.size * 0.5f), (int)(m_fieldY + player.y - player.size * 0.5f),
		(int)(m_fieldX + player.x + player.size * 0.5f) + 1, (int)(m_fieldY + player.y + player.size * 0.5f) + 1,
		GetColor(255, 0, 0), TRUE);
	
		
	//if (shotFlag == true)
			//{
			//	if (m_field[y][x] == kShot)
			//	{
			//	}
			//	//// 弾の描写
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
