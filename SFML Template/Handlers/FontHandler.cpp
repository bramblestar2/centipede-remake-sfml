#include "FontHandler.h"

void FontHandler::load(std::string id, std::string path)
{
	sf::Font* temp = new sf::Font();
	if (!temp->loadFromFile(path))
	{
		std::cout << "Failed to load font (" + path + ")\n";
		delete temp;
	}
	else
		Handler::m_loaded[id] = temp;
}
