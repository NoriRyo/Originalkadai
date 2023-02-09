#include "GameMain.h"
#include "Field.h"

GameMain::GameMain()
{
	m_pField = new Field;
}

GameMain::~GameMain()
{
	delete m_pField;	// ƒƒ‚ƒŠ‚ğ‰ğ•ú
}

void GameMain::init()
{
	//player.init();
	m_pField->init();
}

void GameMain::update()
{
	//player.Update();
	m_pField->update();
}

void GameMain::draw()
{
	//player.Draw();
	m_pField->draw();
}
