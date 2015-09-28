#include "NormalModeState.h"

namespace fbb {

NormalModeState::NormalModeState() {
	std::cout << "Created Normal Mode state!" << std::endl;
}

NormalModeState::~NormalModeState() {
	fbb::IGameState::~IGameState();
}

void NormalModeState::init() {
	sf::Clock* clock = new sf::Clock();
	sf::Time beginTime = clock->getElapsedTime();
	std::cout << "Initializing Normal Mode state..." << std::endl;

	font.loadFromFile("opensansc.ttf");

	sf::Texture textureUnselected;
	textureUnselected.loadFromFile("button_unselected.png");

	sf::Texture textureSelected;
	textureSelected.loadFromFile("button_selected.png");

	sf::Texture textureClicked;
	textureClicked.loadFromFile("button_clicked.png");

	float pos = 100.0f;
	float buttonWidth = 400.0f;
	float buttonHeight = 50.0f;
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(25);
	text.setColor(sf::Color::Black);
	sf::FloatRect textRect;

	fbb::RoundRectangle returnShape(sf::Vector2f(buttonWidth, buttonHeight), 10.0f, 10);
	returnShape.setFillColor(sf::Color(182, 59, 0, 255));
	returnShape.setPosition(pos, pos);
	sf::Text returnText("Return", font, 25);
	returnText.setColor(sf::Color::Black);
	textRect = returnText.getLocalBounds();
	returnText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	returnText.setPosition(pos + buttonWidth / 2, pos + buttonHeight / 2);
	fbb::Button btnReturn(returnShape, returnText);
	btnReturn.setAction([this]() {
		std::cout << "Returning to Menu..." << std::endl;
		fbb::Event e;
		e.type = fbb::Event::Return;
		pushEvent(e);
	});

	fbb::RoundRectangle quitShape(sf::Vector2f(buttonWidth, buttonHeight), 10.0f, 10);
	quitShape.setFillColor(sf::Color(182, 59, 0, 255));
	quitShape.setPosition(pos, pos * 2);
	sf::Text quitText("Quit Game", font, 25);
	quitText.setColor(sf::Color::Black);
	textRect = quitText.getLocalBounds();
	quitText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	quitText.setPosition(pos + buttonWidth / 2, pos * 2 + buttonHeight / 2);
	fbb::Button btnQuit(quitShape, quitText);
	btnQuit.setAction([this]() {
		std::cout << "Closing game..." << std::endl;
		fbb::Event e;
		e.type = fbb::Event::Close;
		pushEvent(e);
	});

	buttonList.push_back(btnReturn);
	buttonList.push_back(btnQuit);

	std::cout << "Done initializing Normal Mode state! Time: " << (clock->getElapsedTime() - beginTime).asMilliseconds() << " milliseconds" << std::endl;
	delete clock;
}

void NormalModeState::draw(sf::RenderTarget& window) {
	IGameState::draw(window);
}

void NormalModeState::update() {

}

void NormalModeState::mouseMoved(sf::Event::MouseMoveEvent e) {
	IGameState::mouseMoved(e);
}

void NormalModeState::mousePressed(sf::Event::MouseButtonEvent e) {
	IGameState::mousePressed(e);
}

void NormalModeState::mouseReleased(sf::Event::MouseButtonEvent e) {
	IGameState::mouseReleased(e);
}

} //End namespace