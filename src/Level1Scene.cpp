#include "Level1Scene.h"
#include "Game.h"
#include "SwitchSceneButton.h"

Level1Scene::Level1Scene()
{
	start();
}

Level1Scene::~Level1Scene()
{
}

void Level1Scene::draw()
{
	m_pBackground->draw();
	if (roll2) {
		m_pDice[0]->draw();
		m_pDice[1]->draw();
		m_pDiceLabel[0]->draw();
		m_pDiceLabel[1]->draw();
	}
	else {
		for (Image* i : m_pStats){
			i->draw();
		}
		for (Label* i : m_pStatsLabel) {
			i->draw();
		}
	}
	m_pSum->draw();
	m_pRoll->draw();
	m_pSwitchScene->draw();
}

void Level1Scene::update()
{
	m_pRoll->setMousePosition(m_mousePosition);
	m_pSwitchScene->setMousePosition(m_mousePosition);
	m_pRoll->ButtonClick();
	m_pSwitchScene->ButtonClick();
}

void Level1Scene::clean()
{
}

void Level1Scene::handleEvents()
{
	int wheel = 0;

	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch(event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pRoll->setMouseButtonClicked(true);
				m_pSwitchScene->setMouseButtonClicked(true);
				break;
			}
		
			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pRoll->setMouseButtonClicked(false);
				m_pSwitchScene->setMouseButtonClicked(false);
				break;
			}
			break;
		case SDL_MOUSEWHEEL:
			wheel = event.wheel.y;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			case SDLK_1:
				TheGame::Instance()->changeSceneState(SceneState::START_SCENE);
				break;
			case SDLK_2:
				TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
				break;
			

				/************************************************************************/
			case SDLK_w:
				
				break;
			case SDLK_s:
				
				break;
			case SDLK_a:

				break;
			case SDLK_d:

				break;
			}
			
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				
				break;

			case SDLK_s:
				
				break;

			case SDLK_a:

				break;
			case SDLK_d:

				break;
			}
			
			break;
		default:
			break;
		}
	}
}

void Level1Scene::start()
{
	m_pBackground = new Image("../Assets/textures/Background.jpg", "background");
	m_pDice[0] = new Image("../Assets/textures/Blank.png", "blank");
	m_pDice[0]->setPosition(glm::vec2((Config::SCREEN_WIDTH - 300) / 2, 300));
	m_pDice[1] = new Image("../Assets/textures/Blank.png", "blank");
	m_pDice[1]->setPosition(glm::vec2((Config::SCREEN_WIDTH + 300) / 2, 300));
	m_pDiceLabel[0] = new Label("blank", "Consolas", 20, { (0),(0),(0),(255) }, glm::vec2((Config::SCREEN_WIDTH - 300) /2, 425));
	m_pDiceLabel[1] = new Label("blank", "Consolas", 20, { (0),(0),(0),(255) }, glm::vec2((Config::SCREEN_WIDTH + 300) /2, 425));
	m_pSum = new Label("Sum: 0", "Consolas", 20, { (0),(0),(0),(255) }, glm::vec2(Config::SCREEN_WIDTH / 2, 500));
	m_pRoll = new RollButton();
	m_pSwitchScene = new SwitchSceneButton();
	addChild(m_pBackground);
	addChild(m_pDice[0]);
	addChild(m_pDice[1]);
	addChild(m_pDiceLabel[0]);
	addChild(m_pDiceLabel[1]);
	addChild(m_pSum);
	addChild(m_pRoll);
	addChild(m_pSwitchScene);
	for (int i = 0; i < 4; ++i) {
		m_pStatsLabel[i] = new Label("blank", "Consolas", 20, { (0),(0),(0),(255) }, glm::vec2((Config::SCREEN_WIDTH + (i * 600) - 900) / 2, 425));
		m_pStats[i] = new Image("../Assets/textures/Blank.png", "blank");
		m_pStats[i]->setPosition(glm::vec2((Config::SCREEN_WIDTH + (i*600)-900) / 2, 300));
		addChild(m_pStats[i]);
		addChild(m_pStatsLabel[i]);
	}
}

glm::vec2 Level1Scene::getMousePosition()
{
	return m_mousePosition;
}

void Level1Scene::roll()
{
	int iterations = roll2 ? 2 : 4;
	int total = 0;
	int savedValues[4] = { 0,0,0,0 };
	for (int z = 0; z < iterations; ++z) {
		if (roll2) {
			diceRoll[z] = Util::RandomRange(1, 6);
			m_pDice[z] = new Image("../Assets/textures/" + std::to_string(diceRoll[z]) + ".png", std::to_string(diceRoll[z]));
			m_pDice[z]->setPosition(glm::vec2((Config::SCREEN_WIDTH - 300+(z*600)) / 2, 300));
			m_pDiceLabel[z]->setText(std::to_string(diceRoll[z]));
			total += diceRoll[z];
		}
		else {
			statRoll[z] = Util::RandomRange(1, 6);
			m_pStats[z] = new Image("../Assets/textures/" + std::to_string(statRoll[z]) + ".png", std::to_string(statRoll[z]));
			m_pStats[z]->setPosition(glm::vec2((Config::SCREEN_WIDTH + (z * 600) - 900) / 2, 300));
			m_pStatsLabel[z]->setText(std::to_string(statRoll[z]));
			total += statRoll[z];
			savedValues[z] = statRoll[z];
		}
	}
	if (!roll2) {
		int i = 6;
		for (int s : savedValues) {
			if (s < i) {
				i = s;
			}
		}
		total -= i;
	}
	m_pSum->setText("Sum: " + std::to_string(total));
}

void Level1Scene::switchScene()
{
	roll2 = roll2 ? false : true;
	/*if (roll2) {

	}
	else {
		for (int i = 0; i < 4; ++i) {
			m_pStats[i]->setPosition(glm::vec2((Config::SCREEN_WIDTH + (i * 600) - 900) / 2, 300));
		}
	}*/
}

