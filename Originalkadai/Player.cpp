#include "Player.h"
#include "DxLib.h"
#include "Game.h"
#include "GameOver.h"

namespace
{
	// キャラクターアニメーション1コマあたり
	constexpr int kAinmeChangeFrame = 8;

	constexpr int m_fieldX((Game::kScreenWidth / 2) / 2);
	constexpr int m_fieldY(124);

}

Player::Player()
{
	// 初期化
	for (auto& handle : m_PlayerHandle)
	{
		handle = -1;
	}
	m_PlayerAnimeNo = 0;
	m_PlayerAnimeFrame = 0;

	// 初期化
	for (auto& handle : m_ExplosionHandle)
	{
		handle = -1;
	}
	m_ExplosionAnimeNo = 0;
	m_ExplosionAnimeFrame = 0;


	m_dirNo = 0;
	m_ExplosionDirNo = 0;
}

Player::~Player()
{
}

void Player::init()
{
	Dummy = 0.0f;

	m_PlayerAnimeNo = 0;
	m_PlayerAnimeFrame = 0;

	m_ExplosionAnimeNo = 0;
	m_ExplosionAnimeFrame = 0;

	m_dirNo = 0;
	m_ExplosionDirNo = 0;
	ExplosionCount = 0;
	Explosion = true;
} 

void Player::Update()
{
	// キャラクターアニメーション
	if (isKey == true)
	{
		m_PlayerAnimeFrame++;
	}
	if (m_PlayerAnimeFrame >= kPlayerGraphicDivX * kAinmeChangeFrame)
	{
		m_PlayerAnimeFrame = 0;
	}

	int PlayertenpAnimeNo = m_PlayerAnimeFrame / kAinmeChangeFrame;
	m_PlayerAnimeNo = m_dirNo * kPlayerGraphicDivX + PlayertenpAnimeNo;


	// 爆発アニメーション
	if (Explosion == false)
	{
		m_ExplosionAnimeFrame++;
		if (m_ExplosionAnimeFrame >= kExplosionGraphicDivX * kAinmeChangeFrame)
		{
			m_ExplosionAnimeFrame = 0;
			if (m_ExplosionAnimeNo == 7)
			{
				m_ExplosionAnimeNo = 7;
				ExplosionCount = +1;
				Explosion = true;
			}
		}
		if (Explosion == false)
		{
			int ExplosiontenpAnimeNo = m_ExplosionAnimeFrame / kAinmeChangeFrame;
			m_ExplosionAnimeNo = m_ExplosionDirNo * kExplosionGraphicDivX + ExplosiontenpAnimeNo;
		}
	}
}

void Player::Draw()
{
	/*DrawBox((int)(m_fieldX + x - size * 0.5f), (int)(m_fieldY + y - size * 0.5f),
		(int)(m_fieldX + x + size * 0.5f) + 1, (int)(m_fieldY + y + size * 0.5f) + 1,
		GetColor(255, 0, 0), FALSE);
	
	DrawExtendGraph((m_fieldX + x - size * 1.0f), (m_fieldY + y - size - 10 * 1.0f),
		(m_fieldX + x + size * 1.0f), (m_fieldY + y + size - 10 * 1.0f),
		m_handle[m_animeNo], TRUE);*/

	//DrawGraph(0, 0, GHandle, TRUE);
	
	
	//DrawGraph(m_fieldX + x , m_fieldY + y , m_handle[m_animeNo], true);
}
