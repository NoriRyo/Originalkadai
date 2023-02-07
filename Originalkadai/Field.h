#pragma once
#include "Player.h"
#include "MovingBlock.h"
class Field
{
public:
	
	// マスのサイズ
	//static constexpr int kSize = 48;

public:
	Field();
	virtual ~Field();
	void init();
	void update();

	// マップとの当たり判定
	int BlockHitCheck(float X, float Y, float& MoveX, float& MoveY);
	// マップチップの値を取得する関数
	int GetChipParam(float X, float Y);

	void draw();
private:
	// エネミーの位置
	//int m_MovingEnemyX;
	//int m_MovingEnemyY;
	// 動かせるブロックの位置
	//int m_MovingBlockX;
	//int m_MovingBlockY;
	// 石の位置
	//int m_Stone1X;
	//int m_Stone1Y;
	// 位置を初期化.
	//int m_shotX;
	//int m_shotY;


	// エネミーが右移動しているかどうかのフラグをリセット
	bool enemyRightMove = true;
	// 弾が画面上に存在しているか保持する変数に『存在していない』を意味するfalseを代入しておく
	bool shotFlag = false;
	
	// 盤面の表示左上座標
	int m_fieldX;
	int m_fieldY;
	// プレイヤーフレームカウント
	//int m_PlayerFrameCount;
	// エネミーフレームカウント
	//int m_EnemyFrameCount;
	// ショットフレームカウント
	//int m_ShotFrameCount;

	// プレイヤー待機時間
	//int m_PlayerWaitingTime;
	// エネミー待機時間
	//int m_EnemyWaitingTime;

	//// 盤面サイズ
	//int m_FieldX;
	//int m_FieldY;

	// 盤面サイズ
	int kFieldX;
	int kFieldY;

	Player player;
	MovingBlock m_Block;
	
};

