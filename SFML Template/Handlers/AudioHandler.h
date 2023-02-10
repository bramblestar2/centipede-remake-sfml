#pragma once
#include <SFML/Audio.hpp>
#include "Handler.h"

class AudioHandler : public Handler<std::string, sf::SoundBuffer>
{
public:
	static void load(std::string id, std::string path);
};

