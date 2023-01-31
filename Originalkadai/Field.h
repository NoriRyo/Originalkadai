#pragma once
class Field
{
public:
	// 盤面サイズ
	static constexpr int kFieldX = 16;
	static constexpr int kFieldY = 12;
	// マスのサイズ
	static constexpr int kSize = 48;
public:
	Field();
	virtual ~Field();
	void init();
	void update();
	void draw();
private:
	// プレイヤーの位置
	int m_playerX;	
	int m_playerY;
	// エネミーの位置
	int m_MovingEnemyX;
	int m_MovingEnemyY;
	// 動かせるブロックの位置
	int m_MovingBlockX;
	int m_MovingBlockY;
	// 石の位置
	int m_StoneX;
	int m_StoneY;
	// 位置を初期化.
	int m_shotX;
	int m_shotY;

	// エネミーが右移動しているかどうかのフラグをリセット
	bool enemyRightMove = true;
	// 弾が画面上に存在しているか保持する変数に『存在していない』を意味するfalseを代入しておく
	bool shotFlag = false;
	// 現在の盤面データ
	int m_field[kFieldY][kFieldX];
	// 盤面の表示左上座標
	int m_fieldX;
	int m_fieldY;
	// プレイヤーフレームカウント
	int m_PlayerFrameCount;
	// エネミーフレームカウント
	int m_EnemyFrameCount;
	// ショットフレームカウント
	int m_ShotFrameCount;

	// プレイヤー待機時間
	int m_PlayerWaitingTime;
	// エネミー待機時間
	int m_EnemyWaitingTime;

	// 盤面サイズ
	int m_FieldX;
	int m_FieldY;
};

