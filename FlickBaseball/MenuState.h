#pragma once
#include "IGameState.h"
#include "Button.h"

namespace fbb {

class MenuState : public fbb::IGameState {
public:
	MenuState();
	~MenuState();

	virtual void init();
	virtual void draw();
	virtual void update();
	virtual std::vector<fbb::Button>* getButtons() { return &buttonList; }

private:
	std::vector<fbb::Button> buttonList;
};

} //End namespace