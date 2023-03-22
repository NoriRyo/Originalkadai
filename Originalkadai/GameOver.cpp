#include "GameOver.h"
#include "DxLib.h"
#include "game.h"
#include "Field.h"
#include "SceneTitle.h"

namespace
{
	// �\�����镶����
	const char* const kTitleText = "GAMEOVER";
	const char* const kGuideText = "A->Return";
	// ������_��
	constexpr int kTextDispFrame = 45;
	constexpr int kTextHideFrame = 15;

	// �����F
	const int kTitleFontColor = GetColor(255, 0, 0);

	const int kFontColor = GetColor(255, 255, 255);

	

}
void GameOver::init()
{
	m_textBlinkFrame = 0;
	SetFontSize(32);
	// �T�E���h
	ENDBGMHandle = LoadSoundMem("sound/ENDBGM.wav");
	PlaySoundMem(ENDBGMHandle, DX_PLAYTYPE_LOOP);
	
}

void GameOver::end()
{
	SetFontSize(16);
}

SceneBase* GameOver::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (isFading())
	{
		bool isOut = isFadingOut();
		SceneBase::updateFade();
		// �t�F�[�h�A�E�g�I�����ɃV�[���؂�ւ�
		if (!isFading() && isOut)
		{
			DeleteSoundMem(ENDBGMHandle);
			//if (Titleback == false)
			//{
			//	// �^�C�g���ɖ߂�
			//	Titleback = true;
			//	return (new SceneTitle);
			//}
			if (Fieldback == false)
			{
				// �t�B�[���h�i�Q�[���j�ɖ߂�
				Fieldback = true;
				return (new Field);
			}
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
			Fieldback = false;
			//Titleback = false;
			// �t�F�[�h�A�E�g�J�n
			startFadeOut();
		}
		//if (padState & PAD_INPUT_2)
		//{
		//	// �t�F�[�h�A�E�g�J�n
		//	startFadeOut();
		//}
	}
	return this;
}

void GameOver::draw()
{
	SetFontSize(64);
	int width = GetDrawStringWidth(kTitleText, static_cast<int>(strlen(kTitleText)));
	DrawString(Game::kScreenWidth / 2 - width / 2, 160, kTitleText, kTitleFontColor);

	if (m_textBlinkFrame < kTextDispFrame)
	{
		SetFontSize(46);
		width = GetDrawStringWidth(kGuideText, static_cast<int>(strlen(kGuideText)));
		DrawString(Game::kScreenWidth / 2 - width / 2, 580, kGuideText, kFontColor);
	}
	SceneBase::drawFade();
}
