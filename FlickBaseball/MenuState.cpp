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

	sf::Texture textureUnselected;
	textureUnselected.loadFromFile("button_unselected.png");

	sf::Texture textureSelected;
	textureSelected.loadFromFile("button_selected.png");

	sf::Texture textureClicked;
	textureClicked.loadFromFile("button_clicked.png");

	int nbButtons = 5;
	float spacing = 75.0f;
	float textureX = 0.0f + textureUnselected.getSize().x;
	float textureY = 0.0f + textureUnselected.getSize().y;
	float x = 1280.0f - spacing - textureX;
	float y = (720.0f - (spacing * (nbButtons - 1) + textureY * nbButtons)) / 2;
	sf::VertexArray quad(sf::Quads, 4);
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(25);
	text.setColor(sf::Color::Black);
	sf::FloatRect textRect;

	quad[0].position = sf::Vector2f(x, y);
	quad[1].position = sf::Vector2f(x + textureX, y);
	quad[2].position = sf::Vector2f(x + textureX, y + textureY);
	quad[3].position = sf::Vector2f(x, y + textureY);
	quad[0].texCoords = sf::Vector2f(0.0f, 0.0f);
	quad[1].texCoords = sf::Vector2f(textureX, 0.0f);
	quad[2].texCoords = sf::Vector2f(textureX, textureY);
	quad[3].texCoords = sf::Vector2f(0.0f, textureY);
	text.setString("Normal Mode");
	textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	text.setPosition(x + textureX / 2, y + textureY / 2);
	fbb::Button btnNormalMode(text, quad, textureUnselected, textureSelected, textureClicked);
	btnNormalMode.setAction([this]() {
		std::cout << "Switching to Normal Mode..." << std::endl;
		fbb::Event e;
		e.type = fbb::Event::ChangeState;
		e.changeState.thisState = MENU_STATE;
		e.changeState.nextState = NORMALMODE_STATE;
		pushEvent(e);
	});

	y += textureY + spacing;
	quad[0].position = sf::Vector2f(x, y);
	quad[1].position = sf::Vector2f(x + textureX, y);
	quad[2].position = sf::Vector2f(x + textureX, y + textureY);
	quad[3].position = sf::Vector2f(x, y + textureY);
	quad[0].texCoords = sf::Vector2f(0.0f, 0.0f);
	quad[1].texCoords = sf::Vector2f(textureX, 0.0f);
	quad[2].texCoords = sf::Vector2f(textureX, textureY);
	quad[3].texCoords = sf::Vector2f(0.0f, textureY);
	text.setString("Free Mode");
	textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	text.setPosition(x + textureX / 2, y + textureY / 2);
	fbb::Button btnFreeMode(text, quad, textureUnselected, textureSelected, textureClicked);
	btnFreeMode.setAction([this]() {
		std::cout << "Switching to Free Mode..." << std::endl;
		fbb::Event e;
		e.type = fbb::Event::ChangeState;
		e.changeState.thisState = MENU_STATE;
		e.changeState.nextState = FREEMODE_STATE;
	});

	y += textureY + spacing;
	quad[0].position = sf::Vector2f(x, y);
	quad[1].position = sf::Vector2f(x + textureX, y);
	quad[2].position = sf::Vector2f(x + textureX, y + textureY);
	quad[3].position = sf::Vector2f(x, y + textureY);
	quad[0].texCoords = sf::Vector2f(0.0f, 0.0f);
	quad[1].texCoords = sf::Vector2f(textureX, 0.0f);
	quad[2].texCoords = sf::Vector2f(textureX, textureY);
	quad[3].texCoords = sf::Vector2f(0.0f, textureY);
	text.setString("Options");
	textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	text.setPosition(x + textureX / 2, y + textureY / 2);
	fbb::Button btnOptions(text, quad, textureUnselected, textureSelected, textureClicked);
	btnOptions.setAction([this]() {
		std::cout << "Switching to Options menu..." << std::endl;
		fbb::Event e;
		e.type = fbb::Event::ChangeState;
		e.changeState.thisState = MENU_STATE;
		e.changeState.nextState = OPTIONS_STATE;
	});

	y += textureY + spacing;
	quad[0].position = sf::Vector2f(x, y);
	quad[1].position = sf::Vector2f(x + textureX, y);
	quad[2].position = sf::Vector2f(x + textureX, y + textureY);
	quad[3].position = sf::Vector2f(x, y + textureY);
	quad[0].texCoords = sf::Vector2f(0.0f, 0.0f);
	quad[1].texCoords = sf::Vector2f(textureX, 0.0f);
	quad[2].texCoords = sf::Vector2f(textureX, textureY);
	quad[3].texCoords = sf::Vector2f(0.0f, textureY);
	text.setString("Help");
	textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	text.setPosition(x + textureX / 2, y + textureY / 2);
	fbb::Button btnHelp(text, quad, textureUnselected, textureSelected, textureClicked);
	btnHelp.setAction([this]() {
		std::cout << "Switching to Help menu..." << std::endl;
		fbb::Event e;
		e.type = fbb::Event::ChangeState;
		e.changeState.thisState = MENU_STATE;
		e.changeState.nextState = HELP_STATE;
	});

	y = y + textureY + spacing;
	quad[0].position = sf::Vector2f(x, y);
	quad[1].position = sf::Vector2f(x + textureX, y);
	quad[2].position = sf::Vector2f(x + textureX, y + textureY);
	quad[3].position = sf::Vector2f(x, y + textureY);
	quad[0].texCoords = sf::Vector2f(0.0f, 0.0f);
	quad[1].texCoords = sf::Vector2f(textureX, 0.0f);
	quad[2].texCoords = sf::Vector2f(textureX, textureY);
	quad[3].texCoords = sf::Vector2f(0.0f, textureY);
	text.setString("Quit game");
	textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	text.setPosition(x + textureX / 2, y + textureY / 2);
	fbb::Button btnQuit(text, quad, textureUnselected, textureSelected, textureClicked);
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
}

void MenuState::update() {

}

} //End namespace