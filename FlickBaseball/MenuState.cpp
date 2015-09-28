#include "MenuState.h"

namespace fbb {

MenuState::MenuState() {
	backgroundImage.loadFromFile("mainmenu.png");
	titleImage.loadFromFile("title.png");
	background.setTexture(backgroundImage);
	title.setTexture(titleImage);
	std::cout << "Created Menu state!" << std::endl;
}

MenuState::~MenuState() {
	fbb::IGameState::~IGameState();
}

void MenuState::init() {
	sf::Clock* clock = new sf::Clock();
	sf::Time beginTime = clock->getElapsedTime();
	std::cout << "Initializing Menu state..." << std::endl;

	font.loadFromFile("opensansc.ttf");

	int nbButtons = 5;
	float spacing = 75.0f;
	float buttonWidth = 400.0f;
	float buttonHeight = 50.0f;
	float x = 1280.0f - spacing - buttonWidth;
	float y = (720.0f - (spacing * (nbButtons - 1) + buttonHeight * nbButtons)) / 2;
	sf::FloatRect textRect;

	fbb::RoundRectangle normalModeShape(sf::Vector2f(buttonWidth, buttonHeight), 10.0f, 10);
	normalModeShape.setFillColor(sf::Color(182, 59, 0, 255));
	normalModeShape.setPosition(x, y);
	sf::Text normalModeText("Normal Mode", font, 25);
	normalModeText.setColor(sf::Color::Black);
	textRect = normalModeText.getLocalBounds();
	normalModeText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	normalModeText.setPosition(x + buttonWidth / 2, y + buttonHeight / 2);
	fbb::Button btnNormalMode(normalModeShape, normalModeText);
	btnNormalMode.setAction([this]() {
		std::cout << "Switching to Normal Mode..." << std::endl;
		fbb::Event e;
		e.type = fbb::Event::ChangeState;
		e.changeState.thisState = MENU_STATE;
		e.changeState.nextState = NORMALMODE_STATE;
		pushEvent(e);
	});

	y += buttonHeight + spacing;
	fbb::RoundRectangle freeModeShape(sf::Vector2f(buttonWidth, buttonHeight), 10.0f, 10);
	freeModeShape.setFillColor(sf::Color(182, 59, 0, 255));
	freeModeShape.setPosition(x, y);
	sf::Text freeModeText("Free Mode", font, 25);
	freeModeText.setColor(sf::Color::Black);
	textRect = freeModeText.getLocalBounds();
	freeModeText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	freeModeText.setPosition(x + buttonWidth / 2, y + buttonHeight / 2);
	fbb::Button btnFreeMode(freeModeShape, freeModeText);
	btnFreeMode.setAction([this]() {
		std::cout << "Switching to Free Mode..." << std::endl;
		fbb::Event e;
		e.type = fbb::Event::ChangeState;
		e.changeState.thisState = MENU_STATE;
		e.changeState.nextState = FREEMODE_STATE;
	});

	y += buttonHeight + spacing;
	fbb::RoundRectangle optionsShape(sf::Vector2f(buttonWidth, buttonHeight), 10.0f, 10);
	optionsShape.setFillColor(sf::Color(182, 59, 0, 255));
	optionsShape.setPosition(x, y);
	sf::Text optionsText("Options", font, 25);
	optionsText.setColor(sf::Color::Black);
	textRect = optionsText.getLocalBounds();
	optionsText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	optionsText.setPosition(x + buttonWidth / 2, y + buttonHeight / 2);
	fbb::Button btnOptions(optionsShape, optionsText);
	btnOptions.setAction([this]() {
		std::cout << "Switching to Options menu..." << std::endl;
		fbb::Event e;
		e.type = fbb::Event::ChangeState;
		e.changeState.thisState = MENU_STATE;
		e.changeState.nextState = OPTIONS_STATE;
	});

	y += buttonHeight + spacing;
	fbb::RoundRectangle helpShape(sf::Vector2f(buttonWidth, buttonHeight), 10.0f, 10);
	helpShape.setFillColor(sf::Color(182, 59, 0, 255));
	helpShape.setPosition(x, y);
	sf::Text helpText("Help", font, 25);
	helpText.setColor(sf::Color::Black);
	textRect = helpText.getLocalBounds();
	helpText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	helpText.setPosition(x + buttonWidth / 2, y + buttonHeight / 2);
	fbb::Button btnHelp(helpShape, helpText);
	btnHelp.setAction([this]() {
		std::cout << "Switching to Help menu..." << std::endl;
		fbb::Event e;
		e.type = fbb::Event::ChangeState;
		e.changeState.thisState = MENU_STATE;
		e.changeState.nextState = HELP_STATE;
	});

	y = y + buttonHeight + spacing;
	fbb::RoundRectangle quitShape(sf::Vector2f(buttonWidth, buttonHeight), 10.0f, 10);
	quitShape.setFillColor(sf::Color(182, 59, 0, 255));
	quitShape.setPosition(x, y);
	sf::Text quitText("Quit Game", font, 25);
	quitText.setColor(sf::Color::Black);
	textRect = quitText.getLocalBounds();
	quitText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	quitText.setPosition(x + buttonWidth / 2, y + buttonHeight / 2);
	fbb::Button btnQuit(quitShape, quitText);
	btnQuit.setAction([this]() {
		std::cout << "Closing game..." << std::endl;
		fbb::Event e;
		e.type = fbb::Event::Close;
		pushEvent(e);
	});

	buttonList.push_back(btnNormalMode);
	buttonList.push_back(btnFreeMode);
	buttonList.push_back(btnOptions);
	buttonList.push_back(btnHelp);
	buttonList.push_back(btnQuit);

	std::cout << "Done initializing Menu state! Time: " << (clock->getElapsedTime() - beginTime).asMilliseconds() << " milliseconds" << std::endl;
	delete clock;
}

void MenuState::draw(sf::RenderTarget& window) {
	window.draw(background);
	window.draw(title);
	IGameState::draw(window);
}

void MenuState::update() {

}

void MenuState::mouseMoved(sf::Event::MouseMoveEvent e) {
	IGameState::mouseMoved(e);
}

void MenuState::mousePressed(sf::Event::MouseButtonEvent e) {
	IGameState::mousePressed(e);
}

void MenuState::mouseReleased(sf::Event::MouseButtonEvent e) {
	IGameState::mouseReleased(e);
}

} //End namespace