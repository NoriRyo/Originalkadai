#include "DxLib.h"
#include "game.h"
#include "SceneTitle.h"
#include "Field.h"
#include "GameMain.h"
#include "Door.h"

namespace
{
	// �\�����镶����
	const char* const kTitleText = "�Q�[���^�C�g��";
	const char* const kGuideText = "A�������Ă�������";
	// ������_��
	constexpr int kTextDispFrame = 45;
	constexpr int kTextHideFrame = 15;

	// �����F
	const int kTitleFontColor = GetColor(255, 0, 0);

	const int kFontColor = GetColor(255, 255, 255);

	const char* const kDoorGraphicFilename = "data/door.png";

}

void SceneTitle::init()
{
	m_textBlinkFrame = 0;
	SetFontSize(32);
	for (auto& doorHandle : m_hDoorGraphic)
	{
		doorHandle = -1;
	}
	// �h�A
	LoadDivGraph(kDoorGraphicFilename, Door::kDoorGraphicDivNum,
		Door::kGraphicDivX, Door::kGraphicDivY,
		Door::kGraphicSizeX, Door::kGraphicSizeY, m_hDoorGraphic);

	for (int i = 0; i < Door::kDoorGraphicDivNum; i++)
	{
		door.setHandle(i, m_hDoorGraphic[i]);
	}
	door.init();
	//m_hBg = LoadGraph("Data/titleBg1.jpg");
}

void SceneTitle::end()
{
	SetFontSize(16);
	for (auto& handle : m_hDoorGraphic)
	{
		DeleteGraph(m_hDoorGraphic[2]);
	}
}

SceneBase* SceneTitle::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	door.Update();

	if (isFading())
	{
		bool isOut = isFadingOut();
		SceneBase::updateFade();
		// �t�F�[�h�A�E�g�I�����ɃV�[���؂�ւ�
		if (!isFading() && isOut)
		{
			door.m_animeNo = 0;
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
			// �����J����
			if (door.OpenCount == 0)
			{
				door.OpenDoor = false;
				
			}
		}
		if (door.m_animeNo == 13)
		{
			// �t�F�[�h�A�E�g�J�n
			startFadeOut();
			
		}
	}
	return this;
}

void SceneTitle::draw()
{
	int Expansion = 150;	// �g��
	DrawExtendGraph(Game::kScreenWidth / 2 - Expansion, 460 - Expansion,
		Game::kScreenWidth / 2 + Expansion, 460 + Expansion, door.m_handle[door.m_animeNo], true);


	int width = GetDrawStringWidth(kTitleText, static_cast<int>(strlen(kTitleText)));
	DrawString(Game::kScreenWidth / 2 - width / 2, 160, kTitleText, kTitleFontColor);

	if (m_textBlinkFrame < kTextDispFrame)
	{
		width = GetDrawStringWidth(kGuideText, static_cast<int>(strlen(kGuideText)));
		DrawString(Game::kScreenWidth / 2 - width / 2, 280, kGuideText, kFontColor);
	}

	SceneBase::drawFade();
}