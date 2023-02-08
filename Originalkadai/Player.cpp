#include "Player.h"

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

	size = 40;
	speed = 5.0f;
	Dummy = 0.0f;
}

void Player::Update()
{
}

void Player::Draw()
{
}
