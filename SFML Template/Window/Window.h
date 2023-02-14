#pragma once
#include <SFML/Graphics.hpp>
#include "../Handlers/TextureHandler.h"
#include "../Handlers/AudioHandler.h"
#include "../Animated.h"

class Window
{
public:
	Window();
	//Free memory
	virtual ~Window();

	void run();
	void render();
	void update();
	void updateDt();
	void updateSFMLEvents();
private:
	void initWindow();
	
	sf::Clock dtClock;
	double dt;

	sf::RenderWindow* window;
	sf::Event event;

	Animated animation;
	sf::RectangleShape shape;
};

