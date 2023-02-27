#pragma once
class Door
{
public:
	// 定数定義

	// ドアグラフィック分割数
	static constexpr int kGraphicDivX = 14;
	static constexpr int kGraphicDivY = 1;
	static constexpr int kDoorGraphicDivNum = kGraphicDivX * kGraphicDivY;

	// ドアグラフィックサイズ
	static constexpr int kGraphicSizeX = 48;
	static constexpr int kGraphicSizeY = 48;
public:
	Door();
	virtual ~Door();
	void init();
	void Update();
	void Draw();

	// グラフィックデータ設定
	void setHandle(int index, int handle) { m_handle[index] = handle; }

	float x;
	float y;

	// 扉が開いた回数
	int OpenCount = 0;

	int OpenDoor = true;

	int m_handle[kDoorGraphicDivNum];

	// キャラクターのアニメーション
	int m_animeNo;	//　表示する番号
	int m_animeFrame;
	int m_dirNo;	// 進行方向
private:
};

