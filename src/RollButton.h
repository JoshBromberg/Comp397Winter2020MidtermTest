#pragma once
#ifndef __ROLL__
#define __ROLL__
#include "Button.h"
class RollButton : public Button {
public:
	RollButton();
	~RollButton();
	bool ButtonClick() override;
private:
	bool m_isClicked;
};
#endif