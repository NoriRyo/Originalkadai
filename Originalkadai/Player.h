#pragma once
class Player
{
public:
	// 定数定義
	// 爆発グラフィック分割数
	static constexpr int kExplosionGraphicDivX = 8;
	static constexpr int kExplosionGraphicDivY = 1;
	static constexpr int kExplosionGraphicDivNum = kExplosionGraphicDivX * kExplosionGraphicDivY;
	// 爆発グラフィックサイズ
	static constexpr int kExplosionGraphicSizeX = 48;
	static constexpr int kExplosionGraphicSizeY = 48;


	// プレイヤーグラフィック分割数
	static constexpr int kPlayerGraphicDivX = 3;
	static constexpr int kPlayerGraphicDivY = 4;
	static constexpr int kPlayerGraphicDivNum = kPlayerGraphicDivX * kPlayerGraphicDivY;
	// プレイヤーグラフィックサイズ
	static constexpr int kPlayerGraphicSizeX = 32;
	static constexpr int kPlayerGraphicSizeY = 32;
public:
	Player();
	virtual ~Player();
	void init();
	void Update();
	void Draw();

	// グラフィックデータ設定
	void PlayerSetHandle(int index, int handle) { m_PlayerHandle[index] = handle; }
	void ExplosionSetHandle(int index, int handle) { m_ExplosionHandle[index] = handle; }

	int m_PlayerHandle[kPlayerGraphicDivNum];
	int m_PlayerAnimeNo;	//　表示する番号

	int m_ExplosionHandle[kExplosionGraphicDivNum];
	int m_ExplosionAnimeNo;	//　表示する番号


	int m_dirNo;	// 進行方向

	int m_ExplosionDirNo;	// 進行方向

	bool isKey = false;	// キーを押しているかどうか

	// 爆発した回数
	int ExplosionCount = 0;

	int Explosion = true;
private:

	// キャラクターのアニメーション
	int m_PlayerAnimeFrame;

	// 爆発のアニメーション
	int m_ExplosionAnimeFrame;

	
};

