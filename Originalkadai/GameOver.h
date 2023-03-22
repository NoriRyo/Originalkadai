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

	// 現在のステージ数
	int CurrentStageNumber = 0;

	int Titleback = true;

	int Fieldback = true;
private:
	// タイトル背景
	int m_hBg;
	
	// テキスト点滅用フレームカウント
	int m_textBlinkFrame;

	// サウンド
	int ENDBGMHandle;
};
