#pragma once

namespace Game
{
#ifdef _DEBUG
	// ウィンドーモード設定
	constexpr bool kWindowMode = true;
#else
	constexpr bool kWindowMode = false;
#endif
	// ウィンドウ名
	const char* const kTitleText = "AdventureOfCat";
	// ウィンドウサイズ
	constexpr int kScreenWidth = 1600;
	constexpr int kScreenHeight = 900;
	// カラーモード
	constexpr int kColorDepth = 32;


};