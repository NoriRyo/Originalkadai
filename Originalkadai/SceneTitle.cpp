#include "DxLib.h"
#include "game.h"
#include "SceneTitle.h"
#include "Field.h"

namespace
{
	// �\�����镶����
	const char* const kTitleText = "Adventure Of Cat";
	const char* const kGuideText = "Start(A)";
	// ������_��
	constexpr int kTextDispFrame = 45;
	constexpr int kTextHideFrame = 15;

	// �����F
	const int kTitleFontColor = GetColor(255, 0, 0);

	const int kFontColor = GetColor(255, 255, 255);

}

void SceneTitle::init()
{
	PlaySoundFile("sound/BGM.wav", DX_PLAYTYPE_BACK + DX_PLAYTYPE_LOOP);
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
		// �t�F�[�h�A�E�g�I�����ɃV�[���؂�ւ�
		if (!isFading() && isOut)
		{
			return (new Field);
		}
	}
	// �e�L�X�g�̓_��
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
		}
		if (pressed == false)
		{
			// �����J��
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
		if (m_animeNo >= 6)
		{
			// �t�F�[�h�A�E�g�J�n
			startFadeOut();
		}
	}
	return this;
}

void SceneTitle::draw()
{
	
	DrawGraph(0, 0, m_handle, false);
	
	int Expansion = 150;	// �g��
	//ChangeFont("Algerian");
	ChangeFont("MS Serif");
	SetFontSize(64);
	int width = GetDrawStringWidth(kTitleText, static_cast<int>(strlen(kTitleText)));
	DrawString(Game::kScreenWidth / 2 - width / 2, 160, kTitleText, kTitleFontColor);

	if (m_textBlinkFrame < kTextDispFrame)
	{
		SetFontSize(46);
		width = GetDrawStringWidth(kGuideText, static_cast<int>(strlen(kGuideText)));
		DrawString(Game::kScreenWidth / 2 - width / 2, 680, kGuideText, kFontColor);
	}
	
	SceneBase::drawFade();
}