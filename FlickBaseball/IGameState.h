#pragma once
#include <vector>
#include <iostream>
#include "Button.h"

namespace fbb {

class IGameState {
public:
	virtual ~IGameState() {}
	virtual void init() {}
	virtual void draw() {}
	virtual void update() {}
	virtual std::vector<fbb::Button>* getButtons() { return nullptr; }

protected:
	sf::Font font;
};

} //End namespace