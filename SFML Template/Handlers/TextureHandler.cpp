#include "TextureHandler.h"
#include <exception>
#include <iostream>

void TextureHandler::load(std::string id, std::string path)
{
	sf::Texture* temp = new sf::Texture();
	if (!temp->loadFromFile(path))
	{
		std::cout << "Failed to load texture (" + path + ")\n";
		delete temp;
	}
	else
		Handler::m_loaded[id] = temp;
}
