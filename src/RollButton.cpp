#include "RollButton.h"
#include "Game.h"

RollButton::RollButton() :Button(
	"../Assets/textures/rollButton.png",
	"rollButton",
	START_BUTTON, glm::vec2(Config::SCREEN_WIDTH/2, 600.0f)), m_isClicked(false)
{
}

RollButton::~RollButton()
{
}

bool RollButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			Game::Instance()->getScene()->roll();
			m_isClicked = true;
		}
		return true;
	}
	else
	{
		m_isClicked = false;
	}
}
