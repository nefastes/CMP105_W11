#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;

	//Menu init
	titleFont.loadFromFile("font/arial.ttf");
	title.setFillColor(sf::Color::Red);
	title.setCharacterSize(24);
	title.setFont(titleFont);
	title.setPosition(window->getPosition().x / 2, window->getPosition().y / 2);
	title.setString("WELCOME TO\nTHE AMAZING GAME");

	// initialise game objects
	audio->addMusic("sfx/cantina.ogg", "cantina");
	// initialise game objects
	playerTex.loadFromFile("gfx/Player.png");
	player.setTexture(&playerTex);
	player.setSize(sf::Vector2f(32, 32));
	//player.setOrigin(sf::Vector2f(player.getSize().x /2, player.getSize().y /2));
	player.setInput(input);
	player.setWindow(window);
	player.setPosition(sf::Vector2f(100, 200));
	player.setVelocity(sf::Vector2f(200, 0));
	player.setCollisionBox(sf::FloatRect(6, 6, 20, 26));

	//Pause
	pauseTxt.setFillColor(sf::Color::Red);
	pauseTxt.setCharacterSize(24);
	pauseTxt.setFont(titleFont);
	pauseTxt.setPosition(window->getSize().x / 2, window->getSize().y / 2);
	pauseTxt.setString("PAUSE");
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	player.handleInput(dt);
	if (input->isKeyDown(sf::Keyboard::G)) gameState->setCurrentState(State::PAUSE);
}

// Update game objects
void Level::update(float dt)
{
	player.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	switch (gameState->getCurrentState())
	{
	case State::MENU:
		window->draw(title);
		break;

	case State::LEVEL:
		window->draw(player);
		break;

	case State::PAUSE:
		window->draw(player);
		window->draw(pauseTxt);
		break;
	}


	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}

void Level::menu(float dt)
{
	if (input->isKeyDown(sf::Keyboard::F)) gameState->setCurrentState(State::LEVEL);
}

void Level::pause(float dt)
{
	if (input->isKeyDown(sf::Keyboard::F)) gameState->setCurrentState(State::LEVEL);
}