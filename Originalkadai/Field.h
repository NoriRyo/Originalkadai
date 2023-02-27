#pragma once
#include "Player.h"
#include "MovingEnemy.h"
#include "Door.h"
#include "SceneBase.h"
class Field : public SceneBase
{
private:
	static constexpr int kFieldX = 13;
	static constexpr int kFieldY = 13;

public:
	Field();
	virtual ~Field();
	virtual void init()override;
	// 終了処理
	void end()override;

	virtual SceneBase* update()override;

	// マップとの当たり判定
	int EnemyBlockHitCheck(float enemyX, float enemyY, float& enemyMoveX, float& enemyMoveY);
	// マップチップの値を取得する関数
	int GetChipParam(float X, float Y);

	virtual void draw()override;

	

private:
	// 盤面の表示左上座標
	int m_fieldX;
	int m_fieldY;
	// ハートの数
	int HeartCount;
	// 宝箱の数
	int TreasureCount;
	// ステージの数
	int StageNumber = 1;

	// 鍵を持ってるかどうか
	int KeyGet = 12;
	// プレイヤーに当たっているかどうか
	int playerHit = 13;
	// 壁に当たっているかどうか
	int WallHit = 15;
	// 敵が当たっているかどうか
	int EnemyHit = 16;
	// 箱に当たっているかどうか
	int BooxHit = 17;

	int PlayerCount = 0;
	
	char m_field[13][13];

	// プレイヤーのグラフィックハンドル
	int m_hPlayerGraphic[Player::kPlayerGraphicDivNum];
	// プレイヤーの爆発グラフィックハンドル
	int m_hExplosionGraphic[Player::kExplosionGraphicDivNum];
	// プレイヤー
	Player player;
	//	生きているかどうか
	int death = true;
	// 扉のグラフィックハンドル
	int m_hDoorGraphic[Door::kDoorGraphicDivNum];
	// 扉
	Door door;

	// 動く敵
	MovingEnemy mEnemy;

	MovingEnemy mEnemy2;
	
};