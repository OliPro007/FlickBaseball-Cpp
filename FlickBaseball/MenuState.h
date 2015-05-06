#pragma once
#include "IGameState.h"
#include "Button.h"
#include <vector>

namespace fbb {

class MenuState : public fbb::IGameState {
public:
	MenuState();
	~MenuState();

	virtual void init();
	virtual void draw();
	virtual void update();

private:
	std::vector<fbb::Button> buttonList;

};

} //End namespace