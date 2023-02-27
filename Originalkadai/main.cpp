#include "DxLib.h"

#include "Game.h"

#include "SceneManager.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// Windowモード設定
	ChangeWindowMode(Game::kWindowMode);
	// ウィンドー名設定
	SetMainWindowText(Game::kTitleText);
	// 画面サイズ設定
	SetGraphMode(Game::kScreenWidth, Game::kScreenHeight, Game::kColorDepth);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	// ダブルバッファモード
	SetDrawScreen(DX_SCREEN_BACK);

	SceneManager scene;
	scene.init();

	//------------------------------------------------------
	// ゲーム部分
	//------------------------------------------------------
	// メインループ処理
	while (ProcessMessage() == 0)
	{
		LONGLONG time = GetNowHiPerformanceCount();
		// 画面のクリア
		ClearDrawScreen();

		scene.update();

		scene.draw();

		// 裏画面を表画面を入れ替える
		ScreenFlip();

		if (CheckHitKey(KEY_INPUT_ESCAPE)) break;

		while (GetNowHiPerformanceCount() - time < 16667)
		{

		}
	}

	scene.end();

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}