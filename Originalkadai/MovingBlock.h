#pragma once
class MovingBlock
{
public:

	void init();
	void Update();
	void Draw();

	float	x, y;		//�@�u���b�N�̍��W(���S���W)
	float LeftX;	//�@�u���b�N�̍�
	float TopY;	//�@�u���b�N�̏�
	float RightX;	//�@�u���b�N�̉E
	float BottomY;	//�@�u���b�N�̂���
private:
};

