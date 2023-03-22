#pragma once
#include "SceneBase.h"

class GameOver : public SceneBase
{
public:
	GameOver()	:
		CurrentStageNumber()
	{
		m_hBg = -1;
		m_textBlinkFrame = 0;
		ENDBGMHandle = 0;
	}
	virtual ~GameOver() {}


	virtual void init() override;
	virtual void end() override;

	virtual SceneBase* update() override;
	virtual void draw() override;

	// ���݂̃X�e�[�W��
	int CurrentStageNumber = 0;

	int Titleback = true;

	int Fieldback = true;
private:
	// �^�C�g���w�i
	int m_hBg;
	
	// �e�L�X�g�_�ŗp�t���[���J�E���g
	int m_textBlinkFrame;

	// �T�E���h
	int ENDBGMHandle;
};
