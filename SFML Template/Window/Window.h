#pragma once
#include <SFML/Graphics.hpp>
#include "../Handlers/TextureHandler.h"
#include "../Handlers/AudioHandler.h"
#include "../Animated.h"
#include "../SpriteSheetAnimation.h"

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
	
	sf::Clock dtClock, timer;
	double dt;

	sf::RenderWindow* window;
	sf::Event event;

	Animated animation;
	sf::RectangleShape shape;

	SpriteSheetAnimation spriteAnimation;
	sf::RectangleShape tile;
};

