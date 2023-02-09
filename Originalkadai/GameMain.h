#pragma once
#include "Player.h"

class Field;
class GameMain
{
public:
	GameMain();
	virtual ~GameMain();

	void init();
	void update();
	void draw();
private:

	Player player;
	Field* m_pField;
};


