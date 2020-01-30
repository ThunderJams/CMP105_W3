#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	sf::RectangleShape rect;
	sf::RectangleShape mover;
	sf::CircleShape circle;
	sf::CircleShape corner;
	float speed = 0;
	float moveSpeed = 0;
	float moveSpeedy = 0;
	float cornerSpeed = 0;
	float cornerSpeedy = 0;

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;
};