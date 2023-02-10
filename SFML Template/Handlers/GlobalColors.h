#pragma once
#include <SFML/Graphics.hpp>
#include "Handler.h"

class GlobalColors : public Handler<int, sf::Color>
{
public:
	static void load(int id, sf::Color color);
};