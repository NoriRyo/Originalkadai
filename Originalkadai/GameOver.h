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
	// タイトル背景
	int m_hBg;

	// テキスト点滅用フレームカウント
	int m_textBlinkFrame;

	// サウンド
	int ENDBGMHandle;
	Field m_field;
};
