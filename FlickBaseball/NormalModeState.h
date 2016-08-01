#pragma once
#include "IGameState.h"
#include "Button.h"

namespace fbb {

class NormalModeState : public fbb::IGameState {
public:
	NormalModeState(fbb::Config);
	virtual ~NormalModeState();

	virtual void draw(sf::RenderTarget& window) override;
	virtual void update() override;

	virtual void mouseMoved(const sf::Event::MouseMoveEvent& e) override;
	virtual void mousePressed(const sf::Event::MouseButtonEvent& e) override;
	virtual void mouseReleased(const sf::Event::MouseButtonEvent& e) override;

private:
	sf::Texture backgroundImage;
	sf::Sprite background;

};

} //End namespace