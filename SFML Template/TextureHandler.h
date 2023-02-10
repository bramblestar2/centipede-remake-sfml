#pragma once
#include <SFML/Graphics.hpp>
#include "Handler.h"
class TextureHandler : public Handler<std::string, sf::Texture>
{
public:
	static void load(std::string id, std::string path);
};

