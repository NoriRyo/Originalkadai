#pragma once
class Door
{
public:
	// �萔��`

	// �h�A�O���t�B�b�N������
	static constexpr int kGraphicDivX = 14;
	static constexpr int kGraphicDivY = 1;
	static constexpr int kDoorGraphicDivNum = kGraphicDivX * kGraphicDivY;

	// �h�A�O���t�B�b�N�T�C�Y
	static constexpr int kGraphicSizeX = 48;
	static constexpr int kGraphicSizeY = 48;
public:
	Door();
	virtual ~Door();
	void init();
	void Update();
	void Draw();

	// �O���t�B�b�N�f�[�^�ݒ�
	void setHandle(int index, int handle) { m_handle[index] = handle; }

	float x;
	float y;

	// �����J������
	int OpenCount = 0;

	int OpenDoor = true;

	int m_handle[kDoorGraphicDivNum];

	// �L�����N�^�[�̃A�j���[�V����
	int m_animeNo;	//�@�\������ԍ�
	int m_animeFrame;
	int m_dirNo;	// �i�s����
private:
};

