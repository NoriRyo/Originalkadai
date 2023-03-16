#include "Door.h"
#include "Game.h"
#include "DxLib.h"

namespace
{
	// キャラクターのサイズ
	constexpr int kSizeX = 48;
	constexpr int kSizeY = 48;
	// キャラクターアニメーション1コマあたり
	constexpr int kAinmeChangeFrame = 8;

	constexpr int m_fieldX((Game::kScreenWidth / 2) / 2);
	constexpr int m_fieldY(124);
	int GHandle;
	
}
Door::Door()
{
	// 初期化
	for (auto& handle : m_handle)
	{
		handle = -1;
	}
	m_animeNo = 0;
	m_animeFrame = 0;
	m_dirNo = 0;
	DoorSHandle = LoadSoundMem("sound/Title.wav");
}

Door::~Door()
{
}

void Door::init()
{
	m_animeNo = 0;
	m_animeFrame = 0;
	m_dirNo = 0;
	OpenDoor = true;
	OpenCount = 0;
	ChangeVolumeSoundMem(255 * 50 / 100, DoorSHandle);
}

void Door::Update()
{
	if (OpenDoor == false)
	{
		PlaySoundMem(DoorSHandle, DX_PLAYTYPE_BACK);
		//printfDx("扉\n");
		m_animeFrame++;
		if (m_animeFrame >= kGraphicDivX * kAinmeChangeFrame)
		{
			m_animeFrame = 0;
			if (m_animeNo == 13)
			{
				m_animeNo = 13;
				OpenCount =+1;
				OpenDoor = true;
				StopSoundMem(DoorSHandle);
			}
		}
		if (OpenDoor == false)
		{
			int tenpAnimeNo = m_animeFrame / kAinmeChangeFrame;
				m_animeNo = m_dirNo * kGraphicDivX + tenpAnimeNo;
		}
	}
	
	
}

void Door::Draw()
{
	//DrawGraph(static_cast<int>(x), static_cast<int>(y), m_handle[m_animeNo], true);
	//DrawGraph(10, 10, m_handle[m_animeNo], true);
}
