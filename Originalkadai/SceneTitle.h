#pragma once

#include "SceneBase.h"

class SceneTitle : public SceneBase
{
public:
	SceneTitle()
	{
		m_textBlinkFrame = 0;
	}
	virtual ~SceneTitle() {}

	virtual void init() override;
	virtual void end() override;

	virtual SceneBase* update() override;
	virtual void draw() override;
private:
	// �^�C�g���w�i
	int m_backgroundGraphic0;
	int m_backgroundGraphic1;
	int m_backgroundGraphic2;
	int m_backgroundGraphic3;
	int m_backgroundGraphic4;
	int m_backgroundGraphic5;
	int m_backgroundGraphic6;
	int m_backgroundGraphic7;
	int m_handle;
	//�@�\������ԍ�
	int m_animeNo;	
	// �e�L�X�g�_�ŗp�t���[���J�E���g
	int m_textBlinkFrame;
	// �����ꂽ���ǂ���
	int pressed = true;

	int m_CountFrame;

};
