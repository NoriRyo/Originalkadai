#include "GameClear.h"
#include "DxLib.h"
#include "game.h"
#include "Field.h"
#include "SceneTitle.h"
#include "Vec2.h"
#include <string>

namespace
{
	// �\�����镶����
	const char* const kTitleText = "GAMECLEAR";
	const char* const kAText = "A->TITLE";
	const char* const kBText = "B->Return";
	// ������_��
	constexpr int kTextDispFrame = 60;
	constexpr int kTextHideFrame = 15;

	// �����F
	const int kTitleFontColor = GetColor(0, 0, 255);

	const int kFontColorA = GetColor(0, 255, 0);
	const int kFontColorB = GetColor(0, 0, 255);

	int Titleback = true;

	int Fieldback = true;

	constexpr int kParticleNum = 256;

	Vec2 pos[kParticleNum];
	Vec2 vec[kParticleNum];

	

	
}
void GameClear::init()
{
	m_textBlinkFrame = 0;
	SetFontSize(32);
	// �T�E���h
	ClearBGMHandle = LoadSoundMem("sound/CLEARBGM.wav");
	PlaySoundMem(ClearBGMHandle, DX_PLAYTYPE_LOOP);
	
	// �t�H���g
	fontHandle = CreateFontToHandle("Showcard Gothic", 64, -1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);

	
	SetAlwaysRunFlag(true);

	sinRate = 0.0f;

	gameScreen = LoadGraph("clear.png");
	effectScreen = MakeScreen(Game::kScreenWidth, Game::kScreenHeight, true);
	
	for (int i = 0; i < kParticleNum; i++)
	{
		pos[i].x = GetRand(Game::kScreenWidth);
		pos[i].y = -GetRand(Game::kScreenHeight);

		vec[i].x = 0.0f;
		vec[i].y = GetRand(20) + 20;
		vec[i].y /= 10.0f;
	}

	charX = 0;
	charY = 0;
	TextSinRate = 0.0f;

	byteCount = 0;	// �\������o�C�g���ɕϊ�����
}

void GameClear::end()
{
	SetFontSize(16);
	DeleteGraph(gameScreen);
	DeleteGraph(effectScreen);
}

SceneBase* GameClear::update()
{
	for (int i = 0; i < kParticleNum; i++)
	{
		pos[i] += vec[i];
		if (pos[i].y > Game::kScreenHeight)
		{
			pos[i].x = GetRand(Game::kScreenWidth);
			pos[i].y = 0.0f;

			vec[i].x = 0.0f;
			vec[i].y = GetRand(20) + 20;
			vec[i].y /= 10.0f;
		}
	}
	sinRate += 0.05f;

	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (isFading())
	{
		bool isOut = isFadingOut();
		SceneBase::updateFade();
		// �t�F�[�h�A�E�g�I�����ɃV�[���؂�ւ�
		if (!isFading() && isOut)
		{
			DeleteSoundMem(ClearBGMHandle);
			if (Titleback == false)
			{
				// �^�C�g���ɖ߂�
				Titleback = true;
				return (new SceneTitle);
			}
			if (Fieldback == false)
			{
				Fieldback = true;
				// �t�B�[���h�i�Q�[���j�ɖ߂�
				return (new Field);
			}
		}
	}
	// �e�L�X�g�̓_��
	m_textBlinkFrame++;
	if (m_textBlinkFrame >= 100)
	{
		m_textBlinkFrame = 0;
	}
	if (!isFading())
	{
		if (padState & PAD_INPUT_1)
		{
			Titleback = false;
			// �t�F�[�h�A�E�g�J�n
			startFadeOut();
		}
		if (padState & PAD_INPUT_2)
		{
			Fieldback = false;
			// �t�F�[�h�A�E�g�J�n
			startFadeOut();
		}
	}

	TextSinRate += 0.05f;

	return this;
}

void GameClear::draw()
{
	SetDrawScreen(effectScreen);
	ClearDrawScreen();
	BeginAADraw();
	for (int i = 0; i < kParticleNum; i++)
	{
		float rate = (vec[i].length() / 4.0f);
		//	DrawCircleAA(pos[i].x, pos[i].y, 4 * rate, 32, 0x808020, true);
			// �����̂���(�������x���x������)�͏������A�Â��`�悷��
		DrawCircleAA(pos[i].x, pos[i].y, 4 * rate, 32, GetColor(128 * rate, 128 * rate, 32 * rate), true);
	}
	EndAADraw();
	SetDrawScreen(DX_SCREEN_BACK);
	// ��ʂ̃N���A
	ClearDrawScreen();

	DrawExtendGraph(0, 0, Game::kScreenWidth, Game::kScreenHeight, gameScreen, false);

	//���Z��������
	SetDrawBlendMode(DX_BLENDMODE_ADD, 192);

	DrawGraph(0, 0, effectScreen, true);
	//��ʂ��ڂ���
	GraphFilter(effectScreen, DX_GRAPH_FILTER_GAUSS, 16, 800);
	for (int i = 0; i < 8; i++)
	{
		DrawGraph(GetRand(4) - 2, GetRand(4) - 2, effectScreen, false);
	}

	GraphFilter(effectScreen, DX_GRAPH_FILTER_GAUSS, 32, 2400);
	for (int i = 0; i < 8; i++)
	{
		DrawGraph(GetRand(8) - 4, GetRand(8) - 4, effectScreen, false);
	}
	//���ɖ߂�
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	


	// �����\��

	byteCount = 0;	// �\������o�C�g���ɕϊ�����

	std::string temp = kTitleText;

	int width = GetDrawStringWidth(kTitleText, static_cast<int>(strlen(kTitleText)));
	charX = Game::kScreenWidth / 2 - width / 2;
	charY = 160;

	tempSin = TextSinRate;

	//DrawString(Game::kScreenWidth / 2 - width / 2, 160, kTitleText, kTitleFontColor);

	if (m_textBlinkFrame < 50)
	{
		//SetFontSize(46);
		width = GetDrawStringWidth(kAText, static_cast<int>(strlen(kAText)));
		DrawString(Game::kScreenWidth / 2 / 2 - width / 2, 580, kAText, kFontColorA);
	}
	else
	{
		width = GetDrawStringWidth(kBText, static_cast<int>(strlen(kBText)));
		DrawString(Game::kScreenWidth / 2 / 2 * 2.5, 580, kBText, kFontColorB);
	}
	while (1)
	{
		if (byteCount > temp.size())	break;
		unsigned char charData = temp[byteCount];	// �`�F�b�N���镶��
		int size = 0;
		if (charData < 0x80)
		{
			size = 1;
		}
		else
		{
			size = 2;
		}
		int moveX = 0;
		int moveY = sinf(tempSin) * 16.0f;
		tempSin += DX_PI_F;


		SetFontSize(64);
		
		DrawStringToHandle(charX + moveX + 2, charY + moveY + 2, temp.substr(byteCount, size).c_str(), 0xffffff, fontHandle);
		DrawStringToHandle(charX + moveX, charY + moveY, temp.substr(byteCount, size).c_str(), 0xffff00, fontHandle);
		charX += GetDrawStringWidthToHandle(temp.substr(byteCount, size).c_str(), size, fontHandle);
		byteCount += size;

	}









	SceneBase::drawFade();
}