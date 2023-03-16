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
	// タイトル背景
	int m_hBg;

	// テキスト点滅用フレームカウント
	int m_textBlinkFrame;
	// サウンド
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
