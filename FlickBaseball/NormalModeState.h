#pragma once
#include <functional>
#include "IGameState.h"
#include "Button.h"

namespace fbb {

class NormalModeState : public fbb::IGameState {
public:
	NormalModeState();
	~NormalModeState();

	virtual void init() override;
	virtual void draw(sf::RenderTarget& window) override;
	virtual void update() override;

};

} //End namespace