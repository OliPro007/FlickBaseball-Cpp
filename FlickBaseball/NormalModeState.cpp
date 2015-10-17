#include "NormalModeState.h"

namespace fbb {

NormalModeState::NormalModeState() {
	sf::Clock* clock = new sf::Clock();
	sf::Time beginTime = clock->getElapsedTime();
	std::cout << "Initializing Normal Mode state..." << std::endl;

	backgroundImage.loadFromFile("background_field.png");
	backgroundImage.setRepeated(true);
	background.setTexture(backgroundImage);
	background.setTextureRect(sf::IntRect(0, 0, backgroundImage.getSize().x * 100, backgroundImage.getSize().y));
	background.scale(fbb::WIDTH / backgroundImage.getSize().x, fbb::HEIGHT / backgroundImage.getSize().y);
	font.loadFromFile("opensansc.ttf");

	float pos = 100.0f;
	float buttonWidth = 400.0f;
	float buttonHeight = 50.0f;
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
	clock = nullptr;
}

NormalModeState::~NormalModeState() {}

void NormalModeState::draw(sf::RenderTarget& window) {
	window.draw(background);
	IGameState::draw(window);
}

void NormalModeState::update() {

}

void NormalModeState::mouseMoved(const sf::Event::MouseMoveEvent& e) {
	IGameState::mouseMoved(e);
}

void NormalModeState::mousePressed(const sf::Event::MouseButtonEvent& e) {
	IGameState::mousePressed(e);
}

void NormalModeState::mouseReleased(const sf::Event::MouseButtonEvent& e) {
	IGameState::mouseReleased(e);
}

} //End namespace