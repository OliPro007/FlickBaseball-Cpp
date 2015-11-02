#pragma once
#include <functional>
#include "IGameState.h"
#include "Button.h"

namespace fbb {

class MenuState : public fbb::IGameState {
public:
	MenuState(fbb::Config config);
	virtual ~MenuState();
	virtual void loadStringtable(std::string locale) override;

	virtual void draw(sf::RenderTarget& window) override;
	virtual void update() override;

	virtual void mouseMoved(const sf::Event::MouseMoveEvent& e) override;
	virtual void mousePressed(const sf::Event::MouseButtonEvent& e) override;
	virtual void mouseReleased(const sf::Event::MouseButtonEvent& e) override;

private:
	sf::Texture backgroundImage;
	sf::Texture titleImage;
	sf::Sprite background;
	sf::Sprite title;

};

} //End namespace