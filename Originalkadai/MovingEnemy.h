#pragma once
//#include "Field.h"
//class Field;
class MovingEnemy
{
public:
	MovingEnemy();
	virtual ~MovingEnemy();
	virtual void init();
	virtual void Update();
	virtual void Draw();

	//　敵の座標(中心座標)
	virtual void setPos(float x, float y);

	// 敵のサイズ
	int size;

	// 敵の移動処理
	float MoveX;
	float MoveY;

	// 敵の位置
	int EnemyX;
	int EnemyY;

	// 敵の速度
	float speed;

	// ステージの番号
	float Number = 1;

	// 敵の向き
	float enemyRightMove = false;

	// 半分のサイズを算出
	float Dummy;
	float hsize;

	// 敵の次の動き
	float afterX;
	float afterY;

	float LeftX;	//　ブロックの左
	float TopY;	//　ブロックの上
	float RightX;	//　ブロックの右
	float BottomY;	//　ブロックのした

private:
	// フレームカウント
	int m_EnemyFrameCount;

	//Field* m_pField;
};

