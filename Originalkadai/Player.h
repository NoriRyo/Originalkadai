#pragma once
class Player
{
public:
	// �萔��`
	// �����O���t�B�b�N������
	static constexpr int kExplosionGraphicDivX = 8;
	static constexpr int kExplosionGraphicDivY = 1;
	static constexpr int kExplosionGraphicDivNum = kExplosionGraphicDivX * kExplosionGraphicDivY;
	// �����O���t�B�b�N�T�C�Y
	static constexpr int kExplosionGraphicSizeX = 48;
	static constexpr int kExplosionGraphicSizeY = 48;


	// �v���C���[�O���t�B�b�N������
	static constexpr int kPlayerGraphicDivX = 3;
	static constexpr int kPlayerGraphicDivY = 4;
	static constexpr int kPlayerGraphicDivNum = kPlayerGraphicDivX * kPlayerGraphicDivY;
	// �v���C���[�O���t�B�b�N�T�C�Y
	static constexpr int kPlayerGraphicSizeX = 32;
	static constexpr int kPlayerGraphicSizeY = 32;
public:
	Player();
	virtual ~Player();
	void init();
	void Update();
	void Draw();

	// �O���t�B�b�N�f�[�^�ݒ�
	void PlayerSetHandle(int index, int handle) { m_PlayerHandle[index] = handle; }
	void ExplosionSetHandle(int index, int handle) { m_ExplosionHandle[index] = handle; }

	int m_PlayerHandle[kPlayerGraphicDivNum];
	int m_PlayerAnimeNo;	//�@�\������ԍ�

	int m_ExplosionHandle[kExplosionGraphicDivNum];
	int m_ExplosionAnimeNo;	//�@�\������ԍ�


	int m_dirNo;	// �i�s����

	int m_ExplosionDirNo;	// �i�s����

	bool isKey = false;	// �L�[�������Ă��邩�ǂ���

	// ����������
	int ExplosionCount = 0;

	int Explosion = true;
private:

	// �L�����N�^�[�̃A�j���[�V����
	int m_PlayerAnimeFrame;

	// �����̃A�j���[�V����
	int m_ExplosionAnimeFrame;

	
};

