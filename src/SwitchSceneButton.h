#pragma once
#ifndef __SWITCHSCENE__
#define __SWITCHSCENE__
#include "Button.h"
class SwitchSceneButton : public Button {
public:
	SwitchSceneButton();
	~SwitchSceneButton();
	bool ButtonClick() override;
private:
	bool m_isClicked;
};
#endif // !__SWITCHSCENE__
