#pragma once
#include <SFML/Graphics.hpp>
#include "Handler.h"

class FontHandler : public Handler<std::string, sf::Font>
{
public:
	static void load(std::string id, std::string path);
};