#include "NormalModeState.h"

using namespace rapidxml;

namespace fbb {

NormalModeState::NormalModeState(fbb::Config config) {
	sf::Clock clock;
	sf::Time beginTime = clock.getElapsedTime();
	std::cout << "Initializing Normal Mode state..." << std::endl;

	backgroundImage.loadFromFile("background_field.png");
	backgroundImage.setRepeated(true);
	background.setTexture(backgroundImage);
	background.setTextureRect(sf::IntRect(0, 0, backgroundImage.getSize().x * 100, backgroundImage.getSize().y));
	background.scale(fbb::WIDTH / backgroundImage.getSize().x, fbb::HEIGHT / backgroundImage.getSize().y);
	font.loadFromFile("opensansc.ttf");

	try {
		loadStringtable(config.locale);
	} catch(std::exception e) {
		std::cerr << "Normal mode state failed to load (see previous exception)" << std::endl;
		throw;
	}

	float pos = 100.0f;
	float buttonWidth = 400.0f;
	float buttonHeight = 50.0f;
	sf::FloatRect textRect;

	std::shared_ptr<fbb::RoundRectangle> returnShape = std::make_shared<fbb::RoundRectangle>(sf::Vector2f(buttonWidth, buttonHeight), 10.0f, 10);
	returnShape->setFillColor(sf::Color(182, 59, 0, 255));
	returnShape->setPosition(pos, pos);
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

	std::shared_ptr<fbb::RoundRectangle> quitShape = std::make_shared<fbb::RoundRectangle>(sf::Vector2f(buttonWidth, buttonHeight), 10.0f, 10);
	quitShape->setFillColor(sf::Color(182, 59, 0, 255));
	quitShape->setPosition(pos, pos * 2);
	sf::Text quitText("Quit Game", font, 25);
	quitText.setColor(sf::Color::Black);
	textRect = quitText.getLocalBounds();
	quitText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	quitText.setPosition(pos + buttonWidth / 2.0f, pos * 2 + buttonHeight / 2.0f);
	fbb::Button btnQuit(quitShape, quitText);
	btnQuit.setAction([this]() {
		std::cout << "Closing game..." << std::endl;
		fbb::Event e;
		e.type = fbb::Event::Close;
		pushEvent(e);
	});

	std::shared_ptr<sf::CircleShape> throwShape = std::make_shared<sf::CircleShape>(50.0f);
	throwShape->setFillColor(sf::Color(182, 59, 0, 255));
	throwShape->setPosition(50.0f, 550.0f);
	sf::Text throwText(stringTable.at("throw"), font, 25);
	throwText.setColor(sf::Color::Black);
	textRect = throwText.getLocalBounds();
	throwText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	throwText.setPosition(throwShape->getPosition().x + throwShape->getRadius(), throwShape->getPosition().y + throwShape->getRadius());
	fbb::Button btnThrow(throwShape, throwText);
	btnThrow.setAction([this]() {
		std::cout << "throw!" << std::endl;
	});

	buttonList.push_back(btnReturn);
	buttonList.push_back(btnQuit);
	buttonList.push_back(btnThrow);

	std::cout << "Done initializing Normal Mode state! Time: " << (clock.getElapsedTime() - beginTime).asMilliseconds() << " milliseconds" << std::endl;
}

NormalModeState::~NormalModeState() {}

void NormalModeState::loadStringtable(std::string locale) {
	std::ifstream file;
	file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try {
		file.open(locale + ".xml");
		xml_document<> doc;
		xml_node<>* root;
		std::vector<char> buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
		buffer.push_back('\0');
		doc.parse<0>(&buffer[0]);
		root = doc.first_node("stringtable");

		for(xml_node<>* state = root->first_node("state"); state; state = state->next_sibling()) {
			if(*(state->first_attribute("id")->value()) == '1') {
				for(xml_node<>* string = state->first_node("string"); string; string = string->next_sibling()) {
					//Use a map to tie the id with the value;
					std::pair<std::string, std::string> pair(string->first_attribute("id")->value(), string->value());
					stringTable.emplace(pair);
				}
			}
		}
		file.close();
	} catch(std::exception e) {
		std::cerr << e.what() << std::endl;
		throw;
	}
}

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