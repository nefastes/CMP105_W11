#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/AudioManager.h"
#include "Framework/GameState.h"
#include "Player.h"
#include <string>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud);
	~Level();

	//Menu state
	void menu(float dt);

	//Level state
	void handleInput(float dt);
	void update(float dt);

	//pause State
	void pause(float dt);

	//Render
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;
	GameState* gameState;
	AudioManager* audio;

	//Menu objects
	sf::Text title;
	sf::Font titleFont;

	//Level objects
	Player player;
	sf::Texture playerTex;

	//Pause Objects
	sf::Text pauseTxt;
};