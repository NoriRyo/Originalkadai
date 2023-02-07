#pragma once
class MovingBlock
{
public:

	void init();
	void Update();
	void Draw();

	float	x, y;		//　ブロックの座標(中心座標)
	float LeftX;	//　ブロックの左
	float TopY;	//　ブロックの上
	float RightX;	//　ブロックの右
	float BottomY;	//　ブロックのした
private:
};

