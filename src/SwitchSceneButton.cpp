#include "SwitchSceneButton.h"
#include "Game.h"

SwitchSceneButton::SwitchSceneButton() :Button(
	"../Assets/textures/switchSceneButton.png",
	"switchSceneButton",
	START_BUTTON, glm::vec2(Config::SCREEN_WIDTH/2 + 300, 600.0f)), m_isClicked(false)
{
}

SwitchSceneButton::~SwitchSceneButton()
{
}

bool SwitchSceneButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			Game::Instance()->getScene()->switchScene();
			m_isClicked = true;
		}
		return true;
	}
	else
	{
		m_isClicked = false;
	}
}
