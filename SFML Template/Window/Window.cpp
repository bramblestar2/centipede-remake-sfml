#include "Window.h"

Window::Window()
{
	initWindow();

	TextureHandler::load("grass", "grass.png");
	AudioHandler::load("sound", "test.wav");

	animation.setup("animation/", "frame (#).png", 1, 59, sf::seconds(0.05));
	shape.setSize(sf::Vector2f(100, 150));
}

Window::~Window()
{
	delete window;

	TextureHandler::freeAll();
	AudioHandler::freeAll();
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

	window->draw(shape);

	window->display();
}

void Window::update()
{
	animation.update(shape);
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
