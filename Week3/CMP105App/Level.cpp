#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	rect.setSize(sf::Vector2f(50, 50));
	rect.setPosition(300, 200);
	rect.setFillColor(sf::Color::Red);
	speed = 200;

	mover.setSize(sf::Vector2f(50, 50));
	mover.setPosition(300, 300);
	mover.setFillColor(sf::Color::Blue);
	moveSpeed = 0;
	moveSpeedy = 0;

	circle.setRadius(50);
	circle.setPosition(1000, 1000);
	circle.setFillColor(sf::Color::Blue);
	circle.setOutlineColor(sf::Color::Red);
	circle.setOutlineThickness(2.f);

	corner.setRadius(50);
	corner.setPosition(100, 100);
	corner.setFillColor(sf::Color::Magenta);
	corner.setOutlineThickness(2.f);
	cornerSpeed = 150;
	cornerSpeedy = 200;
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	moveSpeed = 0;
	moveSpeedy = 0;

	if (input->isMouseRDown()) {
		int fiX = input->getMouseX();
		int fiY = input->getMouseY();
		circle.setPosition((fiX - 50), (fiY - 50));
	}

	if (input->isKeyDown(sf::Keyboard::Left)) {
		moveSpeed = -500;
	}
	if (input->isKeyDown(sf::Keyboard::Right)) {
		moveSpeed = 500;
	}
	if (input->isKeyDown(sf::Keyboard::Up)) {
		moveSpeedy = -500;
	}
	if (input->isKeyDown(sf::Keyboard::Down)) {
		moveSpeedy = 500;
	}
}

// Update game objects
void Level::update(float dt)
{
	sf::Vector2f rp = rect.getPosition();
	sf::Vector2f cp = corner.getPosition();
	sf::Vector2u pos = window->getSize();
	
	//std::cout << rp.x << "\n";
	if ((rp.x >= (pos.x-50)) || (rp.x <= 0.0)) {
		speed = -speed;
	}

	if ((cp.x >= (pos.x - 50)) || (cp.x <= 0.0)) {
		cornerSpeed = -cornerSpeed;
	}

	if ((cp.y >= (pos.y - 50)) || (cp.y <= 0.0)) {
		cornerSpeedy = -cornerSpeedy;
	}

	rect.move(speed*dt, 0);
	mover.move(moveSpeed*dt, moveSpeedy*dt);
	corner.move(cornerSpeed * dt, cornerSpeedy * dt);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(rect);
	window->draw(mover);
	window->draw(circle);
	window->draw(corner);
	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}