#pragma once
class Player
{
public:

	void init();
	void Update();
	void Draw();

	// プレイヤーの座標(中心座標)
	float x;	
	float y;		

	// プレイヤーのサイズ
	int size;	

	// プレイヤーの移動処理
	float MoveX;
	float MoveY;

	// プレイヤーの速度
	float speed;	

	// 半分のサイズを算出
	float Dummy;
	float hsize;	

	// プレイヤーの次の動き
	float afterX;	
	float afterY;

private:

};

