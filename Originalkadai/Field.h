#pragma once
#include "Player.h"
class Field
{
private:
	static constexpr int kFieldX = 13;
	static constexpr int kFieldY = 13;

public:
	Field();
	virtual ~Field();
	virtual void init();
	// 終了処理
	void end();

	virtual void update();

	// マップとの当たり判定
	int BlockHitCheck(float X, float Y, float& MoveX, float& MoveY);
	// マップチップの値を取得する関数
	int GetChipParam(float X, float Y);

	virtual void draw();
	

private:
	// 盤面の表示左上座標
	int m_fieldX;
	int m_fieldY;
	// ハートの数
	int HeartCount;
	// ステージの数
	int StageNumber = 1;

	// 鍵を持ってるかどうか
	int KeyGet;
	
	char m_field[13][13];

	// プレイヤーのグラフィックハンドル
	int m_hPlayerGraphic[Player::kGraphicDivNum];
	// プレイヤー
	Player player;
	
};