#include "CharacterSelect.h"
#include "DxLib.h"
#include "SceneTitle.h"

CharacterSelect::CharacterSelect()
{
}

void CharacterSelect::init()
{
}

void CharacterSelect::end()
{
}

SceneBase* CharacterSelect::update()
{

	if (CheckHitKey(KEY_INPUT_2))
	{
		m_field.setPlayerNo(2);
	}
	if (CheckHitKey(KEY_INPUT_3))
	{
		m_field.setPlayerNo(3);
	}
	if (CheckHitKey(KEY_INPUT_4))
	{
		m_field.setPlayerNo(4);
	}
	if (CheckHitKey(KEY_INPUT_5))
	{
		m_field.setPlayerNo(5);
	}
	if (CheckHitKey(KEY_INPUT_6))
	{
		m_field.setPlayerNo(6);
	}
	if (CheckHitKey(KEY_INPUT_7))
	{
		m_field.setPlayerNo(7);
	}
	
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (isFading())
	{
		bool isOut = isFadingOut();
		SceneBase::updateFade();
		// フェードアウト終了時にシーン切り替え
		if (!isFading() && isOut)
		{
			return (new SceneTitle);
		}
	}
	if (!isFading())
	{
		if (padState & PAD_INPUT_1)
		{
			// フェードアウト開始
			startFadeOut();
		}
	}

	return this;
}

void CharacterSelect::draw()
{
	clsDx();
	DrawBox(10, 10,100,100, GetColor(255, 0, 0), false);
	SceneBase::drawFade();
}
