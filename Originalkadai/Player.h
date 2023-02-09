#pragma once
class Player
{
public:
	// �萔��`

	// �v���C���[�O���t�B�b�N������
	static constexpr int kGraphicDivX = 4;
	static constexpr int kGraphicDivY = 4;
	static constexpr int kGraphicDivNum = kGraphicDivX * kGraphicDivY;

	// �v���C���[�O���t�B�b�N�T�C�Y
	static constexpr int kGraphicSizeX = 48;
	static constexpr int kGraphicSizeY = 48;
public:
	Player();
	virtual ~Player();
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


	// �O���t�B�b�N�f�[�^�ݒ�
	void setHandle(int index, int handle) { m_handle[index] = handle; }


private:
	int m_handle[kGraphicDivNum];

	// �L�����N�^�[�̃A�j���[�V����
	int m_animeNo;	//�@�\������ԍ�
	int m_animeFrame;
	int m_dirNo;	// �i�s����
};

