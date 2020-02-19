#pragma once
#ifndef __LEVEL_1_SCENE__
#define __LEVEL_1_SCENE__

#include "Scene.h"
#include "RollButton.h"
#include "Image.h"
#include "Label.h"

class Level1Scene : public Scene
{
	friend class SwitchSceneButton;
public:
	Level1Scene();
	~Level1Scene();
	
	void draw() override;
	void update() override;
	void clean() override;
	void handleEvents() override;
	void start() override;

	// getters
	glm::vec2 getMousePosition();

	//Dice Methods
	void roll();
	void switchScene();

private:
	// game objects



	// private data member
	glm::vec2 m_mousePosition;
	
	//Dice stuff
	bool roll2 = true;
	int diceRoll[2];
	int statRoll[4];
	Image* m_pDice[2];
	Image* m_pStats[4];
	Image* m_pBackground;
	Label* m_pDiceLabel[2];
	Label* m_pStatsLabel[4];
	Label* m_pSum;
	RollButton* m_pRoll;
	SwitchSceneButton* m_pSwitchScene;
};

#endif
