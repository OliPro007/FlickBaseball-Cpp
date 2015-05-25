#pragma once
#include <functional>
#include "IGameState.h"
#include "Button.h"

namespace fbb {

class MenuState : public fbb::IGameState {
public:
	MenuState();
	~MenuState();

	virtual void init() override;
	virtual void draw() override;
	virtual void update() override;

};

} //End namespace