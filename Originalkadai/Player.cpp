#include "Player.h"
#include "DxLib.h"
#include "Game.h"

namespace
{
	// キャラクターのサイズ
	constexpr int kSizeX = 38;
	constexpr int kSizeY = 38;
	// キャラクターアニメーション1コマあたり
	constexpr int kAinmeChangeFrame = 8;

	constexpr int m_fieldX((Game::kScreenWidth / 2) / 2);
	constexpr int m_fieldY(124);
	int GHandle;

}

Player::Player()
{
	// 初期化
	for (auto& handle : m_handle)
	{
		handle = -1;
	}
	m_animeNo = 0;
	m_animeFrame = 0;
	m_dirNo = 0;
}

Player::~Player()
{
}

void Player::init()
{
	// プレイヤーの位置を初期化
	x = 72.0f;
	y = 552.0f;

	/*x = 60.0f;
	y = 550.0f;*/

	// 移動量の初期化
	MoveX = 0.0f;
	MoveY = 0.0f;

	size = 38;
	speed = 5.0f;
	Dummy = 0.0f;

	m_animeNo = 0;
	m_animeFrame = 0;
	m_dirNo = 0;

} 

void Player::Update()
{
	// パッド(もしくはキーボード)からの入力を取得する
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	bool isKey = false;
	if (padState & PAD_INPUT_UP)
	{
		m_dirNo = 1;
		isKey = true;
	}
	if (padState & PAD_INPUT_DOWN)
	{
		m_dirNo = 0;
		isKey = true;
	}
	if (padState & PAD_INPUT_LEFT)
	{
		m_dirNo = 2;
		isKey = true;
	}
	if (padState & PAD_INPUT_RIGHT)
	{
		m_dirNo = 3;
		isKey = true;
	}

	// キャラクターアニメーション
	if (isKey) m_animeFrame++;
	if (m_animeFrame >= kGraphicDivX * kAinmeChangeFrame)
	{
		m_animeFrame = 0;
	}

	int tenpAnimeNo = m_animeFrame / kAinmeChangeFrame;
	m_animeNo = m_dirNo * kGraphicDivX + tenpAnimeNo;
}

void Player::Draw()
{
	DrawBox((int)(m_fieldX + x - size * 0.5f), (int)(m_fieldY + y - size * 0.5f),
		(int)(m_fieldX + x + size * 0.5f) + 1, (int)(m_fieldY + y + size * 0.5f) + 1,
		GetColor(255, 0, 0), FALSE);
	
	DrawExtendGraph((m_fieldX + x - size * 1.8f), (m_fieldY + y - size * 1.8f), 
		//(m_fieldX + x  + 100.0f), (m_fieldY + y + 100.0f),
		(m_fieldX + x + size * 1.8f), (m_fieldY + y + size * 1.8f),
		m_handle[m_animeNo], TRUE);

	//DrawGraph(0, 0, GHandle, TRUE);
	
	
	//DrawGraph(static_cast<int>(x), static_cast<int>(y), m_handle[m_animeNo], true);
}
