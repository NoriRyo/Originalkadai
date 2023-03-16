#pragma once

namespace Game
{
#ifdef _DEBUG
	// �E�B���h�[���[�h�ݒ�
	constexpr bool kWindowMode = true;
#else
	constexpr bool kWindowMode = false;
#endif
	// �E�B���h�E��
	const char* const kTitleText = "AdventureOfCat";
	// �E�B���h�E�T�C�Y
	constexpr int kScreenWidth = 1600;
	constexpr int kScreenHeight = 900;
	// �J���[���[�h
	constexpr int kColorDepth = 32;


};