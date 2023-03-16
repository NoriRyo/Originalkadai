#pragma once
#include "Field.h"
#include "SceneBase.h"

class GameClear : public SceneBase
{
public:
	GameClear()
	{
		m_hBg = -1;
		m_textBlinkFrame = 0;
	}
	virtual ~GameClear() {}


	virtual void init() override;
	virtual void end() override;

	virtual SceneBase* update() override;
	virtual void draw() override;
private:
	// �^�C�g���w�i
	int m_hBg;

	// �e�L�X�g�_�ŗp�t���[���J�E���g
	int m_textBlinkFrame;
	// �T�E���h
	int ClearBGMHandle;
	Field m_field;

	int gameScreen;
	int effectScreen;

	int charX;
	int charY;

	int byteCount;

	int fontHandle;

	float sinRate;

	float TextSinRate;

	float tempSin;
};
