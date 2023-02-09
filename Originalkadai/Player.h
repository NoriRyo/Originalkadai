#pragma once
class Player
{
public:
	// 定数定義

	// プレイヤーグラフィック分割数
	static constexpr int kGraphicDivX = 4;
	static constexpr int kGraphicDivY = 4;
	static constexpr int kGraphicDivNum = kGraphicDivX * kGraphicDivY;

	// プレイヤーグラフィックサイズ
	static constexpr int kGraphicSizeX = 48;
	static constexpr int kGraphicSizeY = 48;
public:
	Player();
	virtual ~Player();
	void init();
	void Update();
	void Draw();

	// プレイヤーの座標(中心座標)
	float x;	
	float y;		

	// プレイヤーのサイズ
	int size;	

	// プレイヤーの移動処理
	float MoveX;
	float MoveY;

	// プレイヤーの速度
	float speed;	

	// 半分のサイズを算出
	float Dummy;
	float hsize;	

	// プレイヤーの次の動き
	float afterX;	
	float afterY;


	float LeftX;	//　ブロックの左
	float TopY;	//　ブロックの上
	float RightX;	//　ブロックの右
	float BottomY;	//　ブロックのした


	// グラフィックデータ設定
	void setHandle(int index, int handle) { m_handle[index] = handle; }


private:
	int m_handle[kGraphicDivNum];

	// キャラクターのアニメーション
	int m_animeNo;	//　表示する番号
	int m_animeFrame;
	int m_dirNo;	// 進行方向
};

