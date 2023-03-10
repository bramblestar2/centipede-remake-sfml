#include "Window.h"

Window::Window()
{
	initWindow();

	//Load textures
	TextureHandler::load("grass", "grass.png");
	TextureHandler::load("items", "spritesheets/bomberman_items.png");
	TextureHandler::load("centipede", "spritesheets/centipede_sprite_sheet.png");

	//Load animations
	AnimationHandler::load("protogen", "dance", "animation", "frame (#).png", 1, 59);

	//Load audios
	AudioHandler::load("sound", "test.wav");

	animation.setup(AnimationHandler::get("protogen", "dance"), 1, 59, sf::seconds(0.05));
	shape.setSize(sf::Vector2f(125, 150));

	animationTwo.setup(AnimationHandler::get("protogen", "dance"), 1, 59, sf::seconds(0.05));
	animationTwo.setFrame(30);
	tile.setSize(sf::Vector2f(125, 150));
	tile.setPosition(300 - 125, 0);
	//spriteAnimation.setup(TextureHandler::get("items"), sf::seconds(0.1), 0, 5);
	//spriteAnimation.addFrame(sf::IntRect(16 * 0, 16 * 2, 16, 16));
	//spriteAnimation.addFrame(sf::IntRect(16 * 1, 16 * 2, 16, 16));
	//spriteAnimation.addFrame(sf::IntRect(16 * 2, 16 * 2, 16, 16));
	//spriteAnimation.addFrame(sf::IntRect(16 * 3, 16 * 2, 16, 16));
	//spriteAnimation.addFrame(sf::IntRect(16 * 4, 16 * 2, 16, 16));
	//spriteAnimation.addFrame(sf::IntRect(16 * 5, 16 * 2, 16, 16));
	//tile.setSize(sf::Vector2f(100,100));
	//tile.setPosition(100,100);
}

Window::~Window()
{
	delete window;

	TextureHandler::freeAll();
	AudioHandler::freeAll();
	AnimationHandler::freeAll();
}

void Window::run()
{
	while (window->isOpen())
	{
		update();
		updateDt();
		updateSFMLEvents();
		render();
	}
}

void Window::render()
{
	window->clear();

	//window->draw(shape);
	//window->draw(tile);

	window->display();
}

void Window::update()
{
	animation.update(shape);
	animationTwo.update(tile);
	//spriteAnimation.update(tile);
}

void Window::updateDt()
{
	dt = dtClock.restart().asSeconds();
}

void Window::updateSFMLEvents()
{
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
				window->close();
				break;
		case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Escape:
					window->close();
					break;
				}
				break;
		}
	}
}

void Window::initWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(300, 200), "TITLE", sf::Style::Default);
}
