#include "AudioHandler.h"

void AudioHandler::load(std::string id, std::string path)
{
	sf::SoundBuffer* temp = new sf::SoundBuffer();
	if (!temp->loadFromFile(path))
	{
		std::cout << "Failed to load SoundBuffer (" + path + ")\n";
		delete temp;
	}
	else
		Handler::m_loaded[id] = temp;
}
