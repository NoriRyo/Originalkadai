#pragma once
class Player
{
public:

	void init();
	void Update();
	void Draw();

	// �v���C���[�̍��W(���S���W)
	float x;	
	float y;		

	// �v���C���[�̃T�C�Y
	int size;	

	// �v���C���[�̈ړ�����
	float MoveX;
	float MoveY;

	// �v���C���[�̑��x
	float speed;	

	// �����̃T�C�Y���Z�o
	float Dummy;
	float hsize;	

	// �v���C���[�̎��̓���
	float afterX;	
	float afterY;


	float LeftX;	//�@�u���b�N�̍�
	float TopY;	//�@�u���b�N�̏�
	float RightX;	//�@�u���b�N�̉E
	float BottomY;	//�@�u���b�N�̂���

private:

};
