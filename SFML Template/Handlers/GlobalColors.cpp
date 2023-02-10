#include "GlobalColors.h"

void GlobalColors::load(int id, sf::Color color)
{
	Handler::m_loaded[id] = new sf::Color(color);
}
