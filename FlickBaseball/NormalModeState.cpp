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
	float textureX = 0.0f + textureUnselected.getSize().x;
	float textureY = 0.0f + textureUnselected.getSize().y;
	sf::VertexArray quad(sf::Quads, 4);
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(25);
	text.setColor(sf::Color::Black);
	sf::FloatRect textRect;

	quad[0].position = sf::Vector2f(pos, pos);
	quad[1].position = sf::Vector2f(pos + textureX, pos);
	quad[2].position = sf::Vector2f(pos + textureX, pos + textureY);
	quad[3].position = sf::Vector2f(pos, pos + textureY);
	quad[0].texCoords = sf::Vector2f(0.0f, 0.0f);
	quad[1].texCoords = sf::Vector2f(textureX, 0.0f);
	quad[2].texCoords = sf::Vector2f(textureX, textureY);
	quad[3].texCoords = sf::Vector2f(0.0f, textureY);
	text.setString("Return");
	textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	text.setPosition(pos + textureX / 2, pos + textureY / 2);
	fbb::Button btnReturn(text, quad, textureUnselected, textureSelected, textureClicked);
	btnReturn.setAction([this]() {
		std::cout << "Returning to Menu..." << std::endl;
		fbb::Event e;
		e.type = fbb::Event::Return;
		pushEvent(e);
	});

	pos = 200.0f;
	quad[0].position = sf::Vector2f(pos, pos);
	quad[1].position = sf::Vector2f(pos + textureX, pos);
	quad[2].position = sf::Vector2f(pos + textureX, pos + textureY);
	quad[3].position = sf::Vector2f(pos, pos + textureY);
	quad[0].texCoords = sf::Vector2f(0.0f, 0.0f);
	quad[1].texCoords = sf::Vector2f(textureX, 0.0f);
	quad[2].texCoords = sf::Vector2f(textureX, textureY);
	quad[3].texCoords = sf::Vector2f(0.0f, textureY);
	text.setString("Quit game");
	textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	text.setPosition(pos + textureX / 2, pos + textureY / 2);
	fbb::Button btnQuit(text, quad, textureUnselected, textureSelected, textureClicked);
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

}

void NormalModeState::update() {

}

} //End namespace