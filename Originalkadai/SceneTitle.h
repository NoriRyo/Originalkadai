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
	// タイトル背景
	int m_backgroundGraphic0;
	int m_backgroundGraphic1;
	int m_backgroundGraphic2;
	int m_backgroundGraphic3;
	int m_backgroundGraphic4;
	int m_backgroundGraphic5;
	int m_backgroundGraphic6;
	int m_backgroundGraphic7;
	int m_handle;
	//　表示する番号
	int m_animeNo;	
	// テキスト点滅用フレームカウント
	int m_textBlinkFrame;
	// 押されたかどうか
	int pressed = true;

	int m_CountFrame;

};
