#pragma once
#include "Field.h"
#include "SceneBase.h"

class GameOver : public SceneBase
{
public:
	GameOver()
	{
		m_hBg = -1;
		m_textBlinkFrame = 0;
	}
	virtual ~GameOver() {}


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
	int ENDBGMHandle;
	Field m_field;
};
