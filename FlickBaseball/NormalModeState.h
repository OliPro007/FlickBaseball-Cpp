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

	virtual void mouseMoved(const sf::Event::MouseMoveEvent& e) override;
	virtual void mousePressed(const sf::Event::MouseButtonEvent& e) override;
	virtual void mouseReleased(const sf::Event::MouseButtonEvent& e) override;

};

} //End namespace