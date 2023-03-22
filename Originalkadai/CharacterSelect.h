#pragma once
#include "SceneBase.h"
#include "Field.h"
class CharacterSelect : public SceneBase
{
public:
	CharacterSelect();

	virtual ~CharacterSelect() {}


	virtual void init() override;
	virtual void end() override;

	virtual SceneBase* update() override;
	virtual void draw() override;

private:
	Field m_field;
};

