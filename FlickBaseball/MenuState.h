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
	virtual void draw(sf::RenderTarget& window) override;
	virtual void update() override;

private:
	sf::Texture backgroundImage;
	sf::Texture titleImage;
	sf::Sprite background;
	sf::Sprite title;

};

} //End namespace