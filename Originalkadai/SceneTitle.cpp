#include "DxLib.h"
#include "game.h"
#include "SceneTitle.h"
#include "Field.h"

namespace
{
	// 表示する文字列
	const char* const kTitleText = "Adventure Of Cat";
	const char* const kGuideText = "Start(A)";
	// 文字列点滅
	constexpr int kTextDispFrame = 64;
	constexpr int kTextHideFrame = 15;

	// 文字色
	const int kTitleFontColor = GetColor(255, 0, 0);

	const int kFontColor = GetColor(255, 255, 255);

}

void SceneTitle::init()
{
	m_backgroundGraphic0 = LoadGraph("data/title/background0.png");
	m_backgroundGraphic1 = LoadGraph("data/title/background1.png");
	m_backgroundGraphic2 = LoadGraph("data/title/background2.png");
	m_backgroundGraphic3 = LoadGraph("data/title/background3.png");
	m_backgroundGraphic4 = LoadGraph("data/title/background4.png");
	m_backgroundGraphic5 = LoadGraph("data/title/background5.png");
	m_backgroundGraphic6 = LoadGraph("data/title/background6.png");
	m_backgroundGraphic7 = LoadGraph("data/title/background7.png");
	m_textBlinkFrame = 0;
	m_handle = 0;
	m_animeNo = 0;
	m_CountFrame = 0;
	// サウンド
	BGMHandle = LoadSoundMem("sound/BGM.wav");
	TitleSHandle = LoadSoundMem("sound/Title.wav");
	//　音量
	TitleVolume = 100;
	ChangeVolumeSoundMem(255 * 75 / 100, BGMHandle); //ボリューム調整

	PlaySoundMem(BGMHandle, DX_PLAYTYPE_LOOP);
}

void SceneTitle::end()
{
	SetFontSize(16);
}

SceneBase* SceneTitle::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (m_animeNo == 0)
	{
		m_handle = m_backgroundGraphic0;
	}
	if (m_animeNo == 1)
	{
		m_handle = m_backgroundGraphic1;
	}
	if (m_animeNo == 2)
	{
		m_handle = m_backgroundGraphic2;
	}
	if (m_animeNo == 3)
	{
		m_handle = m_backgroundGraphic3;
	}
	if (m_animeNo == 4)
	{
		m_handle = m_backgroundGraphic4;
	}
	if (m_animeNo == 5)
	{
		m_handle = m_backgroundGraphic5;
	}
	if (m_animeNo == 6)
	{
		m_handle = m_backgroundGraphic6;
	}
	if (m_animeNo >= 7)
	{
		m_handle = m_backgroundGraphic7;
	}
	

	if (isFading())
	{
		bool isOut = isFadingOut();
		SceneBase::updateFade();
		// フェードアウト終了時にシーン切り替え
		if (!isFading() && isOut)
		{
			return (new Field);
		}
	}
	// テキストの点滅
	m_textBlinkFrame++;
	if (m_textBlinkFrame >= kTextDispFrame + kTextHideFrame)
	{
		m_textBlinkFrame = 0;
	}
	if (!isFading())
	{
		if (padState & PAD_INPUT_1)
		{
			pressed = false;
			PlaySoundMem(TitleSHandle, DX_PLAYTYPE_BACK);
		}
		if (pressed == false)
		{
			// 扉を開く
			m_CountFrame++;
			if (m_CountFrame >= 12)
			{
				if (!(m_animeNo >= 6))
				{
					m_animeNo++;
					m_CountFrame = 0;
				}

			}
		}
		if (m_animeNo >= 1)
		{
			TitleVolume--;
			ChangeVolumeSoundMem(255 * TitleVolume / 100, TitleSHandle);
			ChangeVolumeSoundMem(255 * TitleVolume / 100, BGMHandle);
			if (TitleVolume == 20)
			{
				// フェードアウト開始
				startFadeOut();
			}
		}
	}
	return this;
}

void SceneTitle::draw()
{

	int m_backgroundGraphicUP = LoadGraph("data/title/backgroundUP.png");
	int button = LoadGraph("data/button.png");
	int button1 = LoadGraph("data/button1.png");
	DrawGraph(0, 0, m_handle, false);
	DrawGraph(0, 0, m_backgroundGraphicUP, false);
	int Expansion = 150;	// 拡大
	//ChangeFont("Algerian");
	ChangeFont("MS Serif");
	
	//int fontHandle = CreateFontToHandle("Showcard Gothic", 64, -1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
	SetFontSize(64);
	int width = GetDrawStringWidth(kTitleText, static_cast<int>(strlen(kTitleText)));
	//DrawString(Game::kScreenWidth / 2 - width / 2, 160, kTitleText, kTitleFontColor);

	int GuideWidth = GetDrawStringWidth(kGuideText, static_cast<int>(strlen(kGuideText)));
	if (pressed == true)
	{
		if (m_textBlinkFrame < kTextDispFrame)
		{
			SetFontSize(46);
			DrawString(Game::kScreenWidth / 2 - GuideWidth / 2, 680, kGuideText, kFontColor);
			DrawExtendGraph(Game::kScreenWidth / 2 + GuideWidth / 3, 680, (Game::kScreenWidth / 2 + GuideWidth / 3) + 64, 680 + 64, button, true);
		}
		else
		{
			DrawExtendGraph(Game::kScreenWidth / 2 + GuideWidth / 3, 680, (Game::kScreenWidth / 2 + GuideWidth / 3) + 64, 680 + 64, button1, true);
		}
	}
	
	SceneBase::drawFade();
}